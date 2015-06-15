#include "admiral_macros.h"

#include "\userconfig\admiral\log\hc.h"
#include "logbook.h"


adm_hc_fnc_initDefaultNames = {
    if (isNil {adm_hc_defaultNames}) then {
        adm_hc_defaultNames = ["HC", "HeadlessClient"];
        DEBUG("admiral.hc","'adm_hc_defaultNames' was not defined. HC won't be used.");
    };
};

adm_hc_fnc_findHcPlayer = {
    adm_hc_present = [false, ""];
    DECLARE(_units) = [];
    FILTER_PUSH_ALL(_units,playableUnits,{isPlayer _x && {name _x in adm_hc_defaultNames}});
    if (count _units > 0) then {
        adm_hc_present = [true, name (_units select 0)]
        DEBUG("admiral.hc",FMT_2("Found player '%1' with name '%2' in HC list.",_units select 0,adm_hc_present select 0));
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

    if (([] call adm_hc_fnc_isHc) || {!([] call adm_hc_fnc_isHcPresent) && {isServer}}) then {
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

adm_hc_fnc_getHcName = {
    adm_hc_present select 1;
};

adm_hc_fnc_isHc = {
    adm_hc_present select 0 && {name player == adm_hc_present select 1};
};

adm_hc_fnc_init = {
    [] call adm_hc_fnc_initDefaultNames;
    if (isServer) then {
        [] call adm_hc_fnc_findHcPlayer;
        [] call adm_hc_fnc_startAdmiral;
    } else {
        "adm_hc_present" addPublicVariableEventHandler {
            [] call adm_hc_fnc_startAdmiral;
        };
    };
};
