#include "json_parser.h"

namespace json {

std::string Int::ToString() const {
  return std::to_string(value_);
}

std::string String::ToString() const {
  return "\"" + value_ + "\"";
}

TokenVector::iterator Array::Begin() {
  return value_.begin();
}

TokenVector::iterator Array::End() {
  return value_.end();
}

std::string Array::ToString() const {
  std::string result = "[ ";
  for (const auto& token: value_) {
    result += token->ToString();
    result += ", ";
  }
  result += "]";
  return result;
}

Array::Array(const TokenVector& values) : value_(values) {}

ObjectMap::iterator Object::Begin() {
  return value_.begin();
}

ObjectMap::iterator Object::End() {
  return value_.end();
}

std::string Object::ToString() const {
  std::string result = "{\n";
  for (const auto& token : value_) {
    result += token.first;
    result += ": ";
    result += token.second->ToString();
    result += ";\n";
  }
  result += "}";
  return result;
}

Object::Object(const ObjectMap& values) : value_(values) {}

}  // namespace json
