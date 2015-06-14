#include "admiral_macros.h"

#include "\userconfig\admiral\log\postinit.h"
#include "logbook.h"


[] call compile preProcessFileLineNumbers ADDON_PATH(config_functions.sqf); DEBUG("admiral.compile","Compiled 'config_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(id_functions.sqf); DEBUG("admiral.compile","Compiled 'id_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(settings_functions.sqf); DEBUG("admiral.compile","Compiled 'settings_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(common_functions.sqf); DEBUG("admiral.compile","Compiled 'common_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(debug_functions.sqf); DEBUG("admiral.compile","Compiled 'debug_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(zone_functions.sqf); DEBUG("admiral.compile","Compiled 'zone_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(cqc_functions.sqf); DEBUG("admiral.compile","Compiled 'cqc_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(camp_functions.sqf); DEBUG("admiral.compile","Compiled 'camp_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(patrol_functions.sqf); DEBUG("admiral.compile","Compiled 'patrol_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(rupture_functions.sqf); DEBUG("admiral.compile","Compiled 'rupture_functions.sqf'.");
[] call compile preProcessFileLineNumbers ADDON_PATH(api_functions.sqf); DEBUG("admiral.compile","Compiled 'api_functions.sqf'.");

if (isMultiplayer) then {
    adm_isDebuggingEnabled = false;
};

if (adm_isBehaviorEnabled) then {
    INFO("admiral.behavior","Admiral Behavior system is enabled.");
    [] call compile preProcessFileLineNumbers ADDON_PATH(behavior_functions.sqf); DEBUG("admiral.compile","Compiled 'behavior_functions.sqf'.");
};

[] call adm_id_fnc_init; DEBUG("admiral.id","Init function 'adm_id_fnc_init' called.");
[] call adm_settings_fnc_init; DEBUG("admiral.settings","Init function 'adm_settings_fnc_init' called.");
[] call adm_zone_fnc_init; DEBUG("admiral.settings","Init function 'adm_zone_fnc_init' called.");
[] call adm_cqc_fnc_init; DEBUG("admiral.cqc","Init function 'adm_cqc_fnc_init' called.");
[] call adm_camp_fnc_init; DEBUG("admiral.camp","Init function 'adm_camp_fnc_init' called.");
[] call adm_patrol_fnc_init; DEBUG("admiral.patrol","Init function 'adm_patrol_fnc_init' called.");
[] call adm_rupture_fnc_checkUnits; DEBUG("admiral.rupture","Init function 'adm_rupture_fnc_checkUnits' called.");

if (adm_isBehaviorEnabled) then {
    [] call adm_behavior_fnc_init; DEBUG("admiral.behavior","Init function 'adm_behavior_fnc_init' called.");
};

if (adm_isDebuggingEnabled) then {
    [] call adm_debug_fnc_init; DEBUG("admiral.debug","Init function 'adm_debug_fnc_init' called.");
};

adm_isInitialized = true;
INFO("admiral",FMT_1("Admiral version '%1' has been successfully initialized.",STR_ADMIRAL_VERSION));