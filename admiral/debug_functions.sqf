#include "admiral_macros.h"

#include "\userconfig\admiral\log\debug.h"
#include "logbook.h"


adm_debug_fnc_createMovingGroupMarkers = {
    FUN_ARGS_1(_group);

    private ["_debugMarkers", "_marker"];
    _groupType = _group getVariable ["adm_group_type", GROUP_TYPE_INF];
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
    if (IS_GROUP_ALIVE(_group)) then {
        if (!isNil {_debugMarkers}) then {
            [_group, _debugMarkers] call adm_debug_fnc_updateMovingGroupWaypointMarkers;
            [_group, _debugMarkers select 3] call adm_debug_fnc_updateMovingGroupsStateMarkers;
        } else {
            [_group] call adm_debug_fnc_createMovingGroupMarkers;
        };
    } else {
        if (!isNil {_debugMarkers}) then {
            [_group, _debugMarkers] call adm_debug_fnc_deleteMovingGroupMarkers;
        };
    };
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

adm_debug_fnc_deleteAllMovingGroupMarkers = {
    {
        DECLARE(_groups) = _x;
        {
            DECLARE(_debugMarkers) = _x getVariable "adm_group_debugMarkers";
            if (!isNil {_debugMarkers}) then {
                [_x, _debugMarkers] call adm_debug_fnc_deleteMovingGroupMarkers;
            };
        } foreach _groups;
    } foreach MOVING_GROUPS;
};

adm_debug_fnc_deleteMovingGroupMarkers = {
    FUN_ARGS_2(_group,_debugMarkers);

    _group setVariable ["adm_group_debugMarkers", nil, false];
    {
        deleteMarkerLocal _x;
    } foreach _debugMarkers;
    DEBUG("admiral.debug",FMT_2("Deleted waypoint markers '%1' for dead patrol group '%2'.",_debugMarkers,_group));
};

adm_debug_fnc_createCqcUnitMarker = {
    FUN_ARGS_2(_unit,_group);

    DECLARE(_debugMarker) = [format ["adm_unit_cqc_%1", _unit], getPosATL _unit, "ICON", CQC_DEBUG_MARKER, [side _group] call adm_debug_fnc_getSideColor, CQC_DEBUG_MARKER_SIZE] call adm_common_fnc_createLocalMarker;
    _unit setVariable ["adm_unit_debugMarker", _debugMarker, false];
    DEBUG("admiral.debug",FMT_3("Created CQC unit marker '%1' for unit '%2' in group '%3'.",_debugMarker,_unit,_group));

    _debugMarker;
};

adm_debug_fnc_deleteCqcUnitMarker = {
    FUN_ARGS_2(_unit,_debugMarker);

    deleteMarkerLocal _debugMarker;
    _unit setVariable ["adm_unit_debugMarker", nil, false];
    DEBUG("admiral.debug",FMT_2("Deleted CQC unit marker '%1' of dead unit '%2'.",_debugMarker,_x));
};

adm_debug_fnc_updateCqcGroupMarkers = {
    FUN_ARGS_1(_group);

    {
        DECLARE(_debugMarker) = _x getVariable "adm_unit_debugMarker";
        if (!isNil {_debugMarker}) then {
            if (alive _x) then {
                _debugMarker setMarkerPosLocal (getPosATL _x);
                _debugMarker setMarkerDirLocal getDir _x;
                DEBUG("admiral.debug",FMT_3("Updated CQC unit marker '%1' of unit '%2' in group '%3'.",_debugMarker,_x,_group));
            } else {
               [_x, _debugMarker] call adm_debug_fnc_deleteCqcUnitMarker;
            };
        } else {
            [_x, _group] call adm_debug_fnc_createCqcUnitMarker; 
        };
    } foreach units _group;
};

adm_debug_fnc_deleteAllCqcGroupMarkers = {
    {
        DECLARE(_group) = _x;
        {
            DECLARE(_debugMarker) = _x getVariable "adm_unit_debugMarker";
            if (!isNil {_debugMarker}) then {
                [_x, _debugMarker] call adm_debug_fnc_deleteCqcUnitMarker;
            } else {
            };
        } foreach units _group;
    } foreach adm_cqc_groups;
};

adm_debug_fnc_updateZoneMarkers = {
    FUN_ARGS_1(_zone);

    DECLARE(_debugMarker) = GET_ZONE_DEBUG_MARKER(_zone);
    if (_debugMarker != "") then {

    } else {
        [_zone] call adm_debug_fnc_createZoneMarker;
        if (GET_ZONE_TYPE(_zone) == "camp") then {
            [_zone] call adm_debug_fnc_createAllCampPathMarkers;
        };
    };
};

adm_debug_fnc_deleteZoneMarkers = {
    FUN_ARGS_1(_zone);

    DECLARE(_debugMarker) = GET_ZONE_DEBUG_MARKER(_zone);
    if (_debugMarker != "") then {
        deleteMarkerLocal _debugMarker;
        if (GET_ZONE_TYPE(_zone) == "camp") then {
            {
                [_x] call adm_debug_fnc_deleteCampPathMarkers
            } foreach GET_CAMP_PATHS(_zone);
        };
    };
    SET_ZONE_DEBUG_MARKER(_zone,"");;
};

adm_debug_fnc_deleteAllZoneMarkers = {
    {
        DECLARE(_zones) = _x;
        {
            [_x] call adm_debug_fnc_deleteZoneMarkers;
        } foreach _zones;
    } foreach [adm_cqc_zones, adm_patrol_zones, adm_camp_zones];
};

adm_debug_fnc_createZoneMarker = {
    FUN_ARGS_2(_zone,_color);

    private ["_shape", "_debugMarker"];
    _shape = "RECTANGLE";
    if (!(GET_ZONE_AREA(_zone) select 3)) then {
        _shape = "ELLIPSE";
    };
    if (isNil {_color}) then {
        _color = [[GET_ZONE_UNIT_TEMPLATE(_zone)] call adm_common_fnc_getUnitTemplateSide] call adm_debug_fnc_getSideColor;
    };

    _debugMarker = [format ["adm_zone_%1", GET_ZONE_ID(_zone)], GET_ZONE_POSITION(_zone), _shape, "DOT", _color] call adm_common_fnc_createLocalMarker;
    _debugMarker setMarkerSizeLocal [GET_ZONE_AREA(_zone) select 0, GET_ZONE_AREA(_zone) select 1];
    _debugMarker setMarkerDirLocal (GET_ZONE_AREA(_zone) select 2);
    _debugMarker setMarkerBrushLocal "Border";
    SET_ZONE_DEBUG_MARKER(_zone,_debugMarker);
    DEBUG("admiral.debug",FMT_6("Created marker '%1' for zone '%2' at position '%3' with shape '%4', color '%4', size '%5' and direction '%6'.",_debugMarker,GET_ZONE_ID(_zone),GET_ZONE_POSITION(_zone),_shape,_color,AS_ARRAY_2(GET_ZONE_AREA(_zone) select 0, GET_ZONE_AREA(_zone) select 1),GET_ZONE_AREA(_zone) select 2));

    _debugMarker;
};

adm_debug_fnc_createTriggerMarker = {
    FUN_ARGS_2(_trigger,_color);

    private ["_shape", "_debugMarker"];
    _shape = "RECTANGLE";
    if (!((triggerArea _trigger) select 3)) then {
        _shape = "ELLIPSE";
    };

    _debugMarker = [format ["adm_trigger_debugMarker_%1", _trigger], getPosATL _trigger, _shape, "DOT", _color] call adm_common_fnc_createLocalMarker;
    _debugMarker setMarkerSizeLocal [(triggerArea _trigger) select 0, (triggerArea _trigger) select 1];
    _debugMarker setMarkerDirLocal ((triggerArea _trigger) select 2);
    _debugMarker setMarkerBrushLocal "Border";
    DEBUG("admiral.debug",FMT_6("Created marker '%1' for trigger '%2' at position '%3' with shape '%4', color '%4', size '%5' and direction '%6'.",_debugMarker,_trigger,getPosATL _trigger,_shape,_color,AS_ARRAY_2((triggerArea _trigger) select 0, (triggerArea _trigger) select 1),(triggerArea _trigger) select 2));

    _debugMarker;
};

adm_debug_fnc_createAllCampPathMarkers = {
    FUN_ARGS_1(_zone);

    DECLARE(_paths) = GET_CAMP_PATHS(_zone);
    {
        if (isNil {_x getVariable "adm_logic_debugMarkers"}) then {
            [_x] call adm_debug_fnc_createCampPathMarkers;
        };
    } foreach _paths;
};

adm_debug_fnc_createCampPathMarkers = {
    FUN_ARGS_1(_path);

    private ["_waypoints", "_lineMarkers", "_endTriggerMarker"];
    _waypoints = waypoints _path;
    _lineMarkers = [];
    for "_i" from 0 to count _waypoints - 2 do {
        private ["_wpPosFrom", "_wpPosTo", "_lineMarker"];
        _wpPosFrom = getWPPos (_waypoints select _i);
        _wpPosTo = getWPPos (_waypoints select (_i + 1));
        _lineMarker = [format ["adm_logic_lineMarker_%1", _wpPosFrom], _wpPosFrom, _wpPosTo, "ColorOrange", 3] call adm_debug_fnc_createLineMarker;
        PUSH(_lineMarkers,_lineMarker);
        DEBUG("admiral.debug",FMT_2("Created line marker between '%1' and '%2' waypoints for camp path '%3'.",_waypoints select _i,_waypoints select (_i + 1),_path));
    };
    _endTriggerMarker = [_path getVariable "adm_camp_endTrigger", "ColorOrange"] call adm_debug_fnc_createTriggerMarker;
    _path setVariable ["adm_logic_debugMarkers", [_lineMarkers, _endTriggerMarker], false];
    DEBUG("admiral.debug",FMT_1("Created end trigger marker for camp path '%1'.",_path));
};

adm_debug_fnc_deleteCampPathMarkers = {
    FUN_ARGS_1(_path);

    DECLARE(_debugMarkers) = _path getVariable "adm_logic_debugMarkers";
    if (!isNil {_debugMarkers}) then {
        {
            deleteMarkerLocal _x;
        } foreach (_debugMarkers select 0);
        deleteMarkerLocal (_debugMarkers select 1);
        _path setVariable ["adm_logic_debugMarkers", nil, false];
    };
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

adm_debug_fnc_debugMonitor = {
    sleep 1;
    waitUntil {
        [] call adm_debug_fnc_debugGroups;
        [] call adm_debug_fnc_debugZones;
        DEBUG("admiral.debug","Updated debug markers.");
        sleep 2;
        !adm_isDebuggingEnabled;
    };
    [] call adm_debug_fnc_deleteAllMovingGroupMarkers;
    [] call adm_debug_fnc_deleteAllCqcGroupMarkers;
    [] call adm_debug_fnc_deleteAllZoneMarkers;
};

adm_debug_fnc_debugGroups = {
    {
        DECLARE(_groups) = _x;
        {
            [_x] call adm_debug_fnc_updateMovingGroupMarkers;
        } foreach _groups;
    } foreach MOVING_GROUPS;
    {
        [_x] call adm_debug_fnc_updateCqcGroupMarkers;
    } foreach adm_cqc_groups;
};

adm_debug_fnc_debugZones = {
    {
        DECLARE(_zones) = _x;
        {
            [_x] call adm_debug_fnc_updateZoneMarkers;
        } foreach _zones;
    } foreach [adm_cqc_zones, adm_patrol_zones, adm_camp_zones];
};

adm_debug_fnc_enableDebugging = {
    if (!adm_isDebuggingEnabled) then {
        adm_isDebuggingEnabled = true;
        [] call adm_debug_fnc_init;
    };
};

adm_debug_fnc_disableDebugging = {
    if (adm_isDebuggingEnabled) then {
        adm_isDebuggingEnabled = false;
    };
};

adm_debug_fnc_init = {
    if (adm_isDebuggingEnabled) then {
        [] spawn adm_debug_fnc_debugMonitor;
    };
};
