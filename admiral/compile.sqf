#include "settings.sqf"

// Necessary for AI spawn
{
    createCenter adm_ai_enemySide;
} foreach SIDE_ARRAY;

// Set side relations
WEST setFriend [EAST, 0];
WEST setFriend [RESISTANCE, 0];
RESISTANCE setFriend [WEST, 0];
RESISTANCE setFriend [EAST, 0];
EAST setFriend [WEST, 0];
EAST setFriend [RESISTANCE, 0];

// Compile functions
call compile preProcessFileLineNumbers "admiral\common_functions.sqf";

// Don't compile, if we don't want to debug
if (adm_ai_debugging) then {
    call compile preProcessFileLineNumbers "admiral\error_functions.sqf";
    call compile preProcessFileLineNumbers "admiral\debug_functions.sqf";
};

call compile preProcessFileLineNumbers "admiral\reduce_functions.sqf";
call compile preProcessFileLineNumbers "admiral\cqc_functions.sqf";
call compile preProcessFileLineNumbers "admiral\camp_functions.sqf";
call compile preProcessFileLineNumbers "admiral\patrol_functions.sqf";
call compile preProcessFileLineNumbers "admiral\rupture_functions.sqf";
call compile preProcessFileLineNumbers "admiral\behavior_functions.sqf";

//Calling init functions

[] call adm_cqc_fnc_init;
[] call adm_camp_fnc_init;
[] call adm_patrol_fnc_init;
[] call adm_rupture_fnc_checkUnits;
[] call adm_reduce_fnc_init;
[] call adm_behavior_fnc_init;

// Don't initialize, if we don't want to debug
if (adm_ai_debugging) then {
    [] call adm_error_fnc_init;
    [] call adm_debug_fnc_init;
};