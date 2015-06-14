#include "admiral_macros.h"

#include "\userconfig\admiral\log\preinit.h"
#include "logbook.h"


adm_isInitialized = false;

[] call compile preProcessFileLineNumbers ADDON_PATH(config_functions.sqf);
adm_isEnabled = ["isEnabled"] call adm_config_fnc_getBool;

if (adm_isEnabled) then {
    [] call compile preProcessFileLineNumbers ADDON_PATH(hc_functions.sqf); DEBUG("admiral.compile","Compiled 'hc_functions.sqf'.");
} else {
    INFO("admiral",FMT_1("Admiral version '%1' was disabled.",STR_ADMIRAL_VERSION));
};