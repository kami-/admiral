#include "admiral_macros.h"

#include "\userconfig\admiral\log\hc.h"
#include "logbook.h"


adm_hc_fnc_findHcPlayer = {
    adm_hc_present = [false, objNull];
    if (isPlayer adm_hc_unit) then {
        adm_hc_present = [true, adm_hc_unit];
        DEBUG("admiral.hc",FMT_2("HC unit '%1' with name '%2' found.",adm_hc_unit,name adm_hc_unit));
    };
    publicVariable "adm_hc_present";
    DEBUG("admiral.hc",FMT_1("Published adm_hc_present='%1'.",adm_hc_present));
};

adm_hc_fnc_startAdmiral = {
    [[], {
        [] call compile preProcessFileLineNumbers ADDON_PATH(admiral_postinit_start.sqf);
        if (isServer) then {
            INFO("admiral.hc",FMT_1("Admiral version '%1' started successfully on server!",STR_ADMIRAL_VERSION));
        } else {
            INFO("admiral.hc",FMT_2("Admiral version '%1' started successfully on player '%1' as Headless Client!",STR_ADMIRAL_VERSION,adm_hc_present select 1));
        };
    }] call adm_hc_fnc_executeIfAdmiralMachine;
};

adm_hc_fnc_executeIfAdmiralMachine = {
    FUN_ARGS_2(_arguments,_code);

    if ([] call adm_hc_fnc_isAdmiralMachine) then {
        _arguments call _code;
    };
};

adm_hc_fnc_executeIfHc = {
    FUN_ARGS_2(_arguments,_code);

    if ([] call adm_hc_fnc_isHc) then {
        _arguments call _code;
    };
};

adm_hc_fnc_isHcPresent = {
    adm_hc_present select 0;
};

adm_hc_fnc_getHcUnit = {
    adm_hc_present select 1;
};

adm_hc_fnc_isHc = {
    adm_hc_present select 0 && {player == adm_hc_present select 1};
};

adm_hc_fnc_isAdmiralMachine = {
    [] call adm_hc_fnc_isHc || {!([] call adm_hc_fnc_isHcPresent) && {isServer}};
};

adm_hc_fnc_init = {
    if (isServer) then {
        [] call adm_fnc_compile;
        [] call adm_hc_fnc_findHcPlayer;
        [] call adm_hc_fnc_startAdmiral;
    } else {
        "adm_hc_present" addPublicVariableEventHandler {
            [] call adm_hc_fnc_startAdmiral;
        };
    };
};
