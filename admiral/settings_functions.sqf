#include "settings.sqf"

adm_settings_fnc_initSideRelations = {
    adm_sideRelations = [];
    {
        adm_sideRelations set [_forEachIndex, []];
    } foreach SIDE_ARRAY;
};

adm_settings_fnc_defaultSideRelations = {
    [SIDE_WEST, SIDE_EAST] call adm_settings_fnc_setEnemy;
    [SIDE_WEST, SIDE_IND] call adm_settings_fnc_setEnemy;
     
    [SIDE_EAST, SIDE_WEST] call adm_settings_fnc_setEnemy;
    [SIDE_EAST, SIDE_IND] call adm_settings_fnc_setEnemy;
     
    [SIDE_IND, SIDE_WEST] call adm_settings_fnc_setEnemy;
    [SIDE_IND, SIDE_EAST] call adm_settings_fnc_setEnemy;
};

adm_settings_fnc_setEnemy = {
    FUN_ARGS_2(_side,_enemySide);

    private "_sideEnemies";
    _sideEnemies = adm_sideRelations select _side;
    if (!(_enemySide in _sideEnemies)) then {
        PUSH(_sideEnemies,_enemySide);
        (SIDE_ARRAY select _side) setFriend [(SIDE_ARRAY select _enemySide), 0];
    };
};

adm_settings_fnc_setFriendly = {
    FUN_ARGS_2(_side,_friendlySide);

    private "_sideEnemies";
    _sideEnemies = adm_sideRelations select _side;
    _enemySideIndex = _sideEnemies find _friendlySide;
    if (_enemySideIndex >= 0) then {
        adm_sideRelations set [_side, _sideEnemies - [_friendlySide]];
    };
    (SIDE_ARRAY select _side) setFriend [(SIDE_ARRAY select _friendlySide), 1];
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