#include "settings.sqf"

adm_settings_fnc_initSideRelations = {
    adm_sideRelations = [];
    {
        adm_sideRelations set [_forEachIndex, []];
    } foreach SIDE_ARRAY;
};

adm_settings_fnc_defaultSideRelations = {
    [SIDE_WEST, SIDE_ENEMY] call adm_settings_fnc_setSideEnemy;
    [SIDE_WEST, SIDE_EAST] call adm_settings_fnc_setSideEnemy;
    [SIDE_WEST, SIDE_IND] call adm_settings_fnc_setSideEnemy;
     
    [SIDE_EAST, SIDE_ENEMY] call adm_settings_fnc_setSideEnemy;
    [SIDE_EAST, SIDE_WEST] call adm_settings_fnc_setSideEnemy;
    [SIDE_EAST, SIDE_IND] call adm_settings_fnc_setSideEnemy;
     
    [SIDE_IND, SIDE_ENEMY] call adm_settings_fnc_setSideEnemy;
    [SIDE_IND, SIDE_WEST] call adm_settings_fnc_setSideEnemy;
    [SIDE_IND, SIDE_EAST] call adm_settings_fnc_setSideEnemy;
    
    [SIDE_CIV, SIDE_ENEMY] call adm_settings_fnc_setSideEnemy;
};

adm_settings_fnc_setSideEnemy = {
    FUN_ARGS_2(_side,_enemySide);

    private "_sideEnemies";
    _sideEnemies = adm_sideRelations select _side;
    if (!(_enemySide in _sideEnemies)) then {
        PUSH(_sideEnemies,_enemySide);
        (SIDE_ARRAY select _side) setFriend [(SIDE_ARRAY select _enemySide), 0];
    };
};

adm_settings_fnc_setSideFriendly = {
    FUN_ARGS_2(_side,_otherSide);

    private "_sideEnemies";
    _sideEnemies = adm_sideRelations select _side;
    _enemySideIndex = _sideEnemies find _otherSide;
    if (_enemySideIndex >= 0) then {
        adm_sideRelations set [_side, _sideEnemies - [_otherSide]];
    };
    (SIDE_ARRAY select _side) setFriend [(SIDE_ARRAY select _otherSide), 1];
};

adm_settings_fnc_createCenters = {
    {
        createCenter _x;
    } foreach SIDE_ARRAY;
};

adm_settings_fnc_init = {
    [] call adm_settings_fnc_createCenters;
    [] call adm_settings_fnc_initSideRelations;
    [] call adm_settings_fnc_setSideRelations;
};