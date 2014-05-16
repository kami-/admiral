#include "admiral_defines.h"

#include "log_macros.h"

adm_rupture_fnc_initUnit = {
    FUN_ARGS_1(_unit);

    DECLARE(_ehId) = _unit addEventHandler ["Hit", {_this call adm_rupture_fnc_hitEH;}];
    _unit setVariable ["adm_rupture_eh_hit", _ehId];
    _ehId = _unit addEventHandler ["Killed", {_this call adm_rupture_fnc_killedEH;}];
    _unit setVariable ["adm_rupture_eh_killed", _ehId];
    DEBUG("admiral.rupture",FMT_3("Initialized unit '%1' with Hit EH '%2' and Killed EH '%3'.",_unit,_unit getVariable "adm_rupture_eh_hit",_unit getVariable "adm_rupture_eh_killed"));
};

adm_rupture_fnc_hitEH = {
    FUN_ARGS_1(_unit);

    if (vehicle _unit == _unit) then {
        DEBUG("admiral.rupture",FMT_2("Unit '%1' got hit at '%2'.",_unit,diag_tickTime));
        _unit setVariable ["adm_rupture_lastHitTime", diag_tickTime, false];
    };
};

adm_rupture_fnc_killedEH = {
    FUN_ARGS_1(_unit);

    DEBUG("admiral.rupture",FMT_3("Unit '%1' got killed. Removing Hit EH '%2' and Killed EH '%3'.",_unit,_unit getVariable "adm_rupture_eh_hit",_unit getVariable "adm_rupture_eh_killed"));
    DECLARE(_ehId) = _unit getVariable ["adm_rupture_eh_hit", nil];
    if (!isNil {_ehId}) then {
        _unit removeEventHandler ["Hit", _ehId];
    };
    _ehId = _unit getVariable ["adm_rupture_eh_killed", nil];
    if (!isNil {_ehId}) then {
        _unit removeEventHandler ["Killed", _ehId];
    };
};

adm_rupture_fnc_initGroups = {
    {
        DECLARE(_group) = _x;
        {
            [_x] call adm_rupture_fnc_initUnit;
        } foreach (units _group)
    } foreach (_this select 0);
};

adm_rupture_fnc_checkUnits = {
    [] spawn { 
        waitUntil {
            DECLARE(_infUnits) = [[adm_cqc_groups, adm_patrol_infGroups, adm_camp_infGroups]] call adm_common_fnc_getAliveUnits;
            {
                private ["_unit", "_elapsedTime"];
                _unit = _x;
                _elapsedTime = diag_tickTime - (_unit getVariable ["adm_rupture_lastHitTime", diag_tickTime]);
                if (_elapsedTime > adm_rupture_length) then {
                    _unit setDamage 1;
                };
            } foreach _infUnits;
            sleep adm_rupture_updateTick;
            false;
        };
    };
};