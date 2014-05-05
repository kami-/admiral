#include "admiral_defines.h"

// Wait for BIS functions to be compiled
waitUntil {
    BIS_fnc_init;
};

// Compile functions
call compile preProcessFileLineNumbers "admiral\settings_functions.sqf";
call compile preProcessFileLineNumbers "admiral\common_functions.sqf";

// Don't compile, if we don't want to debug
if (adm_isDebuggingEnabled) then {
    call compile preProcessFileLineNumbers "admiral\error_functions.sqf";
    call compile preProcessFileLineNumbers "admiral\debug_functions.sqf";
};

call compile preProcessFileLineNumbers "admiral\reduce_functions.sqf";
call compile preProcessFileLineNumbers "admiral\cqc_functions.sqf";
call compile preProcessFileLineNumbers "admiral\camp_functions.sqf";
call compile preProcessFileLineNumbers "admiral\patrol_functions.sqf";
call compile preProcessFileLineNumbers "admiral\rupture_functions.sqf";
call compile preProcessFileLineNumbers "admiral\api_functions.sqf";

if (adm_isBehaviorEnabled) then {
    call compile preProcessFileLineNumbers "admiral\behavior_functions.sqf";
};

//Calling init functions
[] call adm_settings_fnc_init;
[] call adm_cqc_fnc_init;
[] call adm_camp_fnc_init;
[] call adm_patrol_fnc_init;
[] call adm_rupture_fnc_checkUnits;
[] call adm_reduce_fnc_init;

if (adm_isBehaviorEnabled) then {
    [] call adm_behavior_fnc_init;
};

// Don't initialize, if we don't want to debug
if (adm_isDebuggingEnabled) then {
    [] call adm_error_fnc_init;
    [] call adm_debug_fnc_init;
};

adm_isInitialized = true;