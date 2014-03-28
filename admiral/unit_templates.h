#include "admiral_defines.h"

class AdmiralUnitTemplates {
    class Base {
        side=SIDE_WEST;
        infantry[] = {};
        crewmen[] = {};
        pilots[] = {};
        technical[] = {};
        armour[] = {};
    };

    class US_Army_Woodland_TEST : Base {
        side=SIDE_WEST;
        infantry[] = {"US_Soldier_EP1"};
        crewmen[] = {"US_Soldier_Pilot_EP1"};
        pilots[] = {"US_Soldier_Crew_EP1"};
        technical[] = {"HMMWV_M1151_M2_DES_EP1"};
        armour[] = {"M1A2_US_TUSK_MG_EP1"};
    };

    class TK_Army_Woodland_TEST : Base {
        side=SIDE_EAST;
        infantry[] = {"TK_Soldier_EP1"};
        crewmen[] = {"TK_Soldier_Crew_EP1"};
        pilots[] = {"TK_Soldier_Pilot_EP1"};
        technical[] = {"UAZ_MG_TK_EP1"};
        armour[] = {"T72_TK_EP1"};
    };

    class RU_Woodland : Base {
        side=SIDE_EAST;
        infantry[] = {"RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier_GL", "RU_Soldier_GL", "RU_Soldier_MG", "RU_Soldier_AR", "RU_Soldier_AR", "RU_Soldier_AR", "RU_Soldier_LAT"};
        crewmen[] = {"RU_Soldier_Crew"};
        pilots[] = {"RU_Soldier_Pilot"};
        technical[] = {"ACE_UAZ_MG_RU"};
        armour[] = {"ACE_T72B_Base"};
    };

    class RU_Desert : RU_Woodland {
        infantry[] = {"ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_GL_D", "ACE_RU_Soldier_GL_D", "ACE_RU_Soldier_MG_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_LAT_D"};
        crewmen[] = {"ACE_RU_Soldier_Crew_D"};
        pilots[] = {"ACE_RU_Soldier_Pilot_D"};
    };

    class RU_Winter : RU_Woodland {
        infantry[] = {"RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier_GL", "RW_RU_Soldier_GL", "RW_RU_Soldier_MG", "RW_RU_Soldier_AR", "RW_RU_Soldier_AR", "RW_RU_Soldier_AR", "RW_RU_Soldier_LAT"};
        crewmen[] = {"RW_RU_Soldier_Crew"};
        pilots[] = {"RW_RU_Soldier_Pilot"};
        armour[] = {"RW_T72_RU"};
    };
};