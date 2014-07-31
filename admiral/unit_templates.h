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
	
    class US_Army_MUTLICAM : Base {
        side=SIDE_WEST;
        infantry[] = {"US_Soldier_EP1"};
        crewmen[] = {"US_Soldier_Crew_EP1"};
        technicals[] = {"HMMWV_DES_EP1", "MTVR_DES_EP1", "HMMWV_M1151_M2_DES_EP1", "HMMWV_MK19_DES_EP1", "HMMWV_M998_crows_M2_DES_EP1", "HMMWV_M998_crows_MK19_DES_EP1", "HMMWV_Terminal_EP1", "HMMWV_M1035_DES_EP1", "HMMWV_Avenger_DES_EP1"};
        armour[] = {"M1A1_US_DES_EP1", "M1A2_US_TUSK_MG_EP1", "M2A2_EP1", "M2A3_EP1", "M1126_ICV_M2_EP1", "M1126_ICV_mk19_EP1", "M1130_CV_EP1", "M1129_MC_EP1", "M1128_MGS_EP1", "M6_EP1"};
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
	
    class RU_Desert : RU_Woodland {
        infantry[] = {"ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_D", "ACE_RU_Soldier_GL_D", "ACE_RU_Soldier_GL_D", "ACE_RU_Soldier_MG_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_AR_D", "ACE_RU_Soldier_LAT_D"};
        crewmen[] = {"ACE_RU_Soldier_Crew_D"};
    };
	
    class RU_Winter : RU_Woodland {
        infantry[] = {"RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier", "RW_RU_Soldier_GL", "RW_RU_Soldier_GL", "RW_RU_Soldier_MG", "RW_RU_Soldier_AR", "RW_RU_Soldier_AR", "RW_RU_Soldier_AR", "RW_RU_Soldier_LAT"};
        crewmen[] = {"RW_RU_Soldier_Crew"};
        armour[] = {"RW_T72_RU"};
    };
	
	class INS_Woodland : RU_Woodland {
		infantry[] = {"Ins_Soldier_CO", "Ins_Soldier_1", "Ins_Soldier_GL", "Ins_Soldier_MG", "Ins_Soldier_1", "Ins_Soldier_AT", "Ins_Soldier_Medic", "Ins_Soldier_2", "Ins_Soldier_AR", "Ins_Soldier_1", "Ins_Soldier_1", "Ins_Soldier_2", "Ins_Soldier_AT"};
        crewmen[] = {"Ins_Soldier_Crew"};
        technicals[] = {"UAZ_SPG9_INS","Offroad_DSHKM_INS","Pickup_PK_INS"};
        armour[] = {"BRDM2_INS", "BRDM2_ATGM_INS", "BMP2_INS", "T72_INS", "ZSU_INS"};
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
	
	class TK_Milita : Base {
		side=SIDE_EAST;
		infantry[] = {"TK_INS_Soldier_EP1", "TK_INS_Soldier_EP1", "TK_INS_Soldier_TL_EP1", "TK_INS_Soldier_EP1", "TK_INS_Soldier_2_EP1", "TK_INS_Soldier_MG_EP1", "TK_INS_Soldier_4_EP1", "TK_INS_Soldier_3_EP1", "TK_INS_Bonesetter_EP1", "TK_INS_Soldier_EP1", "TK_INS_Soldier_AR_EP1", "TK_INS_Soldier_AT_EP1", "TK_INS_Soldier_AAT_EP1", "TK_INS_Soldier_4_EP1", "TK_INS_Soldier_3_EP1"};
		crewmen[] = {"TK_INS_Soldier_EP1"};
		technicals[] = {"LandRover_MG_TK_INS_EP1", "LandRover_SPG9_TK_INS_EP1"};
		armour[] = {"BTR40_TK_INS_EP1", "BTR40_MG_TK_INS_EP1"};
    };
	
	class CDF_Woodland : Base {
		side=SIDE_WEST;
		infantry[] = {"CDF_Soldier_TL", "CDF_Soldier", "CDF_Soldier_GL", "CDF_Soldier_MG", "CDF_Soldier", "CDF_Soldier_AR", "CDF_Soldier_RPG", "CDF_Soldier", "CDF_Soldier_Engineer", "CDF_Soldier"};
		crewmen[] = {"CDF_Soldier_Crew"};
		technicals[] = {"UAZ_MG_CDF", "UAZ_AGS30_CDF"};
		armour[] = {"BRDM2_CDF", "BMP2_CDF", "T72_CDF", "ZSU_CDF"};
	};
	
	 class African_Rebels : Base {
		side=SIDE_EAST;
		infantry[] = {"ibr_rebel11","ibr_rebel102","ibr_rebel22","ibr_rebel83","ibr_rebel33","ibr_rebel125","ibr_rebel77","ibr_rebel77","ibr_rebel77","ibr_rebel11","ibr_rebel44","ibr_rebel55"};
        crewmen[] = {"ibr_rebel11"};
        technicals[] = {"Offroad_DSHKM_Gue", "Pickup_PK_GUE", "Pickup_PK_GUE", "Pickup_PK_GUE"};
	};
		
};

};