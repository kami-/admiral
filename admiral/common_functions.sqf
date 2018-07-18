#include "admiral_macros.h"

#include "\userconfig\admiral\log\common.h"
#include "logbook.h"


adm_common_fnc_placeMan = {
    FUN_ARGS_4(_position,_group,_unitClassNames,_skillArray);

    private ["_classNameData", "_className", "_classNameArguments", "_unit"];
    _classNameData = SELECT_RAND(_unitClassNames);
    _classNameArguments = [];
    if (typeName _classNameData == "ARRAY") then {
        _className = _classNameData select 0;
        for "_i" from 1 to (count _classNameData) - 1 do {
            PUSH(_classNameArguments,_classNameData select _i);
        };
    } else {
        _className = _classNameData;
    };
    _unit = _group createUnit [_className, _position, [], 0, "NONE"];
    if (isNull _unit) exitWith {
        private _errorMessage = format ["Failed to create unit '%1' at position '%2', in group '%3' with classname '%4' and classNameArguments '%5'!",_unit,_position,_group,_className,_classNameArguments];
        ERROR("admiral.common.create",_errorMessage);
        if (hasInterface) then {
            player globalChat ("Admiral: " + _errorMessage);
        };

        _unit;
    };
    [_unit] joinSilent _group;
    _unit setVariable ["adm_classNameArguments", _classNameArguments, false];
    DEBUG("admiral.common.create",FMT_5("Created unit '%1' at position '%2', in group '%3' with classname '%4' and classNameArguments '%5'.",_unit,_position,_group,_className,_classNameArguments));
    [_unit, _skillArray] call adm_common_fnc_initUnit;

    _unit;
};

adm_common_fnc_placeVehicle = {
    FUN_ARGS_3(_vehicleClassNames,_area,_position);

    private ["_classNameData", "_className", "_classNameArguments", "_vehiclePosition", "_vehicle"];
    _classNameData = SELECT_RAND(_vehicleClassNames);
    _classNameArguments = [];
    if (typeName _classNameData == "ARRAY") then {
        _className = _classNameData select 0;
        for "_i" from 1 to (count _classNameData) - 1 do {
            PUSH(_classNameArguments,_classNameData select _i);
        };
    } else {
        _className = _classNameData;
    };
    _vehiclePosition = [_area, _position, _className] call adm_common_fnc_getRandomEmptyPositionInArea;
    _vehicle = createVehicle [_className, _vehiclePosition, [], 0, "NONE"];
    [_vehicle, true, true, true] call bis_fnc_initVehicle;
    _vehicle setVariable ["adm_classNameArguments", _classNameArguments, false];
    _vehicle allowCrewInImmobile adm_allowCrewInImmobile;
    _vehicle setUnloadInCombat [adm_cargoUnloadInCombat, false];
    DEBUG("admiral.common.create",FMT_4("Created vehicle '%1' at position '%2', with classname '%3' and '%4'.",_vehicle,_vehiclePosition,_className,_classNameArguments));

    _vehicle;
};

adm_common_fnc_spawnCrew = {
    FUN_ARGS_5(_vehicle,_group,_crewClassNames,_skillArray,_canSpawnFfvCrew);

    private ["_driver", "_allTurrets", "_leader"];
    _driver = [getPosATL _vehicle, _group, _crewClassNames, _skillArray] call adm_common_fnc_placeMan;
    _driver assignAsDriver _vehicle;
    _driver moveInDriver _vehicle;
    _allTurrets = if (_canSpawnFfvCrew) then {
        allTurrets [_vehicle, true];
    } else {
        allTurrets _vehicle;
    };
    {
        DECLARE(_crewman) = [getPosATL _vehicle, _group, _crewClassNames, _skillArray] call adm_common_fnc_placeMan;
        _crewman assignAsTurret [_vehicle, _x];
        _crewman moveInTurret [_vehicle, _x];
    } foreach _allTurrets;
    _leader = call {
        if (!isNull (commander _vehicle)) exitWith { commander _vehicle };
        if (!isNull (gunner _vehicle)) exitWith { gunner _vehicle };
        if (count _allTurrets > 0) exitWith { _vehicle turretUnit (_allTurrets select 0) };
        driver _vehicle;
    };
    _group selectLeader _leader;
    DEBUG("admiral.common.create",FMT_4("Created crew '%1' with FFV '%2' for vehicle '%3' in group '%4'.",crew _vehicle,_canSpawnFfvCrew,_vehicle,_group));

    crew _vehicle;
};

adm_common_fnc_delayGroupSpawn = {
    params ["_args", "_func"];

    if (canSuspend) then {
        while { time < adm_lastGroupSpawnTime + adm_groupSpawnDelay } do {
            TRACE("admiral.common.delay",FMT_2("Waiting for group delay time '%1s' at current time '%2s'.",adm_lastGroupSpawnTime + adm_groupSpawnDelay,time));
            sleep adm_groupSpawnDelay;
        };
        adm_lastGroupSpawnTime = time;
    };
    private _group = _args call _func;
    DEBUG("admiral.common.delay",FMT_1("Spawning delayed group '%1'.",_group));

    _group;
};

adm_common_fnc_initUnit = {
    FUN_ARGS_2(_unit,_skillArray);

    {
        _unit setSkill _x;
        TRACE("admiral.common.create",FMT_3("Set unit '%1' skill '%2' to '%3'.",_unit,_x select 0,_x select 1));
    } foreach _skillArray;
    _unit allowFleeing 0;
    [_unit] call adm_common_fnc_setGear;
};

adm_common_fnc_setGear = {
    FUN_ARGS_1(_unit);

    [_unit] call adm_common_fnc_assignNVG;
};

adm_common_fnc_assignNVG = {
    FUN_ARGS_1(_unit);

    DECLARE(_assignedItems) = assignedItems _unit;
    {
        if (_x in _assignedItems) exitWith {
            _unit unlinkItem _x;
        };
    } forEach ARMA3_NVGS;
    if (adm_areNVGsEnabled) then {
        _unit linkItem "NVGoggles_AI";
    };
};

adm_common_fnc_getZoneTemplateSkillValues = {
    FUN_ARGS_1(_zoneTemplate);

    _skills = [];
    {
        DECLARE(_value) = ["ZoneTemplates", _zoneTemplate, _x] call adm_config_fnc_getNumber;
        PUSH(_skills,AS_ARRAY_2(_x,_value));
    } foreach ZONE_SKILLS;

    _skills;
};

adm_common_fnc_getUnitTemplateArray = {
    FUN_ARGS_2(_unitTemplate,_field);

    ["UnitTemplates", _unitTemplate, _field] call adm_config_fnc_getArray;
};

adm_common_fnc_getUnitTemplateSide = {
    FUN_ARGS_1(_unitTemplate);

    call compile (["UnitTemplates", _unitTemplate, "side"] call adm_config_fnc_getText);
};

adm_common_fnc_createWaypoint = {
    FUN_ARGS_5(_group,_wpArray,_type,_behaviour,_mode);
    
    DECLARE(_waypoint) = _group addWaypoint _wpArray;
    _waypoint setWaypointType _type;
    _waypoint setWaypointBehaviour _behaviour;
    _waypoint setWaypointCombatMode _mode;
    
    private _groupType = _group getVariable ["adm_group_type", GROUP_TYPE_INF];
    private _radius = if (_groupType isEqualTo GROUP_TYPE_INF) then { 50 } else { 250 };
    _waypoint setWaypointCompletionRadius _radius;

    DEBUG("admiral.common.create",FMT_6("Created waypoint '%1' at position '%2' for group '%3', with type '%4', behaviour '%5' and combat mode '%6'.",_waypoint,_wpArray,_group,_type,_behaviour,_mode));

    _waypoint;
};

adm_common_fnc_getAliveGroups = {
    FUN_ARGS_1(_groupsArray);

    DECLARE(_aliveGroups) = [];
    {
        DECLARE(_groups) = _x;
        FILTER_PUSH_ALL(_aliveGroups,_groups,{IS_GROUP_ALIVE(_x)});
    } foreach _groupsArray;

    _aliveGroups;
};

adm_common_fnc_getAliveSideGroups = {
    FUN_ARGS_2(_groupsArray,_side);

    DECLARE(_aliveGroups) = [];
    {
        DECLARE(_groups) = _x;
        FILTER_PUSH_ALL(_aliveGroups,_groups,{IS_GROUP_ALIVE(_x) && {side _x == _side}});
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

adm_common_fnc_getAliveSideUnits = {
    FUN_ARGS_2(_groupsArray,_side);
    
    DECLARE(_aliveSideUnits) = [];
    {
        DECLARE(_groups) = _x;
        {
            DECLARE(_groupUnits) = units _x;
            FILTER_PUSH_ALL(_aliveSideUnits,_groupUnits,{alive _x && {side _x == _side}});
        } foreach _groups;
    } foreach _groupsArray;

    _aliveSideUnits;
};

adm_common_fnc_getAllAliveSideUnits = {
    FUN_ARGS_1(_side);
    
    [[adm_cqc_groups, adm_patrol_infGroups, adm_patrol_techGroups, adm_patrol_armourGroups, adm_camp_infGroups, adm_camp_techGroups, adm_camp_armourGroups],_side] call adm_common_fnc_getAliveSideUnits;
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
    } else {
        _size = [1, 1];
    };
    DEBUG("admiral.common.create",FMT_6("Created local marker '%1' at position '%2' with shape '%3', type '%4', color '%5' and size '%6'.",_marker,_position,_shape,_type,_color,if (!isNil "_size") then {"<no size>"} else {_size}));

    _name;
};

adm_common_fnc_getPlayerUnits = {
    [allUnits, {isPlayer _x}] call BIS_fnc_conditionalSelect;
};

adm_common_fnc_randomFlatEmptyPosInTrigger = {
    FUN_ARGS_3(_trigger,_unitType,_canBeWater);

    if (isNil "_canBeWater") then {_canBeWater = false;};
    [triggerArea _trigger, getPosATL _trigger, _unitType, _canBeWater] call adm_common_fnc_getRandomEmptyPositionInArea;
};

adm_common_fnc_getRandomEmptyPositionInArea = {
    FUN_ARGS_4(_area,_areaPosition,_unitType,_canBeWater);

    if (isNil "_canBeWater") then {_canBeWater = false;};
    private ["_randomPosition", "_emptyPosition"];
    _randomPosition = [_area, _areaPosition, _canBeWater] call adm_common_fnc_getRandomPositionInArea;
    _emptyPosition = _randomPosition findEmptyPosition [0, CAMP_SPAWN_CIRCLE_MAX_DIST, _unitType];
    while {count _emptyPosition == 0} do {
        _randomPosition = [_area, _areaPosition, _canBeWater] call adm_common_fnc_getRandomPositionInArea;
        _emptyPosition = _randomPosition findEmptyPosition [0, CAMP_SPAWN_CIRCLE_MAX_DIST, _unitType];
    };

    _emptyPosition;
};

adm_common_fnc_getRandomPositionInArea = {
    FUN_ARGS_3(_area,_areaPosition,_canBeWater);

    private ["_randomPosition", "_shapeFunc"];
    DECLARE_4(_area,_width,_height,_angle,_isRectangle);
    _angle = 180 - _angle;

    if (_isRectangle) then {
        _shapeFunc = adm_common_fnc_getRandomPositionInRectangle;
    } else {
        _shapeFunc = adm_common_fnc_getRandomPositionInEllipse;
    };

    _randomPosition = [_width, _height, _angle, _areaPosition] call _shapeFunc;
    while {!_canBeWater && {surfaceIsWater _randomPosition}} do {
        _randomPosition = [_width, _height, _angle, _areaPosition] call _shapeFunc;
    };

    _randomPosition;
};

adm_common_fnc_getRandomPositionInRectangle = {
    FUN_ARGS_4(_width,_height,_angle,_position);

    private ["_px", "_py"];
    _px = _width - 2 * random _width;
    _py = _height - 2 * random _height;

    [
        (_position select 0) + _px * cos _angle - _py * sin _angle,
        (_position select 1) + _py * cos _angle + _px * sin _angle
    ];
};

adm_common_fnc_getRandomPositionInEllipse = {
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

adm_common_fnc_isPlayerNearTrigger = {
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

adm_common_fnc_isPositionInArea = {
    FUN_ARGS_3(_position,_area,_areaPosition);

    DECLARE_4(_area,_width,_height,_angle,_isRectangle);
    _angle = 180 - _angle;

    private "_shapeFunc";
    if (_isRectangle) then {
        _shapeFunc = adm_common_fnc_isPositionInRectangle;
    } else {
        _shapeFunc = adm_common_fnc_isPositionInEllipse;
    };

    DECLARE_2(_position,_px,_py);
    DECLARE_2(_areaPosition,_ax,_ay);
    private ["_rotatedPx", "_rotatedPy"];
    _rotatedPx = (_px - _ax) * cos (_angle) + (_py - _ay) * sin (_angle) + _ax;
    _rotatedPy = (_py - _ay) * cos (_angle) - (_px - _ax) * sin (_angle) + _ay;

    [_width, _height, _rotatedPx, _rotatedPy, _ax, _ay] call _shapeFunc;
};

adm_common_fnc_isPosInsideTrigger = {
    FUN_ARGS_2(_trigger,_position);

    [_position,triggerArea _trigger, getPosATL _trigger] call adm_common_fnc_isPositionInArea;
};

adm_common_fnc_isPositionInRectangle = {
    FUN_ARGS_6(_width,_height,_rotatedPx,_rotatedPy,_ax,_ay);

    _rotatedPx <= _ax + _width && {_rotatedPx >= _ax - _width} && {_rotatedPy <= _ay + _height} && {_rotatedPy >= _ay - _height};
};

adm_common_fnc_isPositionInEllipse = {
    FUN_ARGS_6(_width,_height,_rotatedPx,_rotatedPy,_ax,_ay);
 
     (_rotatedPx - _ax) ^ 2 / _width ^ 2 + (_rotatedPy - _ay) ^ 2 / _height ^ 2 <= 1;
};

adm_common_fnc_filterFirst = {
    FUN_ARGS_2(_array,_filterFunc);

    DECLARE(_result) = [];
    {
        if (call _filterFunc) exitWith { _result = [_x] };
    } foreach _array;

    _result;
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

    DECLARE(_shuffledArray) = [];
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

adm_common_fnc_getAdmiralSide = {
    FUN_ARGS_1(_side);

    DECLARE(_sideIndex) = SIDE_ARRAY find _side;
    if (_sideIndex == -1) then { _sideIndex = SIDE_CIV; };

    _sideIndex;
};

adm_common_fnc_isFriendlySide = {
    FUN_ARGS_2(_side,_otherSide);

    DECLARE(_isFriendly) = true;
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