#include "Thing.h"

Thing::Thing () {
  this->item_name = "";
  this->item_description = "";
}

void Thing::setItemName(std::string input_item) {
  this->item_name = input_item;
}

void Thing::setItemDescription(std::string input_description) {
  this->item_description = input_description;
}

std::string Thing::getItemName() {
  return this->item_name;
}

std::string Thing::getItemDescription() {
  return this->item_description;
}

Json::Value Thing::dump2JSON()
{
  Json::Value Thing_result;

  if (this->item_name != "") {
    Thing_result["item_name"] = this->item_name;
  }

  if (this->item_description != "") {
    Thing_result["item_description"] = this->item_description;
  }
  
  return Thing_result;
}

