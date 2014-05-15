#ifndef LOG_MACROS_H
#define LOG_MACROS_H

#define TRACE_LVL                   0
#define DEBUG_LVL                   1
#define INFO_LVL                    2
#define WARN_LVL                    3
#define ERROR_LVL                   4
#define DISABLE_LVL                 99

#define TRACE(CTX,MESSG)
#define DEBUG(CTX,MESSG)
#define INFO(CTX,MESSG)
#define WARN(CTX,MESSG)
#define ERROR(CTX,MESSG)

#define FMT_0(FMT)
#define FMT_1(FMT,V1)
#define FMT_2(FMT,V1,V2)
#define FMT_3(FMT,V1,V2,V3)
#define FMT_4(FMT,V1,V2,V3,V4)
#define FMT_5(FMT,V1,V2,V3,V4,V5)
#define FMT_6(FMT,V1,V2,V3,V4,V5,V6)
#define FMT_7(FMT,V1,V2,V3,V4,V5,V6,V7)
#define FMT_8(FMT,V1,V2,V3,V4,V5,V6,V7,V8)
#define FMT_9(FMT,V1,V2,V3,V4,V5,V6,V7,V8,V9)

#define DUMP_1(V1)
#define DUMP_2(V1,V2)
#define DUMP_3(V1,V2,V3)
#define DUMP_4(V1,V2,V3,V4)
#define DUMP_5(V1,V2,V3,V4,V5)
#define DUMP_6(V1,V2,V3,V4,V5,V6)
#define DUMP_7(V1,V2,V3,V4,V5,V6,V7)
#define DUMP_8(V1,V2,V3,V4,V5,V6,V7,V8)
#define DUMP_9(V1,V2,V3,V4,V5,V6,V7,V8,V9)

#define RPT_LOGGER(MESSG)
#define CHAT_LOGGER(MESSG)
#ifdef LOGGING_TO_RPT
    #define RPT_LOGGER(MESSG)       diag_log (MESSG)
#endif //LOGGING_TO_RPT
#ifdef LOGGING_TO_CHAT
    #define CHAT_LOGGER(MESSG)      player globalChat (MESSG)
#endif //LOGGING_TO_CHAT
#ifndef LOGGING_TO_CUSTOM
    #define CUSTOM_LOGGER(MESSG)
#endif //LOGGING_TO_CUSTOM

#ifndef LOGGING_FORMAT
    #define LOGGING_FORMAT(CTX,STRLVL,MESSG)   format ["%1 [%2] %3 - %4", time, CTX, STRLVL, MESSG]
#endif //LOGGING_FORMAT

#ifdef LOGGING_LEVEL_TRACE
    #include "log_common_macros.h"
    #define TRACE(CTX,MESSG)        LOG(CTX,"TRACE",TRACE_LVL,(MESSG))
    #define DEBUG(CTX,MESSG)        LOG(CTX,"DEBUG",DEBUG_LVL,(MESSG))
    #define INFO(CTX,MESSG)         LOG(CTX,"INFO",INFO_LVL,(MESSG))
    #define WARN(CTX,MESSG)         LOG(CTX,"WARN",WARN_LVL,(MESSG))
    #define ERROR(CTX,MESSG)        LOG(CTX,"ERROR",ERROR_LVL,(MESSG))
#endif //LOGGING_LEVEL_TRACE
#ifdef LOGGING_LEVEL_DEBUG
    #include "log_common_macros.h"
    #define TRACE(CTX,MESSG)
    #define DEBUG(CTX,MESSG)        LOG(CTX,"DEBUG",DEBUG_LVL,(MESSG))
    #define INFO(CTX,MESSG)         LOG(CTX,"INFO",INFO_LVL,(MESSG))
    #define WARN(CTX,MESSG)         LOG(CTX,"WARN",WARN_LVL,(MESSG))
    #define ERROR(CTX,MESSG)        LOG(CTX,"ERROR",ERROR_LVL,(MESSG))
#endif //LOGGING_LEVEL_DEBUG
#ifdef LOGGING_LEVEL_INFO
    #include "log_common_macros.h"
    #define TRACE(CTX,MESSG)
    #define DEBUG(CTX,MESSG)
    #define INFO(CTX,MESSG)         LOG(CTX,"INFO",INFO_LVL,(MESSG))
    #define WARN(CTX,MESSG)         LOG(CTX,"WARN",WARN_LVL,(MESSG))
    #define ERROR(CTX,MESSG)        LOG(CTX,"ERROR",ERROR_LVL,(MESSG))
#endif //LOGGING_LEVEL_INFO
#ifdef LOGGING_LEVEL_WARN
    #include "log_common_macros.h"
    #define TRACE(CTX,MESSG)
    #define DEBUG(CTX,MESSG)
    #define INFO(CTX,MESSG)
    #define WARN(CTX,MESSG)         LOG(CTX,"WARN",WARN_LVL,(MESSG))
    #define ERROR(CTX,MESSG)        LOG(CTX,"ERROR",ERROR_LVL,(MESSG))
#endif //LOGGING_LEVEL_WARN
#ifdef LOGGING_LEVEL_ERROR
    #include "log_common_macros.h"
    #define TRACE(CTX,MESSG)
    #define DEBUG(CTX,MESSG)
    #define INFO(CTX,MESSG)
    #define WARN(CTX,MESSG)
    #define ERROR(CTX,MESSG)        LOG(CTX,"ERROR",ERROR_LVL,(MESSG))
#endif //LOGGING_LEVEL_ERROR

#ifdef LOGGING_RUNTIME
    #define LOGGING_INITIALIZED             logging_isInitialized
    #define LOGGING_CONTEXTS                logging_context_repository
    #define LOGGING_FNC_GET_CTX             logging_fnc_getContext
    #define LOGGING_FNC_CAN_LOG             logging_fnc_canLogInContext
    #define LOGGING_FNC_SET_CTX_LVL         logging_fnc_setContextLevel
    #define LOGGING_FNC_DISABLE_CTX         logging_fnc_disableContext

    #include "log_common_macros.h"

    #define LOG(CTX,STRLVL,LVL,MESSG) \
        call { \
            private "_message"; \
            _message = LOGGING_FORMAT(CTX,STRLVL,MESSG); \
            if ([CTX, LVL] call (LOGGING_FNC_CAN_LOG)) then { \
                RPT_LOGGER(_message); \
                CHAT_LOGGER(_message); \
                CUSTOM_LOGGER(_message); \
            }; \
        }

    #define TRACE(CTX,MESSG)        LOG(CTX,"TRACE",TRACE_LVL,(MESSG))
    #define DEBUG(CTX,MESSG)        LOG(CTX,"DEBUG",DEBUG_LVL,(MESSG))
    #define INFO(CTX,MESSG)         LOG(CTX,"INFO",INFO_LVL,(MESSG))
    #define WARN(CTX,MESSG)         LOG(CTX,"WARN",WARN_LVL,(MESSG))
    #define ERROR(CTX,MESSG)        LOG(CTX,"ERROR",ERROR_LVL,(MESSG))

    if (isNil {LOGGING_INITIALIZED}) then {
        LOGGING_INITIALIZED = true;
        LOGGING_CONTEXTS = [];

        LOGGING_FNC_GET_CTX = {
            private ["_contextName", "_context"];
            _contextName = _this select 0;
            _context = [];
            {
                if (_contextName == _x select 0) exitWith {_context = _x};
            } foreach (LOGGING_CONTEXTS);

            _context;
        };

        LOGGING_FNC_CAN_LOG = {
            private ["_contextName", "_level", "_context"];
            _contextName = _this select 0;
            _level = _this select 1;
            _context = [_contextName] call (LOGGING_FNC_GET_CTX);

            count _context > 0 && {_context select 1 <= _level};
        };

        LOGGING_FNC_SET_CTX_LVL = {
            private ["_contextName", "_level", "_context"];
            _contextName = _this select 0;
            _level = _this select 1;
            _context = [_contextName] call (LOGGING_FNC_GET_CTX);
            if (count _context == 0) then {
                (LOGGING_CONTEXTS) set [count (LOGGING_CONTEXTS), [_contextName, _level]];
            } else {
                _context set [1, _level];
            };
        };

        LOGGING_FNC_DISABLE_CTX = {
            private ["_contextName", "_context"];
            _contextName = _this select 0;
            _context = [_contextName] call (LOGGING_FNC_GET_CTX);
            if (count _context > 0) then {
                _context set [1, DISABLE_LVL];
            };
        };
    };
#endif //LOGGING_RUNTIME

#endif //LOG_MACROS_H