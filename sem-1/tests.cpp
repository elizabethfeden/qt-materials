#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "solution/json_parser.h"
//        ^^^^^^^^ change this directory to test your solution

TEST(Tokens, ValueTokens) {
  {
    std::shared_ptr<json::Token> int_token = std::make_shared<json::Int>(3);
    ASSERT_EQ(int_token->ToString(), "3");
    auto dynamic_cast_token = std::dynamic_pointer_cast<json::Value<int>>(
        int_token);
    ASSERT_NE(dynamic_cast_token, nullptr);
    ASSERT_EQ(dynamic_cast_token->GetValue(), 3);
  }
  {
    std::shared_ptr<json::Token> string_token = std::make_shared<json::String>(
        "aa");
    ASSERT_EQ(string_token->ToString(), "\"aa\"");
    auto dynamic_cast_token = std::dynamic_pointer_cast<json::String>(
        string_token);
    ASSERT_NE(dynamic_cast_token, nullptr);
    ASSERT_EQ(dynamic_cast_token->GetValue(), "aa");
  }
}


TEST(Tokens, ArrayToken) {
  {
    std::shared_ptr<json::TokenContainer<json::TokenVector::iterator>> array =
        std::make_shared<json::Array>(json::TokenVector());
    ASSERT_EQ(array->Begin(), array->End());
    ASSERT_EQ(array->ToString(), "[ ]");
  }
  {
    auto int_token = std::make_shared<json::Int>(51);
    auto string_token = std::make_shared<json::String>("hello");
    auto int_token2 = std::make_shared<json::Int>(42);
    std::shared_ptr<json::TokenContainer<json::TokenVector::iterator>> array =
        std::make_shared<json::Array>(
            json::TokenVector({int_token, string_token, int_token2}));
    ASSERT_EQ(array->ToString(), "[ 51, \"hello\", 42, ]");

    std::vector<std::string> answers = {"51", "\"hello\"", "42"};
    int i = 0;
    for (auto it = array->Begin(); it != array->End(); ++it) {
      ASSERT_EQ((*it)->ToString(), answers[i]);
      ++i;
    }

    (*array->Begin()) = int_token2;
    answers = {"42", "\"hello\"", "42"};
    i = 0;
    for (auto it = array->Begin(); it != array->End(); ++it) {
      ASSERT_EQ((*it)->ToString(), answers[i]);
      ++i;
    }
  }
}

TEST(Tokens, ObjectToken) {
  {
    std::shared_ptr<json::TokenContainer<json::ObjectMap::iterator>> object =
        std::make_shared<json::Object>(json::ObjectMap());
    ASSERT_EQ(object->Begin(), object->End());
    ASSERT_EQ(object->ToString(), "{\n}");
  }
  {
    auto int_token = std::make_shared<json::Int>(51);
    auto string_token = std::make_shared<json::String>("hello");
    auto int_token2 = std::make_shared<json::Int>(42);
    auto array_token = std::make_shared<json::Array>(
        json::TokenVector({int_token, string_token}));
    std::shared_ptr<json::TokenContainer<json::ObjectMap::iterator>> object =
        std::make_shared<json::Object>(json::ObjectMap(
            {
                {"age", int_token2},
                {"info", array_token},
                {"greeting", string_token},
            }));

    std::vector<std::string> possible_answers = {
        "{\nage: 42;\ninfo: [ 51, \"hello\", ];\ngreeting: \"hello\";\n}",
        "{\nage: 42;\ngreeting: \"hello\";\ninfo: [ 51, \"hello\", ];\n}",
        "{\ninfo: [ 51, \"hello\", ];\nage: 42;\ngreeting: \"hello\";\n}",
        "{\ninfo: [ 51, \"hello\", ];\ngreeting: \"hello\";\nage: 42;\n}",
        "{\ngreeting: \"hello\";\nage: 42;\ninfo: [ 51, \"hello\", ];\n}",
        "{\ngreeting: \"hello\";\ninfo: [ 51, \"hello\", ];\nage: 42;\n}",
    };
    ASSERT_THAT(possible_answers, ::testing::Contains(object->ToString()));

    int i = 0;
    for (auto it = object->Begin(); it != object->End(); ++it) {
      ++i;
    }
    ASSERT_EQ(i, 3);
  }
}

std::shared_ptr<json::Object> MakeTestObject(const std::vector<json::TokenVector>& arrays, const std::vector<std::string>& names) {
  json::ObjectMap map = {
      {"age", std::make_shared<json::Int>(42)},
      {"greeting", std::make_shared<json::String>("hello")}
  };
  for (size_t i = 0; i < arrays.size(); i++) {
    map[names[i]] = std::make_shared<json::Array>(arrays[i]);
  }
  return std::make_shared<json::Object>(map);
}

//TEST(Traversers, ObjectMemberCounter) {
//  ObjectMemberCounter counter;
//  {
//    auto obj1 = MakeTestObject({}, {});
//    auto obj2 = std::make_shared<json::Object>(json::ObjectMap({
//      {"object", obj1}
//    }));
//    ASSERT_EQ(counter.CountObjectMembers(obj1), 2);
//    ASSERT_EQ(counter.CountObjectMembers(obj2), 3);
//  }
//  // -- 2 --
//  // Your tests here
//}
//
//TEST(Traversers, ObjectComparator) {
//  ObjectComparator comparator;
//  // -- 3 --
//  // Your tests here
//  // Important testcases: empty object, object with objects inside it
//}
//
//TEST(Traversers, ListReverser) {
//  ListReverser reverser;
//  // -- 4 --
//  // Your tests here
//  // Hint: use ObjectComparator to compare reverser's result with expected result
//  // Important testcases: empty list, list with one element, list with odd
//  // elements count, list with even elements count
//}
