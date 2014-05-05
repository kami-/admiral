#define MULTIPLE_SIDES
#ifdef MULTIPLE_SIDES
    #define ALL_UNITS       allUnits
#endif
#ifndef MULTIPLE_SIDES
    #define ALL_UNITS       ([] call adm_common_fnc_getPlayerUnits)
#endif

#define TEMPLATE_CONFIGFILE                 missionConfigFile
#define STR_TEMPLATE_CONFIGFILE             "missionConfigFile"
#define TEMPLATE_CONTAINER_CLASS            "Admiral" >> "UnitTemplates"
#define STR_TEMPLATE_CONTAINER_CLASS        "Admiral >> UnitTemplates"

#define CAMP_SPAWN_CIRCLE_MAX_DIST          30

#define CQC_MAX_ENGAGE_DIST                 50

#define REDUCE_DISTANCE                     1200
#define EXPAND_DISTANCE                     1000

#define CAMP_SKILL_ARRAY                    [["aimingAccuracy", adm_camp_aimingAccuracy],["aimingShake", adm_camp_aimingShake],["aimingSpeed", adm_camp_aimingSpeed], \
                                            ["endurance", adm_camp_endurance],["spotDistance", adm_camp_spotDistance],["spotTime", adm_camp_spotTime], \
                                            ["courage", adm_camp_courage],["reloadSpeed", adm_camp_reloadSpeed],["commanding", adm_camp_commanding], \
                                            ["general", adm_camp_general]]
#define PATROL_SKILL_ARRAY                  [["aimingAccuracy", adm_patrol_aimingAccuracy],["aimingShake", adm_patrol_aimingShake],["aimingSpeed", adm_patrol_aimingSpeed], \
                                            ["endurance", adm_patrol_endurance],["spotDistance", adm_patrol_spotDistance],["spotTime", adm_patrol_spotTime], \
                                            ["courage", adm_patrol_courage],["reloadSpeed", adm_patrol_reloadSpeed],["commanding", adm_patrol_commanding], \
                                            ["general", adm_patrol_general]]
#define CQC_SKILL_ARRAY                     [["aimingAccuracy", adm_cqc_aimingAccuracy],["aimingShake", adm_cqc_aimingShake],["aimingSpeed", adm_cqc_aimingSpeed], \
                                            ["endurance", adm_cqc_endurance],["spotDistance", adm_cqc_spotDistance],["spotTime", adm_cqc_spotTime], \
                                            ["courage", adm_cqc_courage],["reloadSpeed", adm_cqc_reloadSpeed],["commanding", adm_cqc_commanding], \
                                            ["general", adm_cqc_general]]

#define SIDE_ARRAY                          [EAST, WEST, RESISTANCE, CIVILIAN]
#define SIDE_TEXT_ARRAY                     ["EAST", "WEST", "RESISTANCE", "CIVILIAN"]
#define SIDE_EAST                           0
#define SIDE_WEST                           1
#define SIDE_IND                            2
#define SIDE_CIV                            3

#define UNIT_TYPE_ARRAY                     ["infantry", "crewmen", "pilots"]
#define UNIT_TYPE_INF                       0
#define UNIT_TYPE_CREW                      1
#define UNIT_TYPE_PILOT                     2

#define GROUP_TYPE_ARRAY                    ["infantry", "technicals", "armour"]
#define GROUP_TYPE_INF                      0
#define GROUP_TYPE_TECH                     1
#define GROUP_TYPE_ARMOUR                   2

#define CAMP_TYPE_ARRAY                     ["periodic", "ondemand", "random"]
#define CAMP_DEFAULT_DELAY                  60

#define CAMP_DEFAULT_ENDTRIGGER_AREA        [400,400,0,false]

#define GROUP_TYPE_DEBUG_MARKERS            ["b_inf", "b_motor_inf", "b_armor"]
#define GROUP_TYPE_DEBUG_MARKER_SIZES       [[0.7,0.7], [1,1], [1.3,1.3]]
#define WAYPOINT_DEBUG_MARKER_SIZE          [0.5,0.5]
#define CQC_DEBUG_MARKER_SIZE               [0.5,0.5]
#define CQC_DEBUG_MARKER                    "mil_triangle"
#define SIDE_DEBUG_MARKER_COLORS            ["ColorRed", "ColorBlue", "ColorGreen", "ColorPink"]

#define BEHAVIOR_MAX_REINFORCEMENT_DIST         750
#define BEHAVIOR_REINF_TURNAROUND_DIST          300
#define BEHAVIOR_ENEMY_CHECK_RADIUS             200
#define BEHAVIOR_REINF_COOLDOWN                 600
#define BEHAVIOR_CANCALL_PERCENT_CHANCE         25

#define BEHAVIOR_AVG_FT_SIZE                    4
#define BEHAVIOR_AVG_CAR_SIZE                   2.5
#define BEHAVIOR_AVG_AIR_SIZE                   2

#define BEHAVIOR_REINF_NUM(NUMS,INF,CAR,AIR)    \
    round (((NUMS) select 0) / BEHAVIOR_AVG_FT_SIZE / (INF)) \
    + round (((NUMS) select 1) / BEHAVIOR_AVG_CAR_SIZE / (CAR)) \
    + round (((NUMS) select 2) / BEHAVIOR_AVG_AIR_SIZE / (AIR))

#define STATE_INIT                              0
#define STATE_MOVING                            1
#define STATE_ENEMYFOUND                        2
#define STATE_SADENEMY                          3
#define STATE_COMBAT                            4
#define STATE_CONTINUEMOVING                    5

#define ASSERT_NOTNIL(VARNAME,MSG)                  {if (!isNil (VARNAME)) then {""} else {call (MSG)}}
#define ASSERT_TYPE(VAR,TYPE,MSG)                   {if (typename (VAR) == toUpper (TYPE)) then {""} else {call (MSG)}}
#define ASSERT_NOTEMPTY(VAR,MSG)                    {if (count (VAR) > 0) then {""} else {call (MSG)}}
#define ASSERT_ARRAYSIZE(VAR,SIZE,MSG)              {if (count (VAR) == (SIZE)) then {""} else {call (MSG)}}
#define ASSERT_ARRAYMINSIZE(VAR,MIN,MSG)            {if (count (VAR) >= (MIN)) then {""} else {call (MSG)}}
#define ASSERT_MIN(VAR,MINVAL,MSG)                  {if ((VAR) >= (MINVAL)) then {""} else {call (MSG)}}
#define ASSERT_MAX(VAR,MAXVAL,MSG)                  {if ((VAR) <= (MAXVAL)) then {""} else {call (MSG)}}
#define ASSERT_BETWEEN(VAR,MINVAL,MAXVAL,MSG)       {if ((VAR) >= (MINVAL) && (VAR) <= (MAXVAL)) then {""} else {call (MSG)}}
#define ASSERT_BOUNDARY(VAR,MSG)                    {if ((VAR) select 0 <= (VAR) select 1) then {""} else {call (MSG)}}
#define ASSERT_ISKINDOF(CLASSNAME,BASETYPE,MSG)     {if ((CLASSNAME) isKindOf (BASETYPE)) then {""} else {call (MSG)}}
#define ASSERT_INARRAY(VAR,ARRAY,MSG)               {if ((VAR) in (ARRAY)) then {""} else {call (MSG)}}
#define ASSERT_ISCLASS(SELECTOR,MSG)                {if (isClass (SELECTOR)) then {""} else {call (MSG)}}
#define ASSERT_ISNUMBER(SELECTOR,MSG)               {if (isNumber (SELECTOR)) then {""} else {call (MSG)}}
#define ASSERT_ISARRAY(SELECTOR,MSG)                {if (isArray (SELECTOR)) then {""} else {call (MSG)}}

#define CC_VAR                                      (call compile _variableName)

#define DEF_ASSERT_NOTNIL                           ASSERT_NOTNIL(_variableName,DEF_NOTNIL_MSG)
#define DEF_ASSERT_TYPE(TYPE)                       ASSERT_TYPE(CC_VAR,TYPE,DEF_TYPE_MSG)
#define DEF_ASSERT_NOTEMPTY                         ASSERT_NOTEMPTY(CC_VAR,DEF_NOTEMPTY_MSG)
#define DEF_ASSERT_ARRAYSIZE(SIZE)                  ASSERT_ARRAYSIZE(CC_VAR,SIZE,DEF_ARRAYSIZE_MSG)
#define DEF_ASSERT_MIN(MINVAL)                      ASSERT_MIN(CC_VAR,MINVAL,DEF_MIN_MSG)
#define DEF_ASSERT_MAX(MAXVAL)                      ASSERT_MAX(CC_VAR,MAXVAL,DEF_MAX_MSG)
#define DEF_ASSERT_BETWEEN(MINVAL,MAXVAL)           ASSERT_BETWEEN(CC_VAR,MINVAL,MAXVAL,DEF_BETWEEN_MSG)
#define DEF_ASSERT_BOUNDARY                         ASSERT_BOUNDARY(CC_VAR,DEF_BOUNDARY)

#define DEF_NOTNIL_MSG                              {format ["Variable '%1' can not be nil!", _variableName]}
#define DEF_TYPE_MSG                                {format ["Variable '%1' is not type of %2!", _variableName, (TYPE)]}
#define DEF_NOTEMPTY_MSG                            {format ["Array '%1' can not be empty!", _variableName]}
#define DEF_ARRAYSIZE_MSG                           {format ["Array '%1' size must be %2!", _variableName, (SIZE)]}
#define DEF_MIN_MSG                                 {format ["Variable '%1' can not be less, than %2!", _variableName, (MINVAL)]}
#define DEF_MAX_MSG                                 {format ["Variable '%1' can not be greater, than %2!", _variableName, (MAXVAL)]}
#define DEF_BETWEEN_MSG                             {format ["Variable '%1' must be between values %2 and %3!", _variableName, (MINVAL), (MAXVAL)]}
#define DEF_BOUNDARY                                {format ["Variable '%1's first value '%2' must be less, than the second value '%3'!", _variableName, CC_VAR select 0, CC_VAR select 1]}

// WARNING
// Macros are sensitive for "," (comma), "(", ")" (parenthese) and " " (space).
// Provide only the asked numbers of arguments, without additional commas and without spaces beetween commas.
// Example:
//      PUSH_ALL(_units, [_unit] call getPlayersAroundUnit);
//      This will work as intended.
//      PUSH_ALL(_units, [_unit, 100] call getPlayersAroundUnit);
//      This won't work, as the macro identifies 100 as a third parameter.
//      Use AS_ARRAY_* instead of passing actual arrays.
//      PUSH_ALL(_units, AS_ARRAY_2(_unit, 100) call getPlayersAroundUnit);

// Creates private declaritions for arguments.
// Example:
//      GIVEN:
//      WHEN:
//          PVT_3(_unit,_group,_trigger); 
//      THEN:
//          private ["_unit","_group","_trigger"];
#define PVT_1(VAR1) private [#VAR1]
#define PVT_2(VAR1,VAR2) private [#VAR1,#VAR2]
#define PVT_3(VAR1,VAR2,VAR3) private [#VAR1,#VAR2,#VAR3]
#define PVT_4(VAR1,VAR2,VAR3,VAR4) private [#VAR1,#VAR2,#VAR3,#VAR4]
#define PVT_5(VAR1,VAR2,VAR3,VAR4,VAR5) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5]
#define PVT_6(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5,#VAR6]
#define PVT_7(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5,#VAR6,#VAR7]
#define PVT_8(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5,#VAR6,#VAR7,#VAR8]
#define PVT_9(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5,#VAR6,#VAR7,#VAR8,#VAR9]


// Creates array selection for arguments. Only works if the array is a variable!
// Example:
//      GIVEN:
//          _strings = ["unit", "group", "trigger"];
//      WHEN:
//          SELECT_3(_strings,_unit,_group,_trigger); 
//      THEN:
//          _unit == "unit";
//          _group == "group";
//          _trigger == "trigger";
#define SELECT_1(ARRAY,VAR1) VAR1 = (ARRAY) select 0
#define SELECT_2(ARRAY,VAR1,VAR2) SELECT_1(ARRAY,VAR1); VAR2 = (ARRAY) select 1
#define SELECT_3(ARRAY,VAR1,VAR2,VAR3) SELECT_2(ARRAY,VAR1,VAR2); VAR3 = (ARRAY) select 2
#define SELECT_4(ARRAY,VAR1,VAR2,VAR3,VAR4) SELECT_3(ARRAY,VAR1,VAR2,VAR3); VAR4 = (ARRAY) select 3
#define SELECT_5(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5) SELECT_4(ARRAY,VAR1,VAR2,VAR3,VAR4); VAR5 = (ARRAY) select 4
#define SELECT_6(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6) SELECT_5(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5); VAR6 = (ARRAY) select 5
#define SELECT_7(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7) SELECT_6(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6); VAR7 = (ARRAY) select 6
#define SELECT_8(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8) SELECT_7(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7); VAR8 = (ARRAY) select 7
#define SELECT_9(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9) SELECT_8(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8); VAR9 = (ARRAY) select 8


// Creates private declarations and selection from _this array for arguments.
// Recommended for function/script argument processing.
// Example:
//      GIVEN:
//          _this = ["unit", "group", "trigger"];
//      WHEN:
//          FUN_ARGS_3(_unit,_group,_trigger);
//      THEN:
//          private ["_unit","_group","_trigger"];
//          _unit == "unit";
//          _group == "group";
//          _trigger == "trigger";
#define FUN_ARGS_1(VAR1) \
    PVT_1(VAR1); \
    SELECT_1(_this,VAR1)
    
#define FUN_ARGS_2(VAR1,VAR2) \
    PVT_2(VAR1,VAR2); \
    SELECT_2(_this,VAR1,VAR2)
    
#define FUN_ARGS_3(VAR1,VAR2,VAR3) \
    PVT_3(VAR1,VAR2,VAR3); \
    SELECT_3(_this,VAR1,VAR2,VAR3)
    
#define FUN_ARGS_4(VAR1,VAR2,VAR3,VAR4) \
    PVT_4(VAR1,VAR2,VAR3,VAR4); \
    SELECT_4(_this,VAR1,VAR2,VAR3,VAR4)
    
#define FUN_ARGS_5(VAR1,VAR2,VAR3,VAR4,VAR5) \
    PVT_5(VAR1,VAR2,VAR3,VAR4,VAR5); \
    SELECT_5(_this,VAR1,VAR2,VAR3,VAR4,VAR5)
    
#define FUN_ARGS_6(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6) \
    PVT_6(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6); \
    SELECT_6(_this,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6)
    
#define FUN_ARGS_7(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7) \
    PVT_7(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7); \
    SELECT_7(_this,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7)
    
#define FUN_ARGS_8(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8) \
    PVT_8(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8); \
    SELECT_8(_this,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8)
    
#define FUN_ARGS_9(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9) \
    PVT_9(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9); \
    SELECT_9(_this,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9)

// Adds a value to the end of an array.
// Example:
//      GIVEN:
//          _numbers = [1, 3, 5, 1];
//          _number = 1;
//      WHEN:
//          PUSH(_numbers, _number);
//      THEN:
//          _numbers == [1, 3, 5, 1, 1];
#define PUSH(ARRAY,VAL) (ARRAY) set [count (ARRAY), (VAL)]

// Adds all values from one array to another.
// Example:
//      GIVEN:
//          _numbers = [5, 9, 6];
//          _otherNumbers = [1, 3, 8];
//      WHEN:
//          PUSH_ALL(_numbers, _otherNumbers);
//      THEN:
//          _numbers == [5, 9, 6, 1, 3, 8];
#define PUSH_ALL(TO,FROM) { PUSH(TO,_x); } foreach (FROM)

// Filters the FROM array with a condition and adds the values that return true to the TO array.
// The values from the FROM array can be referenced by variable "_x".
// Example:
//      GIVEN:
//          _numbers = [];
//          _otherNumbers = [1, 2, 3, 6, 8];
//          _condition = {_x % 2 == 0};
//      WHEN:
//          FILTER_PUSH_ALL(_numbers, _otherNumbers, _condition);
//      THEN:
//          _numbers == [2, 6, 8];
#define FILTER_PUSH_ALL(TO,FROM,COND) { if (call COND) then { PUSH(TO,_x); }; } foreach (FROM)

// Selects a random value from an array.
// Example:
//      GIVEN:
//          _behaviours = ['AWARE', 'SAFE'];
//      WHEN:
//          _random = SELECT_RAND(_behaviours);
//      THEN:
//          _random == 'AWARE' or _random == 'AWARE'
#define SELECT_RAND(ARRAY) (ARRAY) select (floor (random (count (ARRAY))))

// Adds 1 to the variable.
// Example:
//      GIVEN:
//          _i = 0;
//      WHEN:
//          INC(_i);
//      THEN:
//          _i == 1;
#define INC(VAR) VAR = VAR + 1

// Subtracts 1 from the variable.
// Example:
//      GIVEN:
//          _i = 3;
//      WHEN:
//          DEC(_i);
//      THEN:
//          _i == 2;
#define DEC(VAR) VAR = VAR - 1

// Creates an array from given arguments.
// Example:
//      GIVEN:
//      WHEN:
//          _array = AS_ARRAY_2('AWARE','SAFE');
//      THEN:
//          _array == ['AWARE', 'SAFE'];
#define AS_ARRAY_1(VAL1) [VAL1]
#define AS_ARRAY_2(VAL1,VAL2) [VAL1,VAL2]
#define AS_ARRAY_3(VAL1,VAL2,VAL3) [VAL1,VAL2,VAL3]
#define AS_ARRAY_4(VAL1,VAL2,VAL3,VAL4) [VAL1,VAL2,VAL3,VAL4]
#define AS_ARRAY_5(VAL1,VAL2,VAL3,VAL4,VAL5) [VAL1,VAL2,VAL3,VAL4,VAL5]

// Returns the longest axis of trigger.
// Example:
//      GIVEN:
//          _trigger = trigger;
//          triggerArea _trigger == [300, 400, -31.2, false];
//      WHEN:
//          _longestAxis = LONGEST_AXIS(_trigger);
//      THEN:
//          _longestAxis == 400;
#define LONGEST_AXIS(TRG) (if ((triggerArea (TRG)) select 0 > (triggerArea (TRG)) select 1) then {(triggerArea (TRG)) select 0} else {(triggerArea (TRG)) select 1})

// Return log message iwith given logging level.
// Example:
//      GIVEN:
//          _gearClass = "FTL";
//          _gearTemplate = "M4SOC";
//          (time == 12.341)
//      WHEN:
//          _logMessage = LOG_2("WARN","Template '%1' is missing class '%2'!", _gearClass, _gearTemplate);
//      THEN:
//          _logMessage == "[ADMIRAL] 12.341 [WARN] Template 'M4SOC' is missing class 'FTL'!";
#define LOG_MSG_0(LVL,FORMAT) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + FORMAT)
#define LOG_MSG_1(LVL,FORMAT,MSG1) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + format [FORMAT, MSG1])
#define LOG_MSG_2(LVL,FORMAT,MSG1,MSG2) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + format [FORMAT, MSG1, MSG2])
#define LOG_MSG_3(LVL,FORMAT,MSG1,MSG2,MSG3) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + format [FORMAT, MSG1, MSG2, MSG3])
#define LOG_MSG_4(LVL,FORMAT,MSG1,MSG2,MSG3,MSG4) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + format [FORMAT, MSG1, MSG2, MSG3, MSG4])
#define LOG_MSG_5(LVL,FORMAT,MSG1,MSG2,MSG3,MSG4,MSG5) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + format [FORMAT, MSG1, MSG2, MSG3, MSG4, MSG5])
#define LOG_MSG_6(LVL,FORMAT,MSG1,MSG2,MSG3,MSG4,MSG5,MSG6) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + format [FORMAT, MSG1, MSG2, MSG3, MSG4, MSG5, MSG6])
#define LOG_MSG_7(LVL,FORMAT,MSG1,MSG2,MSG3,MSG4,MSG5,MSG6,MSG7) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + format [FORMAT, MSG1, MSG2, MSG3, MSG4, MSG5, MSG6, MSG7])
#define LOG_MSG_8(LVL,FORMAT,MSG1,MSG2,MSG3,MSG4,MSG5,MSG6,MSG7,MSG8) (format ["[ADMIRAL] %1 [%2] ", time, LVL] + format [FORMAT, MSG1, MSG2, MSG3, MSG4, MSG5, MSG6, MSG7, MSG8])