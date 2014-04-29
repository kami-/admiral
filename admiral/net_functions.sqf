#include "admiral_defines.h"

adm_net_fnc_sendPacket = {
    FUN_ARGS_4(_sender,_receiver,_arguments,_methodName);

    adm_net_packet = [_sender, _arguments, _methodName];
    if (isNull _receiver) then {
        publicVariableServer "adm_net_packet";
    } else {
        (owner _receiver) publicVariableClient "adm_net_packet";
    };
};

adm_net_fnc_receivePacket = {
    FUN_ARGS_4(_operations,_sender,_arguments,_methodName);

    private "_func";
    _func = {};
    {
        if (_x select 0 == _methodName) exitWith {
            _func = _x select 1;
        };
    } foreach _operations;

    [_sender, _arguments] call _func;
};

adm_net_fnc_registerPacketHandler = {
    if (isDedicated) then {
        "adm_net_packet" addPublicVariableEventHandler {
            [adm_net_serverMethods, _this select 1 select 0, _this select 1 select 1, _this select 1 select 2] call adm_net_fnc_receivePacket;
        };
    } else {
        "adm_net_packet" addPublicVariableEventHandler {
            [adm_net_clientMethods, _this select 1 select 0, _this select 1 select 1, _this select 1 select 2] call adm_net_fnc_receivePacket;
        };
    };
};

adm_net_fnc_init = {
    adm_net_clientMethods = [];
    adm_net_serverMethods = [];
    adm_net_packet = [];
};
