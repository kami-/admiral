#include "admiral_macros.h"

#include "\userconfig\admiral\log\preinit.h"
#include "logbook.h"


adm_isInitialized = false;

[] call compile preProcessFileLineNumbers ADDON_PATH(config_functions.sqf);
adm_isEnabled = ["isEnabled"] call adm_config_fnc_getBool;

if (adm_isEnabled) then {
    [] call compile preProcessFileLineNumbers ADDON_PATH(event_functions.sqf);
    [] call hull3_event_fnc_init;

    adm_fnc_compile = {
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
        [] call compile preProcessFileLineNumbers ADDON_PATH(behavior_functions.sqf); DEBUG("admiral.compile","Compiled 'behavior_functions.sqf'.");
    };

    [] call compile preProcessFileLineNumbers ADDON_PATH(hc_functions.sqf); DEBUG("admiral.compile","Compiled 'hc_functions.sqf'.");
} else {
    INFO("admiral",FMT_1("Admiral version '%1' was disabled.",STR_ADMIRAL_VERSION));
};