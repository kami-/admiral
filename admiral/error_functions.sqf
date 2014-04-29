#include "admiral_defines.h"

adm_error_fnc_validateVariables = {
    FUN_ARGS_1(_variableArray);

    {
        private "_variableName";
        _variableName = _x select 0;
        [_x select 1] call adm_error_fnc_processAsserts;
        { call _x } foreach (_x select 2);
    } foreach _variableArray;
};

adm_error_fnc_processAsserts = {
    FUN_ARGS_1(_asserts);

    private ["_i", "_noError"];
    _i = 0;
    _noError = true;
    while {_noError && _i < count _asserts} do {
        private "_assertResult";
        _assertResult = call (_asserts select _i);
        if (_assertResult != "") then {
            PUSH(adm_error_errorMessages,_assertResult);
            diag_log LOG_MSG_1("ERROR","Validation - %1",_assertResult);;
            _noError = false;
        };
        INC(_i);
    };

    _noError;
};

adm_error_fnc_validateUnitTemplate = {
    FUN_ARGS_2(_unitTemplate,_arrayFields);

    private ["_errorMessages", "_asserts", "_noError"];
    _errorMessages = [
        {format ["Unit template '%1' is not type of 'STRING'!", _unitTemplate]}
    ];
    _asserts = [
        ASSERT_TYPE(_unitTemplate,"STRING",_errorMessages select 0)
    ];
    _noError = [_asserts] call adm_error_fnc_processAsserts;

    if (_noError) then {
        private ["_configEntry", "_configEntryString"];
        _configEntry = TEMPLATE_CONFIGFILE >> TEMPLATE_CONTAINER_CLASS >> _unitTemplate;
        _configEntryString = format ["%1 >> %2 >> %3", STR_TEMPLATE_CONFIGFILE, TEMPLATE_CONTAINER_CLASS, _unitTemplate];
        _errorMessages = [
            {format ["Class '%1' was not found, at '%2'!", _unitTemplate, _configEntryString]}
        ];
        _asserts = [
            ASSERT_ISCLASS(_configEntry,_errorMessages select 0)
        ];
        _noError = [_asserts] call adm_error_fnc_processAsserts;

        if (_noError) then {
            [_configEntry, _configEntryString, _arrayFields] call adm_error_fnc_validateUnitTemplateFields;
        };
    };
};

adm_error_fnc_validateUnitTemplateFields = {
    FUN_ARGS_3(_configEntry,_configEntryString,_arrayFields);

    [_configEntry >> "side", _configEntryString + " >> side", "side"] call adm_error_fnc_validateUnitTemplateNumberField;
    {
        private ["_field", "_fieldConfigEntry", "_fieldConfigEntryString", "_noError"];
        _field = _x select 0;
        _fieldConfigEntryString = format ["%1 >> %2", _configEntryString, _field];
        _fieldConfigEntry = _configEntry >> _field;
        _noError = [_fieldConfigEntry, _fieldConfigEntryString, _field] call adm_error_fnc_validateUnitTemplateArrayField;
        if (_noError) then {
            [_fieldConfigEntryString, getArray (_fieldConfigEntry), _x select 1] call adm_error_fnc_validateUnitTemplateClassNames;
        };
    } foreach _arrayFields;
};

adm_error_fnc_validateUnitTemplateNumberField = {
    FUN_ARGS_3(_configEntry,_configEntryString,_field);

    private ["_errorMessages", "_asserts"];
    _errorMessages = [
        {format ["Field '%1' is not a number (or not defined), in unit template '%2'!", _field, _configEntryString]}
    ];
    _asserts = [
        ASSERT_ISNUMBER(_configEntry,_errorMessages select 0)
    ];

    [_asserts] call adm_error_fnc_processAsserts;
};

adm_error_fnc_validateUnitTemplateArrayField = {
    FUN_ARGS_3(_configEntry,_configEntryString,_field);

    private ["_errorMessages", "_asserts", "_noError"];
    _errorMessages = [
        {format ["Field '%1' is not an array (or not defined), in unit template '%2'!", _field, _configEntryString]}
    ];
    _asserts = [
        ASSERT_ISARRAY(_configEntry,_errorMessages select 0)
    ];
    _noError = [_asserts] call adm_error_fnc_processAsserts;

    if (_noError) then {
        _errorMessages = [
            {format ["Field '%1' cannot be empty, in unit template '%2'!", _field, _configEntryString]}
        ];
        _asserts = [
            ASSERT_NOTEMPTY(getArray (_configEntry),_errorMessages select 0)
        ];
        _noError = [_asserts] call adm_error_fnc_processAsserts;
    };

    _noError;
};

adm_error_fnc_validateUnitTemplateClassNames = {
    FUN_ARGS_3(_configEntryString,_classNames,_baseClass);

    private ["_errorMessages", "_asserts"];
    _errorMessages = [
        {format ["Class name '%1' is not type of 'STRING', in unit template '%2' at index '%3'!", _x, _configEntryString, _forEachIndex + 1]},
        {format ["Class name '%1' is not kind of '%2', in unit template '%3' at index '%4'!", _x, _baseClass, _configEntryString, _forEachIndex + 1]}
    ];
    _asserts = [
        ASSERT_TYPE(_x,"STRING",_errorMessages select 0),
        ASSERT_ISKINDOF(_x,_baseClass,_errorMessages select 1)
    ];
    {
        [_asserts] call adm_error_fnc_processAsserts;
    } foreach _classNames;
};

adm_error_fnc_validateCQCBuildings = {
    private ["_errorMessages", "_asserts"];
    _errorMessages = [
        {format ["Class name '%1' is not type of 'STRING', in array 'adm_cqc_buildingBlacklist' at index '%2'!", _x, _forEachIndex + 1]},
        {format ["Class name '%1' is not kind of '%2', in array 'adm_cqc_buildingBlacklist' at index '%3'!", _x, "house", _forEachIndex + 1]}
    ];
    _asserts = [
        ASSERT_TYPE(_x,"STRING",_errorMessages select 0),
        ASSERT_ISKINDOF(_x,"house",_errorMessages select 1)
    ];
    {
        [_asserts] call adm_error_fnc_processAsserts;
    } foreach adm_cqc_buildingBlacklist;

    _errorMessages = [
        {format ["Entry '%1' is not type of 'ARRAY', in 'adm_cqc_buildingCapacity' at index '%2'!", _x, _forEachIndex + 1]},
        {format ["Array '%1' size must be '%2', in 'adm_cqc_buildingCapacity' at index '%3'!", _x, _forEachIndex + 1, 2]},
        {format ["Class name '%1' is not type of 'STRING', in array 'adm_cqc_buildingCapacity' at index '%2'!", _x select 0, _forEachIndex + 1]},
        {format ["Class name '%1' is not kind of '%2', in array 'adm_cqc_buildingCapacity' at index '%3'!", _x select 0, "house", _forEachIndex + 1]},
        {format ["Capacity '%1' is not type of 'SCALAR', in array 'adm_cqc_buildingCapacity' at index '%2'!", _x select 1, _forEachIndex + 1]},
        {format ["Capacity '%1' cannot be less, than %2, in array 'adm_cqc_buildingCapacity' at index '%3'!", _x select 1, 1, _forEachIndex + 1]}
    ];
    _asserts = [
        ASSERT_TYPE(_x,"ARRAY",_errorMessages select 0),
        ASSERT_ARRAYSIZE(_x,2,_errorMessages select 1),
        ASSERT_TYPE(_x select 0,"STRING",_errorMessages select 2),
        ASSERT_ISKINDOF(_x select 0,"house",_errorMessages select 3),
        ASSERT_TYPE(_x select 1,"SCALAR",_errorMessages select 4),
        ASSERT_MIN(_x select 1,1,_errorMessages select 5)
    ];
    {
        [_asserts] call adm_error_fnc_processAsserts;
    } foreach adm_cqc_buildingCapacity;
};

adm_error_fnc_validateZone = {
    FUN_ARGS_1(_trigger);

    private "_validateFunc";
    _validateFunc = call {
        if (triggerText _trigger == "cqc") exitWith { adm_error_fnc_validateCQCZone };
        if (triggerText _trigger == "patrol") exitWith { adm_error_fnc_validatePatrolZone };
        if (triggerText _trigger == "camp") exitWith { adm_error_fnc_validateCampZone };
        {}
    };

    [_trigger] call _validateFunc;
};

adm_error_fnc_validateCQCZone = {
    FUN_ARGS_1(_trigger);

    private ["_errorMessages","_asserts"];
    _errorMessages = [
        {format ["Axis a='%1' cannot be greater, than 500, on CQC zone '%2'!", (triggerArea _trigger) select 0, _trigger]},
        {format ["Axis b='%1' cannot be greater, than 500, on CQC zone '%2'!", (triggerArea _trigger) select 1, _trigger]},
        {format ["Config entry 'pool' is missing, on CQC zone '%1'!", _trigger]},
        {format ["Config entry 'pool'='%1' is not type of 'SCALAR', on CQC zone '%2'!", _trigger getVariable "adm_zone_pool", _trigger]},
        {format ["Config entry 'pool'='%1' cannot be less, than 0, on CQC zone '%2'!", _trigger getVariable "adm_zone_pool", _trigger]}
    ];
    _asserts = [
        ASSERT_MAX((triggerArea _trigger) select 0,500,_errorMessages select 0),
        ASSERT_MAX((triggerArea _trigger) select 0,500,_errorMessages select 1),
        ASSERT_NOTNIL({_trigger getVariable "adm_zone_pool"},_errorMessages select 2),
        ASSERT_TYPE(_trigger getVariable "adm_zone_pool","SCALAR",_errorMessages select 3),
        ASSERT_MIN(_trigger getVariable "adm_zone_pool",0,_errorMessages select 4)
    ];
    [_asserts] call adm_error_fnc_processAsserts;

    if (!isNil {_trigger getVariable "adm_cqc_minHeight"}) then {
        _errorMessages = [
            {format ["Config entry 'minHeight'='%1' is not type of 'SCALAR', on CQC zone '%2'!", _trigger getVariable "adm_cqc_minHeight", _trigger]}
        ];
        _asserts = [
            ASSERT_TYPE(_trigger getVariable "adm_cqc_minHeight","SCALAR",_errorMessages select 0)
        ];
        [_asserts] call adm_error_fnc_processAsserts;
    };
    [_trigger getVariable ["adm_zone_unitTemplate", "TEMPLATE_MISSING"], [["infantry", "Man"]]] call adm_error_fnc_validateUnitTemplate;
};

adm_error_fnc_validatePatrolZone = {
    FUN_ARGS_1(_trigger);

    [_trigger, "Patrol", "pool", "adm_zone_pool", "SCALAR", ASSERT_MIN(_x,0,_errorMessages select 1), "Number of %1 groups '%2' cannot be less, than 0, in config entry '%3' at index '%4', on '%5' zone '%6'!"]
        call adm_error_fnc_validateGroupConfigArray;
    [_trigger getVariable ["adm_zone_unitTemplate", "TEMPLATE_MISSING"], [["infantry", "Man"], ["crewmen", "Man"], ["technicals", "LandVehicle"], ["technicals", "LandVehicle"]]] call adm_error_fnc_validateUnitTemplate;
};

adm_error_fnc_validateCampZone = {
    FUN_ARGS_1(_trigger);

    private ["_errorMessages","_asserts", "_noError"];

    _errorMessages = [
        {format ["Config entry 'type' is missing, on Camp zone '%1'!", _trigger]},
        {format ["Config entry 'type'='%1' is not type of 'STRING', on Camp zone '%2'!", _trigger getVariable "adm_camp_type", _trigger]},
        {format ["Config entry 'type'='%1' must be one of theese '%2', on Camp zone '%3'!", _trigger getVariable "adm_camp_type", CAMP_TYPE_ARRAY, _trigger]},
        {format ["Config entry 'campDelay' is missing, on Camp zone '%1'!", _trigger]},
        {format ["Config entry 'campDelay'='%1' is not type of 'SCALAR', on Camp zone '%2'!", _trigger getVariable "adm_camp_campDelay", _trigger]},
        {format ["Config entry 'campDelay'='%1' cannot be less, than 1, on Camp zone '%2'!", _trigger getVariable "adm_camp_campDelay", _trigger]}
    ];

    _asserts = [
        ASSERT_NOTNIL({_trigger getVariable "adm_camp_type"},_errorMessages select 0),
        ASSERT_TYPE(_trigger getVariable "adm_camp_type","STRING",_errorMessages select 1),
        ASSERT_INARRAY(_trigger getVariable "adm_camp_type", CAMP_TYPE_ARRAY, _errorMessages select 2),
        ASSERT_NOTNIL({_trigger getVariable "adm_camp_campDelay"},_errorMessages select 3),
        ASSERT_TYPE(_trigger getVariable "adm_camp_campDelay","SCALAR",_errorMessages select 4),
        ASSERT_MIN(_trigger getVariable "adm_camp_campDelay",1,_errorMessages select 5)
    ];
    [_asserts] call adm_error_fnc_processAsserts;

    [_trigger, "Camp", "pool", "adm_zone_pool", "SCALAR", ASSERT_MIN(_x,-1,_errorMessages select 1), "Number of %1 groups '%2' cannot be less, than -1, in config entry '%3' at index '%4', on '%5' zone '%6'!"]
        call adm_error_fnc_validateGroupConfigArray;
    [_trigger, "Camp", "wave", "adm_camp_wave", "SCALAR", ASSERT_MIN(_x,0,_errorMessages select 1), "Number of %1 groups '%2' cannot be less, than 0, in config entry '%3' at index '%4', on '%5' zone '%6'!"]
        call adm_error_fnc_validateGroupConfigArray;
    [_trigger] call adm_error_fnc_validateCampZoneType;
    [_trigger getVariable ["adm_zone_unitTemplate", "TEMPLATE_MISSING"], [["infantry", "Man"], ["crewmen", "Man"], ["technicals", "LandVehicle"], ["technicals", "LandVehicle"]]] call adm_error_fnc_validateUnitTemplate;
};

adm_error_fnc_validateCampZoneType = {
    FUN_ARGS_1(_trigger);

    private "_validateFunc";
    _validateFunc = call {
        if (_trigger getVariable "adm_camp_type" == "periodic") exitWith {
            {[_trigger, "Periodic camp", "groupDelay", "adm_camp_groupDelay", "SCALAR", ASSERT_MIN(_x,0,_errorMessages select 1), "Number of %1 groups '%2' cannot be less, than 0, in config entry '%3' at index '%4', on '%5' zone '%6'!"]
                call adm_error_fnc_validateGroupConfigArray;}
        };
        if (_trigger getVariable "adm_camp_type" == "ondemand") exitWith {
            {}
        };
        if (_trigger getVariable "adm_camp_type" == "random") exitWith {
            {[_trigger, "Random camp", "spawnChance", "adm_camp_spawnChance", "SCALAR", ASSERT_BETWEEN(_x,0,100,_errorMessages select 1), "Spawning chance of %1 groups '%2' must be between 0 and 100, in config entry '%3' at index '%4', on '%5' zone '%6'!"]
                call adm_error_fnc_validateGroupConfigArray;}
        };
    };

    [_trigger] call _validateFunc;
};

adm_error_fnc_validateGroupConfigArray = {
    FUN_ARGS_7(_trigger,_zoneType,_prettyVarName,_varName,_elementType,_elementAssert,_assertMsg);

    private ["_errorMessages","_asserts", "_noError"];
    _errorMessages = [
        {format ["Config entry '%1' is missing, on %2 zone '%3'!", _prettyVarName, _zoneType, _trigger]},
        {format ["Config entry '%1'='%2' is not type of 'ARRAY', on '%3' zone '%4'!", _prettyVarName, _trigger getVariable _varName, _zoneType, _trigger]},
        {format ["Config entry '%1'='%2' size must be 3, on '%3' zone '%4'!", _prettyVarName, _trigger getVariable _varName, _zoneType, _trigger]}
    ];
    _asserts = [
        ASSERT_NOTNIL({_trigger getVariable _varName},_errorMessages select 0),
        ASSERT_TYPE(_trigger getVariable _varName,"ARRAY",_errorMessages select 1),
        ASSERT_ARRAYSIZE(_trigger getVariable _varName,3,_errorMessages select 2)
    ];
    _noError = [_asserts] call adm_error_fnc_processAsserts;

    if (_noError) then {
        _errorMessages = [
            {format ["Number of %1 groups '%2' is not type of '%3', in config entry '%4' at index '%5', on '%6' zone '%7'!", GROUP_TYPE_ARRAY select _forEachIndex, (_trigger getVariable _varName) select _forEachIndex, _elementType, _prettyVarName,_forEachIndex + 1, _zoneType, _trigger]},
            {format [_assertMsg, GROUP_TYPE_ARRAY select _forEachIndex, (_trigger getVariable _varName) select _forEachIndex, _prettyVarName,_forEachIndex + 1, _zoneType, _trigger]}
        ];
        _asserts = [
            ASSERT_TYPE(_x,_elementType,_errorMessages select 0),
            _elementAssert
        ];
        {
            _noError = _noError && ([_asserts] call adm_error_fnc_processAsserts);
        } foreach (_trigger getVariable _varName);
    };

    _noError;
};

adm_error_fnc_init = {
    adm_error_errorMessages = [];

    private ["_settingsVariables"];
    _settingsVariables = [
        ["adm_ai_debugging",                [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("BOOL")]],
        ["adm_default_cqc_unitTemplate",    [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("STRING")]],
        ["adm_default_patrol_unitTemplate", [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("STRING")]],
        ["adm_default_camp_unitTemplate",   [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("STRING")]],
        ["adm_ai_caching",                  [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("BOOL")]],
        ["adm_ai_NVGs",                     [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("BOOL")]],
        ["adm_camp_infFireteamSize",        [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_infWaypointAmount",      [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_techFireteamSize",       [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_techWaypointAmount",     [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_armourFireteamSize",     [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_armourWaypointAmount",   [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_aimingAccuracy",         [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_aimingShake",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_aimingSpeed",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_endurance",              [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_spotDistance",           [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_spotTime",               [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_courage",                [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_reloadSpeed",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_commanding",             [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_general",                [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_infFireteamSize",      [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_infWaypointAmount",    [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_techFireteamSize",     [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_techWaypointAmount",   [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_armourFireteamSize",   [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_armourWaypointAmount", [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_aimingAccuracy",       [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_aimingShake",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_aimingSpeed",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_endurance",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_spotDistance",         [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_spotTime",             [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_courage",              [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_reloadSpeed",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_commanding",           [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_general",              [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_infFireteamSize",         [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_cqc_forceFireEnabled",        [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("BOOL")]],
        ["adm_cqc_aimingAccuracy",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_aimingShake",             [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_aimingSpeed",             [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_endurance",               [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_spotDistance",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_spotTime",                [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_courage",                 [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_reloadSpeed",             [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_commanding",              [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_general",                 [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_rupture_updateTick",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_rupture_length",              [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],

        ["adm_cqc_buildingBlacklist",       [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY")], [adm_error_fnc_validateCQCBuildings]],
        ["adm_cqc_buildingCapacity",        [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY")], [adm_error_fnc_validateCQCBuildings]]
    ];

    [_settingsVariables] call adm_error_fnc_validateVariables;
};
