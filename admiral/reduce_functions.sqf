#include "admiral_defines.h"

adm_reduce_fnc_setGroupExpandCount = {
    FUN_ARGS_1(_group);

    _group setVariable ["adm_reduce_expandCount", {alive _x && {_x != leader _group}} count units _group, false];
};

adm_reduce_fnc_setCqcInitPositions = {
    FUN_ARGS_1(_group);

    private ["_initPositions"];
    _initPositions = [];
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
            deleteVehicle _x 
        };
    } foreach units _group;
};

adm_reduce_fnc_expandGroup = {
    FUN_ARGS_3(_group,_positions,_placeManFunc);

    {
        private ["_trigger", "_unitTemplate", "_unitType"];
        _trigger = _group getVariable "adm_zone_parent";
        _unitTemplate = _trigger getVariable "adm_zone_unitTemplate";
        _unitType = UNIT_TYPE_ARRAY select UNIT_TYPE_INF;
        [_x, _group, _unitTemplate, _unitType] call _placeManFunc;
    } foreach _positions;
    _group setVariable ["adm_reduce_isReduced", false, false];
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

    for [{private ["_i"]; _i = 0}, {_i < _expandCount}, {INC(_i)}] do {
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
        private ["_i", "_players"];
        _i = 0;
        _players = [side _group] call adm_reduce_fnc_getMonitoredUnits;
        _canReduce = true;
        while {_canReduce && _i < count _players} do {
            _canReduce = [_players select _i, _group, REDUCE_DISTANCE] call gfn_reduce_fnc_unitOutsideReduceDistance;
            INC(_i);
        };
    };
    _canReduce;
};

adm_reduce_fnc_canExpandGroup = {
    FUN_ARGS_1(_group);

    private ["_canExpand", "_isReduced"];
    _canExpand = false;
    _isReduced = _group getVariable ["adm_reduce_isReduced", false];
    if (_isReduced) then {
        private ["_i", "_players"];
        _i = 0;
        _players = [side _group] call adm_reduce_fnc_getMonitoredUnits;
        while {!_canExpand && _i < count _players} do {
            _canExpand = !([_players select _i, _group, EXPAND_DISTANCE] call gfn_reduce_fnc_unitOutsideReduceDistance);
            INC(_i);
        };
    };

    _canExpand;
};

adm_reduce_fnc_checkGroups = {
    FUN_ARGS_3(_groups,_getPositionsFunc,_placeManFunc);

    {
        if ([_x] call adm_reduce_fnc_canReduceGroup) then {
            [_x] call adm_reduce_fnc_reduceGroup;
        } else {
            if ([_x] call adm_reduce_fnc_canExpandGroup) then {
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
    sleep 1;
    [] call adm_reduce_fnc_expandAllGroups;
};

adm_reduce_fnc_enableCaching = {
    if (!adm_isCachingEnabled) then {
        adm_isCachingEnabled = true;
        [] call adm_reduce_fnc_init;
    };
};

adm_reduce_fnc_disableCaching = {
    if (adm_isCachingEnabled) then {
        adm_isCachingEnabled = false;
        [] call adm_reduce_fnc_expandAllGroups;
    };
};

gfn_reduce_fnc_unitOutsideReduceDistance = {
    FUN_ARGS_3(_unit,_group,_distance);

    (getPosATL _unit) distance (getPosATL leader _group) > _distance;
};

adm_reduce_fnc_getMonitoredUnits = {
    FUN_ARGS_1(_side);

    private "_units";
    _units = [];
    FILTER_PUSH_ALL(_units, ALL_UNITS, {!(AS_ARRAY_2(side _x, _side) call adm_common_fnc_isFriendlySide) || {isPlayer _x}});
    _units;
};

adm_reduce_fnc_init = {
    if (adm_isCachingEnabled) then {
        [] spawn adm_reduce_fnc_monitorGroups;
    };
};