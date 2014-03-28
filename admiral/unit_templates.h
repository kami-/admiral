#include "admiral_defines.h"

class AdmiralUnitTemplates {
    class Base {
        side=SIDE_WEST;
        infantry[] = {};
        technicals[] = {};
        armour[] = {};
        crew[] = {};
        pilots[] = {};
    };

    class TK_Army_Woodland : Base {
        side=SIDE_EAST;
        infantry[] = {"TK_Soldier_EP1"};
        technicals[] = {"UAZ_MG_TK_EP1"};
        armour[] = {"T72_TK_EP1"};
        crew[] = {"TK_Soldier_EP1"};
        pilots[] = {"TK_Soldier_EP1"};
    };
};