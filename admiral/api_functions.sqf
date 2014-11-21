#include "admiral_macros.h"

// HC

/**
 * Executes code if the current machine is running Admiral. This can be the HC (if present), or the server (if not).
 * @param _arguments Arguments for the code to be executed
 * @param _code The code to be executed
 */
adm_api_fnc_executeIfAdmiralMachine = {
    FUN_ARGS_2(_arguments,_code);

    [_arguments, _code] call adm_hc_fnc_executeIfAdmiralMachine;
};

/**
 * Executes code if the current machine is HC. If not present, the code is not executed.
 * @param _arguments Arguments for the code to be executed
 * @param _code The code to be executed
 */
adm_api_fnc_executeIfHc = {
    FUN_ARGS_2(_arguments,_code);

    [_arguments, _code] call adm_hc_fnc_adm_api_fnc_executeIfHc;
};

/*
 * Returns wheter the is HC present or not.
 */
adm_api_fnc_isHcPresent = {
    [] call adm_hc_fnc_isHcPresent;
};

/*
 * Returns the player name of HC.
 */
adm_api_fnc_getHcName = {
    [] call adm_hc_fnc_getHcName;
};

/*
 * Returns wheter the current machine is HC or not.
 */
adm_api_fnc_isHc = {
    [] call adm_hc_fnc_isHc;
};



// Zone

/**
 * Initializes a zone with the given config entries.
 * @param _trigger Trigger object representing a zone
 * @param _configEntries Array of config entries that configure the zone
 */
adm_api_fnc_initZone = {
    FUN_ARGS_2(_trigger,_configEntries);

    [_trigger, _configEntries] call adm_common_fnc_setConfig;
};

/**
 * Returns if a player is closer to the zone, than the given distance.
 * The zone's longest axis is added to the distance.
 * @param _trigger Trigger object representing a zone
 * @param _distance The distance to check for players
 * @return Wether a player is close enough to the zone or not
 */
adm_api_fnc_isPlayerNearZone = {
    FUN_ARGS_2(_trigger,_distance);

    [_trigger, _distance] call adm_common_fnc_isPlayerNearZone;
};



// Settings

/**
 * Sets the _enemySide as enemy of _side.
 * @param _side The side to set the enemy of
 * @param _enemySide The side that will be the enemy
 */
adm_api_fnc_setEnemy = {
    FUN_ARGS_2(_side,_enemySide);

    [_side, _enemySide] call adm_settings_fnc_setEnemy;
};

/**
 * Sets the _friendlySide as friend of _side.
 * @param _side The side to set the friend of
 * @param _enemySide The side that will be the friend
 */
adm_api_fnc_setFriend = {
    FUN_ARGS_2(_side,_friendlySide);

    [_side, _friendlySide] call adm_settings_fnc_setFriend;
};



// Debugging

/**
 * Enables debugging of AI.
 */
adm_api_fnc_enableDebugging = {
    [] call adm_debug_fnc_enableDebugging;
};

/**
 * Disables debugging of AI.
 */
adm_api_fnc_disableDebugging = {
    [] call adm_debug_fnc_disableDebugging;
};



// CQC

/**
 * Disables force fire of a CQC zone.
 */
adm_api_fnc_disableForceFire = {
    FUN_ARGS_1(_trigger);

    [_trigger] call adm_cqc_fnc_disableForceFire;
};

/**
 * Enables force fire of a CQC zone.
 */
adm_api_fnc_enableForceFire = {
    FUN_ARGS_1(_trigger);

    [_trigger] call adm_cqc_fnc_enableForceFire;
};

/**
 * Returns all infantry groups spawned by Patrol zones.
 * @return Array of infantry groups
 */
adm_api_fnc_getCqcGroups = {
    [] call adm_cqc_fnc_getAliveGroups;
};

/**
 * Returns all units spawned by CQC zones.
 * @return Array of units
 */
adm_api_fnc_getCqcUnits = {
    [] call adm_cqc_fnc_getAliveUnits;
};



// Patrol

/**
 * Moves a Patrol zone to a given position. Optional triggerArea parameter will resize the zone.
 * The zone's groups will move to the new position and patrol there.
 * @param _trigger Trigger object representing a Patrol zone
 * @param _position Position where the zone will be moved
 * @param _triggerArea (optional) TriggerArea array containing the new size and shape of the zone
 */
adm_api_fnc_moveZone = {
    FUN_ARGS_3(_trigger,_position,_triggerArea);

    [_trigger, _position, _triggerArea] call adm_patrol_fnc_moveZone;
};

/**
 * Makes the groups of a Patrol zone to follow a given object. Optional triggerArea parameter will resize the zone.
 * The waypoints of the groups will be updated with the objects new position every _delay seconds.
 * @param _trigger Trigger object representing a Patrol zone
 * @param _object An object that has a position
 * @param _delay The delay in seconds between updating group waypoints
 * @param _triggerArea (optional) TriggerArea array containing the new size and shape of the zone
 */
adm_api_fnc_followZone = {
    FUN_ARGS_4(_trigger,_object,_delay,_triggerArea);

    [_trigger, _object, _delay, _triggerArea] call adm_patrol_fnc_followZone;
};

/**
 * Stops a follow Patrol zone. Groups waypoints will be updated one more time.
 * @param _trigger Trigger object representing a Patrol zone
 */
adm_api_fnc_stopFollowZone = {
    FUN_ARGS_1(_trigger);

    [_trigger] call adm_patrol_fnc_stopFollowZone;
};

/**
 * Returns all infantry groups spawned by Patrol zones.
 * @return Array of infantry groups
 */
adm_api_fnc_getPatrolInfGroups = {
    [] call adm_patrol_fnc_getAliveInfGroups;
};

/**
 * Returns all technical groups spawned by Patrol zones.
 * @return Array of technical groups
 */
adm_api_fnc_getPatrolTechGroups = {
    [] call adm_patrol_fnc_getAliveTechGroups;
};

/**
 * Returns all armour groups spawned by Patrol zones.
 * @return Array of armour groups
 */
adm_api_fnc_getPatrolArmGroups = {
    [] call adm_patrol_fnc_getAliveArmGroups;
};

/**
 * Returns all groups spawned by Patrol zones. This includes the infantry,
 * technical and armour groups. 
 * @return Array of groups
 */
adm_api_fnc_getPatrolGroups = {
    [] call adm_patrol_fnc_getAliveGroups;
};

/**
 * Returns all units of infantry groups spawned by Patrol zones.
 * @return Array of infantry units
 */
adm_api_fnc_getPatrolInfUnits = {
    [] call adm_patrol_fnc_getAliveInfUnits;
};

/**
 * Returns all units of technical groups spawned by Patrol zones.
 * @return Array of technical units
 */
adm_api_fnc_getPatrolTechUnits = {
    [] call adm_patrol_fnc_getAliveTechUnits;
};

/**
 * Returns all units of armour groups spawned by Patrol zones.
 * @return Array of armour units
 */
adm_api_fnc_getPatrolArmUnits = {
    [] call adm_patrol_fnc_getAliveArmUnits;
};

/**
 * Returns all units spawned by Patrol zones. This includes the units of infantry,
 * technical and armour groups. 
 * @return Array of units
 */
adm_api_fnc_getPatrolUnits = {
    [] call adm_patrol_fnc_getAliveUnits;
};



// Camp

/**
 * Disables a Camp zone, stopping it from spawning new groups. It's not possible to reenable it after.
 * @param _trigger Trigger object representing a Camp zone
 */
adm_api_fnc_disableCamp = {
    FUN_ARGS_1(_trigger);

    [_trigger] call adm_camp_fnc_disableCamp;
};

/**
 * Returns all infantry groups spawned by Camp zones.
 * @return Array of infantry groups
 */
adm_api_fnc_getCampInfGroups = {
    [] call adm_camp_fnc_getAliveInfGroups;
};

/**
 * Returns all technical groups spawned by Camp zones.
 * @return Array of technical groups
 */
adm_api_fnc_getCampTechGroups = {
    [] call adm_camp_fnc_getAliveTechGroups;
};

/**
 * Returns all armour groups spawned by Camp zones.
 * @return Array of armour groups
 */
adm_api_fnc_getCampArmGroups = {
    [] call adm_camp_fnc_getAliveArmGroups;
};

/**
 * Returns all groups spawned by Camp zones. This includes the infantry,
 * technical and armour groups. 
 * @return Array of groups
 */
adm_api_fnc_getCampGroups = {
    [] call adm_camp_fnc_getAliveGroups;
};

/**
 * Returns all units of infantry groups spawned by Camp zones.
 * @return Array of infantry units
 */
adm_api_fnc_getCampInfUnits = {
    [] call adm_camp_fnc_getAliveInfUnits;
};

/**
 * Returns all units of technical groups spawned by Camp zones.
 * @return Array of technical units
 */
adm_api_fnc_getCampTechUnits = {
    [] call adm_camp_fnc_getAliveTechUnits;
};

/**
 * Returns all units of armour groups spawned by Camp zones.
 * @return Array of armour units
 */
adm_api_fnc_getCampArmUnits = {
    [] call adm_camp_fnc_getAliveArmUnits;
};

/**
 * Returns all units spawned by Camp zones. This includes the units of infantry,
 * technical and armour groups. 
 * @return Array of units
 */
adm_api_fnc_getCampUnits = {
    [] call adm_camp_fnc_getAliveUnits;
};