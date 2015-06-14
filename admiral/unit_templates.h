#include "admiral_macros.h"

class UnitTemplates {
// A2
    class Base {
        side = SIDE_CIV;
        infantry[] = {"Cow02", "Cow03", "Cow04", "Fin", "Goat", "Cock", "Pastor", "Rabbit", "Sheep", "WildBoar"};
        crewmen[] = {"Cow02", "Cow03", "Cow04", "Fin", "Goat", "Cock", "Pastor", "Rabbit", "Sheep", "WildBoar"};
        technicals[] = {"Ikarus"};
        armour[] = {"Ikarus"};
    };

    class US_Army_Woodland_TEST : Base {
        side=SIDE_WEST;
        infantry[] = {"US_Soldier_EP1"};
        crewmen[] = {"US_Soldier_Pilot_EP1"};
        technicals[] = {"HMMWV_M1151_M2_DES_EP1"};
        armour[] = {"M1A2_US_TUSK_MG_EP1"};
    };

    class TK_Army_Woodland_TEST : Base {
        side=SIDE_EAST;
        infantry[] = {"TK_Soldier_EP1"};
        crewmen[] = {"TK_Soldier_Crew_EP1"};
        technicals[] = {"UAZ_MG_TK_EP1"};
        armour[] = {"T72_TK_EP1"};
    };

    class RU_Woodland : Base {
        side=SIDE_EAST;
        infantry[] = {"RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier_GL", "RU_Soldier_GL", "RU_Soldier_MG", "RU_Soldier_AR", "RU_Soldier_AR", "RU_Soldier_AR", "RU_Soldier_LAT"};
        crewmen[] = {"RU_Soldier_Crew"};
        technicals[] = {"ACE_UAZ_MG_RU"};
        armour[] = {"ACE_T72B_Base"};
    };

    class RU_Desert : RU_Woodland {
        infantry[] = {"ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_GL_D", "ACE_RU_Soldier_GL_D", "ACE_RU_Soldier_MG_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_LAT_D"};
        crewmen[] = {"ACE_RU_Soldier_Crew_D"};
    };

    class RU_Winter : RU_Woodland {
        infantry[] = {"RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier_GL", "RW_RU_Soldier_GL", "RW_RU_Soldier_MG", "RW_RU_Soldier_AR", "RW_RU_Soldier_AR", "RW_RU_Soldier_AR", "RW_RU_Soldier_LAT"};
        crewmen[] = {"RW_RU_Soldier_Crew"};
        armour[] = {"RW_T72_RU"};
    };

// A3
/*
    class Base {
        side=SIDE_CIV;
        infantry[]={"Hen_random_F", "Cock_random_F", "Goat_random_F", "Sheep_random_F", "Salema_F", "Mackerel_F", "Fin_random_F", "Alsatian_Random_F", "C_Orestes", "C_Nikos"};
        crewmen[]={"Hen_random_F", "Cock_random_F", "Goat_random_F", "Sheep_random_F", "Salema_F", "Mackerel_F", "Fin_random_F", "Alsatian_Random_F", "C_Orestes", "C_Nikos"};
        technicals[]={"C_Van_01_box_F"};
        armour[]={"C_Van_01_box_F"};
    };
*/
    class NATO_WOODLAND {
        side=SIDE_WEST;
        infantry[]={"B_Soldier_F", "B_Soldier_02_f", "B_Soldier_03_f", "B_Soldier_F", "B_Soldier_TL_F", "B_Soldier_02_f", "B_Soldier_SL_F", "B_soldier_AR_F", "B_soldier_LAT_F"};
        crewmen[]={"B_crew_F", "B_engineer_F"};
        technicals[]={"B_MRAP_01_hmg_F"};
        armour[]={"B_APC_Wheeled_01_cannon_F", "B_MBT_01_TUSK_F"};
    };

    class FIA_GUER {
        side=SIDE_WEST;
        infantry[]={"B_G_Soldier_F", "B_G_Soldier_lite_F", "B_G_Soldier_SL_F", "B_G_Soldier_TL_F", "B_G_Soldier_F", "B_G_Soldier_lite_F", "B_G_Soldier_LAT_F", "B_G_Soldier_AR_F"};
        crewmen[]={"B_G_Soldier_lite_F", "B_G_engineer_F"};
        technicals[]={"B_G_Offroad_01_armed_F"};
        armour[]={"B_G_Offroad_01_armed_F"};
    };

    class CSAT_WOODLAND {
        side=SIDE_EAST;
        infantry[]={"O_Soldier_F", "O_Soldier_02_f", "O_Soldier_lite_F", "O_Soldier_F", "O_Soldier_TL_F", "O_Soldier_02_f", "O_Soldier_SL_F", "O_soldier_AR_F", "O_soldier_LAT_F"};
        crewmen[]={"O_crew_F", "O_engineer_F"};
        technicals[]={"O_MRAP_02_hmg_F"};
        armour[]={"O_APC_Tracked_02_cannon_F", "O_MBT_02_cannon_F"};
    };

    class AAF_WOODLAND {
        side=SIDE_IND;
        infantry[]={"I_Soldier_F", "I_Soldier_02_f", "I_Soldier_lite_F", "I_Soldier_F", "I_Soldier_TL_F", "I_Soldier_02_f", "I_Soldier_SL_F", "I_soldier_AR_F", "I_soldier_LAT_F"};
        crewmen[]={"I_crew_F", "I_engineer_F"};
        technicals[]={"I_MRAP_03_hmg_F"};
        armour[]={"I_APC_tracked_03_cannon_F", "I_MBT_03_cannon_F"};
    };

    class AAF_GUER {
        side=SIDE_IND;
        infantry[]={"I_G_Soldier_F", "I_G_Soldier_lite_F", "I_G_Soldier_F", "I_G_Soldier_TL_F", "I_G_Soldier_lite_F", "I_G_Soldier_SL_F", "I_G_soldier_AR_F", "I_G_soldier_LAT_F"};
        crewmen[]={"I_G_Soldier_lite_F", "I_G_engineer_F"};
        technicals[]={"I_G_Offroad_01_armed_F"};
        armour[]={"I_G_Offroad_01_armed_F"};
    };
};