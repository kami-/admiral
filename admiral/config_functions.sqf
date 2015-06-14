#include "admiral_macros.h"

#include "\userconfig\admiral\log\config.h"
#include "logbook.h"


adm_config_fnc_getConfig = {
    DECLARE(_config) = ADMIRAL_MISSION_CONFIG_FILE;
    {
        _config = _config >> _x;
    } foreach _this;
    if (configName _config == "") then {
        _config = ADMIRAL_CONFIG_FILE;
        {
            _config = _config >> _x;
        } foreach _this;
    };

    _config;
};

adm_config_fnc_getArray = {
    getArray (_this call adm_config_fnc_getConfig);
};

adm_config_fnc_getText = {
    getText (_this call adm_config_fnc_getConfig);
};

adm_config_fnc_getNumber = {
    getNumber (_this call adm_config_fnc_getConfig);
};

adm_config_fnc_getBool = {
    getNumber (_this call adm_config_fnc_getConfig) == 1;
};