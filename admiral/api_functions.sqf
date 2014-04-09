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