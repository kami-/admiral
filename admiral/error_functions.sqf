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
            PUSH(adm_error_errorMessages, call (_asserts select _i));
            diag_log LOG_MSG_1("ERROR","Validation - %1",_assertResult);;
            _noError = false;
        };
        INC(_i);
    };

    _noError;
};

adm_error_fnc_validateFactions = {
    private ["_errorMessages", "_asserts"];
    _errorMessages = [
        {format ["'adm_ai_factions[%1]' is not type of array!", adm_ai_enemySideIndex + 1]},
        {format ["Array 'adm_ai_factions' must have minimum size of %1!", adm_ai_enemySideIndex + 1]},
        {format ["'adm_ai_factions[%1][%2]' is not type of 'STRING'!", adm_ai_enemySideIndex + 1, adm_ai_enemyFaction + 1]}
    ];
    _asserts = [
        ASSERT_TYPE(adm_ai_factions select adm_ai_enemySideIndex,"ARRAY",_errorMessages select 0), 
        ASSERT_ARRAYMINSIZE(adm_ai_factions select adm_ai_enemySideIndex,adm_ai_enemySideIndex + 1,_errorMessages select 1),
        ASSERT_TYPE(adm_ai_factions select adm_ai_enemySideIndex select adm_ai_enemyFaction,"STRING",_errorMessages select 2)
    ];

    [_asserts] call adm_error_fnc_processAsserts;
};

adm_error_fnc_validateCQCBuildings = {
    private ["_errorMessages", "_asserts"];
    _errorMessages = [
        {format ["'adm_cqc_buildingBlacklist[%1]' is not type of 'STRING'!", _forEachIndex + 1]},
        {format ["'adm_cqc_buildingBlacklist[%1]' is not a building classname!", _forEachIndex + 1]}
    ];
    _asserts = [
        ASSERT_TYPE(_x,"STRING",_errorMessages select 0),
        ASSERT_ISKINDOF(_x,"house",_errorMessages select 1)
    ];
    {
        [_asserts] call adm_error_fnc_processAsserts;
    } foreach adm_cqc_buildingBlacklist;

    _errorMessages = [
        {format ["'adm_cqc_buildingCapacity[%1]' is not type of 'ARRAY'!", _forEachIndex + 1]},
        {format ["Array 'adm_cqc_buildingCapacity[%1]' size must be %2!", _forEachIndex + 1, 2]},
        {format ["'adm_cqc_buildingBlacklist[%1][%2]' is not type of 'STRING'!", _forEachIndex + 1, 1]},
        {format ["'adm_cqc_buildingBlacklist[%1][%2]' is not a building classname!", _forEachIndex + 1, 1]},
        {format ["'adm_cqc_buildingBlacklist[%1][%2]' is not type of 'SCALAR'!", _forEachIndex + 1, 2]},
        {format ["'adm_cqc_buildingBlacklist[%1][%2]' can not be less, than %3!", _forEachIndex + 1, 2, 1]}
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

adm_error_fnc_validateUnitTypes = {
    FUN_ARGS_4(_variable,_variableName,_classFunc,_baseClass);

    private ["_side", "_sideSelector", "_faction", "_factionSelector", "_cammo", "_cammoSelector", "_errorMessages", "_asserts", "_noError"];
    _side = SIDE_TEXT_ARRAY select adm_ai_enemySideIndex;
    _sideSelector = format["%1[%2]", _variableName, adm_ai_enemySideIndex + 1];
    _faction = adm_ai_factions select adm_ai_enemySideIndex select adm_ai_enemyFaction;
    _factionSelector = format["%1[%2][%3]", _variableName, adm_ai_enemySideIndex + 1, adm_ai_enemyFaction + 1];
    _cammo = CAMMO_ARRAY select adm_ai_enemyCammo;
    _cammoSelector = format["%1[%2][%3][%4]", _variableName, adm_ai_enemySideIndex + 1, adm_ai_enemyFaction + 1, adm_ai_enemyCammo + 1];

    _errorMessages = [
        {format ["In %1, side '%2' ('%3') is not type of 'ARRAY'!", _variableName, _side, _sideSelector]},
        {format ["In %1, side '%2' ('%3') array is missing!", _variableName, _side, _sideSelector]},
        {format ["In %1, side '%2', faction '%3' ('%4') is not type of 'ARRAY'!", _variableName, _side, _faction, _factionSelector]},
        {format ["In %1, side '%2', faction '%3' ('%4') array is missing!", _variableName, _side, _faction, _factionSelector]},
        {format ["In %1, side '%2', faction '%3' cammo '%4' ('%5') is not type of 'ARRAY'!", _variableName, _side, _faction, _cammo, _cammoSelector]},
        {format ["In %1, side '%2', faction '%3' cammo '%4' ('%5') array is missing!", _variableName, _side, _faction, _cammo, _cammoSelector]}
    ];
    _asserts = [
        ASSERT_ARRAYMINSIZE(_variable,adm_ai_enemySideIndex + 1,_errorMessages select 0),
        ASSERT_TYPE(_variable select adm_ai_enemySideIndex,"ARRAY",_errorMessages select 1),
        ASSERT_ARRAYMINSIZE(_variable select adm_ai_enemySideIndex,adm_ai_enemyFaction + 1,_errorMessages select 2),
        ASSERT_TYPE(_variable select adm_ai_enemySideIndex select adm_ai_enemyFaction,"ARRAY",_errorMessages select 3),
        ASSERT_ARRAYMINSIZE(_variable select adm_ai_enemySideIndex select adm_ai_enemyFaction,adm_ai_enemyCammo + 1,_errorMessages select 4),
        ASSERT_TYPE(_variable select adm_ai_enemySideIndex select adm_ai_enemyFaction select adm_ai_enemyCammo,"ARRAY",_errorMessages select 5)
    ];

    _noError = [_asserts] call adm_error_fnc_processAsserts;
    if (_noError) then {
        [_variable select adm_ai_enemySideIndex select adm_ai_enemyFaction select adm_ai_enemyCammo, _baseClass] call _classFunc;
    };
    
};

adm_error_fnc_validateUnitTypeClassNames = {
    FUN_ARGS_2(_classNames,_baseClass);

    private ["_errorMessages", "_asserts", "_noError"];
    _errorMessages = [
        {format ["In %1, side '%2', faction '%3' cammo '%4', element ('%5[%6]') is not type of 'STRING'!", _variableName, _side, _faction, _cammo, _cammoSelector, _forEachIndex + 1]},
        {format ["In %1, side '%2', faction '%3' cammo '%4' element ('%5[%6]') is not a '%7' classname!", _variableName, _side, _faction, _cammo, _cammoSelector, _forEachIndex + 1, _baseClass]}
    ];
    _asserts = [
        ASSERT_TYPE(_x,"STRING",_errorMessages select 0),
        ASSERT_ISKINDOF(_x,_baseClass,_errorMessages select 1)
    ];

    _noError = true;
    {
        _noError = _noError && ([_asserts] call adm_error_fnc_processAsserts);
    } foreach _classNames;

    _noError;
};

adm_error_fnc_validatePatrolMen = {
    FUN_ARGS_2(_unitTypesArray,_baseClass);

    private "_noError";
    _noError = true;
    {
        private ["_menArray", "_errorMessages", "_asserts"];
        _menArray = _x;
        _errorMessages = [
            {format ["In %1, side '%2', faction '%3' cammo '%4' %6 ('%5[%7]') is not type of 'ARRAY'!", _variableName, _side, _faction, _cammo, _cammoSelector, UNIT_TYPE_ARRAY select _forEachIndex, _forEachIndex + 1]},
            {format ["In %1, side '%2', faction '%3' cammo '%4' %6 ('%5[%7]') array can not be empty!", _variableName, _side, _faction, _cammo, _cammoSelector, UNIT_TYPE_ARRAY select _forEachIndex, _forEachIndex + 1]}
        ];
        _asserts = [
            ASSERT_TYPE(_menArray,"ARRAY",_errorMessages select 0),
            ASSERT_NOTEMPTY(_menArray,_errorMessages select 1)
        ];
        _noError = _noError && ([_asserts] call adm_error_fnc_processAsserts);

        if (_noError) then {
            _errorMessages = [
                {format ["In %1, side '%2', faction '%3' cammo '%4' %6 element ('%5[%7]') is not type of 'STRING'!", _variableName, _side, _faction, _cammo, _cammoSelector, UNIT_TYPE_ARRAY select _forEachIndex, _forEachIndex + 1]},
                {format ["In %1, side '%2', faction '%3' cammo '%4' %6 element ('%5[%7]') is not a '%8' classname!", _variableName, _side, _faction, _cammo, _cammoSelector, UNIT_TYPE_ARRAY select _forEachIndex, _forEachIndex + 1, _baseClass]}
            ];
            _asserts = [
                ASSERT_TYPE(_x,"STRING",_errorMessages select 0),
                ASSERT_ISKINDOF(_x,_baseClass,_errorMessages select 1)
            ];

            _noError = true;
            {
                _noError = _noError && ([_asserts] call adm_error_fnc_processAsserts);
            } foreach _menArray;
        };
    } foreach _unitTypesArray;

    _noError;
};

adm_error_fnc_validatePatrolUnits = {
    [adm_patrol_unitTypes, "adm_patrol_unitTypes", adm_error_fnc_validatePatrolMen, "CAManBase"] call adm_error_fnc_validateUnitTypes;
};

adm_error_fnc_validatePatrolTechnicals = {
    [adm_patrol_techTypes, "adm_patrol_techTypes", adm_error_fnc_validateUnitTypeClassNames, "LandVehicle"] call adm_error_fnc_validateUnitTypes;
};

adm_error_fnc_validatePatrolArmour = {
    [adm_patrol_armourTypes, "adm_patrol_armourTypes", adm_error_fnc_validateUnitTypeClassNames, "LandVehicle"] call adm_error_fnc_validateUnitTypes;
};

adm_error_fnc_validateCQCUnits = {
    [adm_cqc_unitTypes, "adm_cqc_unitTypes", adm_error_fnc_validateUnitTypeClassNames, "CAManBase"] call adm_error_fnc_validateUnitTypes;
};

adm_error_fnc_validateZones = {
    private "_triggers";
    _triggers = [allMissionObjects "EmptyDetector", {triggerText _x == "cqc" || {triggerText _x == "patrol"} || {triggerText _x == "camp"}}] call BIS_fnc_conditionalSelect;
    {
        [_x] call adm_error_fnc_validateZone;
    } foreach _triggers;
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
        {format ["CQC zone '%1', 'Axis a' can not be greater, than 500!", _trigger]},
        {format ["CQC zone '%1', 'Axis b' can not be greater, than 500!", _trigger]},
        {format ["CQC zone '%1', is missing the 'pool' configuration value!", _trigger]},
        {format ["CQC zone '%1', 'pool' configuration value is not type of 'SCALAR'!", _trigger]},
        {format ["CQC zone '%1', 'pool' configuration value can not be less, than 0!", _trigger]}
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
            {format ["CQC zone '%1', 'minHeight' configuration value is not type of 'SCALAR'!", _trigger]}
        ];
        _asserts = [
            ASSERT_TYPE(_trigger getVariable "adm_cqc_minHeight","SCALAR",_errorMessages select 0)
        ];
        [_asserts] call adm_error_fnc_processAsserts;
    };
};

adm_error_fnc_validatePatrolZone = {
    FUN_ARGS_1(_trigger);

    [_trigger, "Patrol", "adm_zone_pool", "SCALAR", ASSERT_MIN(_x,0,_errorMessages select 1), "%1 zone '%2', number of %3 groups ('%4[%5]') can not be less, than 0!"] call adm_error_fnc_validateGroupConfigArray;
};

adm_error_fnc_validateCampZone = {
    FUN_ARGS_1(_trigger);

    private ["_errorMessages","_asserts", "_noError"];
    _errorMessages = [
        {format ["Camp zone '%1', is missing the 'type' configuration value!", _trigger]},
        {format ["Camp zone '%1', 'type' configuration value is not type of 'STRING'!", _trigger]},
        {format ["Camp zone '%1', 'type' configuration value must be one of theese: %2!", _trigger, CAMP_TYPE_ARRAY]},
        {format ["Camp zone '%1', is missing the 'campDelay' configuration value!", _trigger]},
        {format ["Camp zone '%1', 'campDelay' configuration value is not type of 'SCALAR'!", _trigger]},
        {format ["Camp zone '%1', 'campDelay' configuration value can not be less, than 1!", _trigger]}
    ];

    _asserts = [
        ASSERT_NOTNIL({_trigger getVariable "adm_zone_pool"},_errorMessages select 0),
        ASSERT_TYPE(_trigger getVariable "adm_zone_pool","ARRAY",_errorMessages select 1),
        ASSERT_INARRAY(_trigger getVariable "adm_camp_type", CAMP_TYPE_ARRAY, _errorMessages select 2),
        ASSERT_NOTNIL({_trigger getVariable "adm_camp_campDelay"},_errorMessages select 3),
        ASSERT_TYPE(_trigger getVariable "adm_camp_campDelay","SCALAR",_errorMessages select 4),
        ASSERT_MIN(_trigger getVariable "adm_camp_campDelay",1,_errorMessages select 5)
    ];
    [_asserts] call adm_error_fnc_processAsserts;

    [_trigger, "Camp", "adm_zone_pool", "SCALAR", ASSERT_MIN(_x,-1,_errorMessages select 1), "%1 zone '%2', number of %3 groups ('%4[%5]') can not be less, than -1!"] call adm_error_fnc_validateGroupConfigArray;
    [_trigger, "Camp", "adm_camp_wave", "SCALAR", ASSERT_MIN(_x,0,_errorMessages select 1), "%1 zone '%2', number of %3 groups ('%4[%5]') can not be less, than 0!"] call adm_error_fnc_validateGroupConfigArray;
    [_trigger] call adm_error_fnc_validateCampZoneType;
};

adm_error_fnc_validateCampZoneType = {
    FUN_ARGS_1(_trigger);

    private "_validateFunc";
    _validateFunc = call {
        if (_trigger getVariable "adm_camp_type" == "periodic") exitWith {
            {[_trigger, "Periodic camp", "adm_camp_groupDelay", "SCALAR", ASSERT_MIN(_x,0,_errorMessages select 1), "%1 zone '%2', delay of %3 groups ('%4[%5]') can not be less, than 0!"] call adm_error_fnc_validateGroupConfigArray;}
        };
        if (_trigger getVariable "adm_camp_type" == "ondemand") exitWith {
            {}
        };
        if (_trigger getVariable "adm_camp_type" == "random") exitWith {
            {[_trigger, "Random camp", "adm_camp_spawnChance", "SCALAR", ASSERT_BETWEEN(_x,0,100,_errorMessages select 1), "%1 zone '%2', spawning chance of %3 groups ('%4[%5]') can must be between 0 and 100!"] call adm_error_fnc_validateGroupConfigArray;}
        };
    };

    [_trigger] call _validateFunc;
};

adm_error_fnc_validateGroupConfigArray = {
    FUN_ARGS_6(_trigger,_zoneType,_varName,_elementType,_elementAssert,_assertMsg);

    private ["_errorMessages","_asserts", "_noError"];
    _errorMessages = [
        {format ["%1 zone '%2', is missing the '%3' configuration value!", _zoneType, _trigger, _varName]},
        {format ["%1 zone '%2', '%3' configuration value is not type of 'ARRAY'!", _zoneType, _trigger, _varName]},
        {format ["%1 zone '%2', '%3' configuration array's size must be 3!", _zoneType, _trigger, _varName]}
    ];
    _asserts = [
        ASSERT_NOTNIL({_trigger getVariable _varName},_errorMessages select 0),
        ASSERT_TYPE(_trigger getVariable _varName,"ARRAY",_errorMessages select 1),
        ASSERT_ARRAYSIZE(_trigger getVariable _varName,3,_errorMessages select 2)
    ];
    _noError = [_asserts] call adm_error_fnc_processAsserts;

    if (_noError) then {
        _errorMessages = [
            {format ["%1 zone '%2', number of %3 groups ('%4[%5]') is not type of '%6'!", _zoneType, _trigger, GROUP_TYPE_ARRAY select _forEachIndex, _varName, _forEachIndex + 1, _elementType]},
            {format [_assertMsg, _zoneType, _trigger, GROUP_TYPE_ARRAY select _forEachIndex, _varName, _forEachIndex + 1]}
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
        ["adm_ai_enemySideIndex",           [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,3)]],
        ["adm_ai_enemySide",                [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SIDE")]],
        ["adm_ai_factions",                 [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY"), DEF_ASSERT_NOTEMPTY]],
        ["adm_ai_enemyFaction",             [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR")], [adm_error_fnc_validateFactions]],
        ["adm_ai_enemyCammo",               [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,2)]],
        ["adm_ai_caching",                  [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("BOOL")]],
        ["adm_ai_NVGs",                     [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("BOOL")]],
        ["adm_camp_infFireteamSize",        [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_infWaypointAmount",      [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_techFireteamSize",       [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_techWaypointAmount",     [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_armourFireteamSize",     [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_armourWaypointAmount",   [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_camp_skillBoundary",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY"), DEF_ASSERT_ARRAYSIZE(2), DEF_ASSERT_BOUNDARY]],
        ["adm_camp_aimingSpeed",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_camp_aimingAccuracy",         [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_infFireteamSize",      [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_infWaypointAmount",    [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_techFireteamSize",     [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_techWaypointAmount",   [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_armourFireteamSize",   [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_armourWaypointAmount", [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_patrol_skillBoundary",        [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY"), DEF_ASSERT_ARRAYSIZE(2), DEF_ASSERT_BOUNDARY]],
        ["adm_patrol_aimingSpeed",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_patrol_aimingAccuracy",       [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_infFireteamSize",         [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_cqc_forceFireEnabled",        [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("BOOL")]],
        ["adm_cqc_skillBoundary",           [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY"), DEF_ASSERT_ARRAYSIZE(2), DEF_ASSERT_BOUNDARY]],
        ["adm_cqc_aimingSpeed",             [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_cqc_aimingAccuracy",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_BETWEEN(0,1)]],
        ["adm_rupture_updateTick",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],
        ["adm_rupture_length",              [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("SCALAR"), DEF_ASSERT_MIN(1)]],

        ["adm_cqc_buildingBlacklist",       [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY")], [adm_error_fnc_validateCQCBuildings]],
        ["adm_cqc_buildingCapacity",        [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY")], [adm_error_fnc_validateCQCBuildings]],
        
        ["adm_patrol_techTypes",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY")], [adm_error_fnc_validatePatrolTechnicals]],
        ["adm_patrol_armourTypes",          [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY")], [adm_error_fnc_validatePatrolArmour]],
        ["adm_patrol_unitTypes",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY")], [adm_error_fnc_validatePatrolUnits]],

        ["adm_patrol_unitTypes",            [DEF_ASSERT_NOTNIL, DEF_ASSERT_TYPE("ARRAY")], [adm_error_fnc_validatePatrolUnits]]
    ];

    [_settingsVariables] call adm_error_fnc_validateVariables;
};
