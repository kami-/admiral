adm_isInitialized = false;
call compile preProcessFileLineNumbers "admiral\hc_functions.sqf";
[] spawn adm_hc_fnc_init;