#include "admiral_defines.h"

adm_api_createCqcZone = {
    FUN_ARGS_4(_position,_area,_condition,_configEntries);

    [_position,_area,_condition,"cqc",_configEntries] call adm_api_createZone;
};

adm_api_createPatrolZone = {
    FUN_ARGS_4(_position,_area,_condition,_configEntries);

    [_position,_area,_condition,"patrol",_configEntries] call adm_api_createZone;
};

adm_api_createZone = {
    FUN_ARGS_5(_position,_area,_condition,_text,_configEntries);

    private "_trigger";
    _trigger = createTrigger ["NONE", _position];
    
};

adm_api_fnc_moveZone = {
    FUN_ARGS_3(_trigger,_position,_triggerArea);

    [_trigger, _position, _triggerArea] call adm_patrol_fnc_moveZone;
};

adm_api_fnc_followZone = {
    FUN_ARGS_4(_trigger,_object,_delay,_triggerArea);

    [_trigger, _object, _delay, _triggerArea] call dm_patrol_fnc_followZone;
};

adm_api_fnc_stopFollowZone = {
    FUN_ARGS_1(_trigger);

    [_trigger] call adm_patrol_fnc_stopFollowZone;
};

adm_api_fnc_disableCamp = {
    FUN_ARGS_1(_trigger);

    [_trigger] call adm_camp_fnc_disableCamp;
};

//CQC groups and units
adm_api_fnc_getCqcGroups = {
    [] call adm_cqc_fnc_getAliveGroups;
};

adm_api_fnc_getCqcUnits = {
    [] call adm_cqc_fnc_getAliveUnits;
};

//Patrol groups and units
adm_api_fnc_getPatrolInfGroups = {
    [] call adm_patrol_fnc_getAliveInfGroups;
};

adm_api_fnc_getPatrolTechGroups = {
    [] call adm_patrol_fnc_getAliveTechGroups;
};

adm_api_fnc_getPatrolArmGroups = {
    [] call adm_patrol_fnc_getAliveArmGroups;
};

adm_api_fnc_getPatrolGroups = {
    [] call adm_patrol_fnc_getAliveGroups;
};

adm_api_fnc_getPatrolInfUnits = {
    [] call adm_patrol_fnc_getAliveInfUnits;
};

adm_api_fnc_getPatrolTechUnits = {
    [] call adm_patrol_fnc_getAliveTechUnits;
};

adm_api_fnc_getPatrolArmUnits = {
    [] call adm_patrol_fnc_getAliveArmUnits;
};

adm_api_fnc_getPatrolUnits = {
    [] call adm_patrol_fnc_getAliveUnits;
};

// Camp groups and units
adm_api_fnc_getCampInfGroups = {
    [] call adm_camp_fnc_getAliveInfGroups;
};

adm_api_fnc_getCampTechGroups = {
    [] call adm_camp_fnc_getAliveTechGroups;
};

adm_api_fnc_getCampArmGroups = {
    [] call adm_camp_fnc_getAliveArmGroups;
};

adm_api_fnc_getCampGroups = {
    [] call adm_camp_fnc_getAliveGroups;
};

adm_api_fnc_getCampInfUnits = {
    [] call adm_camp_fnc_getAliveInfUnits;
};

adm_api_fnc_getCampTechUnits = {
    [] call adm_camp_fnc_getAliveTechUnits;
};

adm_api_fnc_getCampArmUnits = {
    [] call adm_camp_fnc_getAliveArmUnits;
};

adm_api_fnc_getCampUnits = {
    [] call adm_camp_fnc_getAliveUnits;
};