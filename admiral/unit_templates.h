#include "admiral_macros.h"

class Admiral {
  class UnitTemplates {

    class Base {
        side = SIDE_CIV;
        infantry[] = {"Cow02", "Cow03", "Cow04", "Fin", "Goat", "Cock", "Pastor", "Rabbit", "Sheep", "WildBoar"};
        crewmen[] = {"Cow02", "Cow03", "Cow04", "Fin", "Goat", "Cock", "Pastor", "Rabbit", "Sheep", "WildBoar"};
        technicals[] = {"Ikarus"};
        armour[] = {"Ikarus"};
    };

    class CIV_Takistan : Base {
        infantry[] = {"TK_CIV_Takistani01_EP1", "TK_CIV_Takistani02_EP1", "TK_CIV_Takistani03_EP1", "TK_CIV_Takistani04_EP1", "TK_CIV_Takistani05_EP1", "TK_CIV_Takistani06_EP1", "TK_CIV_Woman01_EP1", "TK_CIV_Woman02_EP1", "TK_CIV_Woman03_EP1", "TK_CIV_Worker01_EP1", "TK_CIV_Worker02_EP1"};
        crewmen[] = {"TK_CIV_Takistani01_EP1", "TK_CIV_Takistani02_EP1", "TK_CIV_Takistani03_EP1", "TK_CIV_Takistani04_EP1", "TK_CIV_Takistani05_EP1", "TK_CIV_Takistani06_EP1", "TK_CIV_Woman01_EP1", "TK_CIV_Woman02_EP1", "TK_CIV_Woman03_EP1", "TK_CIV_Worker01_EP1", "TK_CIV_Worker02_EP1"};
        technicals[] = {"S1203_TK_CIV_EP1", "VolhaLimo_TK_CIV_EP1", "Ikarus_TK_CIV_EP1", "Old_moto_TK_Civ_EP1", "Lada1_TK_CIV_EP1", "Lada2_TK_CIV_EP1", "LandRover_TK_CIV_EP1", "Old_bike_TK_CIV_EP1", "hilux1_civil_3_open_EP1", "V3S_Open_TK_CIV_EP1", "SUV_TK_CIV_EP1", "UAZ_Unarmed_TK_CIV_EP1", "Ural_TK_CIV_EP1", "Volha_1_TK_CIV_EP1", "Volha_2_TK_CIV_EP1", "TT650_TK_CIV_EP1"}; // Did not spawn when tested
        armour[] = {""};
    };

    class CIV_European : Base {
        infantry[] = {"CIV_EuroMan01_EP1", "CIV_EuroMan02_EP1", "CIV_EuroWoman01_EP1", "CIV_EuroWoman02_EP1", "Citizen2_EP1", "Citizen3_EP1", "Dr_Annie_Baker_EP1", "Dr_Hladik_EP1", "Functionay1_EP1", "Functionay2_EP1", "Haris_Press_EP1", "Pilot_EP1", "Profiteer1_EP1", "Rita_Ensler_EP1"};
        crewmen[] = {""};
        technicals[] = {""};
        armour[] = {""};
    };

    class CIV_Russia : Base {
        infantry[] = {"Assistant", "RU_Assistant", "Citizen1", "Citizen2", "Citizen3", "Citizen4", "RU_Citizen1", "RU_Citizen2", "RU_Citizen3", "RU_Citizen4", "Priest", "RU_Priest", "Pilot", "RU_Pilot", "Policeman", "RU_Policeman", "Doctor", "RU_Doctor", "Teacher", "RU_Teacher", "Functionary1", "Functionary2", "RU_Functionary1", "RU_Functionary2", "Rocker1", "Rocker2" , "Rocker3", "Rocker4", "RU_Rocker1", "RU_Rocker2", "RU_Rocker3", "RU_Rocker4", "Profiteer1", "Profiteer2", "Profiteer3", "Profiteer4", "RU_Profiteer1", "RU_Profiteer2", "RU_Profiteer3", "RU_Profiteer4", "Villager1", "Villager2", "Villager3", "Villager4", "RU_Villager1", "RU_Villager2", "RU_Villager3", "RU_Villager4", "RU_Woodlander1", "RU_Woodlander2", "RU_Woodlander3", "RU_Woodlander4", "Worker1", "Worker2", "Worker3", "Worker4", "Secretary1", "Secretary2", "Secretary3", "Secretary4", "RU_Secretary1", "RU_Secretary2", "RU_Secretary3", "RU_Secretary4", "Damsel1", "Damsel2", "Damsel3", "Damsel4", "RU_Damsel1", "RU_Damsel2", "RU_Damsel3", "RU_Damsel4", "Hooker1", "Hooker2", "Hooker3", "Hooker4", "RU_Hooker1", "RU_Hooker2", "RU_Hooker3", "RU_Hooker4", "Madam1", "Madam2", "Madam3", "Madam4", "Ru_Madam1", "Ru_Madam2", "Ru_Madam3", "Ru_Madam4", "WorkWoman1", "WorkWoman2", "WorkWoman3", "WorkWoman4", "RU_WorkWoman1", "RU_WorkWoman2", "RU_WorkWoman3", "RU_WorkWoman4", "HouseWife1", "HouseWife2", "HouseWife3", "HouseWife4", "RU_HouseWife1", "RU_HouseWife2", "RU_HouseWife3", "RU_HouseWife4", "Farmwife1", "Farmwife2", "Farmwife3", "Farmwife4","RU_Farmwife1","RU_Farmwife2","RU_Farmwife3","RU_Farmwife4","Sportswoman1","Sportswoman2","Sportswoman3","Sportswoman4","RU_Sportswoman1","RU_Sportswoman2","RU_Sportswoman3","RU_Sportswoman4"};
        crewmen[] = {""};
        technicals[] = {""};
        armour[] = {""};
    };

    class US_Army_Multicam : Base {
        side=SIDE_WEST;
        infantry[] = {"US_Soldier_EP1", "US_Soldier_AR_EP1", "US_Soldier_AT_EP1", "US_Soldier_AAR_EP1", "US_Soldier_AAT_EP1", "US_Soldier_B_EP1", "US_Soldier_GL_EP1", "US_Soldier_LAT_EP1", "US_Soldier_Light_EP1", "US_Soldier_Medic_EP1", "US_Soldier_Officer_EP1", "US_Soldier_TL_EP1"};
        crewmen[] = {"US_Soldier_Crew_EP1"};
        technicals[] = {"HMMWV_DES_EP1", "MTVR_DES_EP1", "HMMWV_M1151_M2_DES_EP1", "HMMWV_MK19_DES_EP1", "HMMWV_M998_crows_M2_DES_EP1", "HMMWV_M998_crows_MK19_DES_EP1", "HMMWV_Terminal_EP1", "HMMWV_M1035_DES_EP1", "HMMWV_Avenger_DES_EP1"};
        armour[] = {"M1A1_US_DES_EP1", "M1A2_US_TUSK_MG_EP1", "M2A2_EP1", "M2A3_EP1", "M1126_ICV_M2_EP1", "M1126_ICV_mk19_EP1", "M1130_CV_EP1", "M1129_MC_EP1", "M1128_MGS_EP1", "M6_EP1"};
    };

    class USMC_Woodland : US_Army_Multicam {
        infantry[] = {"USMC_Soldier", "USMC_Soldier2", "USMC_SoldierS", "USMC_Soldier_AR", "USMC_Soldier_AT", "USMC_Soldier_GL", "USMC_Soldier_MG", "USMC_Soldier_Medic", "USMC_Soldier_Officer", "USMC_Soldier_TL"};
        crewmen[] = {"USMC_Soldier_Crew"};
        technicals[] = {"ACE_HMMWV_GMV", "ACE_HMMWV_GMV_MK19", "HMMWV", "HMMWV_M2", "HMMWV_MK19", "HMMWV_TOW", "HMMWV_Armored", "HMMWV_Avenger", "ACE_Truck5tMG", "ACE_Truck5tMGOpen"};
        armour[] = {"M1Abrams", "M1A2_TUSK_MG", "AAV", "MLRS", "LAV25", "LAV25_HQ"};
    };

    class US_SOF : USMC_Woodland {
        infantry[] = {"US_Delta_Force_AR_EP1", "US_Delta_Force_MG_EP1", "US_Delta_Force_Assault_EP1", "US_Delta_Force_EP1", "US_Delta_Force_M14_EP1", "US_Delta_Force_Medic_EP1", "US_Delta_Force_TL_EP1"};
    };

    class US_SOF_SD : US_SOF {
        infantry[] = {"US_Delta_Force_SD_EP1"};
    };

    class USMC_FR : USMC_Woodland {
    	infantry[] = {"FR_AR", "FR_Assault_GL", "FR_Assault_R", "FR_Commander", "FR_Corpsman", "FR_GL", "FR_Sapper", "FR_TL"};
    };

    class USMC_Desert : US_Army_Multicam {
        infantry[] = {"ACE_USMC_Soldier_AR_D", "ACE_USMC_Soldier_Medic_D", "ACE_USMC_Soldier_TL_D", "ACE_USMC_Soldier_GL_D", "ACE_USMC_Soldier_MG_D", "ACE_USMC_Soldier_Officer_D", "ACE_USMC_Soldier_D", "ACE_USMC_Soldier_SL_D"};
        crewmen[] = {"ACE_USMC_Soldier_Crew_D"};
    };

    class GER_KSK : Base {
        side=SIDE_WEST;
        infantry[] = {"GER_Soldier_EP1", "GER_Soldier_MG_EP1", "GER_Soldier_Medic_EP1", "GER_Soldier_TL_EP1"};
        crewmen[] = {"GER_Soldier_EP1"};
        technicals[] = {"HMMWV_M2", "HMMWV_MK19"};
        armour[] = {""};
    };

    class CZ_Army : Base {
        side=SIDE_WEST;
        infantry[] = {"CZ_Soldier_AT_DES_EP1", "CZ_Soldier_DES_EP1", "CZ_Soldier_AMG_DES_EP1", "CZ_Soldier_B_DES_EP1", "CZ_Soldier_MG_DES_EP1", "CZ_Soldier_SL_DES_EP1", "CZ_Soldier_Office_DES_EP1", "CZ_Soldier_Light_DES_EP1", "CZ_Soldier_medik_DES_EP1"};
        crewmen[] = {"CZ_Soldier_Pilot_DES_EP1"};
        technicals[] = {"HMMWV_Ambulance_CZ_DES_EP1", "LandRover_CZ_EP1", "HMMWV_M1151_M2_CZ_DES_EP1", "LandRover_Special_CZ_EP1"};
        armour[] = {""};
	};

    class CZ_SOF : CZ_Army {
        infantry[] = {"CZ_Special_Forces_DES_EP1", "CZ_Special_Forces_GL_DES_EP1", "CZ_Special_Forces_MG_DES_EP1", "CZ_Special_Forces_Scout_DES_EP1", "CZ_Special_Forces_TL_DES_EP1"};
    };

    class BAF_Woodland : Base {
        side=SIDE_WEST;
        infantry[] = {"BAF_Soldier_L_W", "BAF_Soldier_Officer_W", "BAF_Soldier_Medic_W", "BAF_Soldier_AR_W", "BAF_Soldier_AT_W", "BAF_Soldier_AAT_W", "BAF_Soldier_AAR_W", "BAF_Soldier_GL_W"};
        crewmen[] = {"BAF_creWman_W"};
        technicals[] = {"BAF_Jackal2_L2A1_W", "BAF_Jackal2_GMG_W", "BAF_Offroad_W"};
        armour[] = {"BAF_FV510_W"};
    };

    class BAF_Desert : BAF_Woodland {
        infantry[] = {"BAF_Soldier_L_DDPM", "BAF_Soldier_Officer_DDPM", "BAF_Soldier_Medic_DDPM", "BAF_Soldier_AR_DDPM", "BAF_Soldier_AT_DDPM", "BAF_Soldier_AAT_DDPM", "BAF_Soldier_AAR_DDPM", "BAF_Soldier_GL_DDPM"};
        crewmen[] = {"BAF_crewman_DDPM"};
        technicals[] = {"BAF_Jackal2_GMG_D", "BAF_Jackal2_L2A1_D", "BAF_Offroad_D"};
        armour[] = {"BAF_FV510_D"};
    };

    class CDF_Woodland : Base {
        side=SIDE_WEST;
        infantry[] = {"CDF_Soldier_TL", "CDF_Soldier", "CDF_Soldier_GL", "CDF_Soldier_MG", "CDF_Soldier", "CDF_Soldier_AR", "CDF_Soldier_RPG", "CDF_Soldier", "CDF_Soldier_Engineer", "CDF_Soldier"};
        crewmen[] = {"CDF_Soldier_Crew"};
        technicals[] = {"UAZ_MG_CDF", "UAZ_AGS30_CDF"};
        armour[] = {"BRDM2_CDF", "BMP2_CDF", "T72_CDF", "ZSU_CDF"};
    };

    class TK_Army_Woodland : Base {
        side=SIDE_EAST;
        infantry[] = {"TK_Soldier_SL_EP1", "TK_Soldier_EP1", "TK_Soldier_GL_EP1", "TK_Soldier_MG_EP1", "TK_Soldier_AT_EP1", "TK_Soldier_Medic_EP1", "TK_Soldier_EP1", "TK_Soldier_AR_EP1", "TK_Soldier_LAT_EP1", "TK_Soldier_EP1", "TK_Soldier_B_EP1", "TK_Soldier_EP1"};
        crewmen[] = {"TK_Soldier_Crew_EP1"};
        technicals[] = {"UAZ_MG_TK_EP1", "UAZ_AGS30_TK_EP1", "LandRover_MG_TK_EP1", "LandRover_SPG9_TK_EP1"};
        armour[] = {"BMP2_TK_EP1", "BRDM2_TK_EP1", "BTR60_TK_EP1", "M113_TK_EP1", "T34_TK_EP1", "T55_TK_EP1", "T72_TK_EP1", "ZSU_TK_EP1", "T72_TK_EP1"};
    };

    class RU_Woodland : Base {
        side=SIDE_EAST;
        infantry[] = {"RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier", "RU_Soldier_GL", "RU_Soldier_GL", "RU_Soldier_MG", "RU_Soldier_AR", "RU_Soldier_AR", "RU_Soldier_AR", "RU_Soldier_LAT"};
        crewmen[] = {"RU_Soldier_Crew"};
        technicals[] = {"ACE_UAZ_MG_RU"};
        armour[] = {"BMP2_RU", "BMP2_RU", "T72_RU", "T72_RU", "BMP2_RU", "ACE_T72B_Base", "ACE_BRDM2_RU", "ACE_BTR70_RU", "ACE_BRDM2_RU", "ACE_BTR70_RU", "ACE_BRDM2_RU"};
    };

    class RU_MVD : RU_Woodland {
        infantry[] = {"MVD_Soldier", "MVD_Soldier_AT", "MVD_Soldier_GL", "MVD_Soldier_GL", "MVD_Soldier_TL"};
    };

    class RU_Spetsnaz : RU_Woodland {
        infantry[] = {"RUS_Commander", "RUS_Soldier1", "RUS_Soldier_GL", "RUS_Soldier_TL"};
    };

    class RU_Spetsnaz_SD : RU_Spetsnaz {
        infantry[] = {"RUS_Soldier2", "RUS_Soldier3", "RUS_Soldier_Sab"};
    };

    class RU_Desert : RU_Woodland {
        infantry[] = {"ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_GL_D", "ACE_RU_Soldier_GL_D", "ACE_RU_Soldier_MG_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_LAT_D"};
        crewmen[] = {"ACE_RU_Soldier_Crew_D"};
    };

    class INS_Woodland : RU_Woodland {
        infantry[] = {"Ins_Soldier_CO", "Ins_Soldier_1", "Ins_Soldier_GL", "Ins_Soldier_MG", "Ins_Soldier_1", "Ins_Soldier_AT", "Ins_Soldier_Medic", "Ins_Soldier_2", "Ins_Soldier_AR", "Ins_Soldier_1", "Ins_Soldier_1", "Ins_Soldier_2", "Ins_Soldier_AT"};
        crewmen[] = {"Ins_Soldier_Crew"};
        technicals[] = {"UAZ_SPG9_INS","Offroad_DSHKM_INS","Pickup_PK_INS"};
        armour[] = {"BRDM2_INS", "BRDM2_ATGM_INS", "BMP2_INS", "T72_INS", "ZSU_INS"};
    };

    class TK_Milita : Base {
        side=SIDE_EAST;
        infantry[] = {"TK_INS_Soldier_EP1", "TK_INS_Soldier_EP1", "TK_INS_Soldier_TL_EP1", "TK_INS_Soldier_EP1", "TK_INS_Soldier_2_EP1", "TK_INS_Soldier_MG_EP1", "TK_INS_Soldier_4_EP1", "TK_INS_Soldier_3_EP1", "TK_INS_Bonesetter_EP1", "TK_INS_Soldier_EP1", "TK_INS_Soldier_AR_EP1", "TK_INS_Soldier_AT_EP1", "TK_INS_Soldier_AAT_EP1", "TK_INS_Soldier_4_EP1", "TK_INS_Soldier_3_EP1"};
        crewmen[] = {"TK_INS_Soldier_EP1"};
        technicals[] = {"LandRover_MG_TK_INS_EP1", "LandRover_SPG9_TK_INS_EP1"};
        armour[] = {"BTR40_TK_INS_EP1", "BTR40_MG_TK_INS_EP1"};
    };

    class NAPA_Woodland : Base {
        side=SIDE_IND;
        infantry[] = {"GUE_Soldier_CO", "GUE_Soldier_2", "GUE_Soldier_3", "GUE_Soldier_1", "GUE_Soldier_MG", "GUE_Soldier_GL", "GUE_Soldier_AT", "GUE_Soldier_2", "GUE_Soldier_AT", "GUE_Soldier_1", "GUE_Soldier_1", "GUE_Soldier_Medic", "GUE_Soldier_3"};
        crewmen[] = {"GUE_Soldier_Crew"};
        technicals[] = {"Offroad_DSHKM_Gue", "Pickup_PK_GUE", "Offroad_SPG9_Gue", "Ural_ZU23_Gue"};
        armour[] = {"BRDM2_Gue", "BMP2_Gue", "T34", "T72_Gue"};
    };

    class TK_Locals : Base {
        side=SIDE_IND;
        infantry[] = {"TK_GUE_Soldier_2_EP1", "TK_GUE_Soldier_2_EP1", "TK_GUE_Soldier_TL_EP1", "TK_GUE_Soldier_EP1", "TK_GUE_Soldier_2_EP1", "TK_GUE_Soldier_MG_EP1", "TK_GUE_Soldier_4_EP1", "TK_GUE_Soldier_3_EP1", "TK_GUE_Soldier_AT_EP1", "TK_GUE_Soldier_AAT_EP1", "TK_GUE_Soldier_AR_EP1", "TK_GUE_Bonesetter_EP1", "TK_GUE_Soldier_EP1", "TK_GUE_Soldier_2_EP1", "TK_GUE_Soldier_5_EP1", "TK_GUE_Soldier_3_EP1"};
        crewmen[] = {"TK_GUE_Soldier_2_EP1"};
        technicals[] = {"Offroad_DSHKM_TK_GUE_EP1", "Offroad_SPG9_TK_GUE_EP1", "Pickup_PK_TK_GUE_EP1"};
        armour[] = {"BRDM2_TK_GUE_EP1", "BTR40_TK_GUE_EP1", "BTR40_MG_TK_GUE_EP1", "T34_TK_GUE_EP1", "T55_TK_GUE_EP1"};		
    };
	
    class United_Nations : Base {
        side=SIDE_IND;
        infantry[]={"UN_CDF_Soldier_AT_EP1", "UN_CDF_Soldier_EP1", "UN_CDF_Soldier_Light_EP1", "UN_CDF_Soldier_Officer_EP1", "UN_CDF_Soldier_SL_EP1", "UN_CDF_Soldier_MG_EP1", "UN_CDF_Soldier_AAT_EP1", "UN_CDF_Soldier_AMG_EP1", "UN_CDF_Soldier_B_EP1"};
        crewmen[]={"UN_CDF_Soldier_Crew_EP1"};
        technicals[]={"BMP2_UN_EP1", "M113Ambul_UN_EP1"};
        armour[]={"T72_CDF"};
    };
    
    class PMC : Base {
        side=SIDE_IND;
        infantry[]={"Soldier_TL_PMC", "Soldier_Medic_PMC", "Soldier_MG_PMC", "Soldier_AT_PMC", "Soldier_MG_PKM_PMC", "Soldier_GL_PMC", "Soldier_M4A3_PMC2", "Soldier_PMC"};
        crewmen[]={"Soldier_Crew_PMC"};
        technicals[]={"SUV_PMC","ArmoredSUV_PMC"};
        armour[]={"BMP2_Gue"};
    };

};
};