#include "admiral_defines.h"

adm_cqc_fnc_placeMan = {
    FUN_ARGS_4(_position,_group,_unitTemplate,_unitType);

    DECLARE(_unit) = [
        _position,
        _group,
        [_unitTemplate, _unitType] call adm_common_fnc_getUnitTemplateArray,
        CQC_SKILL_ARRAY
    ] call adm_common_fnc_placeMan;
    [_unit, _group] call adm_cqc_fnc_initMan;

    _unit;
};

adm_cqc_fnc_initMan = {
    FUN_ARGS_2(_unit,_group);

    _group enableAttack false;
    DECLARE(_wp) = [_group, [getPosATL _unit, 0], 'GUARD', 'AWARE', 'RED'] call adm_common_fnc_createWaypoint;
    _group setCurrentWaypoint _wp;
    _unit setDir (random 360);
    _unit setPosATL (_position);
    doStop _unit;
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

    _hasRoof && _isValidPos;
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
    FUN_ARGS_5(_group,_numOfUnits,_unitTemplate,_possiblePositions,_building);

    for "_i" from 1 to _numOfUnits do {
        DECLARE(_position) = SELECT_RAND(_possiblePositions);
        _possiblePositions = _possiblePositions - [_position];
        [_building buildingPos _position, _group, _unitTemplate, UNIT_TYPE_ARRAY select UNIT_TYPE_INF] call adm_cqc_fnc_placeMan;
    };
};

adm_cqc_fnc_spawnGarrisonGroup = {
    FUN_ARGS_4(_trigger,_numOfUnits,_possiblePositions,_building);

    private ["_unitTemplate", "_group"];
    _unitTemplate = _trigger getVariable "adm_zone_unitTemplate";
    _group = createGroup ([_unitTemplate] call adm_common_fnc_getUnitTemplateSide);
    [_group, _numOfUnits, _unitTemplate, _possiblePositions, _building] call adm_cqc_fnc_spawnGarrisonGroupUnits;
    [_group] call adm_reduce_fnc_setGroupExpandCount;
    [_group] call adm_reduce_fnc_setCqcInitPositions;
    _group setVariable ["adm_zone_parent", _trigger];

    _group;
};

adm_cqc_fnc_getTriggerBuildings = {
    FUN_ARGS_1(_trigger);

    private ["_triggerRadius", "_triggerBuildings"];
    _triggerRadius = ((triggerArea _trigger) select 0) max ((triggerArea _trigger) select 1);
    _triggerBuildings = [nearestObjects [getPosATL _trigger, ["house"], _triggerRadius], {[_trigger, getPosATL _x] call adm_common_fnc_isPosInsideTrigger}] call BIS_fnc_conditionalSelect;
    [_triggerBuildings] call adm_common_fnc_shuffle;
};

adm_cqc_fnc_getGarrisonGroupSize = {
    FUN_ARGS_2(_buildingCapacity,_posCount);

    call {
        if (_buildingCapacity != -1 && {_buildingCapacity <= _posCount})    exitWith {_buildingCapacity};
        if (_buildingCapacity != -1 && {_buildingCapacity > _posCount})     exitWith {_posCount};
        if (_posCount >= adm_cqc_infFireteamSize)                           exitWith {adm_cqc_infFireteamSize};
        if (_posCount < adm_cqc_infFireteamSize && {_posCount >= 2})        exitWith {2};
        if (_posCount == 1)                                                 exitWith {1};
                                                                            0;
    };
};

adm_cqc_fnc_spawnGarrison = {
    FUN_ARGS_1(_trigger);
    
    private ["_buildings", "_maxAmount", "_currentAmount", "_spawnedGroups"];
    _buildings = [_trigger] call adm_cqc_fnc_getTriggerBuildings;
    _maxAmount = _trigger getVariable ["adm_zone_pool", 0];
    _currentAmount = 0;
    _spawnedGroups = [];
    {
        if (_currentAmount < _maxAmount) then exitWith {};
        private ["_building", "_possiblePositions"];
        _building = _x;
        _possiblePositions = [_building, _trigger getVariable "adm_cqc_minHeight"] call adm_cqc_fnc_getPossiblePositions;
        if (count _possiblePositions > 0) then {
            private ["_numOfUnits", "_group"];
            _numOfUnits = [[_building] call adm_cqc_fnc_getBuildingCapacity, count _possiblePositions] call adm_cqc_fnc_getGarrisonGroupSize;
            _currentAmount = _currentAmount + _numOfUnits;
            _group = [_trigger, _numOfUnits, _possiblePositions, _building] call adm_cqc_fnc_spawnGarrisonGroup;
            PUSH(_spawnedGroups, _group);
            if (adm_isDebuggingEnabled) then {
                [_group] call adm_debug_fnc_createMarkersForCqcGroup;
            };
        };
    } foreach _buildings;

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
    FUN_ARGS_1(_groups);
    
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
                    };
                    _aliveGroupLeft = true;
                };
            } foreach (units _group);
        } foreach _groups;
        sleep adm_cqc_forceFireDelay;
        !(_aliveGroupLeft && adm_cqc_forceFireEnabled);
    };
};

adm_cqc_fnc_initZone = {
    FUN_ARGS_1(_trigger);

    waitUntil {
        adm_isInitialized;
    };
    if (adm_isDebuggingEnabled) then {
        [_trigger] call adm_debug_fnc_createTriggerLocalMarker;
        [_trigger] call adm_error_fnc_validateZone;
    };

    DECLARE(_spawnedGroups) = [_trigger] call adm_cqc_fnc_spawnGarrison;
    PUSH_ALL(adm_cqc_groups, _spawnedGroups);
    [_spawnedGroups] call adm_rupture_fnc_initGroups;
    [_spawnedGroups] call adm_cqc_fnc_forceFire;
    PUSH(adm_cqc_groups, _trigger);
};

adm_cqc_fnc_getAliveGroups = {
    [[adm_cqc_groups]] call adm_common_fnc_getAliveGroups;
};

adm_cqc_fnc_getAliveUnits = {
   [[adm_cqc_groups]] call adm_common_fnc_getAliveUnits;
};

adm_cqc_fnc_init = {
    adm_cqc_triggers = [];
    adm_cqc_groups = [];
};
