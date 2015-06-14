#include "settings.sqf"

#include "\userconfig\admiral\log\settings.h"
#include "logbook.h"


adm_settings_fnc_initSideRelations = {
    adm_sideRelations = [];
    {
        adm_sideRelations set [_forEachIndex, []];
    } foreach SIDE_ARRAY;
    DEBUG("admiral.settings.siderelation","Initialized side relations.");
};

adm_settings_fnc_setDefaultSideRelations = {
    [SIDE_WEST, SIDE_EAST] call adm_settings_fnc_setEnemy;
    [SIDE_WEST, SIDE_IND] call adm_settings_fnc_setFriend;

    [SIDE_EAST, SIDE_WEST] call adm_settings_fnc_setEnemy;
    [SIDE_EAST, SIDE_IND] call adm_settings_fnc_setEnemy;

    [SIDE_IND, SIDE_WEST] call adm_settings_fnc_setFriend;
    [SIDE_IND, SIDE_EAST] call adm_settings_fnc_setEnemy;
    DEBUG("admiral.settings.siderelation","Set default side relations.");
};

adm_settings_fnc_setEnemy = {
    FUN_ARGS_2(_side,_enemySide);

    DECLARE(_sideEnemies) = adm_sideRelations select _side;
    if (!(_enemySide in _sideEnemies)) then {
        PUSH(_sideEnemies,_enemySide);
        (SIDE_ARRAY select _side) setFriend [(SIDE_ARRAY select _enemySide), 0];
        DEBUG("admiral.settings.siderelation",FMT_2("Side '%1' is hostile towards side '%2'.",SIDE_TEXT_ARRAY select _side,SIDE_TEXT_ARRAY select _enemySide));
    };
};

adm_settings_fnc_setFriend = {
    FUN_ARGS_2(_side,_friendlySide);

    private ["_sideEnemies", "_enemySideIndex"];
    _sideEnemies = adm_sideRelations select _side;
    _enemySideIndex = _sideEnemies find _friendlySide;
    if (_enemySideIndex >= 0) then {
        adm_sideRelations set [_side, _sideEnemies - [_friendlySide]];
    };
    (SIDE_ARRAY select _side) setFriend [(SIDE_ARRAY select _friendlySide), 1];
    DEBUG("admiral.settings.siderelation",FMT_2("Side '%1' is friendly towards side '%2'.",SIDE_TEXT_ARRAY select _side,SIDE_TEXT_ARRAY select _friendlySide));
};

adm_settings_fnc_createCenters = {
    {
        createCenter _x;
    } foreach SIDE_ARRAY;
    DEBUG("admiral.settings","AI centers have created.");
};

adm_settings_fnc_init = {
    [] call adm_settings_fnc_createCenters;
    [] call adm_settings_fnc_initSideRelations;
    [] call adm_settings_fnc_setDefaultSideRelations;
    [] call adm_settings_fnc_setSideRelations;
};