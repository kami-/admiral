#include "admiral_defines.h"

adm_debug_fnc_debugSpawnedGroups = {
    [] spawn {
        waitUntil {
            [adm_patrol_infGroups] call adm_debug_fnc_updateWaypointMarkersForPatrolGroups;
            [adm_patrol_techGroups] call adm_debug_fnc_updateWaypointMarkersForPatrolGroups;
            [adm_patrol_armourGroups] call adm_debug_fnc_updateWaypointMarkersForPatrolGroups;

            [adm_patrol_infGroups] call adm_debug_fnc_updateStateMarkersForPatrolGroups;
            [adm_patrol_techGroups] call adm_debug_fnc_updateStateMarkersForPatrolGroups;
            [adm_patrol_armourGroups] call adm_debug_fnc_updateStateMarkersForPatrolGroups;

            [adm_camp_infGroups] call adm_debug_fnc_updateWaypointMarkersForPatrolGroups;
            [adm_camp_techGroups] call adm_debug_fnc_updateWaypointMarkersForPatrolGroups;
            [adm_camp_armourGroups] call adm_debug_fnc_updateWaypointMarkersForPatrolGroups;

            [adm_camp_infGroups] call adm_debug_fnc_updateStateMarkersForPatrolGroups;
            [adm_camp_techGroups] call adm_debug_fnc_updateStateMarkersForPatrolGroups;
            [adm_camp_armourGroups] call adm_debug_fnc_updateStateMarkersForPatrolGroups;

            [adm_cqc_groups] call adm_debug_fnc_updateMarkersForCqcGroups;

            sleep 2;
            false;
        };
    };
};

adm_debug_fnc_createMarkersForPatrolGroup = {
    FUN_ARGS_2(_group,_groupType);

    [format["%1", _group], getPosATL leader _group, "ICON", GROUP_TYPE_DEBUG_MARKERS select _groupType, [side _group] call adm_debug_fnc_getSideColor, GROUP_TYPE_DEBUG_MARKER_SIZES select _groupType] call adm_common_fnc_createLocalMarker;
    [format["WP_%1", _group], getWPPos [_group, currentWaypoint _group], "ICON", "waypoint", [side _group] call adm_debug_fnc_getSideColor, WAYPOINT_DEBUG_MARKER_SIZE] call adm_common_fnc_createLocalMarker;
    [format["LINE_%1", _group], getPosATL leader _group, getWPPos [_group, currentWaypoint _group], "ColorBlack", 1] call adm_debug_fnc_createLineMarker;
    [format["STATE_LINE_%1", _group], getPosATL leader _group, getPosATL leader _group, "ColorBlack", 1] call adm_debug_fnc_createLineMarker;
    format["STATE_LINE_%1", _group] setMarkerAlphaLocal 0;
};

adm_debug_fnc_updateWaypointMarkersForPatrolGroups = {
    FUN_ARGS_1(_groups);

    {
        private ["_leaderMarker", "_waypointMarker", "_lineMarker", "_group", "_unit"];
        _group = _x;
        _leaderMarker = format["%1", _group];
        _waypointMarker = format["WP_%1", _group];
        _lineMarker = format["LINE_%1", _group];
        _unit = leader _group;

        if (count units _group > 0) then {
            _leaderMarker setMarkerPosLocal (getPosATL _unit);
            _leaderMarker setMarkerTextLocal format["%1", count units _group];
            _waypointMarker setMarkerPosLocal (getWPPos [_group , currentWaypoint _group]);
            [_lineMarker, getPosATL _unit, getWPPos [_group , currentWaypoint _group]] call adm_debug_fnc_updateLineMarker
        } else {
            deleteMarkerLocal _leaderMarker;
            deleteMarkerLocal _waypointMarker;
            deleteMarkerLocal _lineMarker;
        };
    } foreach _groups;
};

adm_debug_fnc_updateStateMarkersForPatrolGroups = {
    FUN_ARGS_1(_groups);

    {
        private ["_group", "_lineMarker", "_state"];
        _group = _x;
        _lineMarker = format["STATE_LINE_%1", _group];
        _state = _group getVariable ["adm_behavior_state", STATE_INIT];
        if (count units _group > 0) then {
            call {
                if (_state == STATE_INIT || {_state == STATE_MOVING}) exitwith {
                    _lineMarker setMarkerAlphaLocal 0;
                };
                if (isNil {_group getVariable "adm_behavior_reinfGroup"} && {_state == STATE_ENEMYFOUND || {_state == STATE_SADENEMY} || {_state == STATE_COMBAT}}) exitwith {
                    _lineMarker setMarkerAlphaLocal 1;
                    [_lineMarker, getPosATL leader _group, _group getVariable "adm_behavior_enemyPos"] call adm_debug_fnc_updateLineMarker;
                    _lineMarker setMarkerColorLocal "ColorRed";
                };
                if (!isNil {_group getVariable "adm_behavior_reinfGroup"} && {_state == STATE_ENEMYFOUND || {_state == STATE_SADENEMY} || {_state == STATE_COMBAT}}) exitwith {
                    _lineMarker setMarkerAlphaLocal 1;
                    [_lineMarker, getPosATL leader _group, getPosATL leader (_group getVariable "adm_behavior_reinfGroup")] call adm_debug_fnc_updateLineMarker;
                    _lineMarker setMarkerColorLocal "ColorOrange";
                };
            };
        } else {
            deleteMarkerLocal _lineMarker;
        };
    } foreach _groups;
};

adm_debug_fnc_createMarkersForCqcGroup = {
    FUN_ARGS_1(_group);

    {
        [format["%1", _x], getPosATL _x, "ICON", CQC_DEBUG_MARKER, [side _group] call adm_debug_fnc_getSideColor, CQC_DEBUG_MARKER_SIZE] call adm_common_fnc_createLocalMarker;
    } foreach units _group;
};

adm_debug_fnc_updateMarkersForCqcGroups = {
    FUN_ARGS_1(_groups);

    {
        private "_group";
        _group = _x;
        {
            private "_marker";
            _marker = format["%1", _x];

            if (alive _x) then {
                _marker setMarkerPosLocal (getPosATL _x);
                _marker setMarkerDirLocal getDir _x;
            } else {
                deleteMarkerLocal _marker;
            };
        } foreach units _group;
    } foreach _groups;
};

adm_debug_fnc_createTriggerLocalMarker = {
    FUN_ARGS_2(_trigger,_color);

    private ["_shape", "_marker"];
    _shape = "RECTANGLE";
    if (!((triggerArea _trigger) select 3)) then {
        _shape = "ELLIPSE";
    };
    if (isNil {_color}) then {
        _color = [[_trigger getVariable "adm_zone_unitTemplate"] call adm_common_fnc_getUnitTemplateSide] call adm_debug_fnc_getSideColor;
    };

    _marker = [format["%1", _trigger], getPosATL _trigger, _shape, "DOT", _color] call adm_common_fnc_createLocalMarker;
    _marker setMarkerSizeLocal [(triggerArea _trigger) select 0, (triggerArea _trigger) select 1];
    _marker setMarkerDirLocal ((triggerArea _trigger) select 2);
    _marker setMarkerBrushLocal "Border";
};

adm_debug_fnc_updateTriggerLocalMarker = {
    FUN_ARGS_1(_trigger);

    private ["_shape", "_marker"];
    _shape = "RECTANGLE";
    if (!((triggerArea _trigger) select 3)) then {
        _shape = "ELLIPSE";
    };

    _marker = format["%1", _trigger];
    _marker setMarkerShapeLocal _shape;
    _marker setMarkerPosLocal getPosATL _trigger;
    _marker setMarkerSizeLocal [(triggerArea _trigger) select 0, (triggerArea _trigger) select 1];
    _marker setMarkerDirLocal ((triggerArea _trigger) select 2);
};

adm_debug_fnc_createMarkersForCampLogic = {
    FUN_ARGS_1(_logic);

    private "_waypoints";
    _waypoints = waypoints _logic;
    for "_i" from 0 to count _waypoints - 2 do {
        private ["_wpPosFrom", "_wpPosTo", "_marker"];
        _wpPosFrom = getWPPos (_waypoints select _i);
        _wpPosTo = getWPPos (_waypoints select (_i + 1));
        [format["%1", _wpPosFrom], _wpPosFrom, _wpPosTo, "ColorOrange", 3] call adm_debug_fnc_createLineMarker;
    };
    [_logic getVariable "adm_camp_endTrigger", "ColorOrange"] call adm_debug_fnc_createTriggerLocalMarker;
};

adm_debug_fnc_createLineMarker = {
    FUN_ARGS_5(_markerName,_posFrom,_posTo,_markerColor,_markerWidth);

    [_markerName, [_posFrom, (_posFrom distance _posTo) / 2, [_posFrom, _posTo] call BIS_fnc_dirTo] call BIS_fnc_relPos, "RECTANGLE", "DOT", _markerColor] call adm_common_fnc_createLocalMarker;
    _markerName setMarkerSizeLocal [_markerWidth, (_posFrom distance _posTo) / 2];
    _markerName setMarkerDirLocal ([_posFrom, _posTo] call BIS_fnc_dirTo);
};

adm_debug_fnc_updateLineMarker = {
    FUN_ARGS_3(_markerName,_posFrom,_posTo);

    _markerName setMarkerPosLocal ([_posFrom, (_posFrom distance _posTo) / 2, [_posFrom, _posTo] call BIS_fnc_dirTo] call BIS_fnc_relPos);
    _markerName setMarkerSizeLocal [(getMarkerSize _markerName) select 0, (_posFrom distance _posTo) / 2];
    _markerName setMarkerDirLocal ([_posFrom, _posTo] call BIS_fnc_dirTo);
};

adm_debug_fnc_getSideColor = {
    FUN_ARGS_1(_side);

    private "_index";
    _index = SIDE_ARRAY find _side;

    if (_index >= 0) then {
        SIDE_DEBUG_MARKER_COLORS select _index;
    } else {
        "ColorWhite";
    };
};

adm_debug_fnc_init = {
    if (adm_isDebuggingEnabled) then {
        [] call adm_debug_fnc_debugSpawnedGroups;
    };
};
