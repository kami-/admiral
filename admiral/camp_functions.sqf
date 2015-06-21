#include "admiral_macros.h"

#include "\userconfig\admiral\log\camp.h"
#include "logbook.h"


adm_camp_fnc_placeMan = {
    FUN_ARGS_5(_position,_group,_unitTemplate,_zoneTemplate,_unitType);

    DECLARE(_unit) = [
        _position,
        _group,
        [_unitTemplate, _unitType] call adm_common_fnc_getUnitTemplateArray,
        [_zoneTemplate] call adm_common_fnc_getZoneTemplateSkillValues
    ] call adm_common_fnc_placeMan;
    DEBUG("admiral.camp.create",FMT_5("Spawned unit '%1' at position '%2', in group '%3' with type '%4' and classname '%5'.",_unit,_position,_group,_unitType,typeOf _unit));

    _unit;
};

adm_camp_fnc_spawnCrew = {
    FUN_ARGS_5(_vehicle,_group,_unitTemplate,_zoneTemplate,_unitType);

    DECLARE(_crew) = [
        _vehicle,
        _group,
        [_unitTemplate, _unitType] call adm_common_fnc_getUnitTemplateArray,
        [_zoneTemplate] call adm_common_fnc_getZoneTemplateSkillValues
    ] call adm_common_fnc_spawnCrew;
    DEBUG("admiral.camp.create",FMT_4("Spawned crew '%1' for vehicle '%2', in group '%3' with type '%4'.",_crew,_vehicle,_group,_unitType));

    _crew;
};

adm_camp_initPossiblePaths = {
    adm_camp_possiblePaths = [allMissionObjects "Logic", {count (waypoints _x) > 1}] call BIS_fnc_conditionalSelect;
    {
        _x setVariable ["adm_camp_usedBy", _x getVariable ["usedBy", [true,true,true]]];
    } foreach adm_camp_possiblePaths;
};

adm_camp_fnc_tryAddPossiblePaths = {
    FUN_ARGS_2(_zone,_possiblePaths);

    {
        if ([getWPPos (waypoints _x select 0), GET_ZONE_AREA(_zone), GET_ZONE_POSITION(_zone)] call adm_common_fnc_isPositionInArea) then {
            DECLARE(_zonePaths) = GET_CAMP_PATHS(_zone);
            PUSH(_zonePaths,_x);
            DEBUG("admiral.camp.create",FMT_2("Path logic '%1' is inside Camp Zone '%2'. Adding it to zone logics.",_x,GET_ZONE_ID(_zone)));
        };
        _x setVariable ["adm_camp_endTrigger", [getWPPos ((waypoints _x) select (count (waypoints _x) - 1))] call adm_camp_fnc_getLogicEndTrigger, false];
    } foreach _possiblePaths;
};

adm_camp_fnc_getGroupPaths = {
    FUN_ARGS_2(_zone,_groupType);

    [GET_CAMP_PATHS(_zone), {(_x getVariable ["adm_camp_usedBy", [true,true,true]]) select _groupType}] call BIS_fnc_conditionalSelect;
};

adm_camp_fnc_getLogicEndTrigger = {
    FUN_ARGS_1(_wpPos);

    DECLARE(_trigger) = [nearestObjects [_wpPos, [], 50], {typeof _x == "EmptyDetector"}] call adm_common_fnc_filterFirst;
    if (count _trigger == 0) then {
        _trigger = createTrigger ["EmptyDetector", _wpPos];
        _trigger setTriggerArea CAMP_DEFAULT_ENDTRIGGER_AREA;
        _trigger setTriggerActivation["NONE", "PRESENT", false];
        DEBUG("admiral.camp.create",FMT_2("No end trigger was found. Created new end trigger '%1' at position '%2'.",_trigger,_wpPos));
    } else {
        _trigger = _trigger select 0;
    };

    _trigger;
};

adm_camp_fnc_createPatrolWaypoints = {
    FUN_ARGS_6(_group,_unitType,_area,_areaPosition,_waypointBehaviours,_noOfWaypoints);

    DECLARE(_initialWaypointIndex) = 0;
    if (count waypoints _group > 0) then {
        _initialWaypointIndex = (count waypoints _group) - 1;
    };
    for "_i" from 1 to _noOfWaypoints do {
        [_group, [[_area, _areaPosition, _unitType] call adm_common_fnc_getRandomEmptyPositionInArea, 0], 'MOVE', SELECT_RAND(_waypointBehaviours), 'RED'] call adm_common_fnc_createWaypoint;
    };
    [_group, (count waypoints _group) - 1] setWaypointStatements ["true", format["(group this) setCurrentWaypoint [group this, %1]", _initialWaypointIndex]];
    DEBUG("admiral.camp.create",FMT_2("Created '%1' patrol waypoint(s) for group '%2'.",_noOfWaypoints,_group));
};

adm_camp_fnc_createCampWaypoints = {
    FUN_ARGS_5(_group,_unitType,_paths,_waypointBehaviours,_noOfWaypoints);

    private ["_path", "_pathWaypoints", "_endTrigger"];
    _path = SELECT_RAND(_paths);
    _pathWaypoints = waypoints _path;
    {
        [_group, [getWPPos _x, 0], 'MOVE', SELECT_RAND(_waypointBehaviours), 'RED'] call adm_common_fnc_createWaypoint;
    } foreach _pathWaypoints;
    _endTrigger = _path getVariable "adm_camp_endTrigger";
    [_group, _unitType, triggerArea _endTrigger, getPosATL _endTrigger, _waypointBehaviours, _noOfWaypoints] call adm_camp_fnc_createPatrolWaypoints;
    DEBUG("admiral.camp.create",FMT_2("Created '%1' path waypoint(s) for group with path logic '%2'.",count _pathWaypoints,_group));
};

adm_camp_fnc_isPoolEmpty = {
    FUN_ARGS_1(_zone);

    DECLARE(_pool) = GET_ZONE_POOL(_zone);

    _pool select 0 == 0 && {_pool select 1 == 0} && {_pool select 2 == 0};
};

adm_camp_fnc_disableCamp = {
    FUN_ARGS_1(_zone);

    SET_CAMP_ENABLED(_zone,false);
    INFO("admiral.camp.create",FMT_1("Camp Zone '%1' has been disabled.",GET_ZONE_ID(_zone)));
};

adm_camp_fnc_spawnInfGroup = {
    FUN_ARGS_4(_zone,_groupType,_unitType,_placeManFunc);

    private ["_unitTemplate", "_zoneTemplate", "_initialPos", "_group","_groupSize"];
    _unitTemplate = GET_ZONE_UNIT_TEMPLATE(_zone);
    _zoneTemplate = GET_ZONE_TEMPLATE(_zone);
    _initialPos = [GET_ZONE_AREA(_zone), GET_ZONE_POSITION(_zone), "SoldierWB"] call adm_common_fnc_getRandomEmptyPositionInArea;
    _group = createGroup ([_unitTemplate] call adm_common_fnc_getUnitTemplateSide);
    _groupSize = ["ZoneTemplates", _zoneTemplate, "infFireteamSize"] call adm_config_fnc_getNumber;
    for "_i" from 1 to _groupSize do {
        private ["_position", "_unit"];
        _position = _initialPos findEmptyPosition [1, CAMP_SPAWN_CIRCLE_MAX_DIST, "SoldierWB"];
        _unit = [_position, _group, _unitTemplate, _zoneTemplate, UNIT_TYPE_ARRAY select _unitType] call _placeManFunc;
        [format ["%1.spawned.unit", GET_ZONE_TYPE(_zone)], [_unit, UNIT_TYPE_ARRAY select _unitType, _zone]] call adm_event_fnc_emitEvent;
    };
    DEBUG("admiral.camp.create",FMT_4("Spawned '%1' unit(s) for group '%2' of type '%3' in Zone '%4'.",_groupSize,_group,GROUP_TYPE_ARRAY select _groupType,GET_ZONE_ID(_zone)));
    _group setVariable ["adm_zone_parent", _zone];
    _group setVariable ["adm_group_type", _groupType, false];
    [format ["%1.spawned.group", GET_ZONE_TYPE(_zone)], [_group, GROUP_TYPE_ARRAY select _groupType, _zone]] call adm_event_fnc_emitEvent;

    _group;
};

adm_camp_fnc_spawnVehicleGroup = {
    FUN_ARGS_4(_zone,_groupType,_unitType,_placeManFunc);

    private ["_unitTemplate", "_zoneTemplate", "_vehicleTypes", "_vehicleType", "_vehiclePosition", "_vehicle", "_crew", "_group"];
    _unitTemplate = GET_ZONE_UNIT_TEMPLATE(_zone);
    _zoneTemplate = GET_ZONE_TEMPLATE(_zone);
    _vehicleTypes = [_unitTemplate, GROUP_TYPE_ARRAY select _groupType] call adm_common_fnc_getUnitTemplateArray;
    _vehicleType = SELECT_RAND(_vehicleTypes);
    _vehiclePosition = [GET_ZONE_AREA(_zone), GET_ZONE_POSITION(_zone), _vehicleType] call adm_common_fnc_getRandomEmptyPositionInArea;
    _vehicle = [_vehicleType, _vehiclePosition] call adm_common_fnc_placeVehicle;
    [format ["%1.spawned.vehicle", GET_ZONE_TYPE(_zone)], [_vehicle, GROUP_TYPE_ARRAY select _groupType, _zone]] call adm_event_fnc_emitEvent;
    _group = createGroup ([_unitTemplate] call adm_common_fnc_getUnitTemplateSide);
    _group setVariable ["adm_group_type", _groupType, false];
    _crew = [_vehicle, _group, _unitTemplate, _zoneTemplate, UNIT_TYPE_ARRAY select _unitType] call adm_camp_fnc_spawnCrew;
    [format ["%1.spawned.crew", GET_ZONE_TYPE(_zone)], [_crew, UNIT_TYPE_ARRAY select _unitType, GROUP_TYPE_ARRAY select _groupType, _zone]] call adm_event_fnc_emitEvent;
    DEBUG("admiral.camp.create",FMT_4("Spawned crew for vehicle type of '%1' for group '%2' of type '%3' in Zone '%4'.",_vehicleType,_group,GROUP_TYPE_ARRAY select _groupType,GET_ZONE_ID(_zone)));
    [format ["%1.spawned.group", GET_ZONE_TYPE(_zone)], [_group, GROUP_TYPE_ARRAY select _groupType, _zone]] call adm_event_fnc_emitEvent;

    _group;
};

adm_camp_fnc_trySpawnGroups = {
    FUN_ARGS_4(_zone,_groupType,_canSpawnFunc,_spawnFunc);

    DECLARE(_spawnedGroups) = [];
    if ([_zone, _groupType] call _canSpawnFunc) then {
        _spawnedGroups = [_zone, _groupType] call _spawnFunc;
    };

    _spawnedGroups;
};

adm_camp_fnc_spawnGroups = {
    FUN_ARGS_5(_zone,_groupType,_unitType,_groupCount,_placeManFunc);

    private ["_spawnedGroups", "_group", "_waypointAmount"];
    _spawnedGroups = [];
    for "_i" from 1 to _groupCount do {
        call {
            if (_groupType == GROUP_TYPE_INF) exitWith {
                _group = [_zone, _groupType, _unitType, _placeManFunc] call adm_camp_fnc_spawnInfGroup;
                _waypointAmount = "infWaypointAmount";
            };
            if (_groupType in [GROUP_TYPE_TECH, GROUP_TYPE_ARMOUR]) exitWith {
                _group = [_zone, _groupType, _unitType, _placeManFunc] call adm_camp_fnc_spawnVehicleGroup;
                _waypointAmount = "techWaypointAmount";
            };
            if (_groupType in [GROUP_TYPE_TECH, GROUP_TYPE_ARMOUR]) exitWith {
                _group = [_zone, _groupType, _unitType, _placeManFunc] call adm_camp_fnc_spawnVehicleGroup;
                _waypointAmount = "armourWaypointAmount";
            };
        };
        DECLARE(_zoneTemplate) = GET_ZONE_TEMPLATE(_zone);
        [
            _group,
            typeof vehicle leader _group,
            [_zone, _groupType] call adm_camp_fnc_getGroupPaths,
            ["ZoneTemplates", _zoneTemplate, "waypointBehaviours"] call adm_config_fnc_getArray,
            ["ZoneTemplates", _zoneTemplate, _waypointAmount] call adm_config_fnc_getNumber
        ] call adm_camp_fnc_createCampWaypoints;
        PUSH(_spawnedGroups,_group);
    };

    _spawnedGroups
};

adm_camp_fnc_getGroupCount = {
    FUN_ARGS_4(_initialGroupCount,_waveSize,_pool,_groupType);

    DECLARE(_groupCount) = _initialGroupCount;
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
    FUN_ARGS_1(_zone);

    DECLARE(_campType) = GET_CAMP_TYPE(_zone);
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
    FUN_ARGS_2(_zone,_groupType);

    private ["_poolCount", "_lastSpawnTime", "_delay"];
    _poolCount = GET_ZONE_POOL(_zone) select _groupType;
    _lastSpawnTime = GET_CAMP_LAST_SPAWN_TIME(_zone) select _groupType;
    _delay = GET_CAMP_GROUP_DELAY(_zone) select _groupType;

    (_poolCount == -1 || {_poolCount > 0}) && {ceil diag_tickTime - _lastSpawnTime >= _delay};
};

adm_camp_fnc_periodicSpawnGroups = {
    FUN_ARGS_4(_zone,_groupType,_unitType,_placeManFunc);

    private ["_pool", "_waveSize", "_lastSpawnTime"];
    _pool = GET_ZONE_POOL(_zone);
    _waveSize = GET_CAMP_WAVE(_zone) select _groupType;
    _lastSpawnTime = GET_CAMP_LAST_SPAWN_TIME(_zone);
    _lastSpawnTime set [_groupType, floor diag_tickTime];

    [_zone, _groupType, _unitType, [_waveSize, _waveSize, _pool, _groupType] call adm_camp_fnc_getGroupCount, _placeManFunc] call adm_camp_fnc_spawnGroups;
};

adm_camp_fnc_periodicSpawnInfGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_INF, UNIT_TYPE_INF, adm_camp_fnc_placeMan] call adm_camp_fnc_periodicSpawnGroups;
};

adm_camp_fnc_periodicSpawnTechGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_TECH, UNIT_TYPE_INF, adm_camp_fnc_placeMan] call adm_camp_fnc_periodicSpawnGroups;
};

adm_camp_fnc_periodicSpawnArmourGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_ARMOUR, UNIT_TYPE_CREW, adm_camp_fnc_placeMan] call adm_camp_fnc_periodicSpawnGroups;
};

adm_camp_fnc_periodicSpawn = {
    FUN_ARGS_1(_zone);

    private ["_zoneInfGroups", "_zoneTechGroups", "_zoneArmourGroups"];
    _zoneInfGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 0;
    _zoneTechGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 1;
    _zoneArmourGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 2;
    SET_CAMP_LAST_SPAWN_TIME(_zone,AS_ARRAY_3(diag_tickTime,diag_tickTime,diag_tickTime));
    waitUntil {
        DECLARE(_spawnedGroups) = [];
        _spawnedGroups = [_zone, GROUP_TYPE_INF, adm_camp_fnc_periodicCanSpawnGroups, adm_camp_fnc_periodicSpawnInfGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_infGroups,_spawnedGroups);
        PUSH_ALL(_zoneInfGroups,_spawnedGroups);
        INFO("admiral.camp",FMT_2("Periodic Camp Zone '%1' spawned '%2' infantry group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        [_spawnedGroups] call adm_rupture_fnc_initGroups;
        _spawnedGroups = [];
        _spawnedGroups = [_zone, GROUP_TYPE_TECH, adm_camp_fnc_periodicCanSpawnGroups, adm_camp_fnc_periodicSpawnTechGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_techGroups,_spawnedGroups);
        PUSH_ALL(_zoneTechGroups,_spawnedGroups);
        INFO("admiral.camp",FMT_2("Periodic Camp Zone '%1' spawned '%2' technical group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        _spawnedGroups = [];
        _spawnedGroups = [_zone, GROUP_TYPE_ARMOUR, adm_camp_fnc_periodicCanSpawnGroups, adm_camp_fnc_periodicSpawnArmourGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_armourGroups,_spawnedGroups);
        PUSH_ALL(_zoneArmourGroups,_spawnedGroups);
        INFO("admiral.camp",FMT_2("Periodic Camp Zone '%1' spawned '%2' armour group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        ["camp.spawned.groups", [_zoneInfGroups, _zoneTechGroups, _zoneArmourGroups, _zone]] call adm_event_fnc_emitEvent;

        sleep GET_CAMP_DELAY(_zone);
        [_zone] call adm_camp_fnc_isPoolEmpty || {!IS_CAMP_ENABLED(_zone)};
    };
    INFO("admiral.camp",FMT_1("Periodic Camp Zone '%1' has stopped.",GET_ZONE_ID(_zone)));
};



// ==========================================
// OnDemand functions
// ==========================================
adm_camp_fnc_onDemandCanSpawnGroups = {
    FUN_ARGS_2(_zone,_groupType);

    private ["_poolCount", "_waveSize", "_groups", "_aliveGroups"];
    _poolCount = GET_ZONE_POOL(_zone) select _groupType;
    _waveSize = GET_CAMP_WAVE(_zone) select _groupType;
    _groups = GET_ZONE_SPAWNED_GROUPS(_zone) select _groupType;
    _aliveGroups = {IS_GROUP_ALIVE(_x)} count _groups;
    (_poolCount == -1 || {_poolCount > 0}) && {_aliveGroups < _waveSize};
};

adm_camp_fnc_onDemandSpawnGroups = {
    FUN_ARGS_4(_zone,_groupType,_unitType,_placeManFunc);

    private ["_pool", "_waveSize", "_groups", "_aliveGroups"];
    _pool = GET_ZONE_POOL(_zone);
    _waveSize = GET_CAMP_WAVE(_zone) select _groupType;
    _groups = GET_ZONE_SPAWNED_GROUPS(_zone) select _groupType;
    _aliveGroups = {IS_GROUP_ALIVE(_x)} count _groups;
    [_zone, _groupType, _unitType, [_waveSize - _aliveGroups, _waveSize - _aliveGroups, _pool, _groupType] call adm_camp_fnc_getGroupCount, _placeManFunc] call adm_camp_fnc_spawnGroups;
};

adm_camp_fnc_onDemandSpawnInfGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_INF, UNIT_TYPE_INF, adm_camp_fnc_placeMan] call adm_camp_fnc_onDemandSpawnGroups;
};

adm_camp_fnc_onDemandSpawnTechGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_TECH, UNIT_TYPE_INF, adm_camp_fnc_placeMan] call adm_camp_fnc_onDemandSpawnGroups;
};

adm_camp_fnc_onDemandSpawnArmourGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_ARMOUR, UNIT_TYPE_CREW, adm_camp_fnc_placeMan] call adm_camp_fnc_onDemandSpawnGroups;
};

adm_camp_fnc_onDemandSpawn = {
    FUN_ARGS_1(_zone);

    private ["_zoneInfGroups", "_zoneTechGroups", "_zoneArmourGroups"];
    _zoneInfGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 0;
    _zoneTechGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 1;
    _zoneArmourGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 2;
    waitUntil {
        DECLARE(_spawnedGroups) = [];
        _spawnedGroups = [_zone, GROUP_TYPE_INF, adm_camp_fnc_onDemandCanSpawnGroups, adm_camp_fnc_onDemandSpawnInfGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_infGroups, _spawnedGroups);
        PUSH_ALL(_zoneInfGroups, _spawnedGroups);
        INFO("admiral.camp",FMT_2("On-demand Camp Zone '%1' spawned '%2' infantry group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        [_spawnedGroups] call adm_rupture_fnc_initGroups;
        _spawnedGroups = [];
        _spawnedGroups = [_zone, GROUP_TYPE_TECH, adm_camp_fnc_onDemandCanSpawnGroups, adm_camp_fnc_onDemandSpawnTechGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_techGroups, _spawnedGroups);
        PUSH_ALL(_zoneTechGroups, _spawnedGroups);
        INFO("admiral.camp",FMT_2("On-demand Camp Zone '%1' spawned '%2' technical group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        _spawnedGroups = [];
        _spawnedGroups = [_zone, GROUP_TYPE_ARMOUR, adm_camp_fnc_onDemandCanSpawnGroups, adm_camp_fnc_onDemandSpawnArmourGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_armourGroups, _spawnedGroups);
        PUSH_ALL(_zoneArmourGroups, _spawnedGroups);
        INFO("admiral.camp",FMT_2("On-demand Camp Zone '%1' spawned '%2' armour group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        ["camp.spawned.groups", [_zoneInfGroups, _zoneTechGroups, _zoneArmourGroups, _zone]] call adm_event_fnc_emitEvent;

        sleep GET_CAMP_DELAY(_zone);
        [_zone] call adm_camp_fnc_isPoolEmpty || {!IS_CAMP_ENABLED(_zone)};
    };
    INFO("admiral.camp",FMT_1("On-demand Camp Zone '%1' has stopped.",GET_ZONE_ID(_zone)));
};



// ==========================================
// Random functions
// ==========================================
adm_camp_fnc_randomCanSpawnGroups = {
    FUN_ARGS_2(_zone,_groupType);

    private ["_poolCount", "_chance"];
    _poolCount = GET_ZONE_POOL(_zone) select _groupType;
    _chance = GET_CAMP_SPAWN_CHANCE(_zone) select _groupType;

    (_poolCount == -1 || {_poolCount > 0}) && {(floor random 100) + 1 <= _chance};
};

adm_camp_fnc_randomSpawnGroups = {
    FUN_ARGS_4(_zone,_groupType,_unitType,_placeManFunc);

    private ["_pool", "_waveSize", "_groupCount"];
    _pool = GET_ZONE_POOL(_zone);
    _waveSize = GET_CAMP_WAVE(_zone) select _groupType;
    _groupCount = floor random (_waveSize + 1);

    [_zone, _groupType, _unitType, [_groupCount, _groupCount, _pool, _groupType] call adm_camp_fnc_getGroupCount, _placeManFunc] call adm_camp_fnc_spawnGroups;
};

adm_camp_fnc_randomSpawnInfGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_INF, UNIT_TYPE_INF, adm_camp_fnc_placeMan] call adm_camp_fnc_randomSpawnGroups;
};

adm_camp_fnc_randomSpawnTechGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_TECH, UNIT_TYPE_INF, adm_camp_fnc_placeMan] call adm_camp_fnc_randomSpawnGroups;
};

adm_camp_fnc_randomSpawnArmourGroups = {
    FUN_ARGS_1(_zone);

    [_zone, GROUP_TYPE_ARMOUR, UNIT_TYPE_CREW, adm_camp_fnc_placeMan] call adm_camp_fnc_randomSpawnGroups;
};

adm_camp_fnc_randomSpawn = {
    FUN_ARGS_1(_zone);

    private ["_zoneInfGroups", "_zoneTechGroups", "_zoneArmourGroups"];
    _zoneInfGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 0;
    _zoneTechGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 1;
    _zoneArmourGroups = GET_ZONE_SPAWNED_GROUPS(_zone) select 2;
    waitUntil {
        DECLARE(_spawnedGroups) = [];
        _spawnedGroups = [_zone, GROUP_TYPE_INF, adm_camp_fnc_randomCanSpawnGroups, adm_camp_fnc_randomSpawnInfGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_infGroups, _spawnedGroups);
        PUSH_ALL(_zoneInfGroups, _spawnedGroups);
        INFO("admiral.camp",FMT_2("Random Camp Zone '%1' spawned '%2' infantry group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        [_spawnedGroups] call adm_rupture_fnc_initGroups;
        _spawnedGroups = [];
        _spawnedGroups = [_zone, GROUP_TYPE_TECH, adm_camp_fnc_randomCanSpawnGroups, adm_camp_fnc_randomSpawnTechGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_techGroups, _spawnedGroups);
        PUSH_ALL(_zoneTechGroups, _spawnedGroups);
        INFO("admiral.camp",FMT_2("Random Camp Zone '%1' spawned '%2' technical group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        _spawnedGroups = [];
        _spawnedGroups = [_zone, GROUP_TYPE_ARMOUR, adm_camp_fnc_randomCanSpawnGroups, adm_camp_fnc_randomSpawnArmourGroups] call adm_camp_fnc_trySpawnGroups;
        PUSH_ALL(adm_camp_armourGroups, _spawnedGroups);
        PUSH_ALL(_zoneArmourGroups, _spawnedGroups);
        INFO("admiral.camp",FMT_2("Random Camp Zone '%1' spawned '%2' armour group(s).",GET_ZONE_ID(_zone),count _spawnedGroups));
        ["camp.spawned.groups", [_zoneInfGroups, _zoneTechGroups, _zoneArmourGroups, _zone]] call adm_event_fnc_emitEvent;

        sleep GET_CAMP_DELAY(_zone);
        [_zone] call adm_camp_fnc_isPoolEmpty || {!IS_CAMP_ENABLED(_zone)};
    };
    INFO("admiral.camp",FMT_1("Random Camp Zone '%1' has stopped.",GET_ZONE_ID(_zone)));
};

adm_camp_setGroupDelay = {
    FUN_ARGS_1(_zone);

    private ["_campDelay", "_groupDelay"];
    _campDelay = GET_CAMP_DELAY(_zone);
    _groupDelay = GET_CAMP_GROUP_DELAY(_zone);
    for "_i" from 0 to (count _groupDelay) - 1 do {
        _groupDelay set [_i, (_groupDelay select _i) * _campDelay];
    };
    DEBUG("admiral.camp",FMT_1("Multiplied variable 'adm_camp_groupDelay' with variable 'adm_camp_campDelay' in Camp Zone '%1'.",GET_ZONE_ID(_zone)));
};

adm_camp_fnc_initZone = {
    FUN_ARGS_1(_zone);

    waitUntil {
        adm_isInitialized;
    };
    [_zone] call adm_camp_setGroupDelay;
    [_zone, adm_camp_possiblePaths] call adm_camp_fnc_tryAddPossiblePaths;
    INFO("admiral.camp",FMT_1("Camp Zone '%1' has been succesfully initialized.",GET_ZONE_ID(_zone)));
    SET_CAMP_ENABLED(_zone,true);
    PUSH(adm_camp_zones,_zone);
    [_zone] call ([_zone] call adm_camp_fnc_getSpawnFunction);
};

adm_camp_fnc_getAliveInfGroups = {
    [[adm_camp_infGroups]] call adm_common_fnc_getAliveGroups;
};

adm_camp_fnc_getAliveTechGroups = {
    [[adm_camp_techGroups]] call adm_common_fnc_getAliveGroups;
};

adm_camp_fnc_getAliveArmGroups = {
    [[adm_camp_armourGroups]] call adm_common_fnc_getAliveGroups;
};

adm_camp_fnc_getAliveGroups = {
   [[adm_camp_infGroups, adm_camp_techGroups, adm_camp_armourGroups]] call adm_common_fnc_getAliveGroups;
};

adm_camp_fnc_getAliveInfUnits = {
   [[adm_camp_infGroups]] call adm_common_fnc_getAliveUnits;
};

adm_camp_fnc_getAliveTechUnits = {
   [[adm_camp_techGroups]] call adm_common_fnc_getAliveUnits;
};

adm_camp_fnc_getAliveArmUnits = {
   [[adm_camp_armourGroups]] call adm_common_fnc_getAliveUnits;
};

adm_camp_fnc_getAliveUnits = {
   [[adm_camp_infGroups, adm_camp_techGroups, adm_camp_armourGroups]] call adm_common_fnc_getAliveUnits;
};

adm_camp_fnc_init = {
    adm_camp_infGroups = [];
    adm_camp_techGroups = [];
    adm_camp_armourGroups = [];
    adm_camp_zones = [];
    [] call adm_camp_initPossiblePaths;
};
