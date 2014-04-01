#include "admiral_defines.h"

// Debug
adm_ai_debugging = true;

// General
adm_default_cqc_unitTemplate = "Base";
adm_default_patrol_unitTemplate = "Base";
adm_default_camp_unitTemplate = "Base";

adm_ai_caching = true;

adm_ai_NVGs = true;

// Camp
adm_camp_infFireteamSize = 4;
adm_camp_infWaypointAmount = 4;

adm_camp_techFireteamSize = 2;
adm_camp_techWaypointAmount = 3;

adm_camp_armourFireteamSize = 3;
adm_camp_armourWaypointAmount = 2;

adm_camp_skillBoundary = [0.5, 0.75];
adm_camp_aimingSpeed = 0.65;
adm_camp_aimingAccuracy = 0.18;


// Patrol
adm_patrol_infFireteamSize = 4;
adm_patrol_infWaypointAmount = 4;

adm_patrol_techFireteamSize = 2;
adm_patrol_techWaypointAmount = 3;

adm_patrol_armourFireteamSize = 3;
adm_patrol_armourWaypointAmount = 2;

adm_patrol_skillBoundary = [0.5, 0.75];
adm_patrol_aimingSpeed = 0.65;
adm_patrol_aimingAccuracy = 0.18;


// CQC
adm_cqc_infFireteamSize = 4;

adm_cqc_forceFireEnabled = true;

adm_cqc_skillBoundary = [0.5, 0.75];
adm_cqc_aimingSpeed = 1;
adm_cqc_aimingAccuracy = 0.18;


// Rupture
adm_rupture_updateTick = 30;
adm_rupture_length = 120;

// unitTypes
#include "cqc_buildings.sqf"
