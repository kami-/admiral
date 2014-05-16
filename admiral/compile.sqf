#include "admiral_defines.h"

#include "log_macros.h"

// Wait for BIS functions to be compiled
waitUntil {
    BIS_fnc_init;
};

// Compile functions
call compile preProcessFileLineNumbers "admiral\settings_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\settings_functions.sqf'.");
call compile preProcessFileLineNumbers "admiral\common_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\common_functions.sqf'.");

// Don't compile, if we don't want to debug
if (adm_isDebuggingEnabled) then {
    INFO("admiral.debug","Admiral debugging is enabled.");
    call compile preProcessFileLineNumbers "admiral\error_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\error_functions.sqf'.");
    call compile preProcessFileLineNumbers "admiral\debug_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\debug_functions.sqf'.");
};

call compile preProcessFileLineNumbers "admiral\reduce_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\reduce_functions.sqf'.");
call compile preProcessFileLineNumbers "admiral\cqc_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\cqc_functions.sqf'.");
call compile preProcessFileLineNumbers "admiral\camp_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\camp_functions.sqf'.");
call compile preProcessFileLineNumbers "admiral\patrol_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\patrol_functions.sqf'.");
call compile preProcessFileLineNumbers "admiral\rupture_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\rupture_functions.sqf'.");
call compile preProcessFileLineNumbers "admiral\api_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\api_functions.sqf'.");

if (adm_isBehaviorEnabled) then {
    INFO("admiral.behavior","Admiral Behavior system is enabled.");
    call compile preProcessFileLineNumbers "admiral\behavior_functions.sqf"; DEBUG("admiral.compile","Compiled 'admiral\behavior_functions.sqf'.");
};

//Calling init functions
[] call adm_settings_fnc_init; DEBUG("admiral.settings","Init function 'adm_settings_fnc_init' called.");
[] call adm_cqc_fnc_init; DEBUG("admiral.cqc","Init function 'adm_cqc_fnc_init' called.");
[] call adm_camp_fnc_init; DEBUG("admiral.camp","Init function 'adm_camp_fnc_init' called.");
[] call adm_patrol_fnc_init; DEBUG("admiral.patrol","Init function 'adm_patrol_fnc_init' called.");
[] call adm_rupture_fnc_checkUnits; DEBUG("admiral.rupture","Init function 'adm_rupture_fnc_checkUnits' called.");
[] call adm_reduce_fnc_init; DEBUG("admiral.reduce","Init function 'adm_reduce_fnc_init' called.");

if (adm_isBehaviorEnabled) then {
    [] call adm_behavior_fnc_init; DEBUG("admiral.behavior","Init function 'adm_behavior_fnc_init' called.");
};

// Don't initialize, if we don't want to debug
if (adm_isDebuggingEnabled) then {
    [] call adm_error_fnc_init; DEBUG("admiral.error","Init function 'adm_error_fnc_init' called.");
    [] call adm_debug_fnc_init; DEBUG("admiral.debug","Init function 'adm_debug_fnc_init' called.");
};

adm_isInitialized = true;
INFO("admiral",FMT_1("Admiral version '%1' has been successfully initialized.",STR_ADMIRAL_VERSION));