class UnitTemplates {
    class Base {
        side = "civilian";
        camouflage[] = {"woodland", "desert", "snow"};
        infantry[] = {"Hen_random_F", "Cock_random_F", "Goat_random_F", "Sheep_random_F", "Salema_F", "Mackerel_F", "Fin_random_F", "Alsatian_Random_F", "C_Orestes", "C_Nikos"};
        crewmen[] = {"Hen_random_F", "Cock_random_F", "Goat_random_F", "Sheep_random_F", "Salema_F", "Mackerel_F", "Fin_random_F", "Alsatian_Random_F", "C_Orestes", "C_Nikos"};
        pilots[] = {};
        technicals[] = {"C_Van_01_box_F"};
        armour[] = {"C_Van_01_box_F"};
        th[] = {"C_Van_01_box_F"};
        ah[] = {"C_Van_01_box_F"};
    };

    class NATO_WOODLAND {
        side = "west";
        camouflage[] = {};
        infantry[] = {"B_Soldier_SL_F", "B_soldier_AR_F", "B_Soldier_F", "B_Soldier_AT4_F", "B_HeavyGunner_F", "B_soldier_AR_F", "B_Soldier_AT4_F", "B_soldier_AR_F", "B_Soldier_AT4_F"};
        crewmen[] = {"B_crew_F", "B_engineer_F"};
        pilots[] = {"B_Helipilot_F"};
        technicals[] = {"B_MRAP_01_hmg_F"};
        armour[] = {"B_APC_Wheeled_01_cannon_F", "B_MBT_01_TUSK_F", "B_APC_Tracked_01_rcws_F"};
        th[] = {"B_Heli_Transport_01_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class NATO_JUNGLE {
        side = "west";
        camouflage[] = {};
        infantry[] = {"B_T_Soldier_SL_F", "B_T_Soldier_AR_F", "B_T_Soldier_F", "B_T_Soldier_AT4_F", "B_T_Soldier_TL_F", "B_T_Soldier_AR_F", "B_T_Soldier_AT4_F", "B_T_Soldier_AR_F", "B_T_Soldier_AT4_F"};
        crewmen[] = {"B_T_Crew_F", "B_T_Engineer_F"};
        pilots[] = {"B_T_Helipilot_F"};
        technicals[] = {"B_T_LSV_01_armed_F"};
        armour[] = {"B_T_APC_Wheeled_01_cannon_F", "B_T_MBT_01_TUSK_F", "B_APC_Tracked_01_rcws_F"};
        th[] = {"B_Heli_Transport_01_camo_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class NATO_CBRN {
        side = "west";
        camouflage[] = {};
        infantry[] = {"skn_b_nbc_sl", "skn_b_nbc_AR", "skn_b_nbc_rf", "skn_b_nbc_AT4", "skn_b_nbc_tl", "skn_b_nbc_AR", "skn_b_nbc_AT4", "skn_b_nbc_AR", "skn_b_nbc_AT4"};
        crewmen[] = {"skn_b_nbc_crew", "skn_b_nbc_eng"};
        pilots[] = {"skn_b_nbc_crew"};
        technicals[] = {"B_MRAP_01_hmg_F"};
        armour[] = {"B_APC_Wheeled_01_cannon_F", "B_MBT_01_TUSK_F", "B_APC_Tracked_01_rcws_F"};
        th[] = {"B_Heli_Transport_01_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class CTRG_JUNGLE {
        side = "west";
        camouflage[] = {};
        infantry[] = {"B_CTRG_Soldier_JTAC_tna_F", "B_CTRG_Soldier_AR_tna_F", "B_CTRG_Soldier_tna_F", "B_CTRG_Soldier_tna_F", "B_CTRG_Soldier_tna_F", "B_CTRG_Soldier_AR_tna_F", "B_CTRG_Soldier_AT4_tna_F", "B_CTRG_Soldier_AR_tna_F", "B_CTRG_Soldier_AT4_tna_F"};
        crewmen[] = {"B_CTRG_Soldier_tna_F"};
        pilots[] = {"B_T_Helipilot_F"};
        technicals[] = {"B_T_LSV_01_armed_F"};
        armour[] = {"B_T_APC_Wheeled_01_cannon_F", "B_T_MBT_01_TUSK_F", "B_APC_Tracked_01_rcws_F"};
        th[] = {"B_Heli_Transport_01_camo_F"};
        ah[] = {"B_Heli_Attack_01_F"};
    };

    class MNP_USMC_SN {
        side = "west";
        camouflage[] = {"snow"};
        infantry[] = {"MNP_USMCA_Soldier_O", "MNP_USMCA_Soldier_O", "MNP_USMCA_Soldier_F", "MNP_USMCA_Soldier_F", "MNP_USMCA_Soldier_AT", "MNP_USMCA_Soldier_AR", "MNP_USMCA_Soldier_MG", "MNP_USMCA_Soldier_MD"};
        crewmen[] = {"MNP_USMCA_Soldier_F", "MNP_USMCA_Soldier_F"};
        pilots[] = {"MNP_USMCA_Soldier_F"};
        technicals[] = {"CUP_B_HMMWV_M2_NATO_T", "CUP_B_HMMWV_MK19_NATO_T", "CUP_B_HMMWV_M2_GPK_NATO_T", "CUP_B_HMMWV_SOV_M2_NATO_T", "CUP_B_HMMWV_SOV_NATO_T"};
        armour[] = {"CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_Woodland_USMC", "CUP_B_M1A2_TUSK_MG_USMC"};
        th[] = {"CUP_B_UH60S_USN"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class MNP_IDF {
        side = "west";
        camouflage[] = {"desert", "woodland"};
        infantry[] = {"MNP_ISR_O", "MNP_ISR_O", "MNP_ISR_A", "MNP_ISR_A", "MNP_ISR_AT", "MNP_ISR_AR", "MNP_ISR_MG", "MNP_ISR_MD"};
        crewmen[] = {"MNP_ISR_A", "MNP_ISR_A"};
        pilots[] = {"MNP_ISR_A"};
        technicals[] = {"CUP_B_HMMWV_M2_NATO_T", "CUP_B_HMMWV_MK19_NATO_T", "CUP_B_HMMWV_M2_GPK_NATO_T", "CUP_B_HMMWV_SOV_M2_NATO_T", "CUP_B_HMMWV_SOV_NATO_T"};
        armour[] = {"B_MBT_O1_cannon_F", "B_MBT_01_TUSK_F", "B_APC_Tracked_01_rcws_F", "B_APC_Tracked_01_rcws_F", "B_APC_Tracked_01_rcws_F"};
        th[] = {"CUP_B_CH53E_USMC"};
        ah[] = {"CUP_B_AH64D_DL_USA"};
    };

    class MNP_US_ACU {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_USACU_Soldier_O", "MNP_USACU_Soldier_O", "MNP_USACU_Soldier_F", "MNP_USACU_Soldier_F", "MNP_USACU_Soldier_AT", "MNP_USACU_Soldier_AR", "MNP_USACU_Soldier_MG", "MNP_USACU_Soldier_M"};
        crewmen[] = {"MNP_USACU_Soldier_F", "MNP_USACU_Soldier_F"};
        pilots[] = {"MNP_USACU_Soldier_F"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert", "CUP_B_M1126_ICV_M2_Desert", "CUP_B_M1126_ICV_MK19_Desert", "CUP_B_M1128_MGS_Desert", "CUP_B_M2Bradley_USA_D", "CUP_B_M2Bradley_USA_D", "CUP_B_M1A1_DES_US_Army", "CUP_B_M1A2_TUSK_MG_DES_US_Army"};
        th[] = {"CUP_B_UH60M_US"};
        ah[] = {"CUP_B_AH64D_DL_USA"};
    };

    class MNP_US_MC {
        side = "west";
        camouflage[] = {};
        infantry[] = {"", "", "", "", "", "", "", "", "", ""};
        crewmen[] = {"", ""};
        pilots[] = {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_SOV_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_MK19_Desert_Slat", "CUP_B_M1128_MGS_Desert_Slat", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M1A2_TUSK_MG_DES_US_Army"};
        th[] = {"CUP_B_UH60M_US"};
        ah[] = {"CUP_B_AH64D_DL_USA"};
    };

    class MNP_US_RAN_MC {
        side = "west";
        camouflage[] = {};
        infantry[] = {"", "", "", "", "", "", "", "", ""};
        crewmen[] = {"", ""};
        pilots[] = {""};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_SOV_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_M2_Desert_Slat", "CUP_B_M1126_ICV_MK19_Desert_Slat", "CUP_B_M1128_MGS_Desert_Slat", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M2A3Bradley_USA_D", "CUP_B_M1A2_TUSK_MG_DES_US_Army"};
        th[] = {"CUP_B_UH60M_US"};
        ah[] = {"CUP_B_AH64D_DL_USA"};
    };

    class MNP_GE_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_GER_Soldier_S", "MNP_GER_Soldier_S", "MNP_GER_Soldier_F", "MNP_GER_Soldier_F", "MNP_GER_Soldier_AT", "MNP_GER_Soldier_AR", "MNP_GER_Soldier_MG", "MNP_GER_Soldier_MED"};
        crewmen[] = {"MNP_GER_Soldier_F", "MNP_GER_Soldier_F"};
        pilots[] = {"MNP_GER_Soldier_F"};
        technicals[] = {"CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GL_GER_Wdl"};
        armour[] = {"CUP_B_Leopard2A6_GER"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK"};
    };

    class MNP_GE_DE {
        side = "west";
        camouflage[] = {"desert", "snow"};
        infantry[] = {"MNP_GER_Soldier_DS", "MNP_GER_Soldier_DS", "MNP_GER_Soldier_DF", "MNP_GER_Soldier_DF", "MNP_GER_Soldier_AT_D", "MNP_GER_Soldier_AR_D", "MNP_GER_Soldier_MG_D", "MNP_GER_Soldier_MED_D"};
        crewmen[] = {"MNP_GER_Soldier_DF", "MNP_GER_Soldier_DF"};
        pilots[] = {"MNP_GER_Soldier_DF"};
        technicals[] = {"CUP_B_Dingo_GL_GER_Des", "CUP_B_Dingo_GER_Des", "CUP_B_Dingo_GER_Des"};
        armour[] = {"CUP_B_Leopard2A6_GER"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class MNP_CA_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_Canada_Soldier_S", "MNP_Canada_Soldier_S", "MNP_Canada_Soldier_F", "MNP_Canada_Soldier_S", "MNP_Canada_Soldier_AT", "MNP_Canada_Soldier_AR", "MNP_Canada_Soldier_MG", "MNP_Canada_Soldier_M"};
        crewmen[] = {"MNP_Canada_Soldier_F", "MNP_Canada_Soldier_F"};
        pilots[] = {"MNP_Canada_Soldier_F"};
        technicals[] = {"CUP_B_RG31_M2_OD_USMC", "CUP_B_RG31_Mk19_OD_USMC"};
        armour[] = {"ARK_M113_CAN", "ARK_LEO2_CAN"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class MNP_CA_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_Canada_Soldier_DS", "MNP_Canada_Soldier_DS", "MNP_Canada_Soldier_DF", "MNP_Canada_Soldier_DF", "MNP_Canada_Soldier_DAT", "MNP_Canada_Soldier_DAR", "MNP_Canada_Soldier_DMG", "MNP_Canada_Soldier_DM"};
        crewmen[] = {"MNP_Canada_Soldier_DF", "MNP_Canada_Soldier_DF"};
        pilots[] = {"MNP_Canada_Soldier_DF"};
        technicals[] = {"CUP_B_RG31_M2_OD_USMC", "CUP_B_RG31_Mk19_OD_USMC"};
        armour[] = {"ARK_M113_CAN", "ARK_LEO2_CAN"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class MNP_AUS {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_AUS_Soldier_S", "MNP_AUS_Soldier_S", "MNP_AUS_Soldier_F", "MNP_AUS_Soldier_F", "MNP_AUS_Soldier_AT", "MNP_AUS_Soldier_AR", "MNP_AUS_Soldier_MG", "MNP_AUS_Soldier_MD"};
        crewmen[] = {"MNP_AUS_Soldier_F", "MNP_AUS_Soldier_F"};
        pilots[] = {"MNP_AUS_Soldier_F"};
        technicals[] = {"ARK_LR_M2_AUS"};
        armour[] = {"ARK_M113_AUS", "ARK_LAV25M240_AUS", "ARK_M1A1_AUS"};
        th[] = {"ARK_MH60_AUS"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class MNP_AUS_AMCU {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_AMCU_Soldier_O", "MNP_AMCU_Soldier_O", "MNP_AMCU_Soldier_F", "MNP_AMCU_Soldier_F", "MNP_AMCU_Soldier_AT", "MNP_AMCU_Soldier_AR", "MNP_AMCU_Soldier_MG", "MNP_AMCU_Soldier_MD"};
        crewmen[] = {"MNP_AMCU_Soldier_F", "MNP_AMCU_Soldier_F"};
        pilots[] = {"MNP_AMCU_Soldier_F"};
        technicals[] = {"ARK_LR_M2_AUS"};
        armour[] = {"ARK_M113_AUS", "ARK_LAV25M240_AUS", "ARK_M1A1_AUS", "ARK_M1A1_AUS_TUSK"};
        th[] = {"ARK_MH60_AUS"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class MNP_ROK {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_ROK_Soldier_O", "MNP_ROK_Soldier_O", "MNP_ROK_Soldier_O", "MNP_ROK_Soldier_F", "MNP_ROK_Soldier_AT", "MNP_ROK_Soldier_AR", "MNP_ROK_Soldier_MG", "MNP_ROK_Soldier_M"};
        crewmen[] = {"MNP_ROK_Soldier_O", "MNP_ROK_Soldier_O"};
        pilots[] = {"MNP_ROK_Soldier_O"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M163_USA"};
        th[] = {"CUP_B_UH60S_USN"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class MNP_ROK_SEAL {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_ROKMC_O", "MNP_ROKMC_O", "MNP_ROKMC_A", "MNP_ROKMC_A", "MNP_ROKMC_AT", "MNP_ROKMC_AR", "MNP_ROKMC_MG", "MNP_ROKMC_MD"};
        crewmen[] = {"MNP_ROKMC_A", "MNP_ROKMC_A"};
        pilots[] = {"MNP_ROKMC_A"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M163_USA"};
        th[] = {"CUP_B_UH60S_USN"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class MNP_UKR {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_UKR_O", "MNP_UKR_O", "MNP_UKR_A", "MNP_UKR_A", "MNP_UKR_AT", "MNP_UKR_AR", "MNP_UKR_MG", "MNP_UKR_MD"};
        crewmen[] = {"MNP_UKR_A", "MNP_UKR_A"};
        pilots[] = {"MNP_UKR_A"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_BRDM2_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_BTR60_CDF", "CUP_B_MTLB_pk_CDF"};
        th[] = {"CUP_B_Mi17_CDF"};
        ah[] = {"CUP_B_Mi24_D_CDF"};
    };

    class MNP_IRG_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_US6co_Soldier_O", "MNP_US6co_Soldier_O", "MNP_US6co_Soldier_F", "MNP_US6co_Soldier_F", "MNP_US6co_Soldier_AT", "MNP_US6co_Soldier_AR", "MNP_US6co_Soldier_MG", "MNP_US6co_Soldier_MD"};
        crewmen[] = {"MNP_US6co_Soldier_F", "MNP_US6co_Soldier_F"};
        pilots[] = {"MNP_US6co_Soldier_F"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_HMMWV_SOV_M2_USA", "CUP_B_HMMWV_SOV_M2_USA", "CUP_B_HMMWV_SOV_USA"};
        armour[] = {"CUP_I_M60A3_RACS", "CUP_B_LAV25_desert_USMC", "CUP_I_AAV_RACS", "CUP_B_M113_desert_USA"};
        th[] = {"CUP_I_UH60L_RACS"};
        ah[] = {"CUP_I_AH6J_RACS"};
    };

    class MNP_IRG_WD {
        side = "west";
        camouflage[] = {};
        infantry[] = {"", "", "", "", "", "", "", ""};
        crewmen[] = {"", ""};
        pilots[] = {""};
        technicals[] = {"CUP_B_HMMWV_M2_NATO_T", "CUP_B_HMMWV_M2_NATO_T", "CUP_B_HMMWV_MK19_NATO_T", "CUP_B_HMMWV_SOV_M2_NATO_T", "CUP_B_HMMWV_SOV_M2_NATO_T", "CUP_B_HMMWV_SOV_NATO_T"};
        armour[] = {"CUP_B_M60A3_USMC", "CUP_B_LAV25M240_green", "CUP_B_AAV_USMC", "ARK_M113_USA_OD"};
        th[] = {"CUP_I_UH60L_RACS"};
        ah[] = {"CUP_I_AH6J_RACS"};
    };

    class CUP_USMC_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_USMC_Soldier_GL", "CUP_B_USMC_Soldier", "CUP_B_USMC_Soldier", "CUP_B_USMC_Soldier_TL", "CUP_B_USMC_Soldier_MG", "CUP_B_USMC_Soldier_AR", "CUP_B_USMC_Soldier_LAT", "CUP_B_USMC_Soldier_AR", "CUP_B_USMC_Soldier_LAT"};
        crewmen[] = {"CUP_B_USMC_Soldier"};
        pilots[] = {"CUP_B_USMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_MK19_USMC", "CUP_B_RG31_Mk19_OD_USMC", "CUP_B_RG31_M2_OD_USMC"};
        armour[] = {"CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_Woodland_USMC", "CUP_B_M1A2_TUSK_MG_USMC"};
        th[] = {"CUP_B_UH60S_USN"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_KSK_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_GER_Fleck_Soldier", "CUP_B_GER_Fleck_Soldier_MG", "CUP_B_GER_Fleck_Soldier_TL", "CUP_B_GER_Fleck_Soldier_TL", "CUP_B_GER_Fleck_Soldier_MG", "CUP_B_GER_Fleck_Soldier_MG", "CUP_B_GER_Fleck_Soldier_AT", "CUP_B_GER_Fleck_Soldier_MG", "CUP_B_GER_Fleck_Soldier_AT"};
        crewmen[] = {"CUP_B_GER_Fleck_Soldier_TL", "CUP_B_GER_Fleck_Soldier"};
        pilots[] = {"CUP_B_GER_Fleck_Soldier_TL"};
        technicals[] = {"CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GL_GER_Wdl"};
        armour[] = {"CUP_B_Leopard2A6_GER"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK"};
    };

    class CUP_KSK_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_GER_Soldier", "CUP_B_GER_Soldier_MG", "CUP_B_GER_Soldier_TL", "CUP_B_GER_Soldier_TL", "CUP_B_GER_Soldier_TL", "CUP_B_GER_Soldier_MG", "CUP_B_GER_Soldier_AT", "CUP_B_GER_Soldier_MG", "CUP_B_GER_Soldier_AT"};
        crewmen[] = {"CUP_B_GER_Soldier_TL", "CUP_B_GER_Soldier"};
        pilots[] = {"CUP_B_GER_Soldier_TL"};
        technicals[] = {"CUP_B_Dingo_GL_GER_Des", "CUP_B_Dingo_GER_Des", "CUP_B_Dingo_GER_Des"};
        armour[] = {"CUP_B_Leopard2A6_GER"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class CUP_BAF_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_BAF_Soldier_SL_WDL", "CUP_B_BAF_Soldier_WDL", "CUP_B_BAF_Soldier_WDL", "CUP_B_BAF_Soldier_TL_WDL", "CUP_B_BAF_Soldier_MG_WDL", "CUP_B_BAF_Soldier_AR_WDL", "CUP_B_BAF_Soldier_AT_WDL", "CUP_B_BAF_Soldier_AR_WDL", "CUP_B_BAF_Soldier_AT_WDL"};
        crewmen[] = {"CUP_B_BAF_Crew_WDL"};
        pilots[] = {"CUP_B_BAF_Pilot_WDL"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_Jackal2_L2A1_GB_W", "CUP_B_BAF_Coyote_L2A1_W", "CUP_B_Jackal2_GMG_GB_W", "CUP_B_Ridgback_LMG_GB_W"};
        armour[] = {"CUP_B_FV432_Bulldog_GB_W_RWS", "CUP_B_FV432_Bulldog_GB_W", "CUP_B_FV432_Bulldog_GB_W_RWS", "CUP_B_MCV80_GB_W_SLAT", "CUP_B_MCV80_GB_W", "CUP_B_Challenger2_Woodland_BAF"};
        th[] = {"CUP_B_CH47F_GB"};
        ah[] = {"CUP_B_AH1_BAF"};
    };

    class CUP_BAF_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_BAF_Soldier_SL_DDPM", "CUP_B_BAF_Soldier_DDPM", "CUP_B_BAF_Soldier_DDPM", "CUP_B_BAF_Soldier_TL_DDPM", "CUP_B_BAF_Soldier_MG_DDPM", "CUP_B_BAF_Soldier_AR_DDPM", "CUP_B_BAF_Soldier_AT_DDPM", "CUP_B_BAF_Soldier_AR_DDPM", "CUP_B_BAF_Soldier_AT_DDPM"};
        crewmen[] = {"CUP_B_BAF_Crew_DDPM"};
        pilots[] = {"CUP_B_BAF_Pilot_DDPM"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_Jackal2_L2A1_GB_D", "CUP_B_BAF_Coyote_L2A1_D", "CUP_B_Jackal2_GMG_GB_D", "CUP_B_Ridgback_LMG_GB_D"};
        armour[] = {"CUP_B_FV432_Bulldog_GB_D_RWS", "CUP_B_FV432_Bulldog_GB_D", "CUP_B_FV432_Bulldog_GB_D_RWS", "CUP_B_MCV80_GB_D_SLAT", "CUP_B_MCV80_GB_D", "CUP_B_Challenger2_Desert_BAF"};
        th[] = {"CUP_B_CH47F_GB"};
        ah[] = {"CUP_B_AH1_BAF"};
    };

    class CUP_BAF_MTP {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"CUP_B_BAF_Soldier_SL_MTP", "CUP_B_BAF_Soldier_MTP", "CUP_B_BAF_Soldier_MTP", "CUP_B_BAF_Soldier_TL_MTP", "CUP_B_BAF_Soldier_MG_MTP", "CUP_B_BAF_Soldier_AR_MTP", "CUP_B_BAF_Soldier_AT_MTP", "CUP_B_BAF_Soldier_AR_MTP", "CUP_B_BAF_Soldier_AT_MTP"};
        crewmen[] = {"CUP_B_BAF_Crew_MTP"};
        pilots[] = {"CUP_B_BAF_Pilot_MTP"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_Jackal2_L2A1_GB_D", "CUP_B_BAF_Coyote_L2A1_D", "CUP_B_Jackal2_GMG_GB_D", "CUP_B_Ridgback_LMG_GB_D"};
        armour[] = {"CUP_B_FV432_Bulldog_GB_D_RWS", "CUP_B_FV432_Bulldog_GB_D", "CUP_B_FV432_Bulldog_GB_D_RWS", "CUP_B_MCV80_GB_D_SLAT", "CUP_B_MCV80_GB_D", "CUP_B_Challenger2_2CD_BAF"};
        th[] = {"CUP_B_Merlin_HC3_Armed_GB"};
        ah[] = {"CUP_B_AH1_BAF"};
    };

    class CUP_US_ACU {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_US_Soldier_TL", "CUP_B_US_Soldier", "CUP_B_US_Soldier", "CUP_B_US_Soldier_TL", "CUP_B_US_Soldier_MG", "CUP_B_US_Soldier_AR", "CUP_B_US_Soldier_LAT", "CUP_B_US_Soldier_AR", "CUP_B_US_Soldier_LAT"};
        crewmen[] = {"CUP_B_US_Crew"};
        pilots[] = {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_M1126_ICV_M2_Desert", "CUP_B_M1126_ICV_M2_Desert", "CUP_B_M1126_ICV_MK19_Desert", "CUP_B_M1128_MGS_Desert", "CUP_B_M2Bradley_USA_D", "CUP_B_M2Bradley_USA_D", "CUP_B_M1A1_DES_US_Army", "CUP_B_M1A2_TUSK_MG_DES_US_Army"};
        th[] = {"CUP_B_UH60M_US"};
        ah[] = {"CUP_B_AH64D_DL_USA"};
    };

    class FIA_GUER {
        side = "west";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"B_G_Soldier_SL_F", "B_G_Soldier_AR_F", "B_G_Soldier_lite_F", "B_G_Soldier_RPG7_F", "B_G_Soldier_M_F", "B_G_Soldier_AR_F", "B_G_Soldier_RPG7_F", "B_G_Soldier_AR_F", "B_G_Soldier_RPG7_F"};
        crewmen[] = {"B_G_Soldier_F", "B_G_engineer_F"};
        pilots[] = {"B_G_Soldier_lite_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU", "B_G_Offroad_01_armed_F", "B_G_Offroad_01_armed_F"};
        armour[] = {"CUP_B_BTR60_FIA", "CUP_B_MTLB_pk_FIA", "CUP_I_T34_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        th[] = {"I_Heli_Transport_02_F"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class CSAT_WOODLAND {
        side = "east";
        camouflage[] = {};
        infantry[] = {"O_Soldier_SL_F", "O_Soldier_AR_F", "O_Soldier_lite_F", "O_Soldier_RPG18_F", "O_support_MG_F", "O_Soldier_AR_F", "O_Soldier_RPG18_F", "O_Soldier_AR_F", "O_Soldier_LAT_F"};
        crewmen[] = {"O_crew_F", "O_engineer_F"};
        pilots[] = {"O_Helipilot_F"};
        technicals[] = {"O_MRAP_02_hmg_F", "O_LSV_02_armed_F", "O_LSV_02_armed_F"};
        armour[] = {"O_APC_Tracked_02_cannon_F", "O_MBT_02_cannon_F", "O_APC_Wheeled_02_rcws_F"};
        th[] = {"O_Heli_Light_02_F"};
        ah[] = {"O_Heli_Attack_02_F"};
    };

    class CSAT_CBRN {
        side = "east";
        camouflage[] = {};
        infantry[] = {"skn_o_nbc_sl", "skn_o_nbc_ar", "skn_o_nbc_rf", "skn_o_nbc_RPG18", "skn_o_nbc_a", "skn_o_nbc_ar", "skn_o_nbc_RPG18", "skn_o_nbc_ar", "skn_o_nbc_tl"};
        crewmen[] = {"skn_o_nbc_crew", "skn_o_nbc_eng"};
        pilots[] = {"skn_o_nbc_crew"};
        technicals[] = {"O_MRAP_02_hmg_F", "O_LSV_02_armed_F", "O_LSV_02_armed_F"};
        armour[] = {"O_APC_Tracked_02_cannon_F", "O_MBT_02_cannon_F", "O_APC_Wheeled_02_rcws_F"};
        th[] = {"O_Heli_Light_02_unarmed_F"};
        ah[] = {"O_Heli_Attack_02_F"};
    };

    class CSAT_URBAN {
        side = "east";
        camouflage[] = {};
        infantry[] = {"O_soldierU_SL_F", "O_soldierU_AR_F", "O_soldierU_F", "O_soldierU_RPG18_F", "O_soldierU_M_F", "O_soldierU_AR_F", "O_soldierU_RPG18_F", "O_soldierU_AR_F", "O_soldierU_RPG18_F"};
        crewmen[] = {"O_soldierU_F", "O_engineer_U_F"};
        pilots[] = {"O_soldierU_TL_F"};
        technicals[] = {"O_MRAP_02_hmg_F", "O_LSV_02_armed_F", "O_LSV_02_armed_F"};
        armour[] = {"O_APC_Tracked_02_cannon_F", "O_MBT_02_cannon_F", "O_APC_Wheeled_02_rcws_F"};
        th[] = {"O_Heli_Light_02_v2_F"};
        ah[] = {"O_Heli_Attack_02_F"};
    };

    class CSAT_JUNGLE {
        side = "east";
        camouflage[] = {};
        infantry[] = {"O_T_Soldier_SL_F", "O_T_Soldier_AR_F", "O_T_Soldier_TL_F", "O_T_Soldier_RPG18_F", "O_T_Support_MG_F", "O_T_Soldier_AR_F", "O_T_Soldier_RPG18_F", "O_T_Soldier_AR_F", "O_T_Soldier_RPG18_F"};
        crewmen[] = {"O_T_Crew_F", "O_T_Engineer_F"};
        pilots[] = {"O_T_Pilot_F"};
        technicals[] = {"O_T_MRAP_02_hmg_ghex_F", "O_LSV_02_armed_F", "O_LSV_02_armed_F"};
        armour[] = {"O_T_APC_Tracked_02_cannon_ghex_F", "O_T_MBT_02_cannon_ghex_F", "O_T_APC_Wheeled_02_rcws_ghex_F"};
        th[] = {"O_Heli_Light_02_F"};
        ah[] = {"O_Heli_Attack_02_F"};
    };

    class MNP_OPF_F_SN {
        side = "east";
        camouflage[] = {"snow"};
        infantry[] = {"MNP_RU_Soldier_Arctic_O", "MNP_RU_Soldier_Arctic_O", "MNP_RU_Soldier_Arctic_F", "MNP_RU_Soldier_Arctic_F", "MNP_RU_Soldier_Arctic_AT", "MNP_RU_Soldier_Arctic_AR", "MNP_RU_Soldier_Arctic_MG", "MNP_RU_Soldier_Arctic_M"};
        crewmen[] = {"MNP_RU_Soldier_Arctic_F", "MNP_RU_Soldier_Arctic_F"};
        pilots[] = {"MNP_RU_Soldier_Arctic_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_MTLB_pk_Winter_RU", "CUP_O_BTR60_Winter_RU", "CUP_O_T72_RU", "CUP_O_GAZ_Vodnik_BPPU_RU"};
        th[] = {"O_Heli_Light_02_unarmed_F"};
        ah[] = {"CUP_O_Ka60_Blk_CSAT"};
    };

    class MNP_CH_UNI {
        side = "east";
        camouflage[] = {"woodland", "desert", "snow"};
        infantry[] = {"MNP_CN_Soldier_O", "MNP_CN_Soldier_O", "MNP_CN_Soldier_F", "MNP_CN_Soldier_F", "MNP_CN_Soldier_RAT", "MNP_CN_Soldier_AR", "MNP_CN_Soldier_MG", "MNP_CN_Soldier_MED", ""};
        crewmen[] = {"MNP_CN_Soldier_F", "MNP_CN_Soldier_F"};
        pilots[] = {"MNP_CN_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"O_Heli_Light_02_unarmed_F"};
        ah[] = {"CUP_O_Ka60_Blk_CSAT"};
    };

    class MNP_CH_WD {
        side = "east";
        camouflage[] = {};
        infantry[] = {"", "", "", "", "", "", "", "", ""};
        crewmen[] = {"", ""};
        pilots[] = {""};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"O_Heli_Light_02_unarmed_F"};
        ah[] = {"CUP_O_Ka60_Blk_CSAT"};
    };

    class MNP_CH_DE {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_CD_Soldier_O", "MNP_CD_Soldier_O", "MNP_CD_Soldier_F", "MNP_CD_Soldier_F", "MNP_CD_Soldier_RAT", "MNP_CD_Soldier_AR", "MNP_CD_Soldier_MG", "MNP_CD_Soldier_MED"};
        crewmen[] = {"MNP_CD_Soldier_F", "MNP_CD_Soldier_F"};
        pilots[] = {"MNP_CD_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"O_Heli_Light_02_unarmed_F"};
        ah[] = {"CUP_O_Ka60_Blk_CSAT"};
    };

    class MNP_CH_MAR {
        side = "east";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"MNP_CM_Soldier_O", "MNP_CM_Soldier_O", "MNP_CM_Soldier_F", "MNP_CM_Soldier_F", "MNP_CM_Soldier_RAT", "MNP_CM_Soldier_AR", "MNP_CM_Soldier_MG", "MNP_CM_Soldier_MED"};
        crewmen[] = {"MNP_CM_Soldier_F", "MNP_CM_Soldier_F"};
        pilots[] = {"MNP_CM_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"O_Heli_Light_02_unarmed_F"};
        ah[] = {"CUP_O_Ka60_Blk_CSAT"};
    };

    class MNP_RU_VDV_DE {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_RU_Soldier_O_D", "MNP_RU_Soldier_O_D", "MNP_RU_Soldier_MEDIUM_D", "MNP_RU_Soldier_MEDIUM_D", "MNP_RU_Soldier_AT_D", "MNP_RU_Soldier_AR_D", "MNP_RU_Soldier_MG_D", "MNP_RU_Soldier_M_D"};
        crewmen[] = {"MNP_RU_Soldier_MEDIUM_D", "MNP_RU_Soldier_MEDIUM_D"};
        pilots[] = {"MNP_RU_Soldier_MEDIUM_D"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_RU", "CUP_O_BTR90_RU", "CUP_O_BMP2_RU", "CUP_O_T72_RU", "CUP_O_T90_RU"};
        th[] = {"CUP_O_Mi8_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_KOR_OD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_NK_Soldier_O", "MNP_NK_Soldier_O", "MNP_NK_Soldier_F", "MNP_NK_Soldier_F", "MNP_NK_Soldier_AT", "MNP_NK_Soldier_AR", "MNP_NK_Soldier_MG", "MNP_NK_Soldier_MD"};
        crewmen[] = {"MNP_NK_Soldier_F", "MNP_NK_Soldier_F"};
        pilots[] = {"MNP_NK_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_MTLB_pk_WDL_RU", "CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_KOR_WD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_NKC_Soldier_O", "MNP_NKC_Soldier_O", "MNP_NKC_Soldier_F", "MNP_NKC_Soldier_F", "MNP_NKC_Soldier_AT", "MNP_NKC_Soldier_AR", "MNP_NKC_Soldier_MG", "MNP_NKC_Soldier_MD"};
        crewmen[] = {"MNP_NKC_Soldier_F", "MNP_NKC_Soldier_F"};
        pilots[] = {"MNP_NKC_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_MTLB_pk_WDL_RU", "CUP_O_BRDM2_SLA", "CUP_O_BTR60_SLA", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_RU_AIR {
        side = "east";
        camouflage[] = {"woodland", "desert", "snow"};
        infantry[] = {"MNP_RO3_Soldier_O", "MNP_RO3_Soldier_O", "MNP_RO3_Soldier_F", "MNP_RO3_Soldier_F", "MNP_RO3_Soldier_AT", "MNP_RO3_Soldier_AR", "MNP_RO3_Soldier_MG", "MNP_RO3_Soldier_M"};
        crewmen[] = {"MNP_RO3_Soldier_F", "MNP_RO3_Soldier_F"};
        pilots[] = {"MNP_RO3_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_MTLB_pk_WDL_RU", "CUP_O_BRDM2_SLA", "CUP_O_BMP2_RU", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_TK_GUE", "CUP_O_BTR60_RU"};
        th[] = {"CUP_O_Mi8_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_DPR_SUM {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_DPR_T_Soldier_TL", "MNP_DPR_T_Soldier_TL", "MNP_DPR_T_Soldier_F", "MNP_DPR_T_Soldier_TL", "MNP_DPR_T_Soldier_AT", "MNP_DPR_T_Soldier_AR", "MNP_DPR_T_Soldier_MG", "MNP_DPR_T_Soldier_MD"};
        crewmen[] = {"MNP_DPR_T_Soldier_F", "MNP_DPR_T_Soldier_F"};
        pilots[] = {"MNP_DPR_T_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_AGS30_CHDKZ", "CUP_O_UAZ_SPG9_CHDKZ"};
        armour[] = {"CUP_O_BTR60_CHDKZ", "CUP_O_T55_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_CHDKZ", "CUP_O_MTLB_pk_ChDKZ", "CUP_O_T72_CHDKZ"};
        th[] = {"CUP_O_Mi8_CHDKZ"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_DPR_AUT {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_DPR_Soldier_TL", "MNP_DPR_Soldier_TL", "MNP_DPR_Soldier_F", "MNP_DPR_Soldier_F", "MNP_DPR_Soldier_AT", "MNP_DPR_Soldier_AR", "MNP_DPR_Soldier_MG", "MNP_DPR_Soldier_MD"};
        crewmen[] = {"MNP_DPR_Soldier_F", "MNP_DPR_Soldier_F"};
        pilots[] = {"MNP_DPR_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_AGS30_CHDKZ", "CUP_O_UAZ_SPG9_CHDKZ"};
        armour[] = {"CUP_O_BTR60_CHDKZ", "CUP_O_T55_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_CHDKZ", "CUP_O_MTLB_pk_ChDKZ", "CUP_O_T72_CHDKZ"};
        th[] = {"CUP_O_Mi8_CHDKZ"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_IRN {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_IR_IRGC_Soldier_TL", "MNP_IR_IRGC_Soldier_TL", "MNP_IR_IRGC_Soldier_F", "MNP_IR_IRGC_Soldier_F", "MNP_IR_IRGC_Soldier_AT", "MNP_IR_IRGC_Soldier_AR", "MNP_IR_IRGC_Soldier_MG", "MNP_IR_IRGC_Soldier_MD"};
        crewmen[] = {"MNP_IR_IRGC_Soldier_F", "MNP_IR_IRGC_Soldier_F"};
        pilots[] = {"MNP_IR_IRGC_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_RU", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class MNP_IRN_RG {
        side = "east";
        camouflage[] = {};
        infantry[] = {"", "", "", "", "", "", "", "", ""};
        crewmen[] = {"", ""};
        pilots[] = {""};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_SLA", "CUP_O_BTR60_RU", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class CUP_TKA_OD {
        side = "east";
        camouflage[] = {"woodland", "desert"};
        infantry[] = {"CUP_O_TK_Soldier_GL", "CUP_O_TK_Soldier_SL", "CUP_O_TK_Soldier", "CUP_O_TK_Soldier_LAT", "CUP_O_TK_Soldier_MG", "CUP_O_TK_Soldier_AR", "CUP_O_TK_Soldier_AT", "CUP_O_TK_Soldier_AR", "CUP_O_TK_Soldier_AT"};
        crewmen[] = {"CUP_O_TK_Soldier_SL", "CUP_O_TK_Soldier"};
        pilots[] = {"CUP_O_TK_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_AGS30_TKA", "CUP_O_UAZ_SPG9_TKA", "CUP_O_BTR40_MG_TKA", "CUP_O_LR_SPG9_TKA", "CUP_O_LR_MG_TKA"};
        armour[] = {"CUP_O_M113_TKA", "CUP_O_MTLB_pk_TKA", "CUP_O_BTR60_TK", "CUP_O_BTR60_TK", "CUP_O_BRDM2_TKA", "CUP_O_BRDM2_TKA", "CUP_O_BMP1P_TKA", "CUP_O_BMP2_TKA", "CUP_O_BMP2_ZU_TKA", "CUP_O_T55_TK", "CUP_O_T72_TKA"};
        th[] = {"CUP_O_Mi17_TK"};
        ah[] = {"CUP_O_Mi24_D_TK"};
    };

    class CUP_TK_INS {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_O_TK_INS_Soldier_GL", "CUP_O_TK_INS_Commander", "CUP_O_TK_INS_Soldier", "CUP_O_TK_INS_Soldier_FNFAL", "CUP_O_TK_INS_Soldier_MG", "CUP_O_TK_INS_Soldier_AR", "CUP_O_TK_INS_Soldier_Enfield", "CUP_O_TK_INS_Soldier_Enfield", "CUP_O_TK_INS_Soldier_AT", "CUP_O_TK_INS_Soldier_AR", "CUP_O_TK_INS_Soldier_AT"};
        crewmen[] = {"CUP_O_TK_INS_Soldier_FNFAL", "CUP_O_TK_INS_Soldier"};
        pilots[] = {"CUP_O_TK_INS_Soldier"};
        technicals[] = {"CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_MG_TKA", "CUP_O_UAZ_AGS30_TKA", "CUP_O_UAZ_SPG9_TKA", "CUP_O_BTR40_MG_TKA", "CUP_O_LR_SPG9_TKA", "CUP_O_LR_MG_TKA"};
        armour[] = {"CUP_O_BRDM2_TKA", "CUP_O_MTLB_pk_TKA", "CUP_O_BRDM2_TKA", "CUP_O_BMP1P_TKA", "CUP_O_BMP2_TKA", "CUP_O_T55_TK", "CUP_O_M113_TKA", "CUP_O_BTR60_TK", "CUP_O_T34_TKA"};
        th[] = {"CUP_O_Mi17_TK"};
        ah[] = {"CUP_O_Mi24_D_TK"};
    };

    class CUP_SLA_WD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_O_sla_Soldier_SL", "CUP_O_sla_Soldier", "CUP_O_sla_Soldier", "CUP_O_sla_Soldier_LAT", "CUP_O_sla_Soldier_GL", "CUP_O_sla_Soldier_AR", "CUP_O_sla_Soldier_AT", "CUP_O_sla_Soldier_AR", "CUP_O_sla_Soldier_AT", "CUP_O_sla_Soldier_MG"};
        crewmen[] = {"CUP_O_sla_Soldier", "CUP_O_sla_Soldier_SL"};
        pilots[] = {"CUP_O_sla_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_AGS30_SLA", "CUP_O_UAZ_SPG9_SLA"};
        armour[] = {"CUP_O_MTLB_pk_SLA", "CUP_O_BTR60_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_O_T55_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_SLA_1"};
        ah[] = {"CUP_O_Mi24_D_SLA"};
    };

    class CUP_CHDKZ {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_O_INS_Soldier_GL", "CUP_O_INS_Soldier", "CUP_O_INS_Soldier", "CUP_O_INS_Soldier_AT", "CUP_O_INS_Soldier_GL", "CUP_O_INS_Soldier_AR", "CUP_O_INS_Soldier_AT", "CUP_O_INS_Soldier_AR", "CUP_O_INS_Soldier_AT", "CUP_O_INS_Soldier_MG"};
        crewmen[] = {"CUP_O_INS_Crew"};
        pilots[] = {"CUP_O_INS_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_MG_CHDKZ", "CUP_O_UAZ_AGS30_CHDKZ", "CUP_O_UAZ_SPG9_CHDKZ"};
        armour[] = {"CUP_O_BTR60_CHDKZ", "CUP_O_T55_CHDKZ", "CUP_O_BRDM2_CHDKZ", "CUP_O_MTLB_pk_ChDKZ", "CUP_O_BMP2_CHDKZ", "CUP_O_T72_CHDKZ"};
        th[] = {"CUP_O_Mi8_CHDKZ"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class CUP_RU_WD {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_O_RU_Soldier_SL", "CUP_O_RU_Soldier", "CUP_O_RU_Soldier", "CUP_O_RU_Soldier_LAT", "CUP_O_RU_Soldier_TL", "CUP_O_RU_Soldier_AR", "CUP_O_RU_Soldier_LAT", "CUP_O_RU_Soldier_AR", "CUP_O_RU_Soldier_LAT", "CUP_O_RU_Soldier_MG"};
        crewmen[] = {"CUP_O_RU_Crew"};
        pilots[] = {"CUP_O_RU_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_BRDM2_RUS", "CUP_O_BTR60_Green_RU", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_RU", "CUP_O_BMP2_RU", "CUP_O_BMP3_RU", "CUP_O_T72_RU", "CUP_O_T90_RU"};
        th[] = {"CUP_O_Mi8_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class CUP_RU_EMR {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_O_RU_Soldier_SL_EMR", "CUP_O_RU_Soldier_EMR", "CUP_O_RU_Soldier_EMR", "CUP_O_RU_Soldier_LAT_EMR", "CUP_O_RU_Soldier_TL_EMR", "CUP_O_RU_Soldier_AR_EMR", "CUP_O_RU_Soldier_LAT_EMR", "CUP_O_RU_Soldier_AR_EMR", "CUP_O_RU_Soldier_LAT_EMR", "CUP_O_RU_Soldier_MG_EMR"};
        crewmen[] = {"CUP_O_RU_Crew_EMR"};
        pilots[] = {"CUP_O_RU_Pilot_EMR"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU", "CUP_O_GAZ_Vodnik_PK_RU"};
        armour[] = {"CUP_O_BRDM2_RUS", "CUP_O_BTR60_Green_RU", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_RU", "CUP_O_BMP2_RU", "CUP_O_BMP3_RU", "CUP_O_T72_RU", "CUP_O_BTR90_RU", "CUP_O_GAZ_Vodnik_BPPU_RU", "CUP_O_T90_RU"};
        th[] = {"CUP_O_Mi8_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class ARK_RU_CBRN {
        side = "east";
        camouflage[] = {};
        infantry[] = {"ARK_RU_CBRN_Soldier_TL_F", "ARK_RU_CBRN_Soldier_TL_F", "ARK_RU_CBRN_Soldier_LAT_F", "ARK_RU_CBRN_Soldier_F", "ARK_RU_CBRN_Soldier_F", "ARK_RU_CBRN_Soldier_F", "ARK_RU_CBRN_Soldier_MG_F", "ARK_RU_CBRN_Soldier_AR_F", "ARK_RU_CBRN_Soldier_AR_F", "ARK_RU_CBRN_Soldier_LAT_F"};
        crewmen[] = {"ARK_RU_CBRN_Crew_F"};
        pilots[] = {"ARK_RU_CBRN_Pilot_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU", "CUP_O_GAZ_Vodnik_PK_RU"};
        armour[] = {"CUP_O_BRDM2_RUS", "CUP_O_BTR60_Green_RU", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_RU", "CUP_O_BMP2_RU", "CUP_O_BMP3_RU", "CUP_O_T72_RU", "CUP_O_BTR90_RU", "CUP_O_GAZ_Vodnik_BPPU_RU", "CUP_O_T90_RU"};
        th[] = {"CUP_O_Mi8_RU"};
        ah[] = {"CUP_O_Mi24_V_RU"};
    };

    class AAF_WOODLAND {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"I_Soldier_SL_F", "I_Soldier_AR_F", "I_Soldier_lite_F", "I_Soldier_AT4_F", "I_Soldier_M_F", "I_Soldier_AR_F", "I_Soldier_AT4_F", "I_Soldier_AR_F", "I_Soldier_AT4_F"};
        crewmen[] = {"I_crew_F", "I_engineer_F"};
        pilots[] = {"I_Helipilot_F"};
        technicals[] = {"I_MRAP_03_hmg_F", "CUP_I_LR_MG_AAF", "CUP_I_LR_MG_AAF"};
        armour[] = {"I_APC_tracked_03_cannon_F", "I_APC_Wheeled_03_cannon_F", "CUP_I_M113_AAF", "CUP_I_M113_AAF"};
        th[] = {"I_Heli_Transport_02_F"};
        ah[] = {"I_Heli_light_03_F"};
    };

    class AAF_CBRN {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"skn_i_nbc_sl", "skn_i_nbc_AR", "skn_i_nbc_rf", "skn_i_nbc_AT4", "skn_i_nbc_a", "skn_i_nbc_AR", "skn_i_nbc_AT4", "skn_i_nbc_AR", "skn_i_nbc_AT4"};
        crewmen[] = {"skn_i_nbc_crew", "skn_i_nbc_medic"};
        pilots[] = {"skn_i_nbc_crew"};
        technicals[] = {"I_MRAP_03_hmg_F", "CUP_I_LR_MG_AAF", "CUP_I_LR_MG_AAF"};
        armour[] = {"I_APC_tracked_03_cannon_F", "I_APC_Wheeled_03_cannon_F", "CUP_I_M113_AAF", "CUP_I_M113_AAF"};
        th[] = {"I_Heli_Transport_02_F"};
        ah[] = {"I_Heli_light_03_F"};
    };

    class MNP_LVM_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_Militia_Soldier_O", "MNP_Militia_Soldier_O", "MNP_Militia_Soldier_F", "MNP_Militia_Soldier_F", "MNP_Militia_Soldier_RAT", "MNP_Militia_Soldier_AR", "MNP_Militia_Soldier_MG", "MNP_Militia_Soldier_M"};
        crewmen[] = {"MNP_Militia_Soldier_F", "MNP_Militia_Soldier_F"};
        pilots[] = {"MNP_Militia_Soldier_F"};
        technicals[] = {"CUP_B_LR_MG_GB_W", "CUP_O_UAZ_MG_CHDKZ", "CUP_I_Datsun_PK", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_CHDKZ", "CUP_I_Ural_ZU23_NAPA"};
        armour[] = {"CUP_O_MTLB_pk_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class MNP_LVM_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_Militia_Soldier_DO", "MNP_Militia_Soldier_DO", "MNP_Militia_Soldier_DF", "MNP_Militia_Soldier_DF", "MNP_Militia_Soldier_DRAT", "MNP_Militia_Soldier_DAR", "MNP_Militia_Soldier_DMG", "MNP_Militia_Soldier_DM"};
        crewmen[] = {"MNP_Militia_Soldier_DF", "MNP_Militia_Soldier_DF"};
        pilots[] = {"MNP_Militia_Soldier_DF"};
        technicals[] = {"CUP_B_LR_MG_GB_W", "CUP_O_UAZ_MG_CHDKZ", "CUP_I_Datsun_PK", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_CHDKZ", "CUP_I_Ural_ZU23_NAPA"};
        armour[] = {"CUP_O_MTLB_pk_TK_MILITIA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "UP_O_BMP2_SLA", "CUP_I_T55_TK_GUE", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class MNP_IRE_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_Irish_Soldier_Officer", "MNP_Irish_Soldier_Officer", "MNP_Irish_Soldier_F", "MNP_Irish_Soldier_F", "MNP_Irish_Soldier_RAT", "MNP_Irish_Soldier_AR", "MNP_Irish_Soldier_MG", "MNP_Irish_Soldier_Medic"};
        crewmen[] = {"MNP_Irish_Soldier_F", "MNP_Irish_Soldier_F"};
        pilots[] = {"MNP_Irish_Soldier_F"};
        technicals[] = {"CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_M2_GB_W", "CUP_B_LR_Special_GMG_GB_W", "CUP_B_RG31_M2_OD_USMC", "CUP_B_RG31_Mk19_OD_USMC"};
        armour[] = {"CUP_B_LAV25M240_green"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class MNP_IRE_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_Irish_Soldier_DOfficer", "MNP_Irish_Soldier_DOfficer", "MNP_Irish_Soldier_D", "MNP_Irish_Soldier_D", "MNP_Irish_Soldier_DRAT", "MNP_Irish_Soldier_DAR", "MNP_Irish_Soldier_DMG", "MNP_Irish_Soldier_DMedic"};
        crewmen[] = {"MNP_Irish_Soldier_D", "MNP_Irish_Soldier_D"};
        pilots[] = {"MNP_Irish_Soldier_D"};
        technicals[] = {"CUP_B_LR_Special_GMG_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_LR_Special_M2_GB_D", "CUP_B_RG31E_M2_USMC", "CUP_B_RG31_Mk19_USMC"};
        armour[] = {"CUP_B_LAV24M240_desert_USMC"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class MNP_NZ {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"MNP_NZ_Soldier_O", "MNP_NZ_Soldier_O", "MNP_NZ_Soldier_F", "MNP_NZ_Soldier_F", "MNP_NZ_Soldier_AT", "MNP_NZ_Soldier_AR", "MNP_NZ_Soldier_MG", "MNP_NZ_Soldier_MD"};
        crewmen[] = {"MNP_NZ_Soldier_F", "MNP_NZ_Soldier_F"};
        pilots[] = {"MNP_NZ_Soldier_F"};
        technicals[] = {"I_MRAP_03_hmg_F"};
        armour[] = {"I_APC_tracked_03_cannon_F", "I_MBT_03_cannon_F"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_UH1D_gunship_GER_KSK_Des"};
    };

    class MNP_FIN_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_FIN_Soldier_O", "MNP_FIN_Soldier_O", "MNP_FIN_Soldier_F", "MNP_FIN_Soldier_F", "MNP_FIN_Soldier_AT", "MNP_FIN_Soldier_AR", "MNP_FIN_Soldier_MG", "MNP_FIN_Soldier_MD"};
        crewmen[] = {"MNP_FIN_Soldier_F", "MNP_FIN_Soldier_F"};
        pilots[] = {"MNP_FIN_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_B_MTLB_pk_CDF", "CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class MNP_FIN_SN {
        side = "resistance";
        camouflage[] = {"snow"};
        infantry[] = {"MNP_AFIN_Soldier_O", "MNP_AFIN_Soldier_O", "MNP_AFIN_Soldier_F", "MNP_AFIN_Soldier_F", "MNP_AFIN_Soldier_AT", "MNP_AFIN_Soldier_AR", "MNP_AFIN_Soldier_MG", "MNP_AFIN_Soldier_MD"};
        crewmen[] = {"MNP_AFIN_Soldier_F", "MNP_AFIN_Soldier_F"};
        pilots[] = {"MNP_AFIN_Soldier_F"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_B_MTLB_pk_Winter_CDF", "CUP_O_BRDM2_SLA", "CUP_O_BRDM2_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class MNP_NOR_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"MNP_NOR_Soldier_O", "MNP_NOR_Soldier_O", "MNP_NOR_Soldier_F", "MNP_NOR_Soldier_F", "MNP_NOR_Soldier_AT", "MNP_NOR_Soldier_AR", "MNP_NOR_Soldier_MG", "MNP_NOR_Soldier_MD"};
        crewmen[] = {"MNP_NOR_Soldier_F", "MNP_NOR_Soldier_F"};
        pilots[] = {"MNP_NOR_Soldier_F"};
        technicals[] = {"CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GER_Wdl", "CUP_B_Dingo_GL_GER_Wdl"};
        armour[] = {"ARK_M113_NOR", "ARK_M113_NOR", "CUP_B_Leopard2A6_GER"};
        th[] = {"ARK_UH1Y_UNA_NOR"};
        ah[] = {"ARK_UH1Y_GUN_NOR"};
    };

    class MNP_NOR_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"MNP_NOR_D_Soldier_O", "MNP_NOR_D_Soldier_O", "MNP_NOR_D_Soldier_F", "MNP_NOR_D_Soldier_F", "MNP_NOR_D_Soldier_AT", "MNP_NOR_D_Soldier_AR", "MNP_NOR_D_Soldier_MG", "MNP_NOR_D_Soldier_MD"};
        crewmen[] = {"MNP_NOR_D_Soldier_F", "MNP_NOR_D_Soldier_F"};
        pilots[] = {"MNP_NOR_D_Soldier_F"};
        technicals[] = {"CUP_B_Dingo_GL_GER_Des", "CUP_B_Dingo_GER_Des", "CUP_B_Dingo_GER_Des"};
        armour[] = {"ARK_M113_NOR", "ARK_M113_NOR", "CUP_B_Leopard2A6_GER"};
        th[] = {"ARK_UH1Y_UNA_NOR"};
        ah[] = {"ARK_UH1Y_GUN_NOR"};
    };

    class CUP_RACS_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_I_RACS_SL", "CUP_I_RACS_MMG", "CUP_I_RACS_Soldier", "CUP_I_RACS_Soldier", "CUP_I_RACS_Soldier", "CUP_I_RACS_MMG", "CUP_I_RACS_Soldier_MAT", "CUP_I_RACS_Soldier", "CUP_I_RACS_Soldier_MAT"};
        crewmen[] = {"CUP_I_RACS_Soldier", "CUP_I_RACS_Engineer"};
        pilots[] = {"CUP_I_RACS_Pilot"};
        technicals[] = {"CUP_I_LR_MG_RACS"};
        armour[] = {"CUP_I_M113_RACS", "CUP_I_M113_RACS", "CUP_I_AAV_RACS", "CUP_I_M60A3_RACS", "CUP_I_M60A3_TTS_RACS"};
        th[] = {"CUP_I_UH60L_RACS"};
        ah[] = {"CUP_I_AH6J_RACS"};
    };

    class CUP_TK_LOC {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_I_TK_GUE_Commander", "CUP_I_TK_GUE_Soldier_AR", "CUP_I_TK_GUE_Soldier", "CUP_I_TK_GUE_Soldier_M16A2", "CUP_I_TK_GUE_Guerilla_Enfield", "CUP_I_TK_GUE_Soldier_MG", "CUP_I_TK_GUE_Soldier_AT", "CUP_I_TK_GUE_Soldier_M16A2", "CUP_I_TK_GUE_Soldier_AT"};
        crewmen[] = {"CUP_I_TK_GUE_Soldier", "CUP_I_TK_GUE_Soldier_TL"};
        pilots[] = {"CUP_I_TK_GUE_Soldier"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_O_MTLB_pk_TK_MILITIA", "CUP_O_BRDM2_SLA", "CUP_I_T34_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_I_T55_TK_GUE"};
        th[] = {"CUP_O_Mi17_TK"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class CUP_NAPA_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_I_GUE_Officer", "CUP_I_GUE_Soldier_AR", "CUP_I_GUE_Soldier_AKM", "CUP_I_GUE_Soldier_AKS74", "CUP_I_GUE_Soldier_AKSU", "CUP_I_GUE_Soldier_MG", "CUP_I_GUE_Soldier_AT", "CUP_I_GUE_Soldier_AR", "CUP_I_GUE_Soldier_AT"};
        crewmen[] = {"CUP_I_GUE_Soldier_AKM", "CUP_I_GUE_Officer"};
        pilots[] = {"CUP_I_GUE_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_MG_RU", "CUP_O_UAZ_AGS30_RU", "CUP_O_UAZ_SPG9_RU"};
        armour[] = {"CUP_I_MTLB_pk_NAPA", "CUP_O_BRDM2_SLA", "CUP_I_T34_TK_GUE", "CUP_I_BMP1_TK_GUE", "CUP_I_T55_NAPA", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_UH1H_slick_TKA"};
        ah[] = {"CUP_O_UH1H_gunship_SLA_TKA"};
    };

    class SYND_BANDIT {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"I_C_Soldier_Bandit_7_F_ARK", "I_C_Soldier_Bandit_3_F_ARK", "I_C_Soldier_Bandit_4_F_ARK", "I_C_Soldier_Bandit_5_F_ARK", "I_C_Soldier_Bandit_2_F_ARK", "I_C_Soldier_Bandit_2_F_ARK", "I_C_Soldier_Bandit_6_F_ARK", "I_C_Soldier_Bandit_6_F_ARK", "I_C_Soldier_Bandit_7_F_ARK"};
        crewmen[] = {"I_C_Pilot_F_ARK", "I_C_Pilot_F_ARK"};
        pilots[] = {"I_C_Pilot_F_ARK"};
        technicals[] = {"CUP_I_Datsun_PK", "CUP_O_UAZ_AGS30_TKA", "CUP_O_LR_MG_TKA", "CUP_O_LR_SPG9_TKA", "CUP_O_UAZ_SPG9_TKA", "CUP_O_UAZ_MG_TKA", "CUP_I_Datsun_PK_TK_Random"};
        armour[] = {"CUP_O_BTR60_RU", "CUP_O_BRDM2_SLA", "CUP_O_BMP2_SLA", "CUP_O_T55_SLA", "CUP_I_T34_NAPA", "CUP_O_T55_SLA", "CUP_I_MTLB_pk_SYNDIKAT"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class SYND_REBEL {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"I_C_Soldier_Para_2_F_ARK", "I_C_Soldier_Para_2_F_ARK", "I_C_Soldier_Para_1_F_ARK", "I_C_Soldier_Para_1_F_ARK", "I_C_Soldier_Para_6_F_ARK", "I_C_Soldier_Para_1_F_ARK", "I_C_Soldier_Para_1_F_ARK", "I_C_Soldier_Para_7_F_ARK", "I_C_Soldier_Para_4_F_ARK", "I_C_Soldier_Para_4_F_ARK"};
        crewmen[] = {"I_C_Helipilot_F_ARK", "I_C_Helipilot_F_ARK"};
        pilots[] = {"I_C_Helipilot_F_ARK"};
        technicals[] = {"CUP_I_Datsun_PK", "CUP_O_UAZ_AGS30_TKA", "CUP_O_LR_MG_TKA", "CUP_O_LR_SPG9_TKA", "CUP_O_UAZ_SPG9_TKA", "CUP_O_UAZ_MG_TKA", "CUP_I_Datsun_PK_TK_Random"};
        armour[] = {"CUP_O_BTR60_RU", "CUP_O_BRDM2_SLA", "CUP_O_BMP2_SLA", "CUP_O_T55_SLA", "CUP_I_T34_NAPA", "CUP_O_T55_SLA", "CUP_I_MTLB_pk_SYNDIKAT"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi24_D_Dynamic_SLA"};
    };

    class CUP_CDF_DES {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_CDF_Soldier_DST", "CUP_B_CDF_Soldier_AR_DST", "CUP_B_CDF_Soldier_MG_DST", "CUP_B_CDF_Soldier_LAT_DST", "CUP_B_CDF_Soldier_GL_DST", "CUP_B_CDF_Soldier_DST", "CUP_B_CDF_Soldier_AR_DST", "CUP_B_CDF_Soldier_LAT_DST", "CUP_B_CDF_Soldier_DST"};
        crewmen[] = {"CUP_B_CDF_Crew_DST", "CUP_B_CDF_Engineer_DST"};
        pilots[] = {"CUP_B_CDF_Pilot_DST"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_MTLB_pk_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BTR60_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_T72_CDF"};
        th[] = {"CUP_B_Mi17_CDF"};
        ah[] = {"CUP_B_Mi24_D_Dynamic_CDF"};
    };

    class CUP_CDF_FOR {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_CDF_Soldier_FST", "CUP_B_CDF_Soldier_AR_FST", "CUP_B_CDF_Soldier_MG_FST", "CUP_B_CDF_Soldier_LAT_FST", "CUP_B_CDF_Soldier_GL_FST", "CUP_B_CDF_Soldier_FST", "CUP_B_CDF_Soldier_AR_FST", "CUP_B_CDF_Soldier_LAT_FST", "CUP_B_CDF_Soldier_FST"};
        crewmen[] = {"CUP_B_CDF_Crew_FST", "CUP_B_CDF_Engineer_FST"};
        pilots[] = {"CUP_B_CDF_Pilot_FST"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_MTLB_pk_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BTR60_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_T72_CDF"};
        th[] = {"CUP_B_Mi17_CDF"};
        ah[] = {"CUP_B_Mi24_D_Dynamic_CDF"};
    };

    class CUP_CDF_MOU {
        side = "west";
        camouflage[] = {"desert", "woodland"};
        infantry[] = {"CUP_B_CDF_Soldier_MNT", "CUP_B_CDF_Soldier_AR_MNT", "CUP_B_CDF_Soldier_MG_MNT", "CUP_B_CDF_Soldier_LAT_MNT", "CUP_B_CDF_Soldier_GL_MNT", "CUP_B_CDF_Soldier_MNT", "CUP_B_CDF_Soldier_AR_MNT", "CUP_B_CDF_Soldier_LAT_MNT", "CUP_B_CDF_Soldier_MNT"};
        crewmen[] = {"CUP_B_CDF_Crew_MNT", "CUP_B_CDF_Engineer_MNT"};
        pilots[] = {"CUP_B_CDF_Pilot_MNT"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_MTLB_pk_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BTR60_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_T72_CDF"};
        th[] = {"CUP_B_Mi17_CDF"};
        ah[] = {"CUP_B_Mi24_D_Dynamic_CDF"};
    };

    class CUP_CDF_SN {
        side = "west";
        camouflage[] = {"snow"};
        infantry[] = {"CUP_B_CDF_Soldier_SNW", "CUP_B_CDF_Soldier_AR_SNW", "CUP_B_CDF_Soldier_MG_SNW", "CUP_B_CDF_Soldier_LAT_SNW", "CUP_B_CDF_Soldier_GL_SNW", "CUP_B_CDF_Soldier_SNW", "CUP_B_CDF_Soldier_AR_SNW", "CUP_B_CDF_Soldier_LAT_SNW", "CUP_B_CDF_Soldier_SNW"};
        crewmen[] = {"CUP_B_CDF_Crew_SNW", "CUP_B_CDF_Engineer_SNW"};
        pilots[] = {"CUP_B_CDF_Pilot_SNW"};
        technicals[] = {"CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_MG_CDF", "CUP_B_UAZ_AGS30_CDF", "CUP_B_UAZ_SPG9_CDF"};
        armour[] = {"CUP_B_MTLB_pk_Winter_CDF", "CUP_B_BRDM2_CDF", "CUP_B_BTR60_CDF", "CUP_B_BMP2_CDF", "CUP_B_T72_CDF", "CUP_B_T72_CDF"};
        th[] = {"CUP_B_Mi17_CDF"};
        ah[] = {"CUP_B_Mi24_D_Dynamic_CDF"};
    };

    class CUP_RACS_MECH {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_I_RACS_SL_Mech", "CUP_I_RACS_MMG_Mech", "CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_MMG_Mech", "CUP_I_RACS_Soldier_MAT_Mech", "CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_Soldier_MAT_Mech"};
        crewmen[] = {"CUP_I_RACS_Soldier_Mech", "CUP_I_RACS_Engineer_Mech"};
        pilots[] = {"CUP_I_RACS_Pilot"};
        technicals[] = {"CUP_I_LR_MG_RACS"};
        armour[] = {"CUP_I_M113_RACS", "CUP_I_M113_RACS", "CUP_I_AAV_RACS", "CUP_I_M60A3_RACS", "CUP_I_M60A3_TTS_RACS"};
        th[] = {"CUP_I_UH60L_RACS"};
        ah[] = {"CUP_I_AH6J_RACS"};
    };

    class CUP_RACS_URB {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_I_RACS_SL_Urban", "CUP_I_RACS_MMG_Urban", "CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_MMG_Urban", "CUP_I_RACS_Soldier_MAT_Urban", "CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_Soldier_MAT_Urban"};
        crewmen[] = {"CUP_I_RACS_Soldier_Urban", "CUP_I_RACS_Engineer_Urban"};
        pilots[] = {"CUP_I_RACS_Pilot"};
        technicals[] = {"CUP_I_LR_MG_RACS"};
        armour[] = {"CUP_I_M113_RACS_URB", "CUP_I_M113_RACS_URB", "CUP_I_AAV_RACS", "CUP_I_M60A3_RACS", "CUP_I_M60A3_TTS_RACS"};
        th[] = {"CUP_I_UH60L_RACS"};
        ah[] = {"CUP_I_AH6J_RACS"};
    };

    class CUP_SLA_DE {
        side = "east";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_O_sla_Soldier_SL_desert", "CUP_O_sla_soldier_desert", "CUP_O_sla_soldier_desert", "CUP_O_sla_Soldier_LAT_desert", "CUP_O_sla_Soldier_GL_desert", "CUP_O_sla_Soldier_AR_desert", "CUP_O_sla_Soldier_AT_desert", "CUP_O_sla_Soldier_AR_desert", "CUP_O_sla_Soldier_AT_desert", "CUP_O_sla_Soldier_MG_desert"};
        crewmen[] = {"CUP_O_sla_soldier_desert", "CUP_O_sla_Soldier_SL_desert"};
        pilots[] = {"CUP_O_sla_Pilot"};
        technicals[] = {"CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_AGS30_SLA", "CUP_O_UAZ_SPG9_SLA"};
        armour[] = {"CUP_O_MTLB_pk_SLA", "CUP_O_BTR60_SLA", "CUP_O_BTR60_SLA", "CUP_O_BRDM2_SLA", "CUP_O_T55_SLA", "CUP_I_BMP1_TK_GUE", "CUP_O_BMP2_SLA", "CUP_O_T72_SLA"};
        th[] = {"CUP_O_Mi8_SLA_1"};
        ah[] = {"CUP_O_Mi24_D_SLA"};
    };

    class CUP_USMC_FROG_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_USMC_Soldier_GL_FROG_WDL", "CUP_B_USMC_Soldier_FROG_WDL", "CUP_B_USMC_Soldier_FROG_WDL", "CUP_B_USMC_Soldier_TL_FROG_WDL", "CUP_B_USMC_Soldier_MG_FROG_WDL", "CUP_B_USMC_Soldier_AR_FROG_WDL", "CUP_B_USMC_Soldier_LAT_FROG_WDL", "CUP_B_USMC_Soldier_AR_FROG_WDL", "CUP_B_USMC_Soldier_LAT_FROG_WDL"};
        crewmen[] = {"CUP_B_USMC_Crewman_FROG_WDL"};
        pilots[] = {"CUP_B_USMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_MK19_USMC", "CUP_B_RG31_Mk19_OD_USMC", "CUP_B_RG31_M2_OD_USMC"};
        armour[] = {"CUP_B_LAV25_USMC", "CUP_B_LAV25_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_Woodland_USMC", "CUP_B_M1A2_TUSK_MG_USMC"};
        th[] = {"CUP_B_UH60S_USN"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_USMC_FROG_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_USMC_Soldier_GL_FROG_DES", "CUP_B_USMC_Soldier_FROG_DES", "CUP_B_USMC_Soldier_FROG_DES", "CUP_B_USMC_Soldier_TL_FROG_DES", "CUP_B_USMC_Soldier_MG_FROG_DES", "CUP_B_USMC_Soldier_AR_FROG_DES", "CUP_B_USMC_Soldier_LAT_FROG_DES", "CUP_B_USMC_Soldier_AR_FROG_DES", "CUP_B_USMC_Soldier_LAT_FROG_DES"};
        crewmen[] = {"CUP_B_USMC_Crewman_FROG_DES"};
        pilots[] = {"CUP_B_USMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_GPK_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA", "CUP_B_RG31_Mk19_USMC", "CUP_B_RG31_M2_USMC"};
        armour[] = {"CUP_B_LAV25_desert_USMC", "CUP_B_LAV25_desert_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_DES_USMC", "CUP_B_M1A2_TUSK_MG_USMC"};
        th[] = {"CUP_B_UH60S_USN"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class CUP_ION_PMC_WD {
        side = "resistance";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_I_PMC_Contractor1", "CUP_I_PMC_Contractor2", "CUP_I_PMC_Bodyguard_M4", "CUP_I_PMC_Medic", "CUP_I_PMC_Soldier_MG", "CUP_I_PMC_Soldier_MG_PKM", "CUP_I_PMC_Soldier_AT", "CUP_I_PMC_Soldier_GL_M16A2", "CUP_I_PMC_Soldier_M4A3"};
        crewmen[] = {"CUP_I_PMC_Contractor2", "CUP_I_PMC_Bodyguard_M4"};
        pilots[] = {"CUP_I_PMC_Pilot"};
        technicals[] = {"CUP_I_SUV_Armored_ION", "CUP_I_4WD_LMG_ION", "CUP_I_4WD_AT_ION", "CUP_I_LSV_02_Minigun_ION", "CUP_I_LSV_02_AT_ION"};
        armour[] = {"CUP_I_MATV_HMG_ION", "CUP_I_MATV_GMG_ION", "CUP_I_FENNEK_HMG_ION", "CUP_I_FENNEK_GMG_ION"};
        th[] = {"CUP_I_Ka60_GL_Blk_ION"};
        ah[] = {"CUP_I_Mi24_Mk4_AT_ION"};
    };

    class CUP_ION_PMC_DE {
        side = "resistance";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_I_PMC_Contractor1", "CUP_I_PMC_Contractor2", "CUP_I_PMC_Bodyguard_M4", "CUP_I_PMC_Medic", "CUP_I_PMC_Soldier_MG", "CUP_I_PMC_Soldier_MG_PKM", "CUP_I_PMC_Soldier_AT", "CUP_I_PMC_Soldier_GL_M16A2", "CUP_I_PMC_Soldier_M4A3"};
        crewmen[] = {"CUP_I_PMC_Contractor2", "CUP_I_PMC_Bodyguard_M4"};
        pilots[] = {"CUP_I_PMC_Pilot"};
        technicals[] = {"CUP_I_SUV_Armored_ION", "CUP_I_4WD_LMG_ION", "CUP_I_4WD_AT_ION", "CUP_I_LSV_02_Minigun_ION", "CUP_I_LSV_02_AT_ION"};
        armour[] = {"CUP_I_MATV_HMG_ION", "CUP_I_MATV_GMG_ION", "CUP_I_FENNEK_HMG_ION", "CUP_I_FENNEK_GMG_ION"};
        th[] = {"CUP_I_Ka60_GL_Blk_ION"};
        ah[] = {"CUP_I_Mi24_Mk4_AT_ION"};
    };

    class CUP_ION_PMC_SN {
        side = "resistance";
        camouflage[] = {"snow"};
        infantry[] = {"CUP_I_PMC_Winter_Soldier_MG", "CUP_I_PMC_Winter_Soldier_MG_PKM", "CUP_I_PMC_Winter_Soldier_AT", "CUP_I_PMC_Winter_Soldier", "CUP_I_PMC_Winter_Soldier_GL", "CUP_I_PMC_Winter_Soldier_TL", "CUP_I_PMC_Winter_Soldier", "CUP_I_PMC_Winter_Soldier", "CUP_I_PMC_Winter_Soldier"};
        crewmen[] = {"CUP_I_PMC_Winter_Engineer", "CUP_I_PMC_Winter_Crew"};
        pilots[] = {"CUP_I_PMC_Winter_Pilot"};
        technicals[] = {"CUP_I_SUV_Armored_ION", "CUP_I_4WD_LMG_ION", "CUP_I_4WD_AT_ION", "CUP_I_LSV_02_Minigun_ION", "CUP_I_LSV_02_AT_ION"};
        armour[] = {"CUP_I_MATV_HMG_ION", "CUP_I_MATV_GMG_ION", "CUP_I_FENNEK_HMG_ION", "CUP_I_FENNEK_GMG_ION"};
        th[] = {"CUP_I_Ka60_GL_Blk_ION"};
        ah[] = {"CUP_I_Mi24_Mk4_AT_ION"};
    };

    class FOW_USMC {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_usmc_teamleader", "fow_s_usmc_rifleman_m1903", "fow_s_usmc_rifleman", "fow_s_usmc_rifleman", "fow_s_usmc_rifleman", "fow_s_usmc_rifleman_m1_carbine", "fow_s_usmc_rifleman_m1_carbine", "fow_s_usmc_nco", "fow_s_usmc_officer", "fow_s_usmc_m1919a6_gunner", "fow_s_usmc_m1919a6_asst", "fow_s_usmc_bar_gunner", "fow_s_usmc_bar_gunner_asst", "fow_s_usmc_at", "fow_s_usmc_at_asst"};
        crewmen[] = {"fow_s_usmc_crewman", "fow_s_usmc_crewman"};
        pilots[] = {"fow_s_us_pilot"};
        technicals[] = {"LIB_US_Scout_M3_FFV", "LIB_US_Scout_M3_FFV", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A3_75_Tubes", "LIB_M5A1_Stuart", "LIB_M4A3_75"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_USA {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_us_m37_smg_m3", "fow_s_us_m37_smg_m1a1", "fow_s_us_m37_teamleader_asst", "fow_s_us_m37_teamleader", "fow_s_us_m37_rifleman_scout", "fow_s_us_m37_rifleman_m1_carbine", "fow_s_us_m37_rifleman_gl", "fow_s_us_m37_rifleman", "fow_s_us_m37_radio_operator", "fow_s_us_m37_officer", "fow_s_us_m37_nco", "fow_s_us_m37_m1919a6_gunner", "fow_s_us_m37_1919a6_asst", "fow_s_us_m37_bar_gunner", "fow_s_us_m37_bar_asst", "fow_s_us_m37_at", "fow_s_us_m37_at_asst"};
        crewmen[] = {"fow_s_us_crewman", "fow_s_us_crewman"};
        pilots[] = {"fow_s_us_pilot_green"};
        technicals[] = {"LIB_US_Scout_M3_FFV", "LIB_US_Scout_M3_FFV", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A3_76", "LIB_M5A1_Stuart", "LIB_M4A3_75", "LIB_M4A3_76_HVSS"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_USA_PARA {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_us_ab_m42_smg_m3", "fow_s_us_ab_m42_smg_m1a1", "fow_s_us_ab_m42_teamleader_asst", "fow_s_us_ab_m42_teamleader", "fow_s_us_ab_m42_rifleman_scout", "fow_s_us_ab_m42_rifleman_m1_carbine", "fow_s_us_ab_m42_rifleman_gl", "fow_s_us_ab_m42_rifleman", "fow_s_us_ab_m42_radio_operator", "fow_s_us_ab_m42_officer", "fow_s_us_ab_m42_nco", "fow_s_us_ab_m42_m1919a6_gunner", "fow_s_us_ab_m42_m1919a6_gunner_asst", "fow_s_us_ab_m42_bar_gunner", "fow_s_us_ab_m42_bar_asst", "fow_s_us_ab_m42_at", "fow_s_us_ab_m42_at_asst"};
        crewmen[] = {"fow_s_us_crewman", "fow_s_us_crewman"};
        pilots[] = {"fow_s_us_pilot_green"};
        technicals[] = {"LIB_US_Scout_M3_FFV", "LIB_US_Scout_M3_FFV", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A3_76", "LIB_M5A1_Stuart", "LIB_M4A3_75", "LIB_M4A3_76_HVSS"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_USA_PAC {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_us_p_smg_m3", "fow_s_us_p_smg_m1a1", "fow_s_us_p_teamleader_asst", "fow_s_us_p_teamleader", "fow_s_us_p_rifleman_scout", "fow_s_us_p_rifleman_m1_carbine", "fow_s_us_p_rifleman_gl", "fow_s_us_p_rifleman", "fow_s_us_p_radio_operator", "fow_s_us_p_officer", "fow_s_us_p_nco", "fow_s_us_p_m1919a6_gunner", "fow_s_us_p_1919a6_asst", "fow_s_us_p_bar_gunner", "fow_s_us_p_bar_asst", "fow_s_us_p_at", "fow_s_us_p_at_asst"};
        crewmen[] = {"fow_s_us_p_crewman", "fow_s_us_p_crewman"};
        pilots[] = {"fow_s_us_pilot_green"};
        technicals[] = {"LIB_US_Scout_M3_FFV", "LIB_US_Scout_M3_FFV", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A3_75_Tubes", "LIB_M5A1_Stuart", "LIB_M4A3_75"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_BAF_ESX {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_uk_teamleader", "fow_s_uk_section_commander", "fow_s_uk_rifleman", "fow_s_uk_radio_operator", "fow_s_uk_officer", "fow_s_uk_bren", "fow_s_uk_bren_asst", "fow_s_uk_at", "fow_s_uk_at_asst", "fow_s_uk_rifleman", "fow_s_uk_rifleman"};
        crewmen[] = {"fow_s_uk_crewman", "fow_s_uk_crewman"};
        pilots[] = {"fow_s_us_pilot"};
        technicals[] = {"fow_v_universalCarrier", "fow_v_universalCarrier", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A4_FIREFLY", "LIB_M5A1_Stuart", "fow_v_cromwell_uk"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_BAF_PARA {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_uk_para_teamleader", "fow_s_uk_para_section_commander", "fow_s_uk_para_rifleman", "fow_s_uk_para_radio_operator", "fow_s_uk_para_officer", "fow_s_uk_para_bren", "fow_s_uk_para_bren_asst", "fow_s_uk_para_at", "fow_s_uk_para_at_asst", "fow_s_uk_para_rifleman", "fow_s_uk_para_rifleman"};
        crewmen[] = {"fow_s_uk_crewman", "fow_s_uk_crewman"};
        pilots[] = {"fow_s_us_pilot"};
        technicals[] = {"fow_v_universalCarrier", "fow_v_universalCarrier", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A4_FIREFLY", "LIB_M5A1_Stuart", "fow_v_cromwell_uk"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_BAF_COM {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_uk_cdo_teamleader", "fow_s_uk_cdo_section_commander", "fow_s_uk_cdo_rifleman", "fow_s_uk_cdo_radio_operator", "fow_s_uk_cdo_officer", "fow_s_uk_cdo_bren", "fow_s_uk_cdo_bren_asst", "fow_s_uk_cdo_at", "fow_s_uk_cdo_at_asst", "fow_s_uk_cdo_rifleman", "fow_s_uk_cdo_rifleman"};
        crewmen[] = {"fow_s_uk_crewman", "fow_s_uk_crewman"};
        pilots[] = {"fow_s_us_pilot"};
        technicals[] = {"fow_v_universalCarrier", "fow_v_universalCarrier", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A4_FIREFLY", "LIB_M5A1_Stuart", "fow_v_cromwell_uk"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_BAF_PAC {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_uk_seac_teamleader", "fow_s_uk_seac_section_commander", "fow_s_uk_seac_rifleman", "fow_s_uk_seac_radio_operator", "fow_s_uk_seac_officer", "fow_s_uk_seac_bren", "fow_s_uk_seac_bren_asst", "fow_s_uk_seac_at", "fow_s_uk_seac_at_asst", "fow_s_uk_seac_rifleman", "fow_s_uk_seac_rifleman"};
        crewmen[] = {"fow_s_uk_crewman", "fow_s_uk_crewman"};
        pilots[] = {"fow_s_us_pilot"};
        technicals[] = {"fow_v_universalCarrier", "fow_v_universalCarrier", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A3_75_Tubes", "LIB_M5A1_Stuart", "LIB_M4A3_75"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_AUS {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_uk_seac_teamleader_l", "fow_s_uk_seac_section_commander_l", "fow_s_uk_seac_rifleman_l", "fow_s_uk_seac_radio_operator_l", "fow_s_uk_seac_officer_l", "fow_s_uk_seac_bren_gunner_l", "fow_s_uk_seac_bren_asst_l", "fow_s_uk_seac_at_l", "fow_s_uk_seac_at_asst_l", "fow_s_uk_seac_rifleman_l", "fow_s_uk_seac_rifleman_l"};
        crewmen[] = {"fow_s_uk_crewman", "fow_s_uk_crewman"};
        pilots[] = {"fow_s_us_pilot"};
        technicals[] = {"fow_v_universalCarrier", "fow_v_universalCarrier", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A3_75_Tubes", "LIB_M5A1_Stuart", "LIB_M4A3_75"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class FOW_CAN {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"fow_s_uk_can_01_teamleader", "fow_s_uk_can_01_section_commander", "fow_s_uk_can_01_rifleman", "fow_s_uk_can_01_radio_operator", "fow_s_uk_can_01_officer", "fow_s_uk_can_01_bren", "fow_s_uk_can_01_bren_asst", "fow_s_uk_can_01_at", "fow_s_uk_can_01_at_asst", "fow_s_uk_can_01_rifleman", "fow_s_uk_can_01_rifleman"};
        crewmen[] = {"fow_s_uk_crewman", "fow_s_uk_crewman"};
        pilots[] = {"fow_s_us_pilot"};
        technicals[] = {"fow_v_universalCarrier", "fow_v_universalCarrier", "LIB_M8_Greyhound", "LIB_US_M3_Halftrack", "LIB_US_M3_Halftrack"};
        armour[] = {"LIB_M3A3_Stuart", "LIB_M4A4_FIREFLY", "LIB_M5A1_Stuart", "fow_v_cromwell_uk"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_P47"};
    };

    class IF44_POL {
        side = "resistance";
        camouflage[] = {};
        infantry[] = {"LIB_WP_Stggunner", "LIB_WP_Sierzant", "LIB_WP_Porucznic", "LIB_WP_Starszy_strzelec", "LIB_WP_Strzelec", "LIB_WP_Mgunner", "LIB_WP_AT_grenadier"};
        crewmen[] = {"LIB_WP_Strzelec", "LIB_WP_Sierzant"};
        pilots[] = {"LIB_WP_Sierzant"};
        technicals[] = {"LIB_Kfz1_MG42", "LIB_SdKfz252", "LIB_Sdkfz251_FFV", "LIB_SdKfz222", "LIB_SdKfz234_1"};
        armour[] = {"LIB_PzKpfwIV_H", "LIB_StuG_III_G", "LIB_SdKfz124", "LIB_SdKfz234_2"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_Ju87"};
    };

    class IF44_GER_SN {
        side = "west";
        camouflage[] = {};
        infantry[] = {"LIB_GER_Stggunner_w", "LIB_GER_Scout_unterofficer_w", "LIB_GER_Unterofficer_w", "LIB_GER_Lieutenant_w", "LIB_GER_Scout_rifleman_w", "LIB_GER_Rifleman_w", "LIB_GER_Scout_ober_rifleman_w", "LIB_GER_Ober_rifleman_w", "LIB_GER_Scout_mgunner_w", "LIB_GER_AT_soldier_w", "LIB_GER_AT_grenadier_w", "LIB_GER_Scout_smgunner_w"};
        crewmen[] = {"LIB_GER_Scout_smgunner_w", "LIB_GER_Scout_unterofficer_w"};
        pilots[] = {"LIB_GER_pilot"};
        technicals[] = {"LIB_Sdkfz251_w", "LIB_Sdkfz251_FFV_w"};
        armour[] = {"LIB_PzKpfwIV_H_w", "LIB_StuG_III_G_w", "LIB_PzKpfwV_w", "LIB_PzKpfwVI_E_w"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_Ju87_w"};
    };

    class FOW_GER {
        side = "west";
        camouflage[] = {};
        infantry[] = {"fow_s_ger_heer_rifleman_mp40", "fow_s_ger_heer_rifleman_mp40_pzf", "fow_s_ger_heer_rifleman_g43", "fow_s_ger_heer_rifleman", "fow_s_ger_heer_radio_operator", "fow_s_ger_heer_nco_mp40", "fow_s_ger_heer_mg42_gunner", "fow_s_ger_heer_mg34_gunner", "fow_s_ger_heer_tl_asst", "fow_s_ger_heer_tl_stg", "fow_s_ger_heer_tl_mp40", "fow_s_ger_heer_mg42_sparebarrel", "fow_s_ger_heer_mg42_asst"};
        crewmen[] = {"fow_s_ger_heer_tankcrew_01_2nd_leutnant", "fow_s_ger_heer_tankcrew_01_shutz"};
        pilots[] = {"LIB_GER_pilot"};
        technicals[] = {"LIB_SdKfz222", "LIB_Kfz1_MG42", "LIB_SdKfz251", "LIB_Sdkfz251_FFV"};
        armour[] = {"LIB_StuG_III_G", "LIB_SdKfz124", "LIB_PzKpfwVI_E_1", "LIB_PzKpfwIV_H", "LIB_PzKpfwV"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_Ju87"};
    };

    class FOW_GER_SS {
        side = "west";
        camouflage[] = {};
        infantry[] = {"fow_s_ger_ss_tl_stg", "fow_s_ger_ss_tl_mp40", "fow_s_ger_ss_rifleman_mp40", "fow_s_ger_ss_rifleman_g43", "fow_s_ger_ss_rifleman", "fow_s_ger_ss_radio_operator", "fow_s_ger_ss_nco_mp40", "fow_s_ger_ss_mg42_gunner", "fow_s_ger_ss_mg43_gunner", "fow_s_ger_ss_mg42_sparebarrel", "fow_s_ger_ss_mg42_asst"};
        crewmen[] = {"fow_s_ger_heer_tankcrew_01_2nd_leutnant", "fow_s_ger_heer_tankcrew_01_shutz"};
        pilots[] = {"LIB_GER_pilot"};
        technicals[] = {"LIB_SdKfz222", "LIB_Kfz1_MG42", "LIB_SdKfz251", "LIB_Sdkfz251_FFV"};
        armour[] = {"LIB_StuG_III_G", "LIB_SdKfz124", "LIB_PzKpfwVI_E_1", "LIB_PzKpfwIV_H", "LIB_PzKpfwV"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_Ju87"};
    };

    class FOW_GER_PARA {
        side = "west";
        camouflage[] = {};
        infantry[] = {"fow_s_ger_luft_camo_tl_stg", "fow_s_ger_luft_camo_tl_mp40", "fow_s_ger_luft_camo_rifleman_mp40", "fow_s_ger_luft_camo_rifleman_g43", "fow_s_ger_luft_camo_rifleman_fg42", "fow_s_ger_luft_camo_rifleman", "fow_s_ger_luft_camo_radio_operator", "fow_s_ger_luft_camo_nco_mp40", "fow_s_ger_luft_camo_mg34_gunner", "fow_s_ger_luft_camo_mg42_gunner", "fow_s_ger_luft_camo_mg42_sparebarrel", "fow_s_ger_luft_camo_mg42_asst"};
        crewmen[] = {"fow_s_ger_heer_tankcrew_01_2nd_leutnant", "fow_s_ger_heer_tankcrew_01_shutz"};
        pilots[] = {"LIB_GER_pilot"};
        technicals[] = {"LIB_SdKfz222", "LIB_Kfz1_MG42", "LIB_SdKfz251", "LIB_Sdkfz251_FFV"};
        armour[] = {"LIB_StuG_III_G", "LIB_SdKfz124", "LIB_PzKpfwVI_E_1", "LIB_PzKpfwIV_H", "LIB_PzKpfwV"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_Ju87"};
    };

    class FOW_IJA {
        side = "west";
        camouflage[] = {};
        infantry[] = {"fow_s_ija_rifleman_at", "fow_s_ija_rifleman", "fow_s_ija_officer", "fow_s_ija_nco", "fow_s_ija_type99_gunner", "fow_s_ija_type99_asst", "fow_s_ija_rifleman", "fow_s_ija_rifleman"};
        crewmen[] = {"fow_s_ija_crewman", "fow_s_ija_crewman"};
        pilots[] = {"fow_s_ija_pilot"};
        technicals[] = {"fow_v_type97_truck_open_ija", "fow_v_type97_truck_ija"};
        armour[] = {"fow_ija_type95_HaGo_1_ija", "fow_ija_type95_HaGo_2_ija", "fow_ija_type95_HaGo_3_ija"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_RBAF_Ju87"};
    };

    class FOW_IJA_SNLF {
        side = "west";
        camouflage[] = {};
        infantry[] = {"fow_s_ija_snlf_rifleman_at", "fow_s_ija_snlf_rifleman", "fow_s_ija_snlf_nco", "fow_s_ija_snlf_type99_gunner", "fow_s_ija_snlf_type99_asst", "fow_s_ija_snlf_rifleman", "fow_s_ija_snlf_rifleman"};
        crewmen[] = {"fow_s_ija_crewman", "fow_s_ija_crewman"};
        pilots[] = {"fow_s_ija_pilot"};
        technicals[] = {"fow_v_type97_truck_open_ija", "fow_v_type97_truck_ija"};
        armour[] = {"fow_ija_type95_HaGo_1_ija", "fow_ija_type95_HaGo_2_ija", "fow_ija_type95_HaGo_3_ija"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_RBAF_Ju87"};
    };

    class IF44_USSR {
        side = "east";
        camouflage[] = {};
        infantry[] = {"LIB_SOV_smgunner", "LIB_SOV_lieutenant", "LIB_SOV_operator", "LIB_SOV_LC_rifleman", "LIB_SOV_mgunner", "LIB_SOV_gun_crew", "LIB_SOV_gun_sergeant", "LIB_SOV_first_lieutenant", "LIB_SOV_captain", "LIB_SOV_LC_rifleman", "LIB_SOV_AT_grenadier", "LIB_SOV_AT_soldier"};
        crewmen[] = {"LIB_SOV_tank_overall_lieutenant", "LIB_SOV_tank_overall_crew"};
        pilots[] = {"LIB_SOV_pilot"};
        technicals[] = {"LIB_Scout_M3", "LIB_Scout_M3_FFV", "LIB_SOV_M3_Halftrack", "LIB_SdKfz251_captured", "LIB_Sdkfz2_FFV"};
        armour[] = {"LIB_JS2_43", "LIB_M4A2_SOV", "LIB_SU85", "LIB_T34_76", "LIB_T34_85", "LIB_T34_85"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_Pe2"};
    };

    class IF44_USSR_NKVD {
        side = "east";
        camouflage[] = {};
        infantry[] = {"LIB_NKVD_smgunner", "LIB_NKVD_sergeant", "LIB_NKVD_p_officer", "LIB_NKVD_rifleman", "LIB_NKVD_LC_rifleman", "LIB_NKVD_firest_lieutenant"};
        crewmen[] = {"LIB_SOV_tank_overall_lieutenant", "LIB_SOV_tank_overall_crew"};
        pilots[] = {"LIB_SOV_pilot"};
        technicals[] = {"LIB_Scout_M3", "LIB_Scout_M3_FFV", "LIB_SOV_M3_Halftrack", "LIB_SdKfz251_captured", "LIB_Sdkfz2_FFV"};
        armour[] = {"LIB_JS2_43", "LIB_M4A2_SOV", "LIB_SU85", "LIB_T34_76", "LIB_T34_85", "LIB_T34_85"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_Pe2"};
    };

    class IF44_USSR_SN {
        side = "east";
        camouflage[] = {};
        infantry[] = {"LIB_SOV_Smgunner_w", "LIB_SOV_Lieutenant_w", "LIB_SOV_Operator_w", "LIB_SOV_Assault_sergeant_w", "LIB_SOV_P_officer_w", "LIB_SOV_Rifleman_w", "LIB_SOV_Mgunner_w", "LIB_SOV_Captain_w", "LIB_SOV_AT_grenadier_w", "LIB_SOV_AT_soldier_W", "LIB_SOV_Rifleman_w", "LIB_SOV_Rifleman_w"};
        crewmen[] = {"LIB_SOV_tank_captain", "LIB_SOV_tank_crew"};
        pilots[] = {"LIB_SOV_pilot"};
        technicals[] = {"LIB_Scout_M3_w", "LIB_Scout_M3_FFV_w", "LIB_SOV_M3_Halftrack_w"};
        armour[] = {"LIB_JS2_43_w", "LIB_M4A2_SOV_w", "LIB_SU85_w", "LIB_T34_76_w", "LIB_T34_85_w", "LIB_T34_85_w"};
        th[] = {"LIB_Li2﻿"};
        ah[] = {"LIB_Pe2_w"};
    };

    class USM_RAN_90_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"usm_ranger_90s_w_h_ftl", "usm_ranger_90s_w_h_gr", "usm_ranger_90s_w_h_mg", "usm_ranger_90s_w_h_mgab", "usm_ranger_90s_w_h_nco", "usm_ranger_90s_w_h_off", "usm_ranger_90s_w_h_rm1", "usm_ranger_90s_w_h_at4", "usm_ranger_90s_w_h_ar"};
        crewmen[] = {"usm_soldier_90s_w_h_crew1", "usm_soldier_90s_w_h_crew1"};
        pilots[] = {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_MK19_USMC"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M2Bradley_USA_W", "CUP_B_M1A1_Woodland_USMC"};
        th[] = {"CUP_B_UH60S_USN"};
        ah[] = {"CUP_B_AH64D_DL_USA"};
    };

    class USM_USA_90_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"usm_soldier_90s_w_h_ftl", "usm_soldier_90s_w_h_gr", "usm_soldier_90s_w_h_mg", "usm_soldier_90s_w_h_mgab", "usm_soldier_90s_w_h_nco", "usm_soldier_90s_w_h_off", "usm_soldier_90s_w_h_rm1", "usm_soldier_90s_w_h_at4", "usm_soldier_90s_w_h_ar"};
        crewmen[] = {"usm_soldier_90s_w_h_crew1", "usm_soldier_90s_w_h_crew1"};
        pilots[] = {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_MK19_USMC"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M2Bradley_USA_W", "CUP_B_M1A1_Woodland_USMC", "CUP_B_M60A3_TTS_USMC"};
        th[] = {"CUP_B_UH60S_US"};
        ah[] = {"CUP_B_AH64D_DL_USA"};
    };

    class USM_USMC_90_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"usm_marine_90s_w_h_ftl", "usm_marine_90s_w_h_gr", "usm_marine_90s_w_h_mg", "usm_marine_90s_w_h_mgab", "usm_marine_90s_w_h_nco", "usm_marine_90s_w_h_off", "usm_marine_90s_w_h_rm1", "usm_marine_90s_w_h_at4", "usm_marine_90s_w_h_ar"};
        crewmen[] = {"usm_marine_90s_w_h_crew1", "usm_marine_90s_w_h_crew1"};
        pilots[] = {"CUP_B_USMC_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M1114_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_M2_USMC", "CUP_B_HMMWV_MK19_USMC"};
        armour[] = {"CUP_B_LAV24M240_USMC", "CUP_B_LAV24M240_USMC", "CUP_B_AAV_USMC", "CUP_B_M1A1_Woodland_USMC", "CUP_B_M60A3_TTS_USMC"};
        th[] = {"CUP_B_UH60S_USN"};
        ah[] = {"CUP_B_AH1Z_Dynamic_USMC"};
    };

    class USM_USA_90_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"usm_soldier_90s_d_h_ftl", "usm_soldier_90s_d_h_gr", "usm_soldier_90s_d_h_mg", "usm_soldier_90s_d_h_mgab", "usm_soldier_90s_d_h_nco", "usm_soldier_d_h_off", "usm_soldier_90s_d_h_rm1", "usm_soldier_90s_d_h_at4", "usm_soldier_90s_d_h_ar"};
        crewmen[] = {"usm_soldier_90s_d_h_crew1", "usm_soldier_90s_d_h_crew1"};
        pilots[] = {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M2Bradley_USA_D", "CUP_B_M1A1_DES_US_Army"};
        th[] = {"CUP_B_UH60M_US"};
        ah[] = {"CUP_B_AH64D_DL_USA"};
    };

    class USM_USA_80_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"usm_soldier_80s_d_h_ftl", "usm_soldier_80s_d_h_gr", "usm_soldier_80s_d_h_mg", "usm_soldier_80s_d_h_mgab", "usm_soldier_80s_d_h_nco", "usm_soldier_d_h_off", "usm_soldier_80s_d_h_rm1", "usm_soldier_80s_d_h_at4", "usm_soldier_80s_d_h_ar"};
        crewmen[] = {"usm_soldier_80s_d_h_crew1", "usm_soldier_80s_d_h_crew1"};
        pilots[] = {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_M113_USA", "CUP_B_M2Bradley_USA_D", "CUP_B_M1A1_DES_US_Army"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_AH64_DL_USA"};
    };

    class USM_USMC_90_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"usm_marine_90s_d_h_ftl", "usm_marine_90s_d_h_gr", "usm_marine_90s_d_h_mg", "usm_marine_90s_d_h_mgab", "usm_marine_90s_d_h_nco", "usm_soldier_d_h_off", "usm_marine_90s_d_h_rm1", "usm_marine_90s_d_h_at4", "usm_marine_90s_d_h_ar"};
        crewmen[] = {"usm_marine_90s_d_h_crew1", "usm_marine_90s_d_h_crew1"};
        pilots[] = {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_LAV25M240_desert_USMC", "CUP_B_M1A1_DES_US_Army"};
        th[] = {"CUP_B_UH60M_US"};
        ah[] = {"CUP_B_AH1Z_Dynamic_USMC"};
    };

    class USM_USMC_80_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"usm_soldier_80s_d_h_ftl", "usm_soldier_80s_d_h_gr", "usm_soldier_80s_d_h_mg", "usm_soldier_80s_d_h_mgab", "usm_soldier_80s_d_h_nco", "usm_soldier_d_h_off", "usm_soldier_80s_d_h_rm1", "usm_soldier_80s_d_h_at4", "usm_soldier_80s_d_h_ar"};
        crewmen[] = {"usm_soldier_80s_d_h_crew1", "usm_soldier_80s_d_h_crew1"};
        pilots[] = {"CUP_B_US_Pilot"};
        technicals[] = {"CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_M2_USA", "CUP_B_HMMWV_MK19_USA"};
        armour[] = {"CUP_B_M113_USA", "CUP_B_LAV25M240_desert_USMC", "CUP_B_M1A1_DES_US_Army"};
        th[] = {"CUP_B_UH1D_slick_GER_KSK_Des"};
        ah[] = {"CUP_B_AH1Z"};
    };

    class ARK_NVA {
        side = "east";
        camouflage[] = {"woodland"};
        infantry[] = {"ARK_NVA_Soldier_TL_F", "ARK_NVA_Soldier_LAT_F", "ARK_NVA_Soldier_F", "ARK_NVA_Soldier_MG_F", "ARK_NVA_Soldier_AR_F", "ARK_NVA_Soldier_F", "ARK_NVA_Soldier_F", "ARK_NVA_Soldier_AR_F", "ARK_NVA_Soldier_TL_F"};
        crewmen[] = {"ARK_NVA_Crew_F", "ARK_NVA_Crew_F"};
        pilots[] = {"ARK_NVA_Pilot_F"};
        technicals[] = {"CUP_O_UAZ_MG_SLA", "CUP_O_UAZ_MG_SLA", "CUP_I_BTR40_MG_TKG", "CUP_O_UAZ_SPG9_SLA", "CUP_O_UAZ_AGS30_SLA"};
        armour[] = {"CUP_O_BTR60_Green_RU", "CUP_O_BRDM2_SLA", "CUP_I_T55_TK_GUE", "CUP_I_T34_NAPA", "CUP_O_MTLB_pk_SLA"};
        th[] = {"CUP_O_Mi8_SLA_2"};
        ah[] = {"CUP_O_Mi8_SLA_2"};
    };

    class CUP_CZ_WD {
        side = "west";
        camouflage[] = {"woodland"};
        infantry[] = {"CUP_B_CZ_Soldier_ARPG_WDL", "CUP_B_CZ_Soldier_AT_WDL", "CUP_B_CZ_Soldier_AMG_WDL", "CUP_B_CZ_Soldier_AR_WDL", "CUP_B_CZ_Soldier_805_GL_WDL", "CUP_B_CZ_Soldier_805_WDL", "CUP_B_CZ_Soldier_805_WDL", "CUP_B_CZ_Soldier_805_WDL", "CUP_B_CZ_Soldier_SL_WDL", "CUP_B_CZ_Soldier_MG_WDL", "CUP_B_CZ_Soldier_WDL", "CUP_B_CZ_Soldier_backpack_WDL", "CUP_B_CZ_Soldier_RPG_WDL"};
        crewmen[] = {"CUP_B_CZ_Crew_WDL", "CUP_B_CZ_Crew_WDL"};
        pilots[] = {"CUP_B_CZ_Pilot_WDL"};
        technicals[] = {"CUP_B_LR_MG_CZ_W", "CUP_B_LR_Special_CZ_W", "CUP_B_UAZ_AGS30_ACR", "CUP_B_UAZ_MG_ACR", "CUP_B_UAZ_SPG9_ARC", "CUP_B_Dingo_GL_CZ_Wdl", "CUP_B_Dingo_CZ_Wdl"};
        armour[] = {"CUP_B_BMP2_CZ", "CUP_B_BMP2_CZ", "CUP_B_BRDM2_CZ", "CUP_B_T72_CZ"};
        th[] = {"CUP_B_Mi171Sh_ACR"};
        ah[] = {"CUP_B_Mi171Sh_ACR", "CUP_B_Mi35_Dynamic_CZ"};
    };

    class CUP_CZ_DE {
        side = "west";
        camouflage[] = {"desert"};
        infantry[] = {"CUP_B_Soldier_805_DES", "CUP_B_Soldier_805_DES", "CUP_B_CZ_Soldier_805_GL_DES", "CUP_B_CZ_Soldier_AR_DES", "CUP_B_Soldier_SL_DES", "CUP_B_Soldier_RPG_DES", "CUP_B_CZ_Soldier_Backpack_DES", "CUP_B_CZ_Soldier_AT_DES", "CUP_B_CZ_Soldier_DES", "CUP_B_CZ_Soldier_DES", "CUP_B_CZ_Soldier_MG_DES", "CUP_B_CZ_Soldier_AMG_DES", "CUP_B_CZ_Soldier_ARPG_DES"};
        crewmen[] = {"CUP_B_CZ_Crew_DES", "CUP_B_CZ_Crew_DES"};
        pilots[] = {"CUP_B_CZ_Pilot_DES"};
        technicals[] = {"CUP_B_Dingo_GL_CZ_Des", "CUP_B_Dingo_CZ_Des", "CUP_B_HMMWV_AGS_GPK_ACR", "CUP_B_HMMWV_DSHKM_GPK_ACR", "CUP_B_HMMWV_M2_GPK_ACR", "CUP_B_LR_Special_Des_CZ_D", "CUP_B_HMMWV_M2_GPK_ACR"};
        armour[] = {"CUP_B_BMP2_CZ_Des", "CUP_B_BMP2_CZ_Des", "CUP_B_BRDM2_CZ_Des", "CUP_B_T72_CZ"};
        th[] = {"CUP_B_Mi171Sh_ACR"};
        ah[] = {"CUP_B_Mi171Sh_ACR", "CUP_B_Mi35_Dynamic_CZ_Des"};
    };

    class GEND {
        side = "west";
        camouflage[] = {};
        infantry[] = {"B_GEN_Soldier_F", "B_GEN_Soldier_F", "B_GEN_Commander_F", "B_GEN_Soldier_AR_F", "B_GEN_Commander_F", "B_GEN_Soldier_SMG_F", "B_GEN_Soldier_F", "B_GEN_Soldier_SMG_F", "B_GEN_Soldier_Pistol_F", "B_GEN_Soldier_Pistol_F", "B_GEN_Soldier_AR_F"};
        crewmen[] = {"B_GEN_Soldier_Crew_F", "B_GEN_Soldier_Crew_F"};
        pilots[] = {"B_GEN_Soldier_Pilot_F"};
        technicals[] = {"B_GEN_Offroad_01_armed_F"};
        armour[] = {"B_GEN_APC_Wheeled_02_rcws_F"};
        th[] = {"B_Heli_Light_01_F"};
        ah[] = {"B_Heli_Light_01_armed_F"};
    };

    class GEND_SWAT {
        side = "west";
        camouflage[] = {};
        infantry[] = {"B_GEN_SWAT_F", "B_GEN_SWAT_F", "B_GEN_SWAT_TL_F", "B_GEN_SWAT_AR_F", "B_GEN_SWAT_Shield_F", "B_GEN_SWAT_LAT_F", "B_GEN_SWAT_AR_F", "B_GEN_SWAT_F", "B_GEN_SWAT_TL_F", "B_GEN_SWAT_Shield_F", "B_GEN_SWAT_MG_F", "B_GEN_SWAT_MG_F", "B_GEN_SWAT_LAT_F"};
        crewmen[] = {"B_GEN_SWAT_Crew_F", "B_GEN_SWAT_Crew_F"};
        pilots[] = {"B_GEN_SWAT_Pilot_F"};
        technicals[] = {"B_GEN_LSV_01_armed_black_F", "B_GEN_MRAP_01_hmg_F"};
        armour[] = {"B_GEN_APC_Wheeled_02_rcws_F"};
        th[] = {"CUP_B_UH60M_US"};
        ah[] = {"CUP_I_Mi24_D_ION"};
    };

};
