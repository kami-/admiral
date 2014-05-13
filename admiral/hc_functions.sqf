#include "admiral_defines.h"

adm_hc_fnc_initDefaultNames = {
    if (isNil {adm_hc_defaultNames}) then {
        adm_hc_defaultNames = [];
    };
};

adm_hc_fnc_findHCPlayer = {
    adm_hc_name = "NOONE";
    adm_hc_isPresent = false;
    private "_unitsHC";
    _unitsHC = [playableUnits, {isPlayer _x && {name _x in adm_hc_defaultNames}}] call BIS_fnc_conditionalSelect;
    if (count _unitsHC > 0) then {
        adm_hc_name = name (_unitsHC select 0);
        adm_hc_isPresent = true;
    };
    publicVariable "adm_hc_name";
    publicVariable "adm_hc_isPresent";
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
            diag_log LOG_MSG_1("INFO","Headless Client - Admiral started succesfully on player '%1'!",adm_hc_name);
        };
    } else {
        if (isServer) then {
            [] call compile preProcessFileLineNumbers "admiral\compile.sqf";
            diag_log LOG_MSG_0("INFO","Headless Client - Admiral started succesfully on server!");
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
