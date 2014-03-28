#include "admiral_defines.h"

class AdmiralUnitTemplates {
    class Base {
        side=SIDE_WEST;
        infantry[] = {};
        technical[] = {};
        armour[] = {};
        crewmen[] = {};
        pilots[] = {};
    };

    class TK_Army_Woodland : Base {
        side=SIDE_EAST;
        infantry[] = {"TK_Soldier_EP1"};
        technical[] = {"UAZ_MG_TK_EP1"};
        armour[] = {"T72_TK_EP1"};
        crewmen[] = {"TK_Soldier_Crew_EP1"};
        pilots[] = {"TK_Soldier_Pilot_EP1"};
    };
};