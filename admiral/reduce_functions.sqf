#include "admiral_macros.h"

#include "logbook.h"

adm_reduce_fnc_setGroupExpandCount = {
    FUN_ARGS_1(_group);

    _group setVariable ["adm_reduce_expandCount", {alive _x && {_x != leader _group}} count units _group, false];
};

adm_reduce_fnc_setCqcInitPositions = {
    FUN_ARGS_1(_group);

    DECLARE(_initPositions) = [];
    {
        if (leader _group != _x) then { 
            PUSH(_initPositions, getPosATL _x);
        };
    } foreach units _group;
    _group setVariable ["adm_reduce_initPositions", _initPositions, false];
};

adm_reduce_fnc_reduceGroup = {
    FUN_ARGS_1(_group);

    [_group] call adm_reduce_fnc_setGroupExpandCount;
    _group setVariable ["adm_reduce_isReduced", true, false];
    {
        if (leader _group != _x) then { 
            TRACE("admiral.reduce",FMT_2("Removing unit '%1' from group '%2'.",_x,_group));
            deleteVehicle _x;
        };
    } foreach units _group;
    DEBUG("admiral.reduce",FMT_2("Reduced group '%1', removed '%2' unit(s).",_group,_group getVariable "adm_reduce_expandCount"));
};

adm_reduce_fnc_expandGroup = {
    FUN_ARGS_3(_group,_positions,_placeManFunc);

    {
        private ["_trigger", "_unitTemplate", "_unitType"];
        _trigger = _group getVariable "adm_zone_parent";
        _unitTemplate = _trigger getVariable "adm_zone_unitTemplate";
        _unitType = UNIT_TYPE_ARRAY select UNIT_TYPE_INF;
        [_x, _group, _unitTemplate, _unitType] call _placeManFunc;
        TRACE("admiral.reduce",FMT_1("Created unit for group '%1'.",_group));
    } foreach _positions;
    _group setVariable ["adm_reduce_isReduced", false, false];
    DEBUG("admiral.reduce",FMT_2("Expanded group '%1', created '%2' unit(s).",_group,count _positions));
};

adm_reduce_fnc_expandGroups = {
    FUN_ARGS_3(_groups,_positionsFunc,_placeManFunc);

    {
        if (_x getVariable ["adm_reduce_isReduced", false]) then {
            [_x, [_x] call _positionsFunc, _placeManFunc] call adm_reduce_fnc_expandGroup;
        };
    } foreach _groups;
};

adm_reduce_fnc_expandAllGroups = {
    DEBUG("admiral.reduce","Expanding all groups.");
    [adm_cqc_groups, adm_reduce_fnc_getCqcGroupPositions, adm_cqc_fnc_placeMan] call adm_reduce_fnc_expandGroups;
    [adm_patrol_infGroups, adm_reduce_fnc_getPatrolGroupPositions, adm_patrol_fnc_placeMan] call adm_reduce_fnc_expandGroups;
    [adm_camp_infGroups, adm_reduce_fnc_getPatrolGroupPositions, adm_patrol_fnc_placeMan] call adm_reduce_fnc_expandGroups;
};

adm_reduce_fnc_getCqcGroupPositions = {
    FUN_ARGS_1(_group);

    private ["_poitions", "_expandCount", "_initPositions"];
    _positions = [];
    _expandCount = _group getVariable ["adm_reduce_expandCount", 0];
    _initPositions = _group getVariable "adm_reduce_initPositions";
    for "_i" from 0 to  _expandCount - 1 do {
        PUSH(_positions, _initPositions select _i);
    };

    _positions;
};

adm_reduce_fnc_getPatrolGroupPositions = {
    FUN_ARGS_1(_group);

    private ["_poitions", "_expandCount"];
    _positions = [];
    _expandCount = _group getVariable ["adm_reduce_expandCount", 0];
    for "_i" from 1 to _expandCount do {
       PUSH(_positions, getPosATL leader _group);
    };

    _positions;
};


adm_reduce_fnc_canReduceGroup = {
    FUN_ARGS_1(_group);

    private ["_canReduce", "_isReduced"];
    _canReduce = false;
    _isReduced = _group getVariable ["adm_reduce_isReduced", false];
    if (!_isReduced) then {
        DECLARE(_players) = [side _group] call adm_reduce_fnc_getMonitoredUnits;
        _canReduce = true;
        {
            _canReduce = [_x, _group, REDUCE_DISTANCE] call adm_reduce_fnc_unitOutsideReduceDistance;
            if (!_canReduce) exitWith {};
        } foreach _players;
    };
    _canReduce;
};

adm_reduce_fnc_canExpandGroup = {
    FUN_ARGS_1(_group);

    private ["_canExpand", "_isReduced"];
    _canExpand = false;
    _isReduced = _group getVariable ["adm_reduce_isReduced", false];
    if (_isReduced) then {
        DECLARE(_players) = [side _group] call adm_reduce_fnc_getMonitoredUnits;
        {
            _canExpand = !([_x, _group, EXPAND_DISTANCE] call adm_reduce_fnc_unitOutsideReduceDistance);
            if (_canExpand) exitWith {};
        } foreach _players;
    };

    _canExpand;
};

adm_reduce_fnc_checkGroups = {
    FUN_ARGS_3(_groups,_getPositionsFunc,_placeManFunc);

    {
        if ([_x] call adm_reduce_fnc_canReduceGroup) then {
            DEBUG("admiral.reduce",FMT_1("Group '%1' can be reduced.",_x));
            [_x] call adm_reduce_fnc_reduceGroup;
        } else {
            if ([_x] call adm_reduce_fnc_canExpandGroup) then {
                DEBUG("admiral.reduce",FMT_1("Group '%1' can be expanded.",_x));
                [_x, [_x] call _getPositionsFunc, _placeManFunc] call adm_reduce_fnc_expandGroup;
            };
        };
    } foreach _groups;
};

adm_reduce_fnc_monitorGroups = {
    waitUntil {
        [adm_cqc_groups, adm_reduce_fnc_getCqcGroupPositions, adm_cqc_fnc_placeMan] call adm_reduce_fnc_checkGroups;
        [adm_patrol_infGroups, adm_reduce_fnc_getPatrolGroupPositions, adm_patrol_fnc_placeMan] call adm_reduce_fnc_checkGroups;
        [adm_camp_infGroups, adm_reduce_fnc_getPatrolGroupPositions, adm_patrol_fnc_placeMan] call adm_reduce_fnc_checkGroups;
        sleep 1;
        !adm_isCachingEnabled;
    };
    DEBUG("admiral.reduce","Monitoring has been stopped.");
    sleep 1;
    [] call adm_reduce_fnc_expandAllGroups;
};

adm_reduce_fnc_enableCaching = {
    if (!adm_isCachingEnabled) then {
        INFO("admiral.reduce","Enabling caching.");
        adm_isCachingEnabled = true;
        [] call adm_reduce_fnc_init;
    };
};

adm_reduce_fnc_disableCaching = {
    if (adm_isCachingEnabled) then {
        INFO("admiral.reduce","Disabling caching.");
        adm_isCachingEnabled = false;
        [] call adm_reduce_fnc_expandAllGroups;
    };
};

adm_reduce_fnc_unitOutsideReduceDistance = {
    FUN_ARGS_3(_unit,_group,_distance);

    (getPosATL _unit) distance (getPosATL leader _group) > _distance;
};

adm_reduce_fnc_getMonitoredUnits = {
    FUN_ARGS_1(_side);

    DECLARE(_units) = [];
    FILTER_PUSH_ALL(_units, ALL_UNITS, {!(AS_ARRAY_2(side _x, _side) call adm_common_fnc_isFriendlySide) || {isPlayer _x}});
    _units;
};

adm_reduce_fnc_init = {
    if (adm_isCachingEnabled) then {
        [] spawn adm_reduce_fnc_monitorGroups;
    };
};