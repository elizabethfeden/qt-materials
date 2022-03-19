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
  for (const auto& token : value_) {
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

std::shared_ptr<Token> Object::GetValue(const std::string& name) {
  auto value_iter = value_.find(name);
  return value_iter != value_.end() ? value_iter->second : nullptr;
}

}  // namespace json

int ObjectMemberCounter::CountObjectMembers(
    const std::shared_ptr<json::Object>& object) {
  counter_ = 0;
  Traverse(object);
  return counter_ - 1;
}

void ObjectMemberCounter::OnInt(const std::shared_ptr<json::Int>& token) {
  counter_++;
}

void ObjectMemberCounter::OnString(const std::shared_ptr<json::String>& token) {
  counter_++;
}

void ObjectMemberCounter::OnArray(const std::shared_ptr<json::Array>& token) {
  counter_++;
}

void ObjectMemberCounter::OnObject(const std::shared_ptr<json::Object>& token) {
  counter_++;
  for (auto iterator = token->Begin(); iterator != token->End(); ++iterator) {
    Traverse(iterator->second);
  }
}
