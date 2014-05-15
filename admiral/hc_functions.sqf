#include "admiral_defines.h"

#define LOGGING_LEVEL_INFO
#define LOGGING_TO_RPT
#include "log_macros.h"

adm_hc_fnc_initDefaultNames = {
    if (isNil {adm_hc_defaultNames}) then {
        adm_hc_defaultNames = [];
        DEBUG("admiral.hc","'adm_hc_defaultNames' was not defined. HC won't be used.");
    };
};

adm_hc_fnc_findHCPlayer = {
    adm_hc_name = "NOONE";
    adm_hc_isPresent = false;
    DECLARE(_unitsHC) = [playableUnits, {isPlayer _x && {name _x in adm_hc_defaultNames}}] call BIS_fnc_conditionalSelect;
    if (count _unitsHC > 0) then {
        adm_hc_name = name (_unitsHC select 0);
        adm_hc_isPresent = true;
        DEBUG("admiral.hc",FMT_1("Found player '%1' in HC list.",adm_hc_name));
    };
    publicVariable "adm_hc_name";
    publicVariable "adm_hc_isPresent";
    DEBUG("admiral.hc",FMT_2("Published HC data adm_hc_name='%1' and adm_hc_isPresent='%2' to server and clients.",adm_hc_name,adm_hc_isPresent));
};

adm_hc_fnc_waitForHCInit = {
    waitUntil {
        !isNil {adm_hc_name} && {!isNil {adm_hc_isPresent}};
    };
};

adm_hc_fnc_startAdmiral = {
    if (adm_hc_isPresent) then {
        if (name player == adm_hc_name && {!isServer}) then { 
            [] call compile preProcessFileLineNumbers "admiral\compile.sqf";
            INFO("admiral.hc",FMT_2("Admiral version '%1' started successfully on player '%1' as Headless Client!",STR_ADMIRAL_VERSION,adm_hc_name));
        };
    } else {
        if (isServer) then {
            [] call compile preProcessFileLineNumbers "admiral\compile.sqf";
            INFO("admiral.hc",FMT_1("Admiral version '%1' started successfully on server!",STR_ADMIRAL_VERSION));
        };
    };
};

adm_hc_fnc_init = {
    [] call adm_hc_fnc_initDefaultNames;
    if (isServer) then {
        [] call adm_hc_fnc_findHCPlayer;
    } else {
        [] call adm_hc_fnc_waitForHCInit;
    };
    [] call adm_hc_fnc_startAdmiral;
};
