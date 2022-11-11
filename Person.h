#include "Thing.h"
#include "GPS.h"

// for Json::value
#include </usr/include/jsoncpp/json/json.h>
#include </usr/include/jsoncpp/json/reader.h>
#include </usr/include/jsoncpp/json/writer.h>
#include </usr/include/jsoncpp/json/value.h>

#include <string>

#ifndef _PERSON_H_
#define _PERSON_H_

class Person {
 private:
  std::string role;
  std::string description;

  // GPS
  Thing thingInventory[3];
  GPS_DD location;
  
public:
  explicit Person();

  virtual Json::Value dump2JSON();

  void changeLocation(double input_LeagueX, double input_LeagueY);
  GPS_DD getLocation();

  void placeIntoInventory(Thing input_thing);
  std::string getInventoryName(int inventory_number);

  void setRole(std::string input_role);
  void setDescription(std::string input_description);
  std::string getRole();
  std::string getDescription();

  // Person pointer to pass by reference
  void transferThing(Person* receiver, Thing item_to_transfer);

};

#endif