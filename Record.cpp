#include "Record.h"
#include "TIME.h"

#include <iostream>
#include <cstdio>

Record::Record() {
  this->eventDescription = "";
  this->eventTime.setDayAndHour(1, 0);
}

void Record::addGPS(double input_LeagueX, double input_LeagueY) {
  this->eventLocation.setLeagueXY(input_LeagueX, input_LeagueY);
}

void Record::addTime(int input_day, int input_hour) {
  this->eventTime.setDayAndHour(input_day, input_hour);
}

void Record::addRole(const Person& input_role) {
    for (int i = 0; i < 4; i += 1) {
        // Add role into empty roles[4] element
        if ((this->roles[i]).getRole() == "") {
            this->roles[i] = input_role;
            // std::cout << "input_role successfully added into roles[" << i << "]\n" << std::endl;
            break;
        }
    }

}

void Record::addDescription(std::string input_description) {
  this->eventDescription = input_description;
}

Json::Value Record::dump2JSON (void) {
  Json::Value result { };

  if (this->eventDescription != "") {
    result["event_description"] = this->eventDescription;
  }

  result["event_time"] = this->eventTime.dump2JSON();

  // sprintf(event_location, "(leagueX, leagueY) = (%lf, %lf)", this->eventLocation.getLeagueX(), this->eventLocation.getLeagueY());
  result["event_location"] = this->eventLocation.dump2JSON();

  Json::Value Person_result;

// Store individual Person_result into result
  std::string roleName = "";
  for (int i = 0; i < 4; i += 1) {
    roleName = this->roles[i].getRole();
    if (roleName == "") {
        continue;
    }
    Person_result = (this->roles[i].dump2JSON());

    result[roleName] = Person_result;
  }

  return result;
}