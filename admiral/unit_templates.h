class UnitTemplates {
    class Base {
        side = "civilian";
        camouflage[] = {"woodland", "desert", "snow"};
        infantry[] = {"Hen_random_F", "Cock_random_F", "Goat_random_F", "Sheep_random_F", "Salema_F", "Mackerel_F", "Fin_random_F", "Alsatian_Random_F", "C_Orestes", "C_Nikos"};
        crewmen[] = {"Hen_random_F", "Cock_random_F", "Goat_random_F", "Sheep_random_F", "Salema_F", "Mackerel_F", "Fin_random_F", "Alsatian_Random_F", "C_Orestes", "C_Nikos"};
        pilots[]= {};
        technicals[] = {"C_Van_01_box_F"};
        armour[] = {"C_Van_01_box_F"};
        ah[] = {"C_Van_01_box_F"};
    };

    class NATO_WOODLAND {
        side = "west";
        camouflage[] = {};
        infantry[] = {"B_Soldier_SL_F", "B_soldier_AR_F", "B_Soldier_F", "B_Soldier_AT4_F", "B_HeavyGunner_F", "B_soldier_AR_F", "B_Soldier_AT4_F", "B_soldier_AR_F", "B_Soldier_AT4_F"};
        crewmen[] = {"B_crew_F", "B_engineer_F"};
        pilots[]= {"B_Helipilot_F"};
        technicals[] = {"B_MRAP_01_hmg_F"};
        armour[] = {"B_APC_Wheeled_01_cannon_F", "B_MBT_01_TUSK_F", "B_APC_Tracked_01_rcws_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class NATO_JUNGLE {
        side = "west";
        camouflage[] = {};
        infantry[] = {"B_T_Soldier_SL_F", "B_T_Soldier_AR_F", "B_T_Soldier_F", "B_T_Soldier_AT4_F", "B_T_Soldier_TL_F", "B_T_Soldier_AR_F", "B_T_Soldier_AT4_F", "B_T_Soldier_AR_F", "B_T_Soldier_AT4_F"};
        crewmen[] = {"B_T_Crew_F", "B_T_Engineer_F"};
        pilots[]= {"B_T_Helipilot_F"};
        technicals[] = {"B_T_LSV_01_armed_F"};
        armour[] = {"B_T_APC_Wheeled_01_cannon_F", "B_T_MBT_01_TUSK_F", "B_APC_Tracked_01_rcws_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class CTRG_JUNGLE {
        side = "west";
        camouflage[] = {};
        infantry[] = {"B_CTRG_Soldier_JTAC_tna_F", "B_CTRG_Soldier_AR_tna_F", "B_CTRG_Soldier_tna_F", "B_CTRG_Soldier_tna_F", "B_CTRG_Soldier_tna_F", "B_CTRG_Soldier_AR_tna_F", "B_CTRG_Soldier_AT4_tna_F", "B_CTRG_Soldier_AR_tna_F", "B_CTRG_Soldier_AT4_tna_F"};
        crewmen[] = {"B_CTRG_Soldier_tna_F"};
        pilots[]= {"B_T_Helipilot_F"};
        technicals[] = {"B_T_LSV_01_armed_F"};
        armour[] = {"B_T_APC_Wheeled_01_cannon_F", "B_T_MBT_01_TUSK_F", "B_APC_Tracked_01_rcws_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class MNP_USMC_SN {
        side = "west";
        camouflage[] = {"snow"};
        infantry[] = {"MNP_USMCA_Soldier_O", "MNP_USMCA_Soldier_AR", "MNP_USMCA_Soldier_F", "MNP_USMCA_Soldier_AT", "MNP_USMCA_Soldier_MG", "MNP_USMCA_Soldier_AR", "MNP_USMCA_Soldier_AT", "MNP_USMCA_Soldier_AT"};
        crewmen[] = {"MNP_USMCA_Soldier_F", "MNP_USMCA_Soldier_O"};
        pilots[]= {"CUP_B_USMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_NATO_T", "CUP_B_HMMWV_MK19_NATO_T", "CUP_B_HMMWV_M2_GPK_NATO_T", "CUP_B_HMMWV_SOV_M2_NATO_T", "CUP_B_HMMWV_SOV_NATO_T"};
        armour[] = {"CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_Woodland_USMC"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class MNP_US_RAN {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_USR_Soldier_O", "MNP_USR_Soldier_AR", "MNP_USR_Soldier_F", "MNP_USR_Soldier_AT", "MNP_USR_Soldier_MG", "MNP_USR_Soldier_AR", "MNP_USR_Soldier_AT", "MNP_USR_Soldier_AR", "MNP_USR_Soldier_AT"};
        crewmen[] = {"MNP_USR_Soldier_F", "MNP_USR_Soldier_O"};
        pilots[]= {"B_Helipilot_F"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_SOV_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_MK19_Desert_Slat", "CUP_B_M1128_MGS_Desert_Slat", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M1A2_TUSK_MG_DES_US_Army"};
        ah[] = {"CUP_B_AH64D_USA"};
    };

    class MNP_US_ACU {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_USA_Soldier_O", "MNP_USA_Soldier_AR", "MNP_USA_Soldier_F", "MNP_USA_Soldier_AT", "MNP_USA_Soldier_MG", "MNP_USA_Soldier_AR", "MNP_USA_Soldier_AT", "MNP_USA_Soldier_AR", "MNP_USA_Soldier_AT"};
        crewmen[] = {"MNP_USA_Soldier_F", "MNP_USA_Soldier_O"};
        pilots[]= {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert", "CUP_B_M1126_ICV_M2_Desert", "CUP_B_M1126_ICV_MK19_Desert", "CUP_B_M1128_MGS_Desert", "CUP_B_M2Bradley_USA_D", "CUP_B_M2Bradley_USA_D", "CUP_B_M1A1_DES_US_Army"};
        ah[] = {"CUP_B_AH64D_USA"};
    };

    class MNP_US_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_Wood_Soldier_O", "MNP_M81_Soldier_AR", "MNP_Wood_Soldier_F", "MNP_M81_Soldier_AT", "MNP_M81_Soldier_MG", "MNP_M81_Soldier_AR", "MNP_M81_Soldier_AT", "MNP_M81_Soldier_AR", "MNP_M81_Soldier_AT"};
        crewmen[] = {"MNP_M81_Soldier_F", "MNP_M81_Soldier_O"};
        pilots[]= {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_MK19_USMC"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M2Bradley_USA_W", "CUP_B_M60A3_USMC"};
        ah[] = {"CUP_B_AH64D_USA"};
    };

    class MNP_US_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_3Co_Soldier_O2", "MNP_3Co_Soldier_AR", "MNP_3Co_Soldier_F2", "MNP_3Co_Soldier_AT", "MNP_3Co_Soldier_MG", "MNP_3Co_Soldier_AR", "MNP_3Co_Soldier_AT", "MNP_3Co_Soldier_AR", "MNP_3Co_Soldier_AT"};
        crewmen[] = {"MNP_3Co_Soldier_F", "MNP_3Co_Soldier_O"};
        pilots[]= {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M2Bradley_USA_D", "CUP_B_M1A1_DES_US_Army"};
        ah[] = {"CUP_B_AH64D_USA"};
    };

    class MNP_US_SCO {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_Scorpion_Soldier_O", "MNP_Scorpion_Soldier_F", "MNP_Scorpion_Soldier_F", "MNP_Scorpion_Soldier_F", "MNP_Scorpion_Soldier_AT", "NP_Scorpion_Soldier_MG", "MNP_Scorpion_Soldier_AR", "MNP_Scorpion_Soldier_AT", "MNP_Scorpion_Soldier_AR", "MNP_Scorpion_Soldier_AT"};
        crewmen[] = {"MNP_Scorpion_Soldier_F", "MNP_Scorpion_Soldier_O"};
        pilots[]= {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_SOV_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_MK19_Desert_Slat", "CUP_B_M1128_MGS_Desert_Slat", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M1A2_TUSK_MG_DES_US_Army"};
        ah[] = {"CUP_B_AH64D_USA"};
    };

    class MNP_US_RAN_SCO {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_USR_Sco_Soldier_O", "MNP_USR_Sco_Soldier_F", "MNP_USR_Sco_Soldier_F", "MNP_USR_Sco_Soldier_AT", "MNP_USR_Sco_Soldier_MG", "MNP_USR_Sco_Soldier_AR", "MNP_USR_Sco_Soldier_AT", "MNP_USR_Sco_Soldier_AR", "MNP_USR_Sco_Soldier_AT"};
        crewmen[] = {"MNP_USR_Sco_Soldier_F", "MNP_USR_Sco_Soldier_O"};
        pilots[]= {"B_Helipilot_F"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_SOV_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_MK19_Desert_Slat", "CUP_B_M1128_MGS_Desert_Slat", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M1A2_TUSK_MG_DES_US_Army"};
        ah[] = {"CUP_B_AH64D_USA"};
    };

    class MNP_GE_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_GER_Soldier_S", "MNP_GER_Soldier_AR", "MNP_GER_Soldier_F", "MNP_GER_Soldier_AT", "MNP_GER_Soldier_MG", "MNP_GER_Soldier_AR", "MNP_GER_Soldier_AT", "MNP_GER_Soldier_AR", "MNP_GER_Soldier_AT"};
        crewmen[] = {"MNP_GER_Soldier_F", "MNP_GER_Soldier_S"};
        pilots[]= {"MNP_GER_Soldier_S"};
        technicals[] = {"CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GL_GER_Wdl"};
        armour[] = {"I_MBT_03_cannon_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class MNP_GE_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_GER_Soldier_DS", "MNP_GER_Soldier_AR_D", "MNP_GER_Soldier_DF", "MNP_GER_Soldier_AT_D", "MNP_GER_Soldier_MG_D", "MNP_GER_Soldier_AR_D", "MNP_GER_Soldier_AT_D", "MNP_GER_Soldier_AR_D", "MNP_GER_Soldier_AT_D"};
        crewmen[] = {"MNP_GER_Soldier_DF", "MNP_GER_Soldier_DS"};
        pilots[]= {"MNP_GER_Soldier_DS"};
        technicals[] = {"CUP_B_Dingo_GL_GER_Des", "CUP_B_Dingo_GER_Des", "CUP_B_Dingo_GER_Des"};
        armour[] = {"I_MBT_03_cannon_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class MNP_CA_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_Canada_Soldier_S", "MNP_Canada_Soldier_AR", "MNP_Canada_Soldier_F", "MNP_Canada_Soldier_AT", "MNP_Canada_Soldier_MG", "MNP_Canada_Soldier_AR", "MNP_Canada_Soldier_AT", "MNP_Canada_Soldier_AR", "MNP_Canada_Soldier_AT"};
        crewmen[] = {"MNP_Canada_Soldier_F", "MNP_Canada_Soldier_S"};
        pilots[]= {"MNP_Canada_Soldier_S"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_HMMWV_MK19_USMC", "CUP_B_RG31_M2_OD_USMC", "CUP_B_RG31_Mk19_OD_USMC"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC"};
        ah[] = {"CUP_B_UH1Y_GUNSHIP_USMC"};
    };

    class MNP_CA_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_Canada_Soldier_DS", "MNP_Canada_Soldier_DAR", "MNP_Canada_Soldier_DF", "MNP_Canada_Soldier_DAT", "MNP_Canada_Soldier_DMG", "MNP_Canada_Soldier_DAR", "MNP_Canada_Soldier_DAT", "MNP_Canada_Soldier_DAR", "MNP_Canada_Soldier_DAT"};
        crewmen[] = {"MNP_Canada_Soldier_DF", "MNP_Canada_Soldier_DS"};
        pilots[]= {"MNP_Canada_Soldier_DS"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC"};
        ah[] = {"CUP_B_UH1Y_GUNSHIP_USMC"};
    };

    class MNP_AUS {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_AUS_Soldier_S", "MNP_AUS_Soldier_AR", "MNP_AUS_Soldier_F", "MNP_AUS_Soldier_AT", "MNP_AUS_Soldier_MG", "MNP_AUS_Soldier_AR", "MNP_AUS_Soldier_AT", "MNP_AUS_Soldier_AR", "MNP_AUS_Soldier_AT"};
        crewmen[] = {"MNP_AUS_Soldier_F", "MNP_AUS_Soldier_S"};
        pilots[]= {"MNP_AUS_Soldier_S"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_GMG_GB_W"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC", "CUP_B_M1A1_Woodland_US_Army"};
        ah[] = {"CUP_B_UH1Y_GUNSHIP_USMC"};
    };

    class MNP_AUS_AMCU {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_AMCU_Soldier_F", "MNP_AMCU_Soldier_AR", "MNP_AMCU_Soldier_F", "MNP_AMCU_Soldier_O", "MNP_AMCU_Soldier_AT", "MNP_AMCU_Soldier_MG", "MNP_AMCU_Soldier_AR", "MNP_AMCU_Soldier_AT", "MNP_AMCU_Soldier_AR", "MNP_AMCU_Soldier_AT"};
        crewmen[] = {"MNP_AMCU_Soldier_F", "MNP_AMCU_Soldier_O"};
        pilots[]= {"MNP_AMCU_Soldier_O"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_GMG_GB_W"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC", "CUP_B_M1A1_Woodland_US_Army"};
        ah[] = {"CUP_B_UH1Y_GUNSHIP_USMC"};
    };

    class MNP_ROK {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_ROK_Soldier_O", "MNP_ROK_Soldier_AR", "MNP_ROK_Soldier_F", "MNP_ROK_Soldier_AT", "MNP_ROK_Soldier_MG", "MNP_ROK_Soldier_AR", "MNP_ROK_Soldier_AT", "MNP_ROK_Soldier_AR", "MNP_ROK_Soldier_AT"};
        crewmen[] = {"MNP_ROK_Soldier_F", "MNP_ROK_Soldier_O"};
        pilots[]= {"MNP_ROK_Soldier_F"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M163_USA"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class MNP_PMC {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_OD_Soldier_O", "MNP_OD_Soldier_AR", "MNP_OD_Soldier_F", "MNP_OD_Soldier_AT", "MNP_OD_Soldier_MG", "MNP_OD_Soldier_AR", "MNP_OD_Soldier_AT", "MNP_OD_Soldier_AR", "MNP_OD_Soldier_AT"};
        crewmen[] = {"MNP_OD_Soldier_F", "MNP_OD_Soldier_O"};
        pilots[]= {"MNP_OD_Soldier_O"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_I_SUV_Armored_ION", "CUP_I_SUV_Armored_ION"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_I_BMP1_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"CUP_I_Mi24_D_ION"};
    };

    class UKR_TTSKO {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_UKR_G", "MNP_UKR_A", "MNP_UKR_A", "MNP_UKR_O", "MNP_UKR_MG", "MNP_UKR_AR", "MNP_UKR_AT", "MNP_UKR_AR", "MNP_UKR_AT"};
        crewmen[] = {"MNP_UKR_A", "MNP_UKR_O"};
        pilots[]= {"MNP_UKR_O"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_BRDM2_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BMP2_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_BTR60_CDF", "CUP_B_BTR60_CDF"};
        ah[] = {"CUP_B_Mi24_D_CDF"};
    };

    class CUP_USMC_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_USMC_Soldier_GL", "CUP_B_USMC_Soldier", "CUP_B_USMC_Soldier", "CUP_B_USMC_Soldier_TL", "CUP_B_USMC_Soldier_MG", "CUP_B_USMC_Soldier_AR", "CUP_B_USMC_Soldier_LAT", "CUP_B_USMC_Soldier_AR", "CUP_B_USMC_Soldier_LAT"};
        crewmen[] = {"CUP_B_USMC_Soldier"};
        pilots[]= {"CUP_B_USMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_MK19_USMC", "CUP_B_RG31_Mk19_OD_USMC", "CUP_B_RG31_M2_OD_USMC"};
        armour[] = {"CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_Woodland_USMC"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_KSK_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_GER_Fleck_Soldier", "CUP_B_GER_Fleck_Soldier_MG", "CUP_B_GER_Fleck_Soldier_TL", "CUP_B_GER_Fleck_Soldier_TL", "CUP_B_GER_Fleck_Soldier_MG", "CUP_B_GER_Fleck_Soldier_MG", "CUP_B_GER_Fleck_Soldier_AT", "CUP_B_GER_Fleck_Soldier_MG", "CUP_B_GER_Fleck_Soldier_AT"};
        crewmen[] = {"CUP_B_GER_Fleck_Soldier_TL", "CUP_B_GER_Fleck_Soldier"};
        pilots[]= {"CUP_B_GER_Fleck_Soldier_TL"};
        technicals[] = {"CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GL_GER_Wdl"};
        armour[] = {"I_MBT_03_cannon_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class CUP_KSK_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_GER_Soldier", "CUP_B_GER_Soldier_MG", "CUP_B_GER_Soldier_TL", "CUP_B_GER_Soldier_TL", "CUP_B_GER_Soldier_TL", "CUP_B_GER_Soldier_MG", "CUP_B_GER_Soldier_AT", "CUP_B_GER_Soldier_MG", "CUP_B_GER_Soldier_AT"};
        crewmen[] = {"CUP_B_GER_Soldier_TL", "CUP_B_GER_Soldier"};
        pilots[]= {"CUP_B_GER_Soldier_TL"};
        technicals[] = {"CUP_B_Dingo_GL_GER_Des", "CUP_B_Dingo_GER_Des", "CUP_B_Dingo_GER_Des"};
        armour[] = {"I_MBT_03_cannon_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class CUP_BAF_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_BAF_Soldier_SL_WDL", "CUP_B_BAF_Soldier_WDL", "CUP_B_BAF_Soldier_WDL", "CUP_B_BAF_Soldier_TL_WDL", "CUP_B_BAF_Soldier_MG_WDL", "CUP_B_BAF_Soldier_AR_WDL", "CUP_B_BAF_Soldier_AT_WDL", "CUP_B_BAF_Soldier_AR_WDL", "CUP_B_BAF_Soldier_AT_WDL"};
        crewmen[] = {"CUP_B_BAF_Crew_WDL"};
        pilots[]= {"CUP_B_BAF_Pilot_WDL"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_Jackal2_L2A1_GB_W", "CUP_B_BAF_Coyote_L2A1_W", "CUP_B_Jackal2_GMG_GB_W", "CUP_B_Ridgback_LMG_GB_W"};
        armour[] = {"CUP_B_Mastiff_HMG_GB_W", "CUP_B_Mastiff_HMG_GB_W", "CUP_B_FV432_Bulldog_GB_W_RWS", "CUP_B_FV432_Bulldog_GB_W", "CUP_B_FV432_Bulldog_GB_W_RWS", "CUP_B_MCV80_GB_W_SLAT", "CUP_B_MCV80_GB_W", "CUP_B_MCV80_GB_W_SLAT"};
        ah[] = {"CUP_B_AH1_BAF"};
    };

    class CUP_BAF_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_BAF_Soldier_SL_DDPM", "CUP_B_BAF_Soldier_DDPM", "CUP_B_BAF_Soldier_DDPM", "CUP_B_BAF_Soldier_TL_DDPM", "CUP_B_BAF_Soldier_MG_DDPM", "CUP_B_BAF_Soldier_AR_DDPM", "CUP_B_BAF_Soldier_AT_DDPM", "CUP_B_BAF_Soldier_AR_DDPM", "CUP_B_BAF_Soldier_AT_DDPM"};
        crewmen[] = {"CUP_B_BAF_Crew_DDPM"};
        pilots[]= {"CUP_B_BAF_Pilot_DDPM"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_Jackal2_L2A1_GB_D", "CUP_B_BAF_Coyote_L2A1_D", "CUP_B_Jackal2_GMG_GB_D", "CUP_B_Ridgback_LMG_GB_D"};
        armour[] = {"CUP_B_Mastiff_HMG_GB_D", "CUP_B_Mastiff_HMG_GB_D", "CUP_B_FV432_Bulldog_GB_D_RWS", "CUP_B_FV432_Bulldog_GB_D", "CUP_B_FV432_Bulldog_GB_D_RWS", "CUP_B_MCV80_GB_D_SLAT", "CUP_B_MCV80_GB_D", "CUP_B_Challenger2_Desert_BAF"};
        ah[] = {"CUP_B_AH1_BAF"};
    };

    class CUP_BAF_MTP {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"CUP_B_BAF_Soldier_SL_MTP", "CUP_B_BAF_Soldier_MTP", "CUP_B_BAF_Soldier_MTP", "CUP_B_BAF_Soldier_TL_MTP", "CUP_B_BAF_Soldier_MG_MTP", "CUP_B_BAF_Soldier_AR_MTP", "CUP_B_BAF_Soldier_AT_MTP", "CUP_B_BAF_Soldier_AR_MTP", "CUP_B_BAF_Soldier_AT_MTP"};
        crewmen[] = {"CUP_B_BAF_Crew_MTP"};
        pilots[]= {"CUP_B_BAF_Pilot_MTP"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_Jackal2_L2A1_GB_D", "CUP_B_BAF_Coyote_L2A1_D", "CUP_B_Jackal2_GMG_GB_D", "CUP_B_Ridgback_LMG_GB_D"};
        armour[] = {"CUP_B_Mastiff_HMG_GB_D", "CUP_B_Mastiff_HMG_GB_D", "CUP_B_FV432_Bulldog_GB_D_RWS", "CUP_B_FV432_Bulldog_GB_D", "CUP_B_FV432_Bulldog_GB_D_RWS", "CUP_B_MCV80_GB_D_SLAT", "CUP_B_MCV80_GB_D", "CUP_B_Challenger2_Woodland_BAF"};
        ah[] = {"CUP_B_AH1_BAF"};
    };

    class CUP_US_ACU {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_US_Soldier_TL", "CUP_B_US_Soldier", "CUP_B_US_Soldier", "CUP_B_US_Soldier_TL", "CUP_B_US_Soldier_MG", "CUP_B_US_Soldier_AR", "CUP_B_US_Soldier_LAT", "CUP_B_US_Soldier_AR", "CUP_B_US_Soldier_LAT"};
        crewmen[] = {"CUP_B_US_Crew"};
        pilots[]= {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert", "CUP_B_M1126_ICV_M2_Desert", "CUP_B_M1126_ICV_MK19_Desert", "CUP_B_M1128_MGS_Desert", "CUP_B_M2Bradley_USA_D", "CUP_B_M2Bradley_USA_D", "CUP_B_M1A1_DES_US_Army"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class FIA_GUER {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"B_G_Soldier_SL_F", "B_G_Soldier_AR_F", "B_G_Soldier_lite_F", "B_G_Soldier_RPG7_F", "B_G_Soldier_M_F", "B_G_Soldier_AR_F", "B_G_Soldier_RPG7_F", "B_G_Soldier_AR_F", "B_G_Soldier_RPG7_F"};
        crewmen[] = {"B_G_Soldier_F", "B_G_engineer_F"};
        pilots[]= {"B_G_Soldier_lite_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU", "B_G_Offroad_01_armed_F", "B_G_Offroad_01_armed_F"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_T34_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class IF44_GER_WD {
        side = "west";
        camouflage[] = {};
        infantry[] = {"LIB_GER_rifleman", "LIB_GER_rifleman", "LIB_GER_rifleman", "LIB_GER_rifleman", "LIB_GER_rifleman", "LIB_GER_mgunner", "LIB_GER_AT_grenadier", "LIB_GER_mgunner", "LIB_GER_AT_soldier", "LIB_GER_smgunner", "LIB_GER_smgunner", "LIB_GER_ober_rifleman", "LIB_GER_ober_rifleman", "LIB_GER_stggunner", "LIB_GER_ober_lieutenant"};
        crewmen[] = {"LIB_GER_tank_officer", "LIB_GER_spg_crew"};
        technicals[] = {"LIB_Kfz1_MG42", "LIB_Kfz1_MG42", "LIB_Kfz1_MG42", "LIB_SdKfz251"};
        armour[] = {"LIB_StuG_III_G", "LIB_StuG_III_G", "LIB_StuG_III_G", "LIB_PzKpfwIV_H", "LIB_PzKpfwIV_H", "LIB_PzKpfwV", "LIB_PzKpfwVI_E"};
        ah[] = {};
    };

    class IF44_GER_SN {
        side = "west";
        camouflage[] = {};
        infantry[] = {"LIB_GER_rifleman_w", "LIB_GER_rifleman_w", "LIB_GER_rifleman_w", "LIB_GER_rifleman_w", "LIB_GER_rifleman_w", "LIB_GER_mgunner_w", "LIB_GER_AT_grenadier_w", "LIB_GER_mgunner_w", "LIB_GER_AT_soldier_w", "LIB_GER_smgunner_w", "LIB_GER_smgunner_w", "LIB_GER_ober_rifleman_w", "LIB_GER_ober_rifleman_w", "LIB_GER_stggunner_w", "LIB_GER_ober_lieutenant_w"};
        crewmen[] = {"LIB_GER_tank_officer", "LIB_GER_spg_crew"};
        pilots[]= {"LIB_GER_tank_officer"};
        technicals[] = {"LIB_Kfz1_MG42", "LIB_Kfz1_MG42", "LIB_Kfz1_MG42", "LIB_SdKfz251"};
        armour[] = {"LIB_StuG_III_G_w", "LIB_StuG_III_G_w", "LIB_StuG_III_G_w", "LIB_PzKpfwIV_H_w", "LIB_PzKpfwIV_H_w", "LIB_PzKpfwV_w", "LIB_PzKpfwVI_E_w"};
        ah[] = {};
    };

    class CSAT_WOODLAND {
        side = "east";
        camouflage[] = {};
        infantry[] = {"O_Soldier_SL_F", "O_Soldier_AR_F", "O_Soldier_lite_F", "O_Soldier_RPG18_F", "O_support_MG_F", "O_Soldier_AR_F", "O_Soldier_RPG18_F", "O_Soldier_AR_F", "O_Soldier_LAT_F"};
        crewmen[] = {"O_crew_F", "O_engineer_F"};
        pilots[]= {"O_Helipilot_F"};
        technicals[] = {"O_MRAP_02_hmg_F", "O_LSV_02_armed_F", "O_LSV_02_armed_F"};
        armour[] = {"O_APC_Tracked_02_cannon_F", "O_MBT_02_cannon_F", "O_APC_Wheeled_02_rcws_F"};
        ah[] = {"O_Heli_Attack_02_F"};
    };

    class CSAT_URBAN {
        side = "east";
        camouflage[] = {};
        infantry[] = {"O_soldierU_SL_F", "O_soldierU_AR_F", "O_soldierU_F", "O_soldierU_RPG18_F", "O_soldierU_M_F", "O_soldierU_AR_F", "O_soldierU_RPG18_F", "O_soldierU_AR_F", "O_soldierU_RPG18_F"};
        crewmen[] = {"O_soldierU_F", "O_engineer_U_F"};
        pilots[]= {"O_soldierU_TL_F"};
        technicals[] = {"O_MRAP_02_hmg_F", "O_LSV_02_armed_F", "O_LSV_02_armed_F"};
        armour[] = {"O_APC_Tracked_02_cannon_F", "O_MBT_02_cannon_F", "O_APC_Wheeled_02_rcws_F"};
        ah[] = {"O_Heli_Attack_02_F"};
    };

    class CSAT_JUNGLE {
        side = "east";
        camouflage[] = {};
        infantry[] = {"O_T_Soldier_SL_F", "O_T_Soldier_AR_F", "O_T_Soldier_TL_F", "O_T_Soldier_RPG18_F", "O_T_Support_MG_F", "O_T_Soldier_AR_F", "O_T_Soldier_RPG18_F", "O_T_Soldier_AR_F", "O_T_Soldier_RPG18_F"};
        crewmen[] = {"O_T_Crew_F", "O_T_Engineer_F"};
        pilots[]= {"O_T_Pilot_F"};
        technicals[] = {"O_T_MRAP_02_hmg_ghex_F", "O_LSV_02_armed_F", "O_LSV_02_armed_F"};
        armour[] = {"O_T_APC_Tracked_02_cannon_ghex_F", "O_T_MBT_02_cannon_ghex_F", "O_T_APC_Wheeled_02_rcws_ghex_F"};
        ah[] = {"O_Heli_Attack_02_F"};
    };

    class MNP_OPF_F_SN {
        side = "east";
        camouflage[] = {"snow"};
        infantry[] = {"MNP_RU_Soldier_Arctic_O", "MNP_RU_Soldier_Arctic_AR", "MNP_RU_Soldier_Arctic_F", "MNP_RU_Soldier_Arctic_AT", "MNP_RU_Soldier_Arctic_MG", "MNP_RU_Soldier_Arctic_AR", "MNP_RU_Soldier_Arctic_AT", "MNP_RU_Soldier_Arctic_AR", "MNP_RU_Soldier_Arctic_AT"};
        crewmen[] = {"MNP_RU_Soldier_Arctic_F", "MNP_RU_Soldier_Arctic_O"};
        pilots[]= {"MNP_RU_Soldier_Arctic_F"};
        technicals[] = {"O_MRAP_02_hmg_F", "O_LSV_02_armed_F", "O_LSV_02_armed_F"};
        armour[] = {"O_APC_Tracked_02_cannon_F", "O_MBT_02_cannon_F", "O_APC_Wheeled_02_rcws_F"};
        ah[] = {"O_Heli_Attack_02_F"};
    };

    class MNP_CH_WD {
        side = "east";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_CN_Soldier_O", "MNP_CN_Soldier_AR", "MNP_CN_Soldier_F", "MNP_CN_Soldier_RAT", "MNP_CN_Soldier_MG", "MNP_CN_Soldier_AR", "MNP_CN_Soldier_RAT", "MNP_CN_Soldier_AR", "MNP_CN_Soldier_RAT"};
        crewmen[] = {"MNP_CN_Soldier_F", "MNP_CN_Soldier_O"};
        pilots[]= {"MNP_CN_Soldier_O"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"O_Heli_Light_02_v2_F"};
    };

    class MNP_CH_WD2 {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_CN_WD2_Soldier_O", "MNP_CN_WD2_Soldier_F", "MNP_CN_WD2_Soldier_F", "MNP_CN_WD2_Soldier_G", "MNP_CN_WD2_Soldier_MG", "MNP_CN_WD2_Soldier_AR", "MNP_CN_WD2_Soldier_RAT", "MNP_CN_WD2_Soldier_AR", "MNP_CN_WD2_Soldier_RAT"};
        crewmen[] = {"MNP_CN_WD2_Soldier_F", "MNP_CN_WD2_Soldier_O"};
        pilots[]= {"MNP_CN_WD2_Soldier_O"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"O_Heli_Light_02_v2_F"};
    };

    class MNP_CH_DE {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_CD_Soldier_O", "MNP_CD_Soldier_AR", "MNP_CD_Soldier_F", "MNP_CD_Soldier_RAT", "MNP_CD_Soldier_MG", "MNP_CD_Soldier_AR", "MNP_CD_Soldier_RAT", "MNP_CD_Soldier_AR", "MNP_CD_Soldier_RAT"};
        crewmen[] = {"MNP_CD_Soldier_F", "MNP_CD_Soldier_O"};
        pilots[]= {"MNP_CD_Soldier_O"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"O_Heli_Light_02_v2_F"};
    };

    class MNP_CH_MAR {
        side = "east";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_CM_Soldier_O", "MNP_CM_Soldier_AR", "MNP_CM_Soldier_F", "MNP_CM_Soldier_RAT", "MNP_CM_Soldier_MG", "MNP_CM_Soldier_AR", "MNP_CM_Soldier_RAT", "MNP_CM_Soldier_AR", "MNP_CM_Soldier_RAT"};
        crewmen[] = {"MNP_CM_Soldier_F", "MNP_CM_Soldier_O"};
        pilots[]= {"MNP_CM_Soldier_O"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"O_Heli_Light_02_v2_F"};
    };

    class MNP_RU_VDV_DE {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_RU_Soldier_O_D", "MNP_RU_Soldier_AR_D", "MNP_RU_Soldier_MEDIUM_D", "MNP_RU_Soldier_AT_D", "MNP_RU_Soldier_MG_D", "MNP_RU_Soldier_AR_D", "MNP_RU_Soldier_AT_D", "MNP_RU_Soldier_AR_D", "MNP_RU_Soldier_AT_D"};
        crewmen[] = {"MNP_RU_Soldier_MEDIUM_D", "MNP_RU_Soldier_O_D"};
        pilots[]= {"MNP_RU_Soldier_O_D"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BTR90_RU", "CUP_O_BMP2_RU", "CUP_O_T72_RU", "CUP_O_T90_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_KOR_OD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_NK_Soldier_O", "MNP_NK_Soldier_AR", "MNP_NK_Soldier_F", "MNP_NK_Soldier_AT", "MNP_NK_Soldier_MG", "MNP_NK_Soldier_AR", "MNP_NK_Soldier_AT", "MNP_NK_Soldier_AR", "MNP_NK_Soldier_AT"};
        crewmen[] = {"MNP_NK_Soldier_F", "MNP_NK_Soldier_O"};
        pilots[]= {"MNP_NK_Soldier_O"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_KOR_WD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_NKC_Soldier_O", "MNP_NKC_Soldier_AR", "MNP_NKC_Soldier_F", "MNP_NKC_Soldier_AT", "MNP_NKC_Soldier_MG", "MNP_NKC_Soldier_AR", "MNP_NKC_Soldier_AT", "MNP_NKC_Soldier_AR", "MNP_NKC_Soldier_AT"};
        crewmen[] = {"MNP_NKC_Soldier_F", "MNP_NKC_Soldier_O"};
        pilots[]= {"MNP_NKC_Soldier_O"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_RU_AIR {
        side = "east";
        camouflage[] = {"woodland", "desert", "snow"};
        infantry[] = {"MNP_RO3_Soldier_O", "MNP_RO3_Soldier_AR", "MNP_RO3_Soldier_F", "MNP_RO3_Soldier_AT", "MNP_RO3_Soldier_MG", "MNP_RO3_Soldier_AR", "MNP_RO3_Soldier_AT", "MNP_RO3_Soldier_AR", "MNP_RO3_Soldier_AT"};
        crewmen[] = {"MNP_RO3_Soldier_F", "MNP_RO3_Soldier_O"};
        pilots[]= {"MNP_RO3_Soldier_O"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BMP2_RU", "CUP_O_BMP2_RU", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_BTR60_SLA", "CUP_O_BTR60_SLA", "CUP_O_T90_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_DPR_SUM {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_DPR_T_Soldier_TL", "MNP_DPR_T_Soldier_F", "MNP_DPR_T_Soldier_F", "MNP_DPR_T_Soldier_GR", "MNP_DPR_T_Soldier_MG", "MNP_DPR_T_Soldier_AR", "MNP_DPR_T_Soldier_AT", "MNP_DPR_T_Soldier_AR", "MNP_DPR_T_Soldier_AT"};
        crewmen[] = {"MNP_DPR_T_Soldier_F", "MNP_DPR_T_Soldier_TL"};
        pilots[]= {"MNP_DPR_T_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_AGS30_CHDKZ", "CUP_O_UAZ_SPG9_CHDKZ"};
        armour[] = {"CUP_O_BRDM2_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_CHDKZ", "CUP_O_BMP2_CHDKZ", "CUP_O_T72_CHDKZ"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_DPR_AUT {
        side = "east";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_DPR_Soldier_TL", "MNP_DPR_Soldier_F", "MNP_DPR_Soldier_F", "MNP_DPR_Soldier_GR", "MNP_DPR_Soldier_MG", "MNP_DPR_Soldier_AT", "MNP_DPR_Soldier_AR", "MNP_DPR_Soldier_AT", "MNP_DPR_Soldier_AR"};
        crewmen[] = {"MNP_DPR_Soldier_F", "MNP_DPR_Soldier_TL"};
        pilots[]= {"MNP_DPR_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_AGS30_CHDKZ", "CUP_O_UAZ_SPG9_CHDKZ"};
        armour[] = {"CUP_O_BRDM2_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_CHDKZ", "CUP_O_BMP2_CHDKZ", "CUP_O_T72_CHDKZ"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_IRN_WD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_IRN_WD_Soldier_TL", "MNP_IRN_WD_Soldier_F", "MNP_IRN_WD_Soldier_F", "MNP_IRN_WD_Soldier_F", "MNP_IRN_WD_Soldier_GR", "MNP_IRN_WD_Soldier_AR", "MNP_IRN_WD_Soldier_AT", "MNP_IRN_WD_Soldier_AR", "MNP_IRN_WD_Soldier_AT"};
        crewmen[] = {"MNP_IRN_WD_Soldier_F", "MNP_IRN_WD_Soldier_TL"};
        pilots[]= {"MNP_IRN_WD_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_IRN_RG_WD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_IRN_WD_IRGC_Soldier_O", "MNP_IRN_WD_IRGC_Soldier_F", "MNP_IRN_WD_IRGC_Soldier_F", "MNP_IRN_WD_IRGC_Soldier_F", "MNP_IRN_WD_IRGC_Soldier_MG", "MNP_IRN_WD_IRGC_Soldier_AR", "MNP_IRN_WD_IRGC_Soldier_AT", "MNP_IRN_WD_IRGC_Soldier_AR", "MNP_IRN_WD_IRGC_Soldier_AT"};
        crewmen[] = {"MNP_IRN_WD_IRGC_Soldier_F", "MNP_IRN_WD_IRGC_Soldier_O"};
        pilots[]= {"MNP_IRN_WD_IRGC_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_I_T55_TK_GUE"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_IRN_DE {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_IRN_DE_Soldier_TL", "MNP_IRN_DE_Soldier_F", "MNP_IRN_DE_Soldier_F", "MNP_IRN_DE_Soldier_GR", "MNP_IRN_DE_Soldier_MG", "MNP_IRN_DE_Soldier_AR", "MNP_IRN_DE_Soldier_AT", "MNP_IRN_DE_Soldier_AR", "MNP_IRN_DE_Soldier_AT"};
        crewmen[] = {"MNP_IRN_DE_Soldier_F", "MNP_IRN_DE_Soldier_TL"};
        pilots[]= {"MNP_IRN_DE_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_IRN_RG_DE {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_IRN_DE_IRGC_Soldier_O", "MNP_IRN_DE_IRGC_Soldier_F", "MNP_IRN_DE_IRGC_Soldier_F", "MNP_IRN_DE_IRGC_Soldier_G", "MNP_IRN_DE_IRGC_Soldier_MG", "MNP_IRN_DE_IRGC_Soldier_AR", "MNP_IRN_DE_IRGC_Soldier_AT", "MNP_IRN_DE_IRGC_Soldier_AR", "MNP_IRN_DE_IRGC_Soldier_AT"};
        crewmen[] = {"MNP_IRN_DE_IRGC_Soldier_F", "MNP_IRN_DE_IRGC_Soldier_O"};
        pilots[]= {"MNP_IRN_DE_IRGC_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_I_T55_TK_GUE"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class CUP_TKA_OD {
        side = "east";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"CUP_O_TK_Soldier_GL", "CUP_O_TK_Soldier_SL", "CUP_O_TK_Soldier", "CUP_O_TK_Soldier_LAT", "CUP_O_TK_Soldier_MG", "CUP_O_TK_Soldier_AR", "CUP_O_TK_Soldier_AT", "CUP_O_TK_Soldier_AR", "CUP_O_TK_Soldier_AT"};
        crewmen[] = {"CUP_O_TK_Soldier_SL", "CUP_O_TK_Soldier"};
        pilots[]= {"CUP_O_TK_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_AGS30_TKA", "CUP_O_UAZ_SPG9_TKA", "CUP_O_BTR40_MG_TKA", "CUP_O_LR_SPG9_TKA", "CUP_O_LR_MG_TKA"};
        armour[] = {"CUP_O_M113_TKA", "CUP_O_M113_TKA", "CUP_O_BTR60_TK", "CUP_O_BTR60_TK", "CUP_O_BRDM2_TKA", "CUP_O_BRDM2_TKA", "CUP_O_BMP1P_TKA", "CUP_O_BMP2_TKA", "CUP_O_BMP2_ZU_TKA", "CUP_O_T55_TK", "CUP_O_T72_TKA"};
        ah[] = {"CUP_O_Mi24_D_TK"};
    };

    class CUP_TK_INS {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_O_TK_INS_Soldier_GL", "CUP_O_TK_INS_Commander", "CUP_O_TK_INS_Soldier", "CUP_O_TK_INS_Soldier_FNFAL", "CUP_O_TK_INS_Soldier_MG", "CUP_O_TK_INS_Soldier_AR", "CUP_O_TK_INS_Soldier_Enfield", "CUP_O_TK_INS_Soldier_Enfield", "CUP_O_TK_INS_Soldier_AT", "CUP_O_TK_INS_Soldier_AR", "CUP_O_TK_INS_Soldier_AT"};
        crewmen[] = {"CUP_O_TK_INS_Soldier_FNFAL", "CUP_O_TK_INS_Soldier"};
        pilots[]= {"CUP_O_TK_INS_Soldier"};
        technicals[] = {"CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_AGS30_TKA", "CUP_O_UAZ_SPG9_TKA", "CUP_O_BTR40_MG_TKA", "CUP_O_LR_SPG9_TKA", "CUP_O_LR_MG_TKA"};
        armour[] = {"CUP_O_BRDM2_TKA", "CUP_O_BRDM2_TKA", "CUP_O_BRDM2_TKA", "CUP_O_BMP1P_TKA", "CUP_O_BMP2_TKA", "CUP_O_T55_TK", "CUP_O_M113_TKA", "CUP_O_BTR60_TK", "CUP_O_T34_TKA"};
        ah[] = {"CUP_O_Mi24_D_TK"};
    };

    class CUP_SLA_WD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_O_sla_Soldier_SL", "CUP_O_sla_Soldier", "CUP_O_sla_Soldier", "CUP_O_sla_Soldier_LAT", "CUP_O_sla_Soldier_GL", "CUP_O_sla_Soldier_AR", "CUP_O_sla_Soldier_AT", "CUP_O_sla_Soldier_AR", "CUP_O_sla_Soldier_AT", "CUP_O_sla_Soldier_MG"};
        crewmen[] = {"CUP_O_sla_Soldier", "CUP_O_sla_Soldier_SL"};
        pilots[]= {"CUP_O_sla_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_AGS30_SLA", "CUP_O_UAZ_SPG9_SLA"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_O_T55_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi24_D_SLA"};
    };

    class CUP_CHDKZ {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_O_INS_Soldier_GL", "CUP_O_INS_Soldier", "CUP_O_INS_Soldier", "CUP_O_INS_Soldier_AT", "CUP_O_INS_Soldier_GL", "CUP_O_INS_Soldier_AR", "CUP_O_INS_Soldier_AT", "CUP_O_INS_Soldier_AR", "CUP_O_INS_Soldier_AT", "CUP_O_INS_Soldier_MG"};
        crewmen[] = {"CUP_O_INS_Crew"};
        pilots[]= {"CUP_O_INS_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_AGS30_CHDKZ", "CUP_O_UAZ_SPG9_CHDKZ"};
        armour[] = {"CUP_O_BRDM2_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_O_BMP2_CHDKZ", "CUP_O_BMP2_CHDKZ", "CUP_O_T72_CHDKZ"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class CUP_RU_WD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_O_RU_Soldier_SL", "CUP_O_RU_Soldier", "CUP_O_RU_Soldier", "CUP_O_RU_Soldier_LAT", "CUP_O_RU_Soldier_TL", "CUP_O_RU_Soldier_AR", "CUP_O_RU_Soldier_LAT", "CUP_O_RU_Soldier_AR", "CUP_O_RU_Soldier_LAT", "CUP_O_RU_Soldier_MG"};
        crewmen[] = {"CUP_O_RU_Crew"};
        pilots[]= {"CUP_O_RU_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_RUS", "CUP_O_BRDM2_RUS", "CUP_O_BRDM2_RUS", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_RU", "CUP_O_BMP2_RU", "CUP_O_BMP3_RU", "CUP_O_T72_RU", "CUP_O_T90_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class CUP_RU_EMR {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_O_RU_Soldier_SL_EMR", "CUP_O_RU_Soldier_EMR", "CUP_O_RU_Soldier_EMR", "CUP_O_RU_Soldier_LAT_EMR", "CUP_O_RU_Soldier_TL_EMR", "CUP_O_RU_Soldier_AR_EMR", "CUP_O_RU_Soldier_LAT_EMR", "CUP_O_RU_Soldier_AR_EMR", "CUP_O_RU_Soldier_LAT_EMR", "CUP_O_RU_Soldier_MG_EMR"};
        crewmen[] = {"CUP_O_RU_Crew_EMR"};
        pilots[]= {"CUP_O_RU_Pilot_EMR"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU", "CUP_O_GAZ_Vodnik_PK_RU", "CUP_O_GAZ_Vodnik_AGS_RU"};
        armour[] = {"CUP_O_BRDM2_RUS", "CUP_O_BRDM2_RUS", "CUP_O_BRDM2_RUS", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_RU", "CUP_O_BMP2_RU", "CUP_O_BMP3_RU", "CUP_O_T72_RU", "CUP_O_BTR90_RU", "CUP_O_GAZ_Vodnik_BPPU_RU", "CUP_O_T90_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class IF44_USSR_WD {
        side = "east";
        camouflage[] = {};
        infantry[] = {"LIB_SOV_first_lieutenant", "LIB_SOV_mgunner", "LIB_SOV_rifleman", "LIB_SOV_AT_grenadier", "LIB_SOV_smgunner", "LIB_SOV_mgunner", "LIB_SOV_rifleman", "LIB_SOV_rifleman", "LIB_SOV_rifleman", "LIB_SOV_rifleman"};
        crewmen[] = {"LIB_SOV_tank_crew", "LIB_SOV_tank_sergeant"};
        pilots[]= {"LIB_SOV_tank_sergeant"};
        technicals[] = {"LIB_Scout_M3_FFV", "LIB_SOV_M3_Halftrack"};
        armour[] = {"LIB_SU85", "LIB_T34_76", "LIB_T34_76", "LIB_T34_76", "LIB_T34_85", "LIB_T34_85", "LIB_T34_85", "LIB_M4A2_SOV", "LIB_M4A2_SOV", "LIB_JS2_43"};
        ah[] = {};
    };

    class IF44_USSR_SN {
        side = "east";
        camouflage[] = {};
        infantry[] = {"LIB_SOV_first_lieutenant_w", "LIB_SOV_mgunner_w", "LIB_SOV_rifleman_w", "LIB_SOV_AT_grenadier_w", "LIB_SOV_smgunner_w", "LIB_SOV_mgunner_w", "LIB_SOV_AT_grenadier_w", "LIB_SOV_mgunner_w", "LIB_SOV_AT_soldier_w"};
        crewmen[] = {"LIB_SOV_tank_crew", "LIB_SOV_tank_sergeant"};
        pilots[]= {"LIB_SOV_tank_sergeant"};
        technicals[] = {"LIB_Scout_M3_FFV", "LIB_SOV_M3_Halftrack"};
        armour[] = {"LIB_SU85_w", "LIB_T34_76_w", "LIB_T34_76_w", "LIB_T34_76_w", "LIB_T34_85_w", "LIB_T34_85_w", "LIB_T34_85_w", "LIB_M4A2_SOV_w", "LIB_M4A2_SOV_w", "LIB_JS2_43_w"};
        ah[] = {};
    };

    class AAF_WOODLAND {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"I_Soldier_SL_F", "I_Soldier_AR_F", "I_Soldier_lite_F", "I_Soldier_AT4_F", "I_Soldier_M_F", "I_Soldier_AR_F", "I_Soldier_AT4_F", "I_Soldier_AR_F", "I_Soldier_AT4_F"};
        crewmen[] = {"I_crew_F", "I_engineer_F"};
        pilots[]= {"I_Helipilot_F"};
        technicals[] = {"I_MRAP_03_hmg_F", "CUP_I_LR_MG_AAF", "CUP_I_LR_MG_AAF"};
        armour[] = {"I_APC_tracked_03_cannon_F", "I_APC_Wheeled_03_cannon_F", "CUP_I_M113_AAF", "CUP_I_M113_AAF"};
        ah[] = {"I_Heli_light_03_F"};
    };

    class MNP_MIL_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_Militia_Soldier_O", "MNP_Militia_Soldier_AR", "MNP_Militia_Soldier_F", "MNP_Militia_Soldier_RAT", "MNP_Militia_Soldier_MG", "MNP_Militia_Soldier_AR", "MNP_Militia_Soldier_RAT", "MNP_Militia_Soldier_AR", "MNP_Militia_Soldier_RAT"};
        crewmen[] = {"MNP_Militia_Soldier_F", "MNP_Militia_Soldier_O"};
        pilots[]= {"MNP_Militia_Soldier_F"};
        technicals[] = {"CUP_B_LR_MG_GB_W", "CUP_O_UAZ_MG_CHDKZ", "CUP_I_Datsun_PK", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_CHDKZ", "CUP_I_Ural_ZU23_NAPA"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class MNP_MIL_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_Militia_Soldier_DO", "MNP_Militia_Soldier_DAR", "MNP_Militia_Soldier_DF", "MNP_Militia_Soldier_DRAT", "MNP_Militia_Soldier_DMG", "MNP_Militia_Soldier_DAR", "MNP_Militia_Soldier_DRAT", "MNP_Militia_Soldier_DAR", "MNP_Militia_Soldier_DRAT"};
        crewmen[] = {"MNP_Militia_Soldier_DF", "MNP_Militia_Soldier_DO"};
        pilots[]= {"MNP_Militia_Soldier_DF"};
        technicals[] = {"CUP_B_LR_MG_GB_W", "CUP_O_UAZ_MG_CHDKZ", "CUP_I_Datsun_PK", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_CHDKZ", "CUP_I_Ural_ZU23_NAPA"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class MNP_NPA_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_DPM_Soldier_O", "MNP_DPM_Soldier_AR", "MNP_DPM_Soldier_D", "MNP_DPM_Soldier_AT", "MNP_DPM_Soldier_MG", "MNP_DPM_Soldier_AR", "MNP_DPM_Soldier_AT", "MNP_DPM_Soldier_AR", "MNP_DPM_Soldier_AT"};
        crewmen[] = {"MNP_DPM_Soldier_D", "MNP_DPM_Soldier_O"};
        pilots[]= {"MNP_DPM_Soldier_D"};
        technicals[] = {"CUP_B_LR_MG_GB_W", "CUP_O_UAZ_MG_CHDKZ", "CUP_I_Datsun_PK", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_CHDKZ", "CUP_I_Ural_ZU23_NAPA"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class MNP_NPA_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_SixCo_Soldier_O", "MNP_SixCo_Soldier_AR", "MNP_SixCo_Soldier_D", "MNP_SixCo_Soldier_AT", "MNP_SixCo_Soldier_MG", "MNP_SixCo_Soldier_AR", "MNP_SixCo_Soldier_AT", "MNP_SixCo_Soldier_AR", "MNP_SixCo_Soldier_AT"};
        crewmen[] = {"MNP_SixCo_Soldier_D", "MNP_SixCo_Soldier_O"};
        pilots[]= {"MNP_SixCo_Soldier_D"};
        technicals[] = {"CUP_B_LR_MG_GB_W", "CUP_O_UAZ_MG_CHDKZ", "CUP_I_Datsun_PK", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_CHDKZ", "CUP_I_Ural_ZU23_NAPA"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class MNP_IRE_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_Irish_Soldier_S", "MNP_Irish_Soldier_AR", "MNP_Irish_Soldier_F", "MNP_Irish_Soldier_RAT", "MNP_Irish_Soldier_MG", "MNP_Irish_Soldier_AR", "MNP_Irish_Soldier_RAT", "MNP_Irish_Soldier_AR", "MNP_Irish_Soldier_RAT"};
        crewmen[] = {"MNP_Irish_Soldier_F", "MNP_Irish_Soldier_S"};
        pilots[]= {"MNP_Irish_Soldier_F"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_GMG_GB_W", "CUP_B_RG31_M2_OD_USMC", "CUP_B_RG31_Mk19_OD_USMC"};
        armour[] = {"I_APC_tracked_03_cannon_F", "I_MBT_03_cannon_F"};
        ah[] = {"I_Heli_light_03_F"};
    };

    class MNP_IRE_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_Irish_Soldier_DS", "MNP_Irish_Soldier_DAR", "MNP_Irish_Soldier_D", "MNP_Irish_Soldier_DRAT", "MNP_Irish_Soldier_DMG", "MNP_Irish_Soldier_DAR", "MNP_Irish_Soldier_DRAT", "MNP_Irish_Soldier_DAR", "MNP_Irish_Soldier_DRAT"};
        crewmen[] = {"MNP_Irish_Soldier_D", "MNP_Irish_Soldier_DS"};
        pilots[]= {"MNP_Irish_Soldier_D"};
        technicals[] = {"CUP_B_LR_Special_GMG_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"I_APC_tracked_03_cannon_F", "I_MBT_03_cannon_F"};
        ah[] = {"I_Heli_light_03_F"};
    };

    class MNP_NZ {
        side = "resistance";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_NZ_Soldier_O", "MNP_NZ_Soldier_AR", "MNP_NZ_Soldier_F", "MNP_NZ_Soldier_AT", "MNP_NZ_Soldier_MG", "MNP_NZ_Soldier_AR", "MNP_NZ_Soldier_AT", "MNP_NZ_Soldier_AR", "MNP_NZ_Soldier_AT"};
        crewmen[] = {"MNP_NZ_Soldier_F", "MNP_NZ_Soldier_O"};
        pilots[]= {"MNP_NZ_Soldier_F"};
        technicals[] = {"I_MRAP_03_hmg_F"};
        armour[] = {"I_APC_tracked_03_cannon_F", "I_MBT_03_cannon_F"};
        ah[] = {"CUP_B_AH1_MR_BAF"};
    };

    class MNP_FIN_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_FIN_Soldier_O", "MNP_FIN_Soldier_AR", "MNP_FIN_Soldier_F", "MNP_FIN_Soldier_AT", "MNP_FIN_Soldier_MG", "MNP_FIN_Soldier_AR", "MNP_FIN_Soldier_AT", "MNP_FIN_Soldier_AR", "MNP_FIN_Soldier_AT"};
        crewmen[] = {"MNP_FIN_Soldier_F", "MNP_FIN_Soldier_O"};
        pilots[]= {"MNP_FIN_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_FIN_SN {
        side = "resistance";
        camouflage[] = {"snow"};
        infantry[] = {"MNP_AFIN_Soldier_O", "MNP_AFIN_Soldier_AR", "MNP_AFIN_Soldier_F", "MNP_AFIN_Soldier_AT", "MNP_AFIN_Soldier_MG", "MNP_AFIN_Soldier_AR", "MNP_AFIN_Soldier_AT", "MNP_AFIN_Soldier_AR", "MNP_AFIN_Soldier_AT"};
        crewmen[] = {"MNP_AFIN_Soldier_F", "MNP_AFIN_Soldier_O"};
        pilots[]= {"MNP_AFIN_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_NOR_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_NOR_Soldier_O", "MNP_NOR_Soldier_AR", "MNP_NOR_Soldier_F", "MNP_NOR_Soldier_AT", "MNP_NOR_Soldier_MG", "MNP_NOR_Soldier_AR", "MNP_NOR_Soldier_AT", "MNP_NOR_Soldier_AR", "MNP_NOR_Soldier_AT"};
        crewmen[] = {"MNP_NOR_Soldier_F", "MNP_NOR_Soldier_O"};
        pilots[]= {"MNP_NOR_Soldier_F"};
        technicals[] = {"CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GL_GER_Wdl"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "I_MBT_03_cannon_F"};
        ah[] = {"CUP_B_UH1Y_GUNSHIP_USMC"};
    };

    class MNP_NOR_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_NOR_D_Soldier_O", "MNP_NOR_D_Soldier_AR", "MNP_NOR_D_Soldier_F", "MNP_NOR_D_Soldier_AT", "MNP_NOR_D_Soldier_MG", "MNP_NOR_D_Soldier_AR", "MNP_NOR_D_Soldier_AT", "MNP_NOR_D_Soldier_AR", "MNP_NOR_D_Soldier_AT"};
        crewmen[] = {"MNP_NOR_D_Soldier_F", "MNP_NOR_D_Soldier_O"};
        pilots[]= {"MNP_NOR_D_Soldier_F"};
        technicals[] = {"CUP_B_Dingo_GL_GER_Des", "CUP_B_Dingo_GER_Des", "CUP_B_Dingo_GER_Des"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "I_MBT_03_cannon_F"};
        ah[] = {"CUP_B_UH1Y_GUNSHIP_USMC"};
    };

    class CUP_RACS_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_I_RACS_SL", "CUP_I_RACS_MMG", "CUP_I_RACS_Soldier", "CUP_I_RACS_Soldier", "CUP_I_RACS_Soldier", "CUP_I_RACS_MMG", "CUP_I_RACS_Soldier_MAT", "CUP_I_RACS_Soldier", "CUP_I_RACS_Soldier_MAT"};
        crewmen[] = {"CUP_I_RACS_Soldier", "CUP_I_RACS_Engineer"};
        pilots[]= {"CUP_B_RACS_Pilot"};
        technicals[] = {"CUP_I_LR_MG_RACS"};
        armour[] = {"CUP_I_M113_RACS", "CUP_I_M113_RACS", "CUP_I_AAV_RACS", "CUP_I_M60A3_RACS", "CUP_I_M60A3_RACS"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_TK_LOC {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_I_TK_GUE_Commander", "CUP_I_TK_GUE_Soldier_AR", "CUP_I_TK_GUE_Soldier", "CUP_I_TK_GUE_Soldier_M16A2", "CUP_I_TK_GUE_Guerilla_Enfield", "CUP_I_TK_GUE_Soldier_MG", "CUP_I_TK_GUE_Soldier_AT", "CUP_I_TK_GUE_Soldier_M16A2", "CUP_I_TK_GUE_Soldier_AT"};
        crewmen[] = {"CUP_I_TK_GUE_Soldier", "CUP_I_TK_GUE_Soldier_TL"};
        pilots[]= {"CUP_I_TK_GUE_Soldier"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_T34_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_I_T55_TK_GUE"};
        ah[] = {"CUP_I_Mi24_D_ION"};
    };

    class CUP_NAPA_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_I_GUE_Officer", "CUP_I_GUE_Soldier_AR", "CUP_I_GUE_Soldier_AKM", "CUP_I_GUE_Soldier_AKS74", "CUP_I_GUE_Soldier_AKSU", "CUP_I_GUE_Soldier_MG", "CUP_I_GUE_Soldier_AT", "CUP_I_GUE_Soldier_AR", "CUP_I_GUE_Soldier_AT"};
        crewmen[] = {"CUP_I_GUE_Soldier_AKM", "CUP_I_GUE_Officer"};
        pilots[]= {"CUP_I_GUE_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_T34_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_I_Mi24_D_ION"};
    };

    class SYND_BANDIT {
        side = "resistance";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"I_C_Soldier_Bandit_6_F", "I_C_Soldier_Bandit_3_F", "I_C_Soldier_Bandit_4_F", "I_C_Soldier_Bandit_2_F", "I_C_Soldier_Bandit_7_F", "I_C_Soldier_Bandit_3_F", "I_C_Soldier_Bandit_2_F", "I_C_Soldier_Bandit_5_F", "I_C_Soldier_Bandit_2_F"};
        crewmen[] = {"I_C_Soldier_Bandit_1_F", "I_C_Soldier_Bandit_8_F"};
        pilots[]= {"I_C_Pilot_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU", "B_G_Offroad_01_armed_F", "B_G_Offroad_01_armed_F"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_T34_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class SYND_REBEL {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"I_C_Soldier_Para_6_F", "I_C_Soldier_Para_4_F", "I_C_Soldier_Para_4_F", "I_C_Soldier_Para_4_F", "I_C_Soldier_Para_4_F", "I_C_Soldier_Para_4_F", "I_C_Soldier_Para_7_F", "I_C_Soldier_Para_2_F", "I_C_Soldier_Para_2_F"};
        crewmen[] = {"I_C_Soldier_Para_2_F", "I_C_Soldier_Para_2_F"};
        pilots[]= {"I_C_Helipilot_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU", "B_G_Offroad_01_armed_F", "B_G_Offroad_01_armed_F"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_T34_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class IF44_USA_WD {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"LIB_US_first_lieutenant", "LIB_US_mgunner", "LIB_US_rifleman", "LIB_US_grenadier", "LIB_US_smgunner", "LIB_US_mgunner", "LIB_US_grenadier", "LIB_US_mgunner", "LIB_US_AT_soldier", "LIB_US_rifleman", "LIB_US_rifleman", "LIB_US_rifleman", "LIB_US_FC_rifleman", "LIB_US_FC_rifleman"};
        crewmen[] = {"LIB_US_tank_crew", "LIB_US_tank_sergeant"};
        pilots[]= {"LIB_US_tank_sergeant"};
        technicals[] = {"LIB_US_Scout_M3_FFV", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M4A3_75"};
        ah[] = {};
    };

    class IF44_USA_SN {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"LIB_US_first_lieutenant_w", "LIB_US_mgunner_w", "LIB_US_rifleman_w", "LIB_US_grenadier_w", "LIB_US_smgunner_w", "LIB_US_mgunner_w", "LIB_US_grenadier_w", "LIB_US_mgunner_w", "LIB_US_AT_soldier_w", "LIB_US_rifleman_w", "LIB_US_rifleman_w", "LIB_US_rifleman_w", "LIB_US_FC_rifleman_w", "LIB_US_FC_rifleman_w"};
        crewmen[] = {"LIB_US_tank_crew", "LIB_US_tank_sergeant"};
        pilots[]= {"LIB_US_tank_sergeant"};
        technicals[] = {"LIB_US_Scout_M3_FFV", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M4A3_75"};
        ah[] = {};
    };

    class IF44_POL_WD {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"LIB_WP_Strzelec", "LIB_WP_Strzelec", "LIB_WP_Strzelec", "LIB_WP_Strzelec", "LIB_WP_Strzelec", "LIB_WP_Strzelec", "LIB_WP_Sierzant", "LIB_WP_Sierzant", "LIB_WP_AT_grenadier", "LIB_WP_AT_grenadier", "LIB_WP_Mgunner", "LIB_WP_Stggunner", "LIB_WP_Starszy_strzelec", "LIB_WP_Starszy_strzelec"};
        crewmen[] = {"LIB_WP_Strzelec", "LIB_WP_Strzelec"};
        pilots[]= {"LIB_WP_Strzelec"};
        technicals[] = {"LIB_Kfz1_MG42"};
        armour[] = {"LIB_StuG_III_G"};
        ah[] = {};
    };

    class CUP_CDF_DES {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_CDF_Soldier_DST", "CUP_B_CDF_Soldier_AR_DST", "CUP_B_CDF_Soldier_MG_DST", "CUP_B_CDF_Soldier_LAT_DST", "CUP_B_CDF_Soldier_GL_DST", "CUP_B_CDF_Soldier_DST", "CUP_B_CDF_Soldier_AR_DST", "CUP_B_CDF_Soldier_LAT_DST", "CUP_B_CDF_Soldier_DST"};
        crewmen[] = {"CUP_B_CDF_Crew_DST", "CUP_B_CDF_Engineer_DST"};
        pilots[]= {"CUP_B_CDF_Pilot_DST"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_BRDM2_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BTR60_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_T72_CDF"};
        ah[] = {"CUP_I_Mi24_D_UN"};
    };

    class CUP_CDF_FOR {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_CDF_Soldier_FST", "CUP_B_CDF_Soldier_AR_FST", "CUP_B_CDF_Soldier_MG_FST", "CUP_B_CDF_Soldier_LAT_FST", "CUP_B_CDF_Soldier_GL_FST", "CUP_B_CDF_Soldier_FST", "CUP_B_CDF_Soldier_AR_FST", "CUP_B_CDF_Soldier_LAT_FST", "CUP_B_CDF_Soldier_FST"};
        crewmen[] = {"CUP_B_CDF_Crew_FST", "CUP_B_CDF_Engineer_FST"};
        pilots[]= {"CUP_B_CDF_Pilot_FST"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_BRDM2_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BTR60_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_T72_CDF"};
        ah[] = {"CUP_I_Mi24_D_UN"};
    };

    class CUP_CDF_MOU {
        side = "west";
        camouflage[] = {"desert", "woodland"};
        infantry[] = {"CUP_B_CDF_Soldier_MNT", "CUP_B_CDF_Soldier_AR_MNT", "CUP_B_CDF_Soldier_MG_MNT", "CUP_B_CDF_Soldier_LAT_MNT", "CUP_B_CDF_Soldier_GL_MNT", "CUP_B_CDF_Soldier_MNT", "CUP_B_CDF_Soldier_AR_MNT", "CUP_B_CDF_Soldier_LAT_MNT", "CUP_B_CDF_Soldier_MNT"};
        crewmen[] = {"CUP_B_CDF_Crew_MNT", "CUP_B_CDF_Engineer_MNT"};
        pilots[]= {"CUP_B_CDF_Pilot_MNT"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_BRDM2_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BTR60_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_T72_CDF"};
        ah[] = {"CUP_I_Mi24_D_UN"};
    };

    class CUP_RACS_MECH {
        side = "resistance";
        camouflage[] = {"desert", "woodland"};
        infantry[] = {"CUP_I_RACS_SL_Mech", "CUP_I_RACS_MMG_Mech", "CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_MMG_Mech", "CUP_I_RACS_Soldier_MAT_Mech", "CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_Soldier_MAT_Mech"};
        crewmen[] = {"CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_Engineer_Mech"};
        pilots[]= {"CUP_B_RACS_Pilot"};
        technicals[] = {"CUP_I_LR_MG_RACS"};
        armour[] = {"CUP_I_M113_RACS", "CUP_I_M113_RACS", "CUP_I_AAV_RACS", "CUP_I_M60A3_RACS", "CUP_I_M60A3_RACS"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_RACS_URB {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_I_RACS_SL_Urban", "CUP_I_RACS_MMG_Urban", "CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_MMG_Urban", "CUP_I_RACS_Soldier_MAT_Urban", "CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_Soldier_MAT_Urban"};
        crewmen[] = {"CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_Engineer_Urban"};
        pilots[]= {"CUP_B_RACS_Pilot"};
        technicals[] = {"CUP_I_LR_MG_RACS"};
        armour[] = {"CUP_I_M113_RACS", "CUP_I_M113_RACS", "CUP_I_AAV_RACS", "CUP_I_M60A3_RACS", "CUP_I_M60A3_RACS"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_SLA_DE {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_O_sla_Soldier_SL_desert", "CUP_O_sla_soldier_desert", "CUP_O_sla_soldier_desert", "CUP_O_sla_Soldier_LAT_desert", "CUP_O_sla_Soldier_GL_desert", "CUP_O_sla_Soldier_AR_desert", "CUP_O_sla_Soldier_AT_desert", "CUP_O_sla_Soldier_AR_desert", "CUP_O_sla_Soldier_AT_desert", "CUP_O_sla_Soldier_MG_desert"};
        crewmen[] = {"CUP_O_sla_soldier_desert", "CUP_O_sla_Soldier_SL_desert"};
        pilots[]= {"CUP_O_sla_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_AGS30_SLA", "CUP_O_UAZ_SPG9_SLA"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_O_T55_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        ah[] = {"CUP_O_Mi24_D_SLA"};
    };

    class CUP_USMC_FROG_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_USMC_Soldier_GL_FROG_WDL", "CUP_B_USMC_Soldier_FROG_WDL", "CUP_B_USMC_Soldier_FROG_WDL", "CUP_B_USMC_Soldier_TL_FROG_WDL", "CUP_B_USMC_Soldier_FROG_MG_WDL", "CUP_B_USMC_Soldier_AR_FROG_WDL", "CUP_B_USMC_Soldier_LAT_FROG_WDL", "CUP_B_USMC_Soldier_AR_FROG_WDL", "CUP_B_USMC_Soldier_LAT_FROG_WDL"};
        crewmen[] = {"CUP_B_USMC_Crewman_FROG_WDL"};
        pilots[]= {"CUP_B_USMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_MK19_USMC", "CUP_B_RG31_Mk19_OD_USMC", "CUP_B_RG31_M2_OD_USMC"};
        armour[] = {"CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_Woodland_USMC"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_USMC_FROG_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_USMC_Soldier_GL_FROG_DES", "CUP_B_USMC_Soldier_FROG_DES", "CUP_B_USMC_Soldier_FROG_DES", "CUP_B_USMC_Soldier_TL_FROG_DES", "CUP_B_USMC_Soldier_MG_FROG_DES", "CUP_B_USMC_Soldier_AR_FROG_DES", "CUP_B_USMC_Soldier_LAT_FROG_DES", "CUP_B_USMC_Soldier_AR_FROG_DES", "CUP_B_USMC_Soldier_LAT_FROG_DES"};
        crewmen[] = {"CUP_B_USMC_Crewman_FROG_DES"};
        pilots[]= {"CUP_B_USMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_RG31_Mk19_USMC", "CUP_B_RG31_M2_USMC"};
        armour[] = {"CUP_B_LAV25_desert_USMC", "CUP_B_LAV25_desert_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_DES_USMC"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_ION_PMC_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_I_PMC_Contractor1", "CUP_I_PMC_Contractor2", "CUP_I_PMC_Bodyguard_M4", "CUP_I_PMC_Medic", "CUP_I_PMC_Soldier_MG", "CUP_I_PMC_Soldier_MG_PKM", "CUP_I_PMC_Soldier_AT", "CUP_I_PMC_Soldier_GL_M16A2", "CUP_I_PMC_Soldier_M4A3"};
        crewmen[] = {"CUP_I_PMC_Contractor2", "CUP_I_PMC_Bodyguard_M4"};
        pilots[]= {"CUP_I_PMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_NATO_T", "CUP_B_HMMWV_MK19_NATO_T", "CUP_B_HMMWV_M2_GPK_NATO_T", "CUP_B_HMMWV_SOV_M2_NATO_T", "CUP_B_HMMWV_SOV_NATO_T"};
        armour[] = {"CUP_B_M1126_ICV_M2_Woodland_Slat", "CUP_B_M1126_ICV_M2_Woodland_Slat", "CUP_B_M1126_ICV_MK19_Woodland_Slat", "CUP_B_M1128_MGS_Woodland_Slat"};
        ah[] = {"CUP_I_Mi24_Mk4_AT_ION"};
    };

    class CUP_ION_PMC_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_I_PMC_Contractor1", "CUP_I_PMC_Contractor2", "CUP_I_PMC_Bodyguard_M4", "CUP_I_PMC_Medic", "CUP_I_PMC_Soldier_MG", "CUP_I_PMC_Soldier_MG_PKM", "CUP_I_PMC_Soldier_AT", "CUP_I_PMC_Soldier_GL_M16A2", "CUP_I_PMC_Soldier_M4A3"};
        crewmen[] = {"CUP_I_PMC_Contractor2", "CUP_I_PMC_Bodyguard_M4"};
        pilots[]= {"CUP_I_PMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_SOV_M2_USA", "CUP_B_HMMWV_SOV_USA"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_MK19_Desert_Slat", "CUP_B_M1128_MGS_Desert_Slat"};
        ah[] = {"CUP_I_Mi24_Mk4_AT_ION"};
    };

    class CUP_ION_PMC_SN {
        side = "resistance";
        camouflage[] = {"snow"};
        infantry[] = {"CUP_I_PMC_Winter_Soldier_MG", "CUP_I_PMC_Winter_Soldier_MG_PKM", "CUP_I_PMC_Winter_Soldier_AT", "CUP_I_PMC_Winter_Soldier", "CUP_I_PMC_Winter_Soldier_GL", "CUP_I_PMC_Winter_Soldier_TL", "CUP_I_PMC_Winter_Soldier", "CUP_I_PMC_Winter_Soldier", "CUP_I_PMC_Winter_Soldier"};
        crewmen[] = {"CUP_I_PMC_Winter_Engineer", "CUP_I_PMC_Winter_Crew"};
        pilots[]= {"CUP_I_PMC_Winter_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_NATO_T", "CUP_B_HMMWV_MK19_NATO_T", "CUP_B_HMMWV_M2_GPK_NATO_T", "CUP_B_HMMWV_SOV_M2_NATO_T", "CUP_B_HMMWV_SOV_NATO_T"};
        armour[] = {"CUP_B_M1126_ICV_M2_Woodland_Slat", "CUP_B_M1126_ICV_M2_Woodland_Slat", "CUP_B_M1126_ICV_MK19_Woodland_Slat", "CUP_B_M1128_MGS_Woodland_Slat"};
        ah[] = {"CUP_I_Mi24_Mk4_AT_ION"};
    };

};
