#include "admiral_defines.h"

adm_common_fnc_placeMan = {
    FUN_ARGS_4(_position,_group,_units,_skillArray);

    DECLARE(_unit) = _group createUnit [SELECT_RAND(_units), _position, [], 0, "NONE"];
    {
        _unit setSkill _x;
    } foreach _skillArray;
    _unit allowFleeing 0;
    [_unit] call adm_common_fnc_setGear;

    _unit;
};

adm_common_fnc_placeVehicle = {
    FUN_ARGS_2(_vehType,_vehPos);

    createVehicle [_vehType, _vehPos, [], 0, "NONE"];
};

adm_common_fnc_setGear = {
    FUN_ARGS_1(_unit);

    if (!adm_areNVGsEnabled) then {
        _unit removeWeapon "NVGoggles";
    };
};

adm_common_initUnitTemplate = {
    FUN_ARGS_2(_trigger,_defaultTemplate);

    if (isNil {_trigger getVariable "adm_zone_unitTemplate"}) then {
        _trigger setVariable ["adm_zone_unitTemplate", _defaultTemplate, false];
    };
};

adm_common_fnc_getUnitTemplateArray = {
    FUN_ARGS_2(_unitTemplate,_field);

    getArray(TEMPLATE_CONFIGFILE >> TEMPLATE_CONTAINER_CLASS >> _unitTemplate >> _field);
};

adm_common_fnc_getUnitTemplateSide = {
    FUN_ARGS_1(_unitTemplate);

    SIDE_ARRAY select getNumber(TEMPLATE_CONFIGFILE >> TEMPLATE_CONTAINER_CLASS >> _unitTemplate >> "side");
};

adm_common_fnc_createWaypoint = {
    FUN_ARGS_5(_group,_wpArray,_type,_behaviour,_mode);
    
    DECLARE(_waypoint) = _group addWaypoint _wpArray;
    _waypoint setWaypointType _type;
    _waypoint setWaypointBehaviour _behaviour;
    _waypoint setWaypointCombatMode _mode;

    _waypoint;
};

adm_common_fnc_getAliveGroups = {
    FUN_ARGS_1(_groupsArray);

    DECLARE(_aliveGroups) = [];
    {
        DECLARE(_groups) = _x;
        FILTER_PUSH_ALL(_aliveGroups,_groups,{{alive _x} count units _x > 0});
    } foreach _groupsArray;

    _aliveGroups;
};

adm_common_fnc_getAliveUnits = {
    FUN_ARGS_1(_groupsArray);

    DECLARE(_aliveUnits) = [];
    {
        DECLARE(_groups) = _x;
        {
            DECLARE(_groupUnits) = units _x;
            FILTER_PUSH_ALL(_aliveUnits,_groupUnits,{alive _x});
        } foreach _groups;
    } foreach _groupsArray;

    _aliveUnits;
};

adm_common_fnc_getAdmiralUnits = {
    [[adm_cqc_groups, adm_patrol_infGroups, adm_patrol_techGroups, adm_patrol_armourGroups, adm_camp_infGroups, adm_camp_techGroups, adm_camp_armourGroups]] call adm_common_fnc_getAliveUnits;
};

adm_common_fnc_createLocalMarker = {
    FUN_ARGS_6(_name,_position,_shape,_type,_color,_size);

    DECLARE(_marker) = createMarkerLocal [_name, _position];
    _marker setMarkerShapeLocal _shape;
    _name setMarkerTypeLocal _type;
    _name setMarkerColorLocal _color;
    if (!isNil "_size") then {
        _name setMarkerSizeLocal _size;
    };

    _name;
};

adm_common_fnc_getPlayerUnits = {
    [allUnits, {isPlayer _x}] call BIS_fnc_conditionalSelect;
};

adm_common_fnc_randomFlatEmptyPosInTrigger = {
    FUN_ARGS_3(_trigger,_unitType,_canBeWater);

    if (isNil "_canBeWater") then {_canBeWater = false;};
    private ["_position", "_emptyPosition"];
    _position = [_trigger, _canBeWater] call adm_common_fnc_randomPosInTrigger;
    _emptyPosition = _position findEmptyPosition [0, CAMP_SPAWN_CIRCLE_MAX_DIST, _unitType];
    while {count _emptyPosition > 0} do {
        _position = [_trigger, _canBeWater] call adm_common_fnc_randomPosInTrigger;
        _emptyPosition = _position findEmptyPosition [0, CAMP_SPAWN_CIRCLE_MAX_DIST, _unitType];
    };

    _emptyPosition;
};

adm_common_fnc_randomPosInTrigger = {
    FUN_ARGS_2(_trigger,_canBeWater);

    private ["_triggerArea", "_width", "_height", "_angle", "_isRectangle", "_triggerPosition", "_position", "_shapeFunc"];
    _triggerArea = triggerArea _trigger;
    SELECT_4(_triggerArea,_width,_height,_angle,_isRectangle);
    _angle = 180 - _angle;
    _triggerPosition = getPosATL _trigger;

    if (_isRectangle) then {
        _shapeFunc = adm_common_fnc_randomPosInRectangle;
    } else {
        _shapeFunc = adm_common_fnc_randomPosInEllipse;
    };

    _position = [_width, _height, _angle, _triggerPosition] call _shapeFunc;
    while {!_canBeWater && {surfaceIsWater _position}} do {
        _position = [_width, _height, _angle, _triggerPosition] call _shapeFunc;
    };

    _position;
};

adm_common_fnc_randomPosInRectangle = {
    FUN_ARGS_4(_width,_height,_angle,_position);

    private ["_px", "_py"];
    _px = _width - 2 * random _width;
    _py = _height - 2 * random _height;

    [
        (_position select 0) + _px * cos _angle - _py * sin _angle,
        (_position select 1) + _py * cos _angle + _px * sin _angle
    ];
};

adm_common_fnc_randomPosInEllipse = {
    FUN_ARGS_4(_width,_height,_angle,_position);

    private ["_ellipseAngle", "_px", "_py"];
    _ellipseAngle = deg random (2 * pi);
    _px = random (_width) * cos _ellipseAngle;
    _py = random (_height) * sin _ellipseAngle;

    [
        (_position select 0) + _px * cos _angle - _py * sin _angle,
        (_position select 1) + _py * cos _angle + _px * sin _angle
    ];
};

adm_common_fnc_isPlayerNearZone = {
    FUN_ARGS_2(_trigger,_distance);

    private ["_width", "_height", "_longestAxis"];
    SELECT_2(triggerArea _trigger,_width,_height);
    _longestAxis = if (_width > _height) then {_width} else {_height};

    [_trigger, _longestAxis + _distance] call adm_common_fnc_isPlayersInRange;
};

adm_common_fnc_isPlayersInRange = {
    FUN_ARGS_2(_position,_distance);

    private ["_players", "_inRange"];
    _players = [] call adm_common_fnc_getPlayerUnits;
    _inRange = false;
    {
        _inRange = _position distance _x <= _distance;
        if (_inRange) exitWith {};
    } foreach _players;

    _inRange;
};

adm_common_fnc_isPosInsideTrigger = {
    FUN_ARGS_2(_trigger,_position);

    private ["_triggerArea", "_width", "_height", "_angle", "_isRectangle", "_triggerPosition", "_shapeFunc"];
    _triggerArea = triggerArea _trigger;
    SELECT_4(_triggerArea,_width,_height,_angle,_isRectangle);
    _angle = 180 - _angle;
    _triggerPosition = getPosATL _trigger;

    if (_isRectangle) then {
        _shapeFunc = adm_common_fnc_isPosInsideRectangle;
    } else {
        _shapeFunc = adm_common_fnc_isPosInsideEllipse;
    };

    private ["_px", "_py", "_tx", "_ty", "_rotatedPx", "_rotatedPy"];
    SELECT_2(_position,_px,_py);
    SELECT_2(_triggerPosition,_tx,_ty);
    _rotatedPx = (_px - _tx) * cos (_angle) + (_py - _ty) * sin (_angle) + _tx;
    _rotatedPy = (_py - _ty) * cos (_angle) - (_px - _tx) * sin (_angle) + _ty;

    [_width, _height, _rotatedPx, _rotatedPy, _tx, _ty] call _shapeFunc;
};

adm_common_fnc_isPosInsideRectangle = {
    FUN_ARGS_6(_width,_height,_rotatedPx,_rotatedPy,_tx,_ty);

    _rotatedPx <= _tx + _width && {_rotatedPx >= _tx - _width} && {_rotatedPy <= _ty + _height} && {_rotatedPy >= _ty - _height};
};

adm_common_fnc_isPosInsideEllipse = {
    FUN_ARGS_6(_width,_height,_rotatedPx,_rotatedPy,_tx,_ty);
 
     (_rotatedPx - _tx) ^ 2 / _width ^ 2 + (_rotatedPy - _ty) ^ 2 / _height ^ 2 <= 1;
};

adm_common_fnc_filterFirst = {
    FUN_ARGS_2(_array,_filterFunc);

    DECLARE(_result) = [];
    {
        if (call _filterFunc) exitWith { _result = [_x] };
    } foreach _array;

    _result;
};

adm_common_fnc_setConfig = {
    FUN_ARGS_2(_trigger,_configArray);

    {
        _trigger setVariable [[_x select 0] call adm_common_fnc_getRealConfig, _x select 1];
    } foreach _configArray;
    [_trigger] call adm_common_fnc_initZone;
};

adm_common_fnc_getRealConfig = {
    FUN_ARGS_1(_configName);

    call {
        if (_configName == "pool")          exitWith {"adm_zone_pool"};
        if (_configName == "minHeight")     exitWith {"adm_cqc_minHeight"};
        if (_configName == "type")          exitWith {"adm_camp_type"};
        if (_configName == "wave")          exitWith {"adm_camp_wave"};
        if (_configName == "campDelay")     exitWith {"adm_camp_campDelay"};
        if (_configName == "groupDelay")    exitWith {"adm_camp_groupDelay"};
        if (_configName == "spawnChance")   exitWith {"adm_camp_spawnChance"};
        if (_configName == "unitTemplate")  exitWith {"adm_zone_unitTemplate"};
    };
};

adm_common_fnc_initZone = {
    FUN_ARGS_1(_trigger);

    private ["_defaultTemplate", "_initFunc", "_triggerText"];
    _defaultTemplate = "";
    _initFunc = {};
    _triggerText = triggerText _trigger;
    call {
        if (_triggerText == "cqc") exitWith {
            _defaultTemplate = adm_cqc_defaultUnitTemplate;
            _initFunc = adm_cqc_fnc_initZone;
        };
        if (_triggerText == "patrol") exitWith {
            _defaultTemplate = adm_patrol_defaultUnitTemplate;
            _initFunc = adm_patrol_fnc_initZone;
        };
        if (_triggerText == "camp") exitWith {
            _defaultTemplate = adm_camp_defaultUnitTemplate;
            _initFunc = adm_camp_fnc_initZone;
        };
    };
    if (_defaultTemplate != "") then {
        [_trigger, _defaultTemplate] call adm_common_initUnitTemplate;
        [_trigger] spawn _initFunc;
    };
};

adm_common_fnc_insertionSort = {
    FUN_ARGS_2(_array,_compareFunc);

    DECLARE(_sortArray) = +_array;
    for "_i" from 1 to (count _sortArray) - 1 do {
        private ["_x", "_j", "_y"];
        _x = _sortArray select _i;
        _j = _i;
        // such hack, very ugly, many thinking, wow!
        while {_j > 0 && {_y = _sortArray select (_j - 1); true} && {!([_x, _y] call _compareFunc)}} do {
            _sortArray set [_j, _y];
            DEC(_j);
        };
        _sortArray set [_j, _x];
    };

    _sortArray;
};

// Implementation of "inside-out" shuffle algorithm
adm_common_fnc_shuffle = {
    FUN_ARGS_1(_array);

    _shuffledArray = [];
    if (count _array > 0) then {
        _shuffledArray set [0, _array select 0];
        for "_i" from 1 to (count _array) - 1 do {
            _randomIndex = floor random (_i + 1);
            _shuffledArray set [_i, _shuffledArray select _randomIndex];
            _shuffledArray set [_randomIndex, _array select _i];
        };
    };

    _shuffledArray;
};

adm_common_fnc_isFriendlySide = {
    FUN_ARGS_2(_side,_otherSide);

    private "_isFriendly";
    _isFriendly = true;
    if (_side == sideEnemy || {_otherSide == sideEnemy}) then {
        _isFriendly = false;
    } else {
        private ["_sideIndex", "_otherSideIndex"];
        _sideIndex = SIDE_ARRAY find _side;
        _otherSideIndex = SIDE_ARRAY find _otherSide;
        _isFriendly = _sideIndex >= 0 && {_otherSideIndex >= 0} && {!(_otherSideIndex in (adm_sideRelations select _sideIndex))};
    };

    _isFriendly;
};