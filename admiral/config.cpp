#include "admiral_macros.h"

class CfgPatches {
    class Admiral {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"CBA_MAIN"};
        author[] = {"Kami", "Cam", "Ark"};
        authorUrl = "https://github.com/kami-";
    };
};

class Extended_PreInit_EventHandlers {
    class Admiral {
        init = "[] call compile preProcessFileLineNumbers 'x\ark\addons\admiral\admiral_preinit.sqf';";
    };
};

class Extended_PostInit_EventHandlers {
    class Admiral {
        init = "[] call compile preProcessFileLineNumbers 'x\ark\addons\admiral\admiral_postinit.sqf';";
    };
};

#include "admiral.h"