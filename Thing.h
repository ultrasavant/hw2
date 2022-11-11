
#ifndef _THING_H_
#define _THING_H_

#include <string>

// for Json::value
#include </usr/include/jsoncpp/json/json.h>
#include </usr/include/jsoncpp/json/reader.h>
#include </usr/include/jsoncpp/json/writer.h>
#include </usr/include/jsoncpp/json/value.h>

class Thing {
 private:

  std::string item_name;
  std::string item_description;

 public:

  explicit Thing();

  void setItemName(std::string input_item);
  void setItemDescription(std::string input_description);

  std::string getItemName();
  std::string getItemDescription();

  virtual Json::Value dump2JSON();

};

#endif