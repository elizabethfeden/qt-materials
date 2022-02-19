#ifndef JSON_PARSER_H
#define JSON_PARSER_H

/** Let's create a [very basic] JSON Parser!
 * Tasks are marked with "// -- N --". Follow through them and don't forget to
 * run tests!
 *
 * Reference on JSON:
 * https://www.json.org/json-en.html
 * https://json.org/example.html
 */

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

namespace json {

class Token {
 public:
  virtual std::string ToString() const = 0;
  virtual ~Token() = default;
};

template<typename T>
class Value : public Token {
 public:
  explicit Value(const T& value) : value_(value) {}

  const T& GetValue() const {
    return value_;
  }

 protected:
  T value_;
};

template<class Iterator>
class TokenContainer : public Token {
 public:
  virtual Iterator Begin() = 0;
  virtual Iterator End() = 0;
};

// -- 1 --
// Implement Int, String, Array, Object tokens.

class Int : public Value<int> {
 public:
  explicit Int(int value) : Value(value) {};
  std::string ToString() const override;
};

class String : public Value<std::string> {
 public:
  explicit String(const std::string& value) : Value(value) {};
  std::string ToString() const override;
};

using TokenVector = std::vector<std::shared_ptr<Token>>;

class Array : public TokenContainer<TokenVector::iterator> {
 public:
  explicit Array(const TokenVector& values);
  TokenVector::iterator Begin() override;
  TokenVector::iterator End() override;
  std::string ToString() const override;

 private:
  TokenVector value_;
};

using ObjectMap = std::unordered_map<std::string, std::shared_ptr<Token>>;

class Object : public TokenContainer<ObjectMap::iterator> {
 public:
  explicit Object(const ObjectMap& values);
  ObjectMap::iterator Begin() override;
  ObjectMap::iterator End() override;
  std::string ToString() const override;

 private:
  ObjectMap value_;
};

}  // namespace json

// Now, basically, json::Object.ToString() parses our construction to JSON
// in the way we want - that's the cool superpower of virtual functions.
// Now let's say that we cannot change namespace json (e.g. it's a part of
// another library). But we want to perform some specific actions on our
// JSON object structure. Let's see how we can do this.

//class Traverser {
// protected:
//  void Traverse(const std::shared_ptr<json::Token>& token) {
//    if (auto cast_result = std::dynamic_pointer_cast<json::Int>(token);
//        cast_result != nullptr) {
//      OnInt(cast_result);
//    } else if (auto cast_result =
//          std::dynamic_pointer_cast<json::String>(token); cast_result != nullptr) {
//      OnString(cast_result);
//    } else if (auto cast_result =
//          std::dynamic_pointer_cast<json::Array>(token); cast_result != nullptr) {
//      OnArray(cast_result);
//    } else if (auto cast_result =
//          std::dynamic_pointer_cast<json::Object>(token); cast_result != nullptr) {
//      OnObject(cast_result);
//    }
//  }
//
//  virtual void OnInt(const std::shared_ptr<json::Int>& token) {}
//  virtual void OnString(const std::shared_ptr<json::String>& token) {}
//  virtual void OnArray(const std::shared_ptr<json::Array>& token) {}
//  virtual void OnObject(const std::shared_ptr<json::Object>& token) {}
//};
//
//// -- 2 --
//class ObjectMemberCounter : public Traverser {
// public:
//  int CountObjectMembers(const std::shared_ptr<json::Object>& object);
//};
//
//// -- 3 --
//class ObjectComparator : public Traverser {
// public:
//  bool ObjectsEqual(const std::shared_ptr<json::Object>& one, const std::shared_ptr<json::Object>& other);
//};
//
//// -- 4 --
//class ListReverser : public Traverser {
// public:
//  void ReverseLists(const std::shared_ptr<json::Object>& object);
//};

#endif // JSON_PARSER_H
