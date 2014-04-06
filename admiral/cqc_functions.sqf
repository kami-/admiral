#include "admiral_defines.h"

// Returns a newly created cqc unit
adm_cqc_fnc_placeMan = {
    FUN_ARGS_4(_pos,_grp,_unitTemplate,_unitType);

    private ["_unit", "_wp"];
    _unit = [
        _pos,
        _grp,
        [_unitTemplate, _unitType] call adm_common_fnc_getUnitTemplateArray,
        adm_cqc_skillBoundary,
        adm_cqc_aimingSpeed,
        adm_cqc_aimingAccuracy
    ] call adm_common_fnc_placeMan;

    _grp enableAttack false;

    _wp = [_grp, [getPosATL _unit, 0], 'GUARD', 'AWARE', 'RED'] call adm_common_fnc_createWaypoint;

    _unit setDir (random 360);
    _unit setPosATL (_pos);
    doStop _unit;
    _unit setUnitPos 'UP';
    _grp setCurrentWaypoint _wp;

    _unit;
};

// Returns positions that are inside the building
adm_cqc_fnc_getBuildingPositions = {
    FUN_ARGS_1(_building);

    private["_buildingPositions"];
    _buildingPositions = [];

    if (!((typeOf _building) in adm_cqc_buildingBlacklist)) then {
        private ["_i"];
        _i = 0;
        while { !([_building buildingPos _i, [0,0,0]] call BIS_fnc_areEqual) } do {
            if([_building buildingPos _i] call adm_cqc_fnc_isPositionInBuilding) then {
                PUSH(_buildingPositions, _i);
            };
            INC(_i);
        };
    };

    _buildingPositions;
};

// Returns if a building position has "roof" above and is valid
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

    private "_buildingHeight";
    _buildingHeight = (getPosASL _building) select 2;
    [_positions, {((ATLToASL (_building buildingPos _x)) select 2) - _buildingHeight >= _minHeight}] call BIS_fnc_conditionalSelect
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
        private "_randomPos";
        _randomPos = SELECT_RAND(_buildingPositions);
        PUSH(_newPositions, _randomPos);
        _buildingPositions = _buildingPositions - [_randomPos];
    };

    _newPositions;
};

adm_cqc_fnc_getBuildingCapacity = {
    FUN_ARGS_1(_building);

    private "_capacity";
    _capacity = -1;
    {
        if (typeof _building == _x select 0) exitWith { _capacity = _x select 1; };
    } foreach adm_cqc_buildingCapacity;

    _capacity;
};

adm_cqc_fnc_getPossiblePositions = {
    FUN_ARGS_2(_building,_minHeight);

    private ["_buildingPositions"];
    _buildingPositions = if (isNil "_minHeight") then {
        [_building] call adm_cqc_fnc_getBuildingPositions
    } else {
        [_building, [_building] call adm_cqc_fnc_getBuildingPositions, _minHeight] call adm_cqc_fnc_getMinHeightBuildingPositions
    };

    [_building, _buildingPositions] call adm_cqc_fnc_getBuildingCapacityPositions;
};

// Returns a newly created cqc group
adm_cqc_fnc_spawnGarrisonGroup = {
    FUN_ARGS_4(_trigger,_numOfUnits,_possiblePositions,_building);

    private ["_unitTemplate", "_grp"];
    _unitTemplate = _trigger getVariable "adm_zone_unitTemplate";
    _grp = createGroup ([_unitTemplate] call adm_common_fnc_getUnitTemplateSide);
    for "_i" from 1 to _numOfUnits do {
        private ["_pos"];
        _pos = SELECT_RAND(_possiblePositions);
        _possiblePositions = _possiblePositions - [_pos];
        [_building buildingPos _pos, _grp, _unitTemplate, UNIT_TYPE_ARRAY select UNIT_TYPE_INF] call adm_cqc_fnc_placeMan;
    };

    [_grp] call adm_reduce_fnc_setGroupExpandCount;
    [_grp] call adm_reduce_fnc_setCqcInitPositions;
    _grp setVariable ["adm_zone_parent", _trigger];

    _grp;
};

adm_cqc_fnc_getTriggerBuildings = {
    FUN_ARGS_1(_trigger);

    private ["_triggerRadius", "_triggerBuildings"];
    _triggerRadius = ((triggerArea _trigger) select 0) max ((triggerArea _trigger) select 1);
    _triggerBuildings = [nearestObjects [getPosATL _trigger, ["house"], _triggerRadius], {[_trigger, getPosATL _x] call adm_common_fnc_isPosInsideTrigger}] call BIS_fnc_conditionalSelect;
    [_triggerBuildings] call adm_common_fnc_shuffle;
};

// Returns the newly created cqc groups
adm_cqc_fnc_spawnGarrison = {
    FUN_ARGS_1(_trigger);
    
    private ["_buildings", "_maxAmount", "_currentAmount", "_spawnedGroups"];
    _buildings = [_trigger] call adm_cqc_fnc_getTriggerBuildings;
    _maxAmount = _trigger getVariable ["adm_zone_pool", 0];
    _currentAmount = 0;
    _spawnedGroups = [];
    for [{private ["_i"]; _i = 0}, {_i < count _buildings && {_currentAmount < _maxAmount}}, {INC(_i)}] do {
        private ["_building", "_possiblePositions"];
        _building = _buildings select _i;
        _possiblePositions = [_building, _trigger getVariable "adm_cqc_minHeight"] call adm_cqc_fnc_getPossiblePositions;

        if((!([_possiblePositions, []] call BIS_fnc_areEqual)) && {_currentAmount < _maxAmount}) then {
            private ["_buildingCapacity", "_posCount", "_numOfUnits", "_group"];
            _buildingCapacity = [_building] call adm_cqc_fnc_getBuildingCapacity;
            _posCount = count _possiblePositions;
            _numOfUnits = switch (true) do
            {
                case (_buildingCapacity != -1 && _buildingCapacity <= _posCount): { _buildingCapacity };
                case (_buildingCapacity != -1 && _buildingCapacity > _posCount): { _posCount };
                case (_posCount >= adm_cqc_infFireteamSize): { adm_cqc_infFireteamSize };
                case (_posCount < adm_cqc_infFireteamSize && {_posCount >= 2}): { 2 };
                case (_posCount == 1): { 1 };
                default { 0 };
            };
            _currentAmount = _currentAmount + _numOfUnits;

            _group = [_trigger, _numOfUnits, _possiblePositions, _building] call adm_cqc_fnc_spawnGarrisonGroup;

            PUSH(_spawnedGroups, _group);
            
            if (adm_ai_debugging) then {
                [_group] call adm_debug_fnc_createMarkersForCqcGroup;
            };
        };
    };

    _spawnedGroups;
};

adm_cqc_fnc_canForceFire = {
    FUN_ARGS_2(_ai,_unit);

    (side _ai != side _unit) && {!terrainIntersect [eyePos _ai, eyePos _unit]} && {!lineIntersects [eyePos _ai, eyePos _unit]} && {alive _ai} && {alive _unit};
};

adm_cqc_fnc_getForceFireEnemy = {
    FUN_ARGS_1(_ai);

    private ["_enemies"];
    _enemies= [];
    if (!isNull _ai) then {
        _enemies = [getPosATL _ai nearEntities  ["Man", CQC_MAX_ENGAGE_DIST], {[_ai, _x] call adm_cqc_fnc_canForceFire}] call adm_common_fnc_filterFirst;
    };

    _enemies;
};

adm_cqc_fnc_forceFire = {
    FUN_ARGS_1(_groups);
    
    waitUntil {
        {
            private ["_group"];
            _group = _x;
            {
                private ["_unit", "_enemy"];
                _unit = _x;
                _enemy = [_unit] call adm_cqc_fnc_getForceFireEnemy;
                if (!([_enemy, []] call BIS_fnc_areEqual)) then {
                    _unit lookAt _enemy;
                    _unit doFire _enemy;
                };
            } foreach (units _group);
            
            if (count (units _group) == 0) then {
                _groups = _groups - [_group];
            }
        } foreach _groups;

        !(count _groups > 0 && adm_cqc_forceFireEnabled);
    };
};

// Initializes cqc
adm_cqc_fnc_init = {
    adm_cqc_triggers = [allMissionObjects "EmptyDetector", {triggerText _x == "cqc"}] call BIS_fnc_conditionalSelect;
    adm_cqc_groups = [];
    {
        [_x] spawn {
            FUN_ARGS_1(_trigger);
            waitUntil { triggerActivated _trigger };
            [_trigger, adm_default_cqc_unitTemplate] call adm_common_initUnitTemplate;
            if (adm_ai_debugging) then {
                [_trigger] call adm_debug_fnc_createTriggerLocalMarker;
                [_trigger] call adm_error_fnc_validateZone;
            };
            // Spawn CQC
            private ["_spawnedGroups"];
            _spawnedGroups = [_trigger] call adm_cqc_fnc_spawnGarrison;
            PUSH_ALL(adm_cqc_groups, _spawnedGroups);
            [_spawnedGroups] call adm_rupture_fnc_initGroups;
            [_spawnedGroups] call adm_cqc_fnc_forceFire;
        };
    } foreach adm_cqc_triggers;
};