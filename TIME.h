#ifndef _TIME_H_
#define _TIME_H_

// TIME.h

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

class TIME
{
 private:
  int day;
  int hour;

 public:
  
  explicit TIME();
  explicit TIME(int arg_day, int arg_hour);
  int getDay();
  int getHour();
  void setDayAndHour(int arg_day, int arg_hour);

  virtual Json::Value dump2JSON();

};

#endif /* _TIME_H_ */
