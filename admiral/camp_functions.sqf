#include "admiral_defines.h"

adm_camp_fnc_placeMan = {
    FUN_ARGS_4(_pos,_grp,_unitTemplate,_unitType);

    private "_unit";
    _unit = [
        _this select 0,
        _this select 1,
        [_unitTemplate, _unitType] call adm_common_fnc_getUnitTemplateArray,
        adm_camp_skillBoundary,
        adm_camp_aimingSpeed,
        adm_camp_aimingAccuracy
    ] call adm_common_fnc_placeMan;

    _unit;
};

adm_camp_fnc_processTiggerLogics = {
    FUN_ARGS_1(_triggers);

    {
        _x setVariable ["adm_camp_logics", []];
    } foreach _triggers;

    private "_logics";
    _logics = [allMissionObjects "Logic", {count waypoints _x > 1}] call BIS_fnc_conditionalSelect;
    {
        private ["_logic", "_isInsideTrigger"];
        _logic = _x;
        _logic setVariable ["adm_camp_usedBy", _logic getVariable ["usedBy", [true,true,true]]];
        _isInsideTrigger = false;
        {
            private "_trigger";
            _trigger = _x;
            if ([_trigger, getWPPos (waypoints _logic select 0)] call adm_common_fnc_isPosInsideTrigger) then {
                private "_triggerLogics";
                _triggerLogics = _trigger getVariable ["adm_camp_logics", []];
                PUSH(_triggerLogics,_logic);
                _isInsideTrigger = true;
            };
        } foreach _triggers;
        _logic setVariable ["adm_camp_endTrigger", [getWPPos ((waypoints _logic) select (count (waypoints _logic) - 1))] call adm_camp_fnc_getLogicEndTrigger, false];

        if (_isInsideTrigger && {adm_ai_debugging}) then {
            [_logic] call adm_debug_fnc_createMarkersForCampLogic;
        };
    } foreach _logics;
};

adm_camp_fnc_getGroupLogics = {
    FUN_ARGS_2(_trigger,_groupType);

    [_trigger getVariable ["adm_camp_logics", []], {(_x getVariable ["adm_camp_usedBy", [true,true,true]]) select _groupType}] call BIS_fnc_conditionalSelect;
};

adm_camp_fnc_getLogicEndTrigger = {
    FUN_ARGS_1(_wpPos);

    private "_trigger";
    _trigger = [nearestObjects [_wpPos, [], 50], {typeof _x == "EmptyDetector"}] call adm_common_fnc_filterFirst;
    if ([_trigger, []] call BIS_fnc_areEqual) then {
        _trigger = createTrigger ["EmptyDetector", _wpPos];
        _trigger setTriggerArea CAMP_DEFAULT_ENDTRIGGER_AREA;
        _trigger setTriggerActivation["NONE", "PRESENT", false];
    };

    _trigger;
};

adm_camp_fnc_createPatrolWaypoints = {
    FUN_ARGS_4(_group,_unitType,_trigger,_noOfWaypoints);

    private "_initialWaypointIndex";
    _initialWaypointIndex = 0;
    if (count waypoints _group > 0) then {
        _initialWaypointIndex = (count waypoints _group) - 1;
    };
    for "_i" from 1 to _noOfWaypoints do {
        [_group, [[_trigger, _unitType] call adm_common_fnc_randomFlatEmptyPosInTrigger, 0], 'MOVE', SELECT_RAND(AS_ARRAY_2('AWARE','SAFE')), 'RED'] call adm_common_fnc_createWaypoint;
    };
    [_group, (count waypoints _group) - 1] setWaypointStatements ["true", format["(group this) setCurrentWaypoint [group this, %1]", _initialWaypointIndex]];
};

adm_camp_fnc_createCampWaypoints = {
    FUN_ARGS_5(_group,_unitType,_trigger,_noOfWaypoints,_groupType);

    private ["_logics","_logic", "_logicWaypoints"];
    _logics = [_trigger, _groupType] call adm_camp_fnc_getGroupLogics;
    _logic = SELECT_RAND(_logics);
    _logicWaypoints = waypoints _logic;
    {
        [_group, [getWPPos _x, 0], 'MOVE', SELECT_RAND(AS_ARRAY_2('AWARE','SAFE')), 'RED'] call adm_common_fnc_createWaypoint;
    } foreach _logicWaypoints;
    [_group, _unitType, _logic getVariable "adm_camp_endTrigger", _noOfWaypoints] call adm_camp_fnc_createPatrolWaypoints;
};

adm_camp_fnc_isPoolEmpty = {
    FUN_ARGS_1(_trigger);

    private "_pool";
    _pool = _trigger getVariable ["adm_zone_pool", [0, 0, 0]];

    _pool select 0 == 0 && {_pool select 1 == 0} && {_pool select 2 == 0};
};

adm_camp_fnc_disableCamp = {
    FUN_ARGS_1(_trigger);

    _trigger setVariable ["adm_camp_isDisabled", true, false];
};

adm_camp_fnc_spawnInfGroup = {
    FUN_ARGS_5(_trigger,_groupSize,_groupType,_placeManFunc,_unitType);

    private ["_unitTemplate", "_initialPos", "_group"];
    _unitTemplate = _trigger getVariable "adm_zone_unitTemplate";
    _initialPos = [_trigger, "SoldierWB"] call adm_common_fnc_randomFlatEmptyPosInTrigger;
    _group = createGroup ([_unitTemplate] call adm_common_fnc_getUnitTemplateSide);

    for "_i" from 1 to _groupSize do {
        private ["_pos"];
        _pos = _initialPos findEmptyPosition [1, CAMP_SPAWN_CIRCLE_MAX_DIST, "SoldierWB"];
        [_pos, _group, _unitTemplate, UNIT_TYPE_ARRAY select _unitType] call _placeManFunc;
    };
    [_group] call adm_reduce_fnc_setGroupExpandCount;
    _group setVariable ["adm_zone_parent", _trigger];
    _group setVariable ["adm_ai_type", _groupType, false]; // TODO remove?

    if (adm_ai_debugging) then {
        [_group, _groupType] call adm_debug_fnc_createMarkersForPatrolGroup;
    };

    _group;
};

adm_camp_fnc_spawnVehicleGroup = {
    FUN_ARGS_5(_trigger,_groupSize,_groupType,_placeManFunc,_unitType);

    private ["_unitTemplate", "_vehicleTypes", "_vehTpye", "_vehPos", "_veh", "_group"];
    _unitTemplate = _trigger getVariable "adm_zone_unitTemplate";
    _vehicleTypes = [_unitTemplate, GROUP_TYPE_ARRAY select _groupType] call adm_common_fnc_getUnitTemplateArray;
    _vehTpye = SELECT_RAND(_vehicleTypes);
    _vehPos = [_trigger, _vehTpye] call adm_common_fnc_randomFlatEmptyPosInTrigger;
    _veh = [_vehTpye, _vehPos] call adm_common_fnc_placeVehicle;
    _group = createGroup ([_unitTemplate] call adm_common_fnc_getUnitTemplateSide);

    for "_i" from 1 to _groupSize do {
        private ["_pos", "_unit"];
        _pos = _vehPos findEmptyPosition [1, CAMP_SPAWN_CIRCLE_MAX_DIST, "SoldierWB"];
        _unit = [_pos, _group, _unitTemplate, UNIT_TYPE_ARRAY select _unitType] call _placeManFunc;
        call {
            if (_i == 1) exitWith { _unit moveInDriver _veh; };
            if (_i == 2) exitWith { _unit moveInGunner _veh; };
            if (_i == 3) exitWith { _unit moveInCommander _veh; };
        };
    };
    _group setVariable ["adm_ai_type", _groupType, false]; // TODO remove?

    if (adm_ai_debugging) then {
        [_group, _groupType] call adm_debug_fnc_createMarkersForPatrolGroup;
    };

    _group;
};

adm_camp_fnc_trySpawnGroups = {
    FUN_ARGS_4(_trigger,_groupType,_canSpawnFunc,_spawnFunc);

    if ([_trigger, _groupType] call _canSpawnFunc) then {
        [_trigger, _groupType] call _spawnFunc;
    }
};

adm_camp_fnc_spawnGroups = {
    FUN_ARGS_7(_trigger,_spawnFunc,_groupSize,_groupType,_noOfWaypoints,_unitType,_groupCount);

    private "_spawnedGroups";
    _spawnedGroups = [];
    for "_i" from 1 to _groupCount do {
        private "_group";
        _group = [_trigger, _groupSize, _groupType, adm_camp_fnc_placeMan, _unitType] call _spawnFunc;
        [_group, typeof vehicle leader _group, _trigger, _noOfWaypoints, _groupType] call adm_camp_fnc_createCampWaypoints;
        PUSH(_spawnedGroups, _group);
    };

    _spawnedGroups
};

adm_camp_fnc_getGroupCount = {
    FUN_ARGS_4(_initialGroupCount,_waveSize,_pool,_groupType);

    private "_groupCount";
    _groupCount = _initialGroupCount;
    if (_pool select _groupType != -1) then {
        if ((_pool select _groupType) < _waveSize) then {
            _groupCount = _pool select _groupType;
            _pool set [_groupType, 0];
        } else {
            _pool set [_groupType, (_pool select _groupType) - _waveSize];
        };
    };

    _groupCount;
};

adm_camp_fnc_getSpawnFunction = {
    FUN_ARGS_1(_trigger);

    private "_campType";
    _campType = _trigger getVariable "adm_camp_type";
    call {
        if (_campType == "random") exitWith {adm_camp_fnc_randomSpawn};
        if (_campType == "periodic") exitWith {adm_camp_fnc_periodicSpawn};
        if (_campType == "ondemand") exitWith {adm_camp_fnc_onDemandSpawn};
    };
};



// ==========================================
// Periodic functions
// ==========================================

adm_camp_fnc_periodicCanSpawnGroups = {
    FUN_ARGS_2(_trigger,_groupType);

    private ["_poolCount", "_lastSpawnTime", "_delay"];
    _poolCount = (_trigger getVariable ["adm_zone_pool", [0, 0, 0]]) select _groupType;
    _lastSpawnTime = (_trigger getVariable ["adm_camp_lastSpawnTime", [diag_tickTime, diag_tickTime, diag_tickTime]]) select _groupType;
    _delay = (_trigger getVariable ["adm_camp_groupDelay", [0, 0, 0]]) select _groupType;

    (_poolCount == -1 || {_poolCount > 0}) && {ceil diag_tickTime - _lastSpawnTime >= _delay};
};

adm_camp_fnc_periodicSpawnGroups = {
    FUN_ARGS_6(_trigger,_spawnFunc,_groupSize,_groupType,_noOfWaypoints,_unitType);

    private ["_pool", "_waveSize", "_lastSpawnTime"];
    _pool = _trigger getVariable ["adm_zone_pool", [0, 0, 0]];
    _waveSize = _trigger getVariable ["adm_camp_wave", [0, 0, 0]] select _groupType;
    _lastSpawnTime = _trigger getVariable ["adm_camp_lastSpawnTime", [diag_tickTime, diag_tickTime, diag_tickTime]];
    _lastSpawnTime set [GROUP_TYPE_INF, floor diag_tickTime];

    [_trigger, _spawnFunc, _groupSize, _groupType, _noOfWaypoints, _unitType, [_waveSize, _waveSize, _pool, _groupType] call adm_camp_fnc_getGroupCount] call adm_camp_fnc_spawnGroups;
};

adm_camp_fnc_periodicSpawnInfGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnInfGroup, adm_camp_infFireteamSize, GROUP_TYPE_INF, adm_camp_infWaypointAmount, UNIT_TYPE_INF] call adm_camp_fnc_periodicSpawnGroups;
};

adm_camp_fnc_periodicSpawnTechGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnVehicleGroup, adm_camp_techFireteamSize, GROUP_TYPE_TECH, adm_camp_techWaypointAmount, UNIT_TYPE_INF] call adm_camp_fnc_periodicSpawnGroups;
};

adm_camp_fnc_periodicSpawnArmourGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnVehicleGroup, adm_camp_armourFireteamSize, GROUP_TYPE_ARMOUR, adm_camp_armourWaypointAmount, UNIT_TYPE_CREW] call adm_camp_fnc_periodicSpawnGroups;
};

adm_camp_fnc_periodicSpawn = {
    FUN_ARGS_1(_trigger);

    _trigger setVariable ["adm_camp_lastSpawnTime", [diag_tickTime, diag_tickTime, diag_tickTime]];
    waitUntil {
        private "_spawnedGroups";
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_INF, adm_camp_fnc_periodicCanSpawnGroups, adm_camp_fnc_periodicSpawnInfGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_infGroups, _spawnedGroups);
        [_spawnedGroups] call adm_rupture_fnc_initGroups;
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_TECH, adm_camp_fnc_periodicCanSpawnGroups, adm_camp_fnc_periodicSpawnTechGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_techGroups, _spawnedGroups);
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_ARMOUR, adm_camp_fnc_periodicCanSpawnGroups, adm_camp_fnc_periodicSpawnArmourGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_armourGroups, _spawnedGroups);

        sleep (_trigger getVariable ["adm_camp_campDelay", CAMP_DEFAULT_DELAY]);
        [_trigger] call adm_camp_fnc_isPoolEmpty || {_trigger getVariable ["adm_camp_isDisabled", false]};
    };
};



// ==========================================
// OnDemand functions
// ==========================================
adm_camp_fnc_onDemandCanSpawnGroups = {
    FUN_ARGS_2(_trigger,_groupType);

    private ["_poolCount", "_waveSize", "_groups", "_aliveGroups"];
    _poolCount = (_trigger getVariable ["adm_zone_pool", [0, 0, 0]]) select _groupType;
    _waveSize = _trigger getVariable ["adm_camp_wave", [0, 0, 0]] select _groupType;
    _groups = (_trigger getVariable ["adm_camp_spawnedGroups", [[],[],[]]]) select _groupType;
    _aliveGroups = {alive leader _x} count _groups;

    (_poolCount == -1 || {_poolCount > 0}) && {_aliveGroups < _waveSize};
};

adm_camp_fnc_onDemandSpawnGroups = {
    FUN_ARGS_6(_trigger,_spawnFunc,_groupSize,_groupType,_noOfWaypoints,_unitType);

    private ["_pool", "_waveSize", "_groups", "_aliveGroups"];
    _pool = _trigger getVariable ["adm_zone_pool", [0, 0, 0]];
    _waveSize = _trigger getVariable ["adm_camp_wave", [0, 0, 0]] select _groupType;
    _groups = (_trigger getVariable ["adm_camp_spawnedGroups", [[],[],[]]]) select _groupType;
    _aliveGroups = {alive leader _x} count _groups;

    [_trigger, _spawnFunc, _groupSize, _groupType, _noOfWaypoints, _unitType, [_waveSize - _aliveGroups, _waveSize - _aliveGroups, _pool, _groupType] call adm_camp_fnc_getGroupCount] call adm_camp_fnc_spawnGroups;
};

adm_camp_fnc_onDemandSpawnInfGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnInfGroup, adm_camp_infFireteamSize, GROUP_TYPE_INF, adm_camp_infWaypointAmount, UNIT_TYPE_INF] call adm_camp_fnc_onDemandSpawnGroups;
};

adm_camp_fnc_onDemandSpawnTechGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnVehicleGroup, adm_camp_techFireteamSize, GROUP_TYPE_TECH, adm_camp_techWaypointAmount, UNIT_TYPE_INF] call adm_camp_fnc_onDemandSpawnGroups;
};

adm_camp_fnc_onDemandSpawnArmourGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnVehicleGroup, adm_camp_armourFireteamSize, GROUP_TYPE_ARMOUR, adm_camp_armourWaypointAmount, UNIT_TYPE_CREW] call adm_camp_fnc_onDemandSpawnGroups;
};

adm_camp_fnc_onDemandSpawn = {
    FUN_ARGS_1(_trigger);

    private ["_triggerInfGroups", "_triggerTechGroups", "_triggerArmourGroups"];
    _triggerInfGroups = [];
    _triggerTechGroups = [];
    _triggerArmourGroups = [];
    _trigger setVariable ["adm_camp_spawnedGroups", [_triggerInfGroups, _triggerTechGroups, _triggerArmourGroups], false];
    waitUntil {
        private "_spawnedGroups";
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_INF, adm_camp_fnc_onDemandCanSpawnGroups, adm_camp_fnc_onDemandSpawnInfGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_infGroups, _spawnedGroups);
        PUSH_ALL(_triggerInfGroups, _spawnedGroups);
        [_spawnedGroups] call adm_rupture_fnc_initGroups;
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_TECH, adm_camp_fnc_onDemandCanSpawnGroups, adm_camp_fnc_onDemandSpawnTechGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_techGroups, _spawnedGroups);
        PUSH_ALL(_triggerTechGroups, _spawnedGroups);
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_ARMOUR, adm_camp_fnc_onDemandCanSpawnGroups, adm_camp_fnc_onDemandSpawnArmourGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_armourGroups, _spawnedGroups);
        PUSH_ALL(_triggerArmourGroups, _spawnedGroups);

        sleep (_trigger getVariable ["adm_camp_campDelay", CAMP_DEFAULT_DELAY]);
        [_trigger] call adm_camp_fnc_isPoolEmpty || {_trigger getVariable ["adm_camp_isDisabled", false]};
    };
};



// ==========================================
// Random functions
// ==========================================
adm_camp_fnc_randomCanSpawnGroups = {
    FUN_ARGS_2(_trigger,_groupType);

    private ["_poolCount", "_chance"];
    _poolCount = (_trigger getVariable ["adm_zone_pool", [0, 0, 0]]) select _groupType;
    _chance = (_trigger getVariable ["adm_camp_spawnChance", [100, 100, 100]]) select _groupType;

    (_poolCount == -1 || {_poolCount > 0}) && {(floor random 100) + 1 <= _chance};
};

adm_camp_fnc_randomSpawnGroups = {
    FUN_ARGS_6(_trigger,_spawnFunc,_groupSize,_groupType,_noOfWaypoints,_unitType);

    private ["_pool", "_waveSize", "_groupCount"];
    _pool = _trigger getVariable ["adm_zone_pool", [0, 0, 0]];
    _waveSize = _trigger getVariable ["adm_camp_wave", [0, 0, 0]] select _groupType;
    _groupCount = floor random (_waveSize + 1);

    [_trigger, _spawnFunc, _groupSize, _groupType, _noOfWaypoints, _unitType, [_groupCount, _groupCount, _pool, _groupType] call adm_camp_fnc_getGroupCount] call adm_camp_fnc_spawnGroups;
};

adm_camp_fnc_randomSpawnInfGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnInfGroup, adm_camp_infFireteamSize, GROUP_TYPE_INF, adm_camp_infWaypointAmount, UNIT_TYPE_INF] call adm_camp_fnc_randomSpawnGroups;
};

adm_camp_fnc_randomSpawnTechGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnVehicleGroup, adm_camp_techFireteamSize, GROUP_TYPE_TECH, adm_camp_techWaypointAmount, UNIT_TYPE_INF] call adm_camp_fnc_randomSpawnGroups;
};

adm_camp_fnc_randomSpawnArmourGroups = {
    FUN_ARGS_1(_trigger);

    [_trigger, adm_camp_fnc_spawnVehicleGroup, adm_camp_armourFireteamSize, GROUP_TYPE_ARMOUR, adm_camp_armourWaypointAmount, UNIT_TYPE_CREW] call adm_camp_fnc_randomSpawnGroups;
};

adm_camp_fnc_randomSpawn = {
    FUN_ARGS_1(_trigger);

    waitUntil {
        private "_spawnedGroups";
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_INF, adm_camp_fnc_randomCanSpawnGroups, adm_camp_fnc_randomSpawnInfGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_infGroups, _spawnedGroups);
        [_spawnedGroups] call adm_rupture_fnc_initGroups;
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_TECH, adm_camp_fnc_randomCanSpawnGroups, adm_camp_fnc_randomSpawnTechGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_techGroups, _spawnedGroups);
        _spawnedGroups = [];
        _spawnedGroups = [_trigger, GROUP_TYPE_ARMOUR, adm_camp_fnc_randomCanSpawnGroups, adm_camp_fnc_randomSpawnArmourGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_armourGroups, _spawnedGroups);

        sleep (_trigger getVariable ["adm_camp_campDelay", CAMP_DEFAULT_DELAY]);
        [_trigger] call adm_camp_fnc_isPoolEmpty || {_trigger getVariable ["adm_camp_isDisabled", false]};
    };
};

adm_camp_fnc_init = {
    adm_camp_infGroups = [];
    adm_camp_techGroups = [];
    adm_camp_armourGroups = [];

    adm_camp_triggers = [allMissionObjects "EmptyDetector", {triggerText _x == "camp"}] call BIS_fnc_conditionalSelect;
    [adm_camp_triggers] call adm_camp_fnc_processTiggerLogics;
    {
        [_x] spawn {
            FUN_ARGS_1(_trigger);

            waitUntil { triggerActivated _trigger };

            if (adm_ai_debugging) then {
                [_trigger, "ColorGreen"] call adm_debug_fnc_createTriggerLocalMarker;
                [_trigger] call adm_error_fnc_validateZone;
            };

            [_trigger, adm_default_camp_unitTemplate] call adm_common_initUnitTemplate;
            [_trigger] call ([_trigger] call adm_camp_fnc_getSpawnFunction);
        };
    } foreach adm_camp_triggers;
};