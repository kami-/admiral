#include "admiral_defines.h"

adm_rupture_fnc_initUnit = {
    FUN_ARGS_1(_unit);

    private "_ehId";
    _ehId = _unit addEventHandler ["Hit", {_this call adm_rupture_fnc_hitEH;}];
    _unit setVariable ["adm_rupture_eh_hit", _ehId];
    _ehId = _unit addEventHandler ["Killed", {_this call adm_rupture_fnc_killedEH;}];
    _unit setVariable ["adm_rupture_eh_killed", _ehId];
};

adm_rupture_fnc_hitEH = {
    FUN_ARGS_1(_unit);

    if (vehicle _unit == _unit) then {
        _unit setVariable ["adm_rupture_lastHitTime", diag_tickTime, false];
    };
};

adm_rupture_fnc_killedEH = {
    FUN_ARGS_1(_unit);

    _unit removeEventHandler ["Hit", _unit getVariable "adm_rupture_eh_hit"];
    _unit removeEventHandler ["Killed", _unit getVariable "adm_rupture_eh_killed"];
    _unit setVariable ["adm_rupture_eh_hit", nil];
    _unit setVariable ["adm_rupture_eh_killed", nil];
};

adm_rupture_fnc_initGroups = {
    {
        private "_group";
        _group = _x;
        {
            [_x] call adm_rupture_fnc_initUnit;
        } foreach (units _group)
    } foreach (_this select 0);
};

adm_rupture_fnc_checkUnits = {
    [] spawn { 
        waitUntil {
            {
                private ["_unit", "_elapsedTime"];
                _unit = _x;
                _elapsedTime = diag_tickTime - (_unit getVariable ["adm_rupture_lastHitTime", diag_tickTime]);
                if (_elapsedTime > adm_rupture_length) then {
                    _unit setDamage 1;
                }
            } foreach ([] call adm_common_fnc_getEnemyFactionUnits);
            sleep adm_rupture_updateTick;
            false;
        };
    };
};