#include "admiral_defines.h"

adm_common_fnc_placeMan = {
    FUN_ARGS_6(_pos,_grp,_units,_skillBoundary,_aimingSpeed,_aimingAccuracy);

    private ["_unit"];
    _unit = _grp createUnit [SELECT_RAND(_units), _pos, [], 0, "NONE"];

    _unit setSkill ((_skillBoundary select 0) + ((_skillBoundary select 1) - (_skillBoundary select 0)));                       
    _unit setSkill ['aimingSpeed', _aimingSpeed];
    _unit setSkill ['aimingAccuracy', _aimingAccuracy];
    _unit setSkill ['spotDistance', 1];
    _unit setSkill ['spotTime', 1];
    _unit setSkill ['commanding', 1];

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

    if (!adm_ai_NVGs) then {
        _unit removeWeapon "NVGoggles";
    };
};

adm_common_initUnitTemplate = {
    FUN_ARGS_1(_trigger);

    if (isNil {_trigger getVariable "adm_zone_unitTemplate"}) then {
        _trigger setVariable ["adm_zone_unitTemplate", adm_ai_default_unitTemplate, false];
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
    FUN_ARGS_5(_grp,_wpArray,_type,_behaviour,_mode);
    
    private ["_wp"];
    _wp = _grp addWaypoint _wpArray;
    _wp setWaypointType _type;
    _wp setWaypointBehaviour _behaviour;
    _wp setWaypointCombatMode _mode;

    _wp;
};

adm_common_fnc_getEnemyFactionUnits = {
    [allUnits, {local _x && {toLower faction _x == toLower (adm_ai_factions select adm_ai_enemySideIndex select adm_ai_enemyFaction)}}] call BIS_fnc_conditionalSelect;
};

adm_common_fnc_createLocalMarker = {
    FUN_ARGS_6(_name,_pos,_shape,_type,_color,_size);

    private ["_marker"];
    _marker = createMarkerLocal [_name, _pos];
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
    if (isNil "_canBeWater") then { _canBeWater = false; };

    private ["_position", "_emptyPosition"];
    _position = [_trigger, _canBeWater] call adm_common_fnc_randomPosInTrigger;
    _emptyPosition = _position findEmptyPosition [0, CAMP_SPAWN_CIRCLE_MAX_DIST, _unitType];
    while {[_emptyPosition, []] call BIS_fnc_areEqual} do {
        _position = [_trigger, _canBeWater] call adm_common_fnc_randomPosInTrigger;
        _emptyPosition = _position findEmptyPosition [0, CAMP_SPAWN_CIRCLE_MAX_DIST, _unitType];
    };

    _emptyPosition;
};

adm_common_fnc_randomPosInTrigger = {
    FUN_ARGS_2(_trigger,_canBeWater);

    private ["_width", "_height", "_angle", "_isRectangle", "_triggerPosition", "_position", "_shapeFunc"];
    _width = triggerArea _trigger select 0;
    _height = triggerArea _trigger select 1;
    _angle = 180 - (triggerArea _trigger select 2);
    _isRectangle = triggerArea _trigger select 3;
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
    FUN_ARGS_1(_trigger);

    private ["_width", "_height", "_longestAxis"];
    _width = triggerArea _trigger select 0;
    _height = triggerArea _trigger select 1;
    _longestAxis = if (_width > _height) then {_width} else {_height};

    [_trigger, _longestAxis + ZONE_ACTIVATION_DIST] call adm_common_fnc_isPlayersInRange;
};

adm_common_fnc_isPlayersInRange = {
    FUN_ARGS_2(_position,_distance);

    private ["_i", "_players", "_inRange"];
    _i = 0;
    _players = [] call adm_common_fnc_getPlayerUnits;
    _inRange = false;
    while {!_inRange && _i < count _players} do {
        _inRange = _position distance (_players select _i) <= _distance;
        INC(_i);
    };

    _inRange;
};

adm_common_fnc_isPosInsideTrigger = {
    FUN_ARGS_2(_trigger,_position);

    private ["_width", "_height", "_angle", "_isRectangle", "_triggerPosition", "_shapeFunc"];
    _width = triggerArea _trigger select 0;
    _height = triggerArea _trigger select 1;
    _angle = 180 - (triggerArea _trigger select 2);
    _isRectangle = triggerArea _trigger select 3;
    _triggerPosition = getPosATL _trigger;

    if (_isRectangle) then {
        _shapeFunc = adm_common_fnc_isPosInsideRectangle;
    } else {
        _shapeFunc = adm_common_fnc_isPosInsideEllipse;
    };

    private ["_px", "_py", "_tx", "_ty", "_rotatedPx", "_rotatedPy"];
    _px = _position select 0;
    _py = _position select 1;
    _tx = _triggerPosition select 0;
    _ty = _triggerPosition select 1;
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

    private ["_result"];
    _result = [];
    {
        if (call _filterFunc) exitWith { _result = _x };
    } foreach _array;

    _result;
};

adm_common_fnc_setConfig = {
    FUN_ARGS_2(_trigger,_configArray);

    {
        _trigger setVariable [[_x select 0] call adm_common_fnc_getRealConfig, _x select 1];
    } foreach _configArray;
};

adm_common_fnc_getRealConfig = {
    FUN_ARGS_1(_configName);

    call {
        if (_configName == "pool") exitWith {"adm_zone_pool"};
        if (_configName == "minHeight") exitWith {"adm_cqc_minHeight"};
        if (_configName == "type") exitWith {"adm_camp_type"};
        if (_configName == "wave") exitWith {"adm_camp_wave"};
        if (_configName == "campDelay") exitWith {"adm_camp_campDelay"};
        if (_configName == "groupDelay") exitWith {"adm_camp_groupDelay"};
        if (_configName == "spawnChance") exitWith {"adm_camp_spawnChance"};
        if (_configName == "unitTemplate") exitWith {"adm_zone_unitTemplate"};
    };
};

// Compare function must return true if _x is bigger, than _y, else return false
adm_common_fnc_insertionSort = {
    FUN_ARGS_2(_array,_compareFunc);

    private "_sortArray";
    _sortArray = +_array;
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