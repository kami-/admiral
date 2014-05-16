#include "admiral_defines.h"

#include "log_macros.h"

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

            DEBUG("admiral.debug","Updated debug markers.");
            sleep 2;
            false;
        };
    };
};

adm_debug_fnc_createMarkersForPatrolGroup = {
    FUN_ARGS_2(_group,_groupType);

    [format ["%1", _group], getPosATL leader _group, "ICON", GROUP_TYPE_DEBUG_MARKERS select _groupType, [side _group] call adm_debug_fnc_getSideColor, GROUP_TYPE_DEBUG_MARKER_SIZES select _groupType] call adm_common_fnc_createLocalMarker;
    [format ["WP_%1", _group], getWPPos [_group, currentWaypoint _group], "ICON", "waypoint", [side _group] call adm_debug_fnc_getSideColor, WAYPOINT_DEBUG_MARKER_SIZE] call adm_common_fnc_createLocalMarker;
    [format ["LINE_%1", _group], getPosATL leader _group, getWPPos [_group, currentWaypoint _group], "ColorBlack", 1] call adm_debug_fnc_createLineMarker;
    [format ["STATE_LINE_%1", _group], getPosATL leader _group, getPosATL leader _group, "ColorBlack", 1] call adm_debug_fnc_createLineMarker;
    format ["STATE_LINE_%1", _group] setMarkerAlphaLocal 0;
    DEBUG("admiral.debug",FMT_5("Created waypoint markers '[%1, %2, %3]' and behavior marker '%4' for dead patrol group '%5'.",_group,format AS_ARRAY_2("WP_%1", _group),format AS_ARRAY_2("LINE_%1", _group),format AS_ARRAY_2("STATE_LINE_%1", _group),_group));
};

adm_debug_fnc_updateWaypointMarkersForPatrolGroups = {
    FUN_ARGS_1(_groups);

    {
        private ["_leaderMarker", "_waypointMarker", "_lineMarker", "_group", "_unit"];
        _group = _x;
        _leaderMarker = format ["%1", _group];
        _waypointMarker = format ["WP_%1", _group];
        _lineMarker = format ["LINE_%1", _group];
        _unit = leader _group;

        if (count units _group > 0) then {
            _leaderMarker setMarkerPosLocal (getPosATL _unit);
            _leaderMarker setMarkerTextLocal format ["%1", count units _group];
            _waypointMarker setMarkerPosLocal (getWPPos [_group , currentWaypoint _group]);
            [_lineMarker, getPosATL _unit, getWPPos [_group , currentWaypoint _group]] call adm_debug_fnc_updateLineMarker
        } else {
            deleteMarkerLocal _leaderMarker;
            deleteMarkerLocal _waypointMarker;
            deleteMarkerLocal _lineMarker;
            DEBUG("admiral.debug",FMT_4("Deleted waypoint markers '[%1, %2, %3]' for dead patrol group '%4'.",_leaderMarker,_waypointMarker,_lineMarker,_group));
        };
    } foreach _groups;
};

adm_debug_fnc_updateStateMarkersForPatrolGroups = {
    FUN_ARGS_1(_groups);

    {
        private ["_group", "_lineMarker", "_state"];
        _group = _x;
        _lineMarker = format ["STATE_LINE_%1", _group];
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
            DEBUG("admiral.debug",FMT_3("Updated behavior line marker '%1' for group '%2' with state '%3'.",_lineMarker,_group,STATE_TEXT_ARRAY select _state));
        } else {
            deleteMarkerLocal _lineMarker;
            DEBUG("admiral.debug",FMT_2("Deleted behavior line marker '%1' for dead group '%2'.",_lineMarker,_group));
        };
    } foreach _groups;
};

adm_debug_fnc_createMarkersForCqcGroup = {
    FUN_ARGS_1(_group);

    {
        [format ["%1", _x], getPosATL _x, "ICON", CQC_DEBUG_MARKER, [side _group] call adm_debug_fnc_getSideColor, CQC_DEBUG_MARKER_SIZE] call adm_common_fnc_createLocalMarker;
        DEBUG("admiral.debug",FMT_3("Created CQC unit marker '%1' for unit '%2' in group '%3'.",_x,_x,_group));
    } foreach units _group;
};

adm_debug_fnc_updateMarkersForCqcGroups = {
    FUN_ARGS_1(_groups);

    {
        DECLARE(_group) = _x;
        {
            DECLARE(_marker) = format ["%1", _x];
            if (alive _x) then {
                _marker setMarkerPosLocal (getPosATL _x);
                _marker setMarkerDirLocal getDir _x;
                DEBUG("admiral.debug",FMT_3("Updated CQC unit marker '%1' of unit '%2' in group '%3'.",_marker,_x,_group));
            } else {
                deleteMarkerLocal _marker;
                DEBUG("admiral.debug",FMT_3("Deleted CQC unit marker '%1' of dead unit '%2' in group '%3'.",_marker,_x,_group));
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

    _marker = [format ["%1", _trigger], getPosATL _trigger, _shape, "DOT", _color] call adm_common_fnc_createLocalMarker;
    _marker setMarkerSizeLocal [(triggerArea _trigger) select 0, (triggerArea _trigger) select 1];
    _marker setMarkerDirLocal ((triggerArea _trigger) select 2);
    _marker setMarkerBrushLocal "Border";
    DEBUG("admiral.debug",FMT_6("Created marker '%1' for trigger '%2' at position '%3' with shape '%4', color '%4', size '%5' and direction '%6'.",_marker,_trigger,getPosATL _trigger,_shape,_color,AS_ARRAY_2((triggerArea _trigger) select 0, (triggerArea _trigger) select 1),(triggerArea _trigger) select 2));
};

adm_debug_fnc_updateTriggerLocalMarker = {
    FUN_ARGS_1(_trigger);

    private ["_shape", "_marker"];
    _shape = "RECTANGLE";
    if (!((triggerArea _trigger) select 3)) then {
        _shape = "ELLIPSE";
    };

    _marker = format ["%1", _trigger];
    _marker setMarkerShapeLocal _shape;
    _marker setMarkerPosLocal getPosATL _trigger;
    _marker setMarkerSizeLocal [(triggerArea _trigger) select 0, (triggerArea _trigger) select 1];
    _marker setMarkerDirLocal ((triggerArea _trigger) select 2);
    DEBUG("admiral.debug",FMT_2("Updated marker '%1' for trigger '%2'.",_marker,_trigger));
};

adm_debug_fnc_createMarkersForCampLogic = {
    FUN_ARGS_1(_logic);

    DECLARE(_waypoints) = waypoints _logic;
    for "_i" from 0 to count _waypoints - 2 do {
        private ["_wpPosFrom", "_wpPosTo"];
        _wpPosFrom = getWPPos (_waypoints select _i);
        _wpPosTo = getWPPos (_waypoints select (_i + 1));
        [format ["%1", _wpPosFrom], _wpPosFrom, _wpPosTo, "ColorOrange", 3] call adm_debug_fnc_createLineMarker;
        DEBUG("admiral.debug",FMT_2("Created line marker between '%1' and '%2' waypoints for camp path '%3'.",_waypoints select _i,_waypoints select (_i + 1),_logic));
    };
    [_logic getVariable "adm_camp_endTrigger", "ColorOrange"] call adm_debug_fnc_createTriggerLocalMarker;
    DEBUG("admiral.debug",FMT_1("Created end trigger marker for camp path '%1'.",_logic));
};

adm_debug_fnc_createLineMarker = {
    FUN_ARGS_5(_markerName,_posFrom,_posTo,_markerColor,_markerWidth);

    [_markerName, [_posFrom, (_posFrom distance _posTo) / 2, [_posFrom, _posTo] call BIS_fnc_dirTo] call BIS_fnc_relPos, "RECTANGLE", "DOT", _markerColor] call adm_common_fnc_createLocalMarker;
    _markerName setMarkerSizeLocal [_markerWidth, (_posFrom distance _posTo) / 2];
    _markerName setMarkerDirLocal ([_posFrom, _posTo] call BIS_fnc_dirTo);
    DEBUG("admiral.debug",FMT_5("Created line marker '%1' from position '%2' to '%3' with color '%4' and width '%5'.",_markerName,_posFrom,_posTo,_markerColor,_markerWidth));
};

adm_debug_fnc_updateLineMarker = {
    FUN_ARGS_3(_markerName,_posFrom,_posTo);

    _markerName setMarkerPosLocal ([_posFrom, (_posFrom distance _posTo) / 2, [_posFrom, _posTo] call BIS_fnc_dirTo] call BIS_fnc_relPos);
    _markerName setMarkerSizeLocal [(getMarkerSize _markerName) select 0, (_posFrom distance _posTo) / 2];
    _markerName setMarkerDirLocal ([_posFrom, _posTo] call BIS_fnc_dirTo);
    DEBUG("admiral.debug",FMT_3("Updated line marker '%1' position between '%2' and '%3'.",_markerName,_posFrom,_posTo));
};

adm_debug_fnc_getSideColor = {
    FUN_ARGS_1(_side);

    DECLARE(_index) = SIDE_ARRAY find _side;
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
