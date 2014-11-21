#include "admiral_macros.h"

// Side Relations
adm_settings_fnc_setSideRelations = {

};

// Debug
adm_isDebuggingEnabled = true;

// General
adm_areNVGsEnabled = true;

// Behavior
adm_isBehaviorEnabled = true;

// Camp
adm_camp_defaultUnitTemplate = "Base";
adm_camp_defaultZoneTemplate = "Camp";

// Patrol
adm_patrol_defaultUnitTemplate = "Base";
adm_patrol_defaultZoneTemplate = "Patrol";

// CQC
adm_cqc_defaultUnitTemplate = "Base";
adm_cqc_defaultZoneTemplate = "Cqc";

adm_cqc_forceFireEnabled = true;
adm_cqc_forceFireDelay = 5;

adm_cqc_buildingBlacklist = [
    "Land_dum_mesto2l", "Land_dum_mesto3"
];

adm_cqc_buildingCapacity = [
    ["Land_House_C_2_EP1", 4], ["Land_House_K_6_EP1", 4], ["Land_House_K_7_EP1", 4]
    , ["Land_A_GeneralStore_01", 4]
];


// Rupture
adm_rupture_updateTick = 30;
adm_rupture_length = 120;
