#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

// for Json::value
#include </usr/include/jsoncpp/json/json.h>
#include </usr/include/jsoncpp/json/reader.h>
#include </usr/include/jsoncpp/json/writer.h>
#include </usr/include/jsoncpp/json/value.h>

using namespace std;

class GPS_DD
{
 private:
  double LeagueX;
  double LeagueY;

 public:
  explicit GPS_DD();
  explicit GPS_DD(double, double);
  double getLeagueX();
  double getLeagueY();

  void setLeagueXY(double input_LeagueX, double input_LeagueY); 

  virtual Json::Value dump2JSON();

};

#endif /* _GPS_H_ */