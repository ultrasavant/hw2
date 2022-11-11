#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include "TIME.h"
#include "Record.h"

#include <iostream>

int main() {
    
    // Initialize roles, GPS default of (0, 0)
    Person ridingHood;
    ridingHood.setRole("Little Red Riding Hood");
    ridingHood.setDescription("A dear little girl");

    Person grandmother;
    grandmother.setRole("Grandmother");
    grandmother.changeLocation(0, 0.5);

    Person mother;
    mother.setRole("Mother");
    mother.changeLocation(0, 0);

    Person wolf;
    wolf.setRole("Wolf");
    wolf.changeLocation(0, 0.6);
   
    // Intialize things
    Thing cap;
    cap.setItemName("Cap");
    cap.setItemDescription("A little cap of red velvet");

    Thing cake;
    cake.setItemName("cake");
    
    Thing wine;
    wine.setItemName("wine");

    // Record 1: Riding hood wearing cap
    grandmother.placeIntoInventory(cap);
    grandmother.transferThing(&ridingHood, cap);

    Record ridingHoodWearCap;
    ridingHoodWearCap.addRole(ridingHood);
    ridingHoodWearCap.addRole(grandmother);
    ridingHoodWearCap.addDescription("Grandmother gives riding hood the cap long before she sets out.");


    // Record 2: Mother gives riding hood cake and wine in village
    mother.placeIntoInventory(cake);
    mother.placeIntoInventory(wine);

    mother.transferThing(&ridingHood, cake);
    mother.transferThing(&ridingHood, wine);

    Record ridingHoodGetsFood;
    ridingHoodGetsFood.addRole(ridingHood);
    ridingHoodGetsFood.addRole(mother);
    ridingHoodGetsFood.addTime(100, 12);
    ridingHoodGetsFood.addDescription("Mother gives riding hood cake and wine in village");


    // Record 3: Riding Hood meets wolf in woods
    Record ridingHoodEncountersWolf;
    ridingHoodEncountersWolf.addRole(ridingHood);
    ridingHoodEncountersWolf.addRole(wolf);
    ridingHoodEncountersWolf.addTime(100, 20);
    ridingHoodEncountersWolf.addGPS(0, 0.25);
    ridingHoodEncountersWolf.addDescription("Riding Hood meets wolf in woods");


    // Record 4: Grandmother at home right outside woods with three oak trees nearby
    GPS_DD threeOakTrees(0, 0.5);
    
    Record grandmotherAtHome;
    grandmotherAtHome.addRole(grandmother);
    grandmotherAtHome.addTime(100, 20);
    grandmotherAtHome.addGPS(0, 0.5);
    grandmotherAtHome.addDescription("Grandmother at home right outside woods with three oak trees nearby");


    // dump2json, print records
    std::cout << "Riding Hood Wears Cap:\n" << ridingHoodWearCap.dump2JSON()  << "\n" << std::endl;
    std::cout << "Riding Hood Gets Food:\n" << ridingHoodGetsFood.dump2JSON()  << "\n" << std::endl;
    std::cout << "Riding Hood Encounters Wolf:\n" << ridingHoodEncountersWolf.dump2JSON()  << "\n" << std::endl;
    std::cout << "Grandmother At Home:\n" << grandmotherAtHome.dump2JSON()  << "\n" << std::endl;
    
    return 0;
}