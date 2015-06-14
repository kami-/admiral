#include "admiral_macros.h"

#include "\userconfig\admiral\log\zone.h"
#include "logbook.h"


adm_zone_fnc_init = {
    adm_zones = [];
};

adm_zone_fnc_initZone = {
    DECLARE(_zone) = if (count _this > 1) then {
        _this call adm_zone_fnc_createTriggerZone;
    } else {
        _this call adm_zone_fnc_createZone;
    };
    [_zone] spawn GET_ZONE_INIT_FUNCTION(_zone);

    _zone;
};

adm_zone_fnc_createTriggerZone = {
    FUN_ARGS_2(_trigger,_configs);

    PUSH(_configs,AS_ARRAY_2("type",triggerText _trigger));
    PUSH(_configs,AS_ARRAY_2("position",getPosATL _trigger));
    PUSH(_configs,AS_ARRAY_2("area",triggerArea _trigger));

    [_configs] call adm_zone_fnc_createZone;
};

adm_zone_fnc_getDefaultZoneFromType = {
    FUN_ARGS_1(_configs);

    DECLARE(_zoneType) = (FIRST(_configs,{_x select 0 == "type"})) select 1;

    call {
        if (_zoneType == "camp")    exitWith {DEFAULT_CAMP_VALUES};
        if (_zoneType == "patrol")  exitWith {DEFAULT_PATROL_VALUES};
        if (_zoneType == "cqc")     exitWith {DEFAULT_CQC_VALUES};
    };
};

adm_zone_fnc_createZone = {
    FUN_ARGS_1(_configs);

    DECLARE(_zone) = [_configs] call adm_zone_fnc_getDefaultZoneFromType;
    SET_ZONE_ID(_zone,[] call adm_id_fnc_nextId);
    {
        [_zone,_x] call adm_zone_fnc_setZoneValueFromConfig;
    } foreach _configs;
    [_zone] call adm_zone_fnc_initZoneName;
    PUSH(adm_zones,_zone);

    _zone;
};

adm_zone_fnc_initZoneName = {
    FUN_ARGS_1(_zone);

    DECLARE(_zoneName) = GET_ZONE_NAME(_zone);
    if (_zoneName != "") then {
        _zone call compile format ["%1 = _this;", _zoneName];
    };
    
};

adm_zone_fnc_setZoneValueFromConfig = {
    FUN_ARGS_2(_zone,_config);

    DECLARE_2(_config,_configName,_configValue);
    call {
        if (_configName == "name")              exitWith {SET_ZONE_NAME(_zone,_configValue);};
        if (_configName == "type")              exitWith {SET_ZONE_TYPE(_zone,_configValue);};
        if (_configName == "position")          exitWith {SET_ZONE_POSITION(_zone,_configValue);};
        if (_configName == "area")              exitWith {SET_ZONE_AREA(_zone,_configValue);};
        if (_configName == "enabled")           exitWith {SET_ZONE_ENABLED(_zone,_configValue);};
        if (_configName == "unitTemplate")      exitWith {SET_ZONE_UNIT_TEMPLATE(_zone,_configValue);};
        if (_configName == "pool")              exitWith {SET_ZONE_POOL(_zone,_configValue);};
        if (_configName == "zoneTemplate")      exitWith {SET_ZONE_TEMPLATE(_zone,_configValue);};
        if (_configName == "campType")          exitWith {SET_CAMP_TYPE(_zone,_configValue);};
        if (_configName == "wave")              exitWith {SET_CAMP_WAVE(_zone,_configValue);};
        if (_configName == "campDelay")         exitWith {SET_CAMP_DELAY(_zone,_configValue);};
        if (_configName == "groupDelay")        exitWith {SET_CAMP_GROUP_DELAY(_zone,_configValue);};
        if (_configName == "spawnChance")       exitWith {SET_CAMP_SPAWN_CHANCE(_zone,_configValue);};
        if (_configName == "minHeight")         exitWith {SET_CQC_MIN_HEIGHT(_zone,_configValue);};
    };
};

adm_zone_fnc_getZoneById = {
    FUN_ARGS_1(_id);

    FIRST(adm_zones,{GET_ZONE_ID(_x) == _id});
};