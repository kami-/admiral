#include "admiral_macros.h"

#include "logbook.h"

adm_debug_fnc_debugSpawnedGroups = {
    [] spawn {
        waitUntil {
            {
                DECLARE(_groups) = _x;
                {
                    [_x] call adm_debug_fnc_updateMovingGroupMarkers;
                } foreach _groups;
            } foreach [adm_patrol_infGroups, adm_patrol_techGroups, adm_patrol_armourGroups, adm_camp_infGroups, adm_camp_techGroups, adm_camp_armourGroups];
            {
                [_x] call adm_debug_fnc_updateCqcGroupMarkers;
            } foreach adm_cqc_groups;
            DEBUG("admiral.debug","Updated debug markers.");
            sleep 2;
            false;
        };
    };
};

adm_debug_fnc_createMovingGroupMarkers = {
    FUN_ARGS_2(_group,_groupType);

    private ["_debugMarkers", "_marker"];
    _debugMarkers = [];
    _marker = [format ["adm_group_%1", _group], getPosATL leader _group, "ICON", GROUP_TYPE_DEBUG_MARKERS select _groupType, [side _group] call adm_debug_fnc_getSideColor, GROUP_TYPE_DEBUG_MARKER_SIZES select _groupType] call adm_common_fnc_createLocalMarker;
    PUSH(_debugMarkers,_marker);
    _marker = [format ["adm_group_WP_%1", _group], getWPPos [_group, currentWaypoint _group], "ICON", "waypoint", [side _group] call adm_debug_fnc_getSideColor, WAYPOINT_DEBUG_MARKER_SIZE] call adm_common_fnc_createLocalMarker;
    PUSH(_debugMarkers,_marker);
    _marker = [format ["adm_group_LINE_%1", _group], getPosATL leader _group, getWPPos [_group, currentWaypoint _group], "ColorBlack", 1] call adm_debug_fnc_createLineMarker;
    PUSH(_debugMarkers,_marker);
    _marker = [format ["adm_group_STATE_LINE_%1", _group], getPosATL leader _group, getPosATL leader _group, "ColorBlack", 1] call adm_debug_fnc_createLineMarker;
    PUSH(_debugMarkers,_marker);
    _marker setMarkerAlphaLocal 0;
    _group setVariable ["adm_group_debugMarkers", _debugMarkers, false];
    DEBUG("admiral.debug",FMT_2("Created waypoint markers '%1' for patrol group '%2'.",_debugMarkers,_group));
};

adm_debug_fnc_updateMovingGroupMarkers = {
    FUN_ARGS_1(_group);

    DECLARE(_debugMarkers) = _group getVariable "adm_group_debugMarkers";
    if (!isNil {_debugMarkers}) exitWith {
        if (IS_GROUP_ALIVE(_group)) then {
            [_group, _debugMarkers] call adm_debug_fnc_updateMovingGroupWaypointMarkers;
            [_group, _debugMarkers select 3] call adm_debug_fnc_updateMovingGroupsStateMarkers;
        } else {
            [_group, _debugMarkers] call adm_debug_fnc_deletePatrolGroupMarkers;
        };
    }
};

adm_debug_fnc_updateMovingGroupWaypointMarkers = {
    FUN_ARGS_2(_group,_debugMarkers);

    (_debugMarkers select 0) setMarkerPosLocal (getPosATL leader _group);
    (_debugMarkers select 0) setMarkerTextLocal format ["%1", count units _group];
    (_debugMarkers select 1) setMarkerPosLocal (getWPPos [_group , currentWaypoint _group]);
    [_debugMarkers select 2, getPosATL leader _group, getWPPos [_group , currentWaypoint _group]] call adm_debug_fnc_updateLineMarker
};

adm_debug_fnc_updateMovingGroupsStateMarkers = {
    FUN_ARGS_2(_group,_lineMarker);

    DECLARE(_state) = _group getVariable ["adm_behavior_state", STATE_INIT];
    call {
        if (_state in [STATE_INIT, STATE_MOVING]) exitwith {
            _lineMarker setMarkerAlphaLocal 0;
        };
        if (isNil {_group getVariable "adm_behavior_reinfGroup"} && {_state in [STATE_ENEMYFOUND, STATE_SADENEMY, STATE_COMBAT]}) exitwith {
            _lineMarker setMarkerAlphaLocal 1;
            [_lineMarker, getPosATL leader _group, _group getVariable "adm_behavior_enemyPos"] call adm_debug_fnc_updateLineMarker;
            _lineMarker setMarkerColorLocal "ColorRed";
        };
        if (!isNil {_group getVariable "adm_behavior_reinfGroup"} && {_state in [STATE_ENEMYFOUND, STATE_SADENEMY, STATE_COMBAT]}) exitwith {
            _lineMarker setMarkerAlphaLocal 1;
            [_lineMarker, getPosATL leader _group, getPosATL leader (_group getVariable "adm_behavior_reinfGroup")] call adm_debug_fnc_updateLineMarker;
            _lineMarker setMarkerColorLocal "ColorOrange";
        };
    };
    DEBUG("admiral.debug",FMT_3("Updated behavior line marker '%1' for group '%2' with state '%3'.",_lineMarker,_group,STATE_TEXT_ARRAY select _state));
};

adm_debug_fnc_deleteMovingGroupMarkers = {
    FUN_ARGS_2(_group,_debugMarkers);

    {
        deleteMarkerLocal _x;
    } foreach _debugMarkers;
    _group setVariable ["adm_group_debugMarkers", nil, false];
    DEBUG("admiral.debug",FMT_2("Deleted waypoint markers '%1' for dead patrol group '%2'.",_debugMarkers,_group));
};

adm_debug_fnc_createCqcGroupMarkers = {
    FUN_ARGS_1(_group);

    {
        DECLARE(_marker) = [format ["adm_unit_cqc_%1", _x], getPosATL _x, "ICON", CQC_DEBUG_MARKER, [side _group] call adm_debug_fnc_getSideColor, CQC_DEBUG_MARKER_SIZE] call adm_common_fnc_createLocalMarker;
        _x setVariable ["adm_unit_debugMarker", _marker, false];
        DEBUG("admiral.debug",FMT_3("Created CQC unit marker '%1' for unit '%2' in group '%3'.",_marker,_x,_group));
    } foreach units _group;
};

adm_debug_fnc_updateCqcGroupMarkers = {
    FUN_ARGS_1(_group);

    {
        DECLARE(_marker) = _x getVariable ["adm_unit_debugMarker", ""];
        if (_marker != "" && {alive _x}) then {
            _marker setMarkerPosLocal (getPosATL _x);
            _marker setMarkerDirLocal getDir _x;
            DEBUG("admiral.debug",FMT_3("Updated CQC unit marker '%1' of unit '%2' in group '%3'.",_marker,_x,_group));
        } else {
            deleteMarkerLocal _marker;
            _x setVariable ["adm_unit_debugMarker", nil, false];
            DEBUG("admiral.debug",FMT_3("Deleted CQC unit marker '%1' of dead unit '%2' in group '%3'.",_marker,_x,_group));
        };
    } foreach units _group;
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

    _markerName;
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
