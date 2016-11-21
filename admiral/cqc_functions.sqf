#include "admiral_macros.h"

#include "\userconfig\admiral\log\cqc.h"
#include "logbook.h"


adm_cqc_fnc_placeMan = {
    FUN_ARGS_5(_position,_group,_unitTemplate,_zoneTemplate,_unitType);

    DECLARE(_unit) = [
        _position,
        _group,
        [_unitTemplate, _unitType] call adm_common_fnc_getUnitTemplateArray,
        [_zoneTemplate] call adm_common_fnc_getZoneTemplateSkillValues
    ] call adm_common_fnc_placeMan;
    _unit setPos _position;
    [_unit, _group] call adm_cqc_fnc_initMan;
    DEBUG("admiral.cqc.create",FMT_4("Created unit '%1' at position '%2', in group '%3' with classname '%4'.",_unit,_position,_group,typeOf _unit));

    _unit;
};

adm_cqc_fnc_initMan = {
    FUN_ARGS_2(_unit,_group);

    _group enableAttack false;
    DECLARE(_wp) = [_group, [getPosATL _unit, 0], 'GUARD', 'AWARE', 'RED'] call adm_common_fnc_createWaypoint;
    _group setCurrentWaypoint _wp;
    _unit setDir (random 360);
    _unit disableAI "PATH";
    _unit disableAI "FSM";
    _unit setUnitPos 'UP';
};

adm_cqc_fnc_getBuildingPositions = {
    FUN_ARGS_1(_building);

    DECLARE(_buildingPositions) = [];
    if (!((typeOf _building) in adm_cqc_buildingBlacklist)) then {
        DECLARE(_i) = 0;
        while {!([_building buildingPos _i, [0,0,0]] call BIS_fnc_areEqual)} do {
            if([_building buildingPos _i] call adm_cqc_fnc_isPositionInBuilding) then {
                PUSH(_buildingPositions, _i);
            };
            INC(_i);
        };
    };

    _buildingPositions;
};

adm_cqc_fnc_isPositionInBuilding = {
    FUN_ARGS_1(_pos);

    private["_pos", "_posAbove", "_hasRoof", "_isValidPos"];
    _posAbove = [_pos select 0, _pos select 1, (_pos select 2) + 30];
    _hasRoof = lineIntersects [ATLtoASL _pos, ATLtoASL _posAbove];
    _isValidPos = !(lineIntersects [ATLtoASL _pos, ATLtoASL _pos]);

    _isValidPos && {adm_canSpawnOnRoof || _hasRoof};
};

adm_cqc_fnc_getMinHeightBuildingPositions = {
    FUN_ARGS_3(_building,_positions,_minHeight);

    DECLARE(_buildingHeight) = (getPosASL _building) select 2;

    [_positions, {((ATLToASL (_building buildingPos _x)) select 2) - _buildingHeight >= _minHeight}] call BIS_fnc_conditionalSelect;
};

adm_cqc_fnc_getBuildingCapacityPositions = {
    FUN_ARGS_2(_building,_buildingPositions);

    private ["_found", "_capacity", "_newPositions"];
    _found = false;
    _capacity = [_building] call adm_cqc_fnc_getBuildingCapacity;
    if (_capacity == -1 ) then {
        _capacity = ceil (count _buildingPositions) / 2;
    };
    if (_capacity > count _buildingPositions) then {
        _capacity = count _buildingPositions;
    };
    _newPositions = [];
    for "_i" from 1 to _capacity do {
        DECLARE(_randomPos) = SELECT_RAND(_buildingPositions);
        PUSH(_newPositions, _randomPos);
        _buildingPositions = _buildingPositions - [_randomPos];
    };

    _newPositions;
};

adm_cqc_fnc_getBuildingCapacity = {
    FUN_ARGS_1(_building);

    DECLARE(_capacity) = -1;
    {
        if (typeof _building == _x select 0) exitWith { _capacity = _x select 1; };
    } foreach adm_cqc_buildingCapacity;

    _capacity;
};

adm_cqc_fnc_getPossiblePositions = {
    FUN_ARGS_2(_building,_minHeight);

    DECLARE(_buildingPositions) = if (isNil "_minHeight") then {
        [_building] call adm_cqc_fnc_getBuildingPositions
    } else {
        [_building, [_building] call adm_cqc_fnc_getBuildingPositions, _minHeight] call adm_cqc_fnc_getMinHeightBuildingPositions
    };

    [_building, _buildingPositions] call adm_cqc_fnc_getBuildingCapacityPositions;
};

adm_cqc_fnc_spawnGarrisonGroupUnits = {
    FUN_ARGS_7(_group,_numOfUnits,_unitTemplate,_zoneTemplate,_possiblePositions,_building,_zone);

    for "_i" from 1 to _numOfUnits do {
        private ["_position", "_unit"];
        _position = SELECT_RAND(_possiblePositions);
        _possiblePositions = _possiblePositions - [_position];
        _unit = [_building buildingPos _position, _group, _unitTemplate, _zoneTemplate, UNIT_TYPE_ARRAY select UNIT_TYPE_INF] call adm_cqc_fnc_placeMan;
        ["cqc.spawned.unit", [_unit, _building, _position, UNIT_TYPE_ARRAY select UNIT_TYPE_INF, _zone]] call adm_event_fnc_emitEvent;
        ["zone.spawned.unit", [_unit, UNIT_TYPE_ARRAY select UNIT_TYPE_INF, _zone]] call adm_event_fnc_emitEvent;
    };
    DEBUG("admiral.cqc.create",FMT_3("Created '%1' CQC unit(s) for group '%2' in building '%3'.",_numOfUnits,_group,_building));
};

adm_cqc_fnc_spawnGarrisonGroup = {
    FUN_ARGS_4(_zone,_numOfUnits,_possiblePositions,_building);

    private ["_unitTemplate", "_group"];
    _unitTemplate = GET_ZONE_UNIT_TEMPLATE(_zone);
    _group = createGroup ([_unitTemplate] call adm_common_fnc_getUnitTemplateSide);
    [_group, _numOfUnits, _unitTemplate, GET_ZONE_TEMPLATE(_zone), _possiblePositions, _building, _zone] call adm_cqc_fnc_spawnGarrisonGroupUnits;
    _group setVariable ["adm_zone_parent", _zone];

    _group;
};

adm_cqc_fnc_getZoneBuildings = {
    FUN_ARGS_1(_zone);

    private ["_zoneRadius", "_buildings"];
    _zoneRadius = (GET_ZONE_AREA(_zone) select 0) max (GET_ZONE_AREA(_zone) select 1);
    _buildings = [nearestObjects [GET_ZONE_POSITION(_zone), ["house"], _zoneRadius], {[getPosATL _x, GET_ZONE_AREA(_zone), GET_ZONE_POSITION(_zone)] call adm_common_fnc_isPositionInArea}] call BIS_fnc_conditionalSelect;
    [_buildings] call adm_common_fnc_shuffle;
};

adm_cqc_fnc_getGarrisonGroupSize = {
    FUN_ARGS_3(_buildingCapacity,_posCount,_zone);

    DECLARE(_fireTeamSize) = ["ZoneTemplates", GET_ZONE_TEMPLATE(_zone), "infFireteamSize"] call adm_config_fnc_getNumber;
    call {
        if (_buildingCapacity != -1 && {_buildingCapacity <= _posCount})    exitWith {_buildingCapacity};
        if (_buildingCapacity != -1 && {_buildingCapacity > _posCount})     exitWith {_posCount};
        if (_posCount >= _fireTeamSize)                                     exitWith {_fireTeamSize};
        if (_posCount < _fireTeamSize && {_posCount >= 2})                  exitWith {2};
        if (_posCount == 1)                                                 exitWith {1};
                                                                            0;
    };
};

adm_cqc_fnc_spawnGarrison = {
    FUN_ARGS_1(_zone);
    
    private ["_buildings", "_maxAmount", "_currentAmount", "_spawnedGroups"];
    _buildings = [_zone] call adm_cqc_fnc_getZoneBuildings;
    DEBUG("admiral.cqc",FMT_2("CQC Zone '%1' found '%2' suitable building(s).",GET_ZONE_ID(_zone),count _buildings));
    _maxAmount = GET_ZONE_POOL(_zone);
    _currentAmount = 0;
    _spawnedGroups = [];
    {
        if (_currentAmount >= _maxAmount) exitWith {};
        private ["_building", "_possiblePositions"];
        _building = _x;
        _possiblePositions = [_building, GET_CQC_MIN_HEIGHT(_zone)] call adm_cqc_fnc_getPossiblePositions;
        if (count _possiblePositions > 0) then {
            private ["_numOfUnits", "_group"];
            _numOfUnits = [[_building] call adm_cqc_fnc_getBuildingCapacity, count _possiblePositions, _zone] call adm_cqc_fnc_getGarrisonGroupSize;
            _currentAmount = _currentAmount + _numOfUnits;
            _group = [_zone, _numOfUnits, _possiblePositions, _building] call adm_cqc_fnc_spawnGarrisonGroup;
            ["cqc.spawned.group", [_group, _building, _zone]] call adm_event_fnc_emitEvent;
            ["zone.spawned.group", [_group, "cqc", _zone]] call adm_event_fnc_emitEvent;
            PUSH(_spawnedGroups, _group);
        };
    } foreach _buildings;
    ["cqc.spawned.groups", [_spawnedGroups, _zone]] call adm_event_fnc_emitEvent;
    INFO("admiral.cqc",FMT_3("CQC Zone '%1' spawned '%2' unit(s) in '%3' group(s).",GET_ZONE_ID(_zone),_currentAmount,count _spawnedGroups));

    _spawnedGroups;
};

adm_cqc_fnc_canForceFire = {
    FUN_ARGS_2(_ai,_unit);

    alive _unit && {!([side _ai, side _unit] call adm_common_fnc_isFriendlySide)} && {!terrainIntersect [eyePos _ai, eyePos _unit]} && {!lineIntersects [eyePos _ai, eyePos _unit]};
};

adm_cqc_fnc_getForceFireEnemy = {
    FUN_ARGS_1(_ai);

    DECLARE(_enemies) = [];
    if (!isNull _ai) then {
        _enemies = [getPosATL _ai nearEntities  ["Man", CQC_MAX_ENGAGE_DIST], {[_ai, _x] call adm_cqc_fnc_canForceFire}] call adm_common_fnc_filterFirst;
    };

    _enemies;
};

adm_cqc_fnc_forceFire = {
    FUN_ARGS_1(_zone);

    if (call adm_hc_fnc_isHcPresent) exitWith {
        DEBUG("admiral.cqc.forcefire",FMT_1("Headless Client detected. ForceFire has been disabled for CQC Zone '%1'.",GET_ZONE_ID(_zone)));
    };
    SET_CQC_FORCE_FIRE_RUNNING(_zone,true);
    waitUntil {
        DECLARE(_aliveGroupLeft) = false;
        {
            DECLARE(_group) = _x;
            {
                DECLARE(_unit) = _x;
                if (alive _unit) then {
                    DECLARE(_enemy) = [_unit] call adm_cqc_fnc_getForceFireEnemy;
                    if (count _enemy > 0) then {
                        _enemy = _enemy select 0;
                        _unit lookAt _enemy;
                        _unit doFire _enemy;
                        TRACE("admiral.cqc.forcefire",FMT_4("CQC unit '%1' in group '%2', in CQC Zone '%3' has found an enemy '%4' and is being forced to fire at it.",_unit,_group,GET_ZONE_ID(_zone),_enemy));
                    };
                    _aliveGroupLeft = true;
                };
            } foreach (units _group);
        } foreach (GET_ZONE_SPAWNED_GROUPS(_zone));
        sleep adm_cqc_forceFireDelay;
        !(_aliveGroupLeft && {IS_CQC_FORCE_FIRE_ENABLED(_zone)});
    };
    SET_CQC_FORCE_FIRE_RUNNING(_zone,false);
    DEBUG("admiral.cqc.forcefire",FMT_1("ForceFire has been disabled for CQC Zone '%1'.",GET_ZONE_ID(_zone)));
};

adm_cqc_fnc_globalForceFire = {
    DEBUG("admiral.cqc.forcefire","Starting global force fire loop.");
    while {true} do {
        {
            private _group = _x;
            if (!isNull _group) then {
                {
                    private _unit = _x;
                    if (alive _unit) then {
                        private _enemy = [_unit] call adm_cqc_fnc_getForceFireEnemy;
                        if (count _enemy > 0) then {
                            _enemy = _enemy select 0;
                            _unit lookAt _enemy;
                            _unit doFire _enemy;
                            TRACE("admiral.cqc.forcefire",FMT_3("CQC unit '%1' in group '%2' has found an enemy '%3' and is being forced to fire at it.",_unit,_group,_enemy));
                        };
                    };
                } foreach units _group;
            };
        } foreach adm_cqc_groups;
        sleep adm_cqc_forceFireDelay;
    };
};

adm_cqc_fnc_disableForceFire = {
    FUN_ARGS_1(_zone);

    SET_CQC_FORCE_FIRE_ENABLED(_zone,false);
};

adm_cqc_fnc_enableForceFire = {
    FUN_ARGS_1(_zone);

    if (!IS_CQC_FORCE_FIRE_RUNNING(_zone)) then {
        SET_CQC_FORCE_FIRE_ENABLED(_zone,true);
        [_zone] spawn adm_cqc_fnc_forceFire;
    };
};

adm_cqc_fnc_initZone = {
    FUN_ARGS_1(_zone);

    DECLARE(_spawnedGroups) = [_zone] call adm_cqc_fnc_spawnGarrison;
    PUSH_ALL(adm_cqc_groups, _spawnedGroups);
    SET_ZONE_SPAWNED_GROUPS(_zone,_spawnedGroups);
    SET_CQC_FORCE_FIRE_ENABLED(_zone,adm_cqc_forceFireEnabled);
    SET_CQC_FORCE_FIRE_RUNNING(_zone,false);
    [_zone] spawn adm_cqc_fnc_forceFire;
    PUSH(adm_cqc_zones,_zone);
    INFO("admiral.cqc",FMT_1("CQC Zone '%1' has been succesfully initialized.",GET_ZONE_ID(_zone)));
};

adm_cqc_fnc_getAliveGroups = {
    [[adm_cqc_groups]] call adm_common_fnc_getAliveGroups;
};

adm_cqc_fnc_getAliveUnits = {
   [[adm_cqc_groups]] call adm_common_fnc_getAliveUnits;
};

adm_cqc_fnc_init = {
    adm_cqc_zones = [];
    adm_cqc_groups = [];
};
