#include "admiral_defines.h"

adm_patrol_fnc_placeMan = {
    FUN_ARGS_4(_pos,_grp,_unitTemplate,_unitType);

    private "_unit";
    _unit = [
        _pos,
        _grp,
        [_unitTemplate, _unitType] call adm_common_fnc_getUnitTemplateArray,
        adm_cqc_skillBoundary,
        adm_cqc_aimingSpeed,
        adm_cqc_aimingAccuracy,
        adm_cqc_aimingShake,
        adm_cqc_endurance,
        adm_cqc_spotDistance,
        adm_cqc_spotTime,
        adm_cqc_courage,
        adm_cqc_reloadSpeed,
        adm_cqc_commanding,
        adm_cqc_general
    ] call adm_common_fnc_placeMan;

    _unit;
};

adm_patrol_fnc_createWaypoints = {
    FUN_ARGS_4(_group,_unitType,_trigger,_noOfWaypoints);

    [_group, _unitType, _trigger, _noOfWaypoints] call adm_camp_fnc_createPatrolWaypoints;

    private "_defultWp";
    _defultWp = (waypoints _group) select 0;
    _defultWp setWaypointPosition [getPosATL (leader _group), 0];
    _defultWp setWaypointType 'MOVE';
    _defultWp setWaypointBehaviour (SELECT_RAND(AS_ARRAY_2('AWARE','SAFE')));
    _defultWp setWaypointCombatMode 'RED';
};

adm_patrol_fnc_spawnInfGroup = {
    FUN_ARGS_1(_trigger);

    private "_group";
    _group = [_trigger, adm_patrol_infFireteamSize, GROUP_TYPE_INF, adm_patrol_fnc_placeMan, UNIT_TYPE_INF] call adm_camp_fnc_spawnInfGroup;
    [_group, "SoldierWB", _trigger, adm_patrol_infWaypointAmount] call adm_patrol_fnc_createWaypoints;

    _group;
};

adm_patrol_fnc_spawnTechGroup = {
    FUN_ARGS_1(_trigger);

    private ["_group"];
    _group = [_trigger, adm_patrol_techFireteamSize, GROUP_TYPE_TECH, adm_patrol_fnc_placeMan, UNIT_TYPE_INF] call adm_camp_fnc_spawnVehicleGroup;
    [_group, typeOf vehicle leader _group, _trigger, adm_patrol_techWaypointAmount] call adm_patrol_fnc_createWaypoints;

    _group;
};

adm_patrol_fnc_spawnArmorGroup = {
    FUN_ARGS_1(_trigger);

    private ["_group"];
    _group = [_trigger, adm_patrol_armourFireteamSize, GROUP_TYPE_ARMOUR, adm_patrol_fnc_placeMan, UNIT_TYPE_CREW] call adm_camp_fnc_spawnVehicleGroup;
    [_group, typeOf vehicle leader _group, _trigger, adm_patrol_armourWaypointAmount] call adm_patrol_fnc_createWaypoints;

    _group;
};

adm_patrol_fnc_moveZone = {
    FUN_ARGS_3(_trigger,_position,_triggerArea);

    [_trigger, _position, _triggerArea] call adm_patrol_fnc_moveTrigger;
    [_trigger] call adm_patrol_fnc_moveUpdateAllGroupWaypoints;
};

adm_patrol_fnc_followZone = {
    FUN_ARGS_4(_trigger,_object,_delay,_triggerArea);

    _trigger setVariable ["adm_patrol_following", true, false];
    [_trigger, _object, _delay, _triggerArea] spawn {
        FUN_ARGS_4(_trigger,_object,_delay,_triggerArea);

        waitUntil {
            [_trigger, getPosATL _object, _triggerArea] call adm_patrol_fnc_moveTrigger;
            [_trigger, getPosATL _object] call adm_patrol_fnc_followUpdateAllGroupWaypoints;
            sleep _delay;
            !(_trigger getVariable ["adm_patrol_following", false]);
        };
    };
};

adm_patrol_fnc_stopFollowZone = {
    FUN_ARGS_1(_trigger);

    if (_trigger getVariable ["adm_patrol_following", false]) then {
        _trigger setVariable ["adm_patrol_following", false, false];
        [_trigger] call adm_patrol_fnc_moveUpdateAllGroupWaypoints;
    };
};

adm_patrol_fnc_moveTrigger = {
    FUN_ARGS_3(_trigger,_position,_triggerArea);

    if (!isNil "_triggerArea") then {
        _trigger setTriggerArea _triggerArea;
    };
    _trigger setPos _position;

    if (adm_ai_debugging) then {
        [_trigger] call adm_debug_fnc_updateTriggerLocalMarker;
    };
};

adm_patrol_fnc_moveUpdateAllGroupWaypoints = {
    FUN_ARGS_1(_trigger);

    {
        [_trigger, _x, "SoldierWB", adm_patrol_infWaypointAmount] call adm_patrol_fnc_moveUpdateGroupWaypoints;
    } foreach (_trigger getVariable ["adm_zone_infGroups", []]);

    {
        [_trigger, _x, typeof vehicle leader _x, adm_patrol_techWaypointAmount] call adm_patrol_fnc_moveUpdateGroupWaypoints;
    } foreach (_trigger getVariable ["adm_zone_techGroups", []]);

    {
        [_trigger, _x, typeof vehicle leader _x, adm_patrol_armourWaypointAmount] call adm_patrol_fnc_moveUpdateGroupWaypoints;
    } foreach (_trigger getVariable ["adm_zone_armourGroups", []]);
};

adm_patrol_fnc_followUpdateAllGroupWaypoints = {
    FUN_ARGS_2(_trigger,_position);

    {
        [_x, _position] call adm_patrol_fnc_followUpdateGroupWaypoints;
    } foreach (_trigger getVariable ["adm_zone_infGroups", []]);

    {
        [_x, _position] call adm_patrol_fnc_followUpdateGroupWaypoints;
    } foreach (_trigger getVariable ["adm_zone_techGroups", []]);

    {
        [_x, _position] call adm_patrol_fnc_followUpdateGroupWaypoints;
    } foreach (_trigger getVariable ["adm_zone_armourGroups", []]);
};

adm_patrol_fnc_moveUpdateGroupWaypoints = {
    FUN_ARGS_4(_trigger,_group,_unitType,_noOfWaypoints);

    [_group] call adm_patrol_fnc_deleteGroupWaypoints;
    [_group, _unitType, _trigger, _noOfWaypoints] call adm_patrol_fnc_createWaypoints;
    [_group, [_trigger, _unitType] call adm_common_fnc_randomFlatEmptyPosInTrigger] call adm_patrol_fnc_updateDefaultWaypoint;
    [_group] call adm_patrol_fnc_updateEnemyWaypoint;
};

adm_patrol_fnc_followUpdateGroupWaypoints = {
    FUN_ARGS_2(_group,_position);

    [_group] call adm_patrol_fnc_deleteGroupWaypoints;
    [_group, _position] call adm_patrol_fnc_updateDefaultWaypoint;
    [_group] call adm_patrol_fnc_updateEnemyWaypoint;
};

adm_patrol_fnc_deleteGroupWaypoints = {
    FUN_ARGS_1(_group);

    while {count (waypoints _group) > 1} do
    {
        deleteWaypoint ((waypoints _group) select 0);
    };
};

adm_patrol_fnc_updateDefaultWaypoint = {
    FUN_ARGS_2(_group,_position);

    private "_defultWp";
    _defultWp = (waypoints _group) select 0;
    _defultWp setWaypointPosition [_position, 0];
    _group setCurrentWaypoint _defultWp;
};

adm_patrol_fnc_updateEnemyWaypoint = {
    FUN_ARGS_1(_group);

    private "_enemy";
    _enemy = _group getVariable ["target", objNull]; // TODO wtf?
    if (!isNull _enemy) then {
        private "_wp";
        _wp = [_group, [getPosATL _enemy, 0], 'MOVE', 'AWARE', 'RED'] call adm_common_fnc_createWaypoint;
        _group setCurrentWaypoint _wp;
    };
};

adm_patrol_fnc_initZone = {
    FUN_ARGS_1(_trigger);

    waitUntil {
        adm_isInitialized;
    };
    if (adm_ai_debugging) then {
        [_trigger] call adm_debug_fnc_createTriggerLocalMarker;
        [_trigger] call adm_error_fnc_validateZone;
    };

    private ["_pool", "_spawnedGroups"];
    _pool = _trigger getVariable "adm_zone_pool";

    // Spawn infantry groups
    _spawnedGroups = [];
    for "_i" from 1 to (_pool select 0) do {
        PUSH(_spawnedGroups, [_trigger] call adm_patrol_fnc_spawnInfGroup);
    };
    _trigger setVariable ["adm_zone_infGroups", _spawnedGroups, false];
    PUSH_ALL(adm_patrol_infGroups, _spawnedGroups);
    [adm_patrol_infGroups] call adm_rupture_fnc_initGroups;

    // Spawn technical groups
    _spawnedGroups = [];
    for "_i" from 1 to (_pool select 1) do {
        PUSH(_spawnedGroups, [_trigger] call adm_patrol_fnc_spawnTechGroup);
    };
    _trigger setVariable ["adm_zone_techGroups", _spawnedGroups, false];
    PUSH_ALL(adm_patrol_techGroups, _spawnedGroups);

    // Spawn armour groups
    _spawnedGroups = [];
    for "_i" from 1 to (_pool select 2) do {
        PUSH(_spawnedGroups, [_trigger] call adm_patrol_fnc_spawnArmorGroup);
    };
    _trigger setVariable ["adm_zone_armourGroups", _spawnedGroups, false];
    PUSH_ALL(adm_patrol_armourGroups, _spawnedGroups);
    PUSH(adm_patrol_triggers, _trigger);
};

adm_patrol_fnc_getAliveInfGroups = {
    [[adm_patrol_infGroups]] call adm_common_fnc_getAliveGroups;
};

adm_patrol_fnc_getAliveTechGroups = {
    [[adm_patrol_techGroups]] call adm_common_fnc_getAliveGroups;
};

adm_patrol_fnc_getAliveArmGroups = {
    [[adm_patrol_armourGroups]] call adm_common_fnc_getAliveGroups;
};

adm_patrol_fnc_getAliveGroups = {
   [[adm_patrol_infGroups, adm_patrol_techGroups, adm_patrol_armourGroups]] call adm_common_fnc_getAliveGroups;
};

adm_patrol_fnc_getAliveInfUnits = {
   [[adm_patrol_infGroups]] call adm_common_fnc_getAliveUnits;
};

adm_patrol_fnc_getAliveTechUnits = {
   [[adm_patrol_techGroups]] call adm_common_fnc_getAliveUnits;
};

adm_patrol_fnc_getAliveArmUnits = {
   [[adm_patrol_armourGroups]] call adm_common_fnc_getAliveUnits;
};

adm_patrol_fnc_getAliveUnits = {
   [[adm_patrol_infGroups, adm_patrol_techGroups, adm_patrol_armourGroups]] call adm_common_fnc_getAliveUnits;
};

adm_patrol_fnc_init = {
    adm_patrol_infGroups = [];
    adm_patrol_techGroups = [];
    adm_patrol_armourGroups = [];
    adm_patrol_triggers = [];
};
