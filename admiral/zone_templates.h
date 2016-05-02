class ZoneTemplates {
    class Camp {
        infFireteamSize = 4;
        infWaypointAmount = 4;
        techWaypointAmount = 3;
        armourWaypointAmount = 3;
        waypointBehaviours[] = {"AWARE"};
        aimingAccuracy = 0.2;
        aimingShake = 0.2;
        aimingSpeed = 0.65;
        endurance = 0.5;
        spotDistance = 0.65;
        spotTime = 0.2;
        courage = 0.4;
        reloadSpeed = 1;
        commanding = 0.5;
        general = 0.7;
    };

    class Patrol {
        infFireteamSize = 4;
        infWaypointAmount = 4;
        techWaypointAmount = 3;
        armourWaypointAmount = 3;
        waypointBehaviours[] = {"AWARE", "SAFE"};
        aimingAccuracy = 0.2;
        aimingShake = 0.2;
        aimingSpeed = 0.65;
        endurance = 0.5;
        spotDistance = 0.65;
        spotTime = 0.2;
        courage = 0.4;
        reloadSpeed = 1;
        commanding = 0.5;
        general = 0.7;
    };

    class Cqc {
        infFireteamSize = 4;
        aimingAccuracy = 0.2;
        aimingShake = 0.1;
        aimingSpeed = 1;
        endurance = 0.5;
        spotDistance = 0.4;
        spotTime = 0.1;
        courage = 0.4;
        reloadSpeed = 1;
        commanding = 1;
        general = 1;
    };
};
