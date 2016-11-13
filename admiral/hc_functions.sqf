#include "admiral_macros.h"

#include "\userconfig\admiral\log\hc.h"
#include "logbook.h"


adm_hc_fnc_startAdmiral = {
    [[], {
        [] call compile preProcessFileLineNumbers ADDON_PATH(admiral_postinit_start.sqf);
        if (isServer) then {
            INFO("admiral.hc",FMT_1("Admiral version '%1' started successfully on server!",STR_ADMIRAL_VERSION));
        } else {
            INFO("admiral.hc",FMT_2("Admiral version '%1' started successfully on player '%1' as Headless Client!",STR_ADMIRAL_VERSION,adm_hc_unit));
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
    !isNil {adm_hc_unit} && {!isNull adm_hc_unit} && {isPlayer adm_hc_unit};
};

adm_hc_fnc_getHcUnit = {
    if (isNil {adm_hc_unit}) then { objNull } else { adm_hc_unit };
};

adm_hc_fnc_isHc = {
    [] call adm_hc_fnc_isHcPresent && {player == [] call adm_hc_fnc_getHcUnit};
};

adm_hc_fnc_isAdmiralMachine = {
    [] call adm_hc_fnc_isHc || {!([] call adm_hc_fnc_isHcPresent) && {isServer}};
};

adm_hc_fnc_init = {
    sleep 5;
    if (isServer && {[] call adm_hc_fnc_isHcPresent}) then {
        [] call adm_fnc_compile;
    };
    [] call adm_hc_fnc_startAdmiral;
};
