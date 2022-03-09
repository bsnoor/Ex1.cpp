#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;
/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
        std::erase(input, ' ');
        std::erase(input, '\t');
        std::erase(input, '\n');
        std::erase(input, '\r');
        return input;
}
TEST_CASE("Good input") {
        CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                                                                         "@-------@\n"
                                                                                                         "@-@@@@@-@\n"
                                                                                                         "@-@---@-@\n"
                                                                                                         "@-@@@@@-@\n"
                                                                                                         "@-------@\n"
                                                                                                         "@@@@@@@@@"));
        CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                                                                         "@-----------@\n"
                                                                                                         "@-@@@@@@@@@-@\n"
                                                                                                        "@-----------@\n"
                                                                                                        "@@@@@@@@@@@@@"));  
        CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@@\n"
                                                         "@-@\n"
                                                         "@@@")); // 
        
        CHECK(nospaces(mat(3, 3, '@', '@')) == nospaces("@@@@\n"
                                                         "@@@\n"
                                                         "@@@")); // 
}

TEST_CASE("Good code"){                                                         
        CHECK(nospaces(mat(1, 1, '@', '@')) == nospaces("@\n"));// 
        CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@\n")); // 
        CHECK(nospaces(mat(1, 3, '@', '-')) == nospaces("@\n"
                                                         "@\n"
                                                          "@\n")); //  
        CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces("@@@\n")); //                                                  
}
TEST_CASE("bad expected result") {
     CHECK_THROWS(mat(0, 9, '@', '!')); // 
  //   CHECK_THROWS(mat(10.5, 9, '@', 'b'));//
    // CHECK_THROWS(mat(10, 7, 'q', '!'));// 
     CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces("@@\n"));
}
TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); // 
   // CHECK_THROWS(mat(0, 0, 'b', 'b')); //  
    CHECK_THROWS(mat(-10, 5, '@', '!')); //
    CHECK_THROWS(mat(10, 15, '@', '!'));// 
    CHECK_THROWS(mat(10, -7, '@', '!'));// 
    CHECK_THROWS(mat(3, 18, '@', '!'));// 
    CHECK_THROWS(mat(10, 7, '@', '!'));// 
    CHECK_THROWS(mat(12, 16, 'q', '!'));// 
    CHECK_THROWS(mat(-3, 5, '@', '!'));//
    CHECK_THROWS(mat(-9, 13, '@', '!'));//
    CHECK_THROWS(mat(20, 27, '@', '!'));// 
   // CHECK_THROWS(mat(10.5, 9, '@', 'b'));//
    //CHECK_THROWS(mat(10.5, 7, 'a', '9'));// 
    CHECK_THROWS(mat(10, -7, '@', '!'));//                 
}

TEST_CASE("bad result") {
     CHECK_THROWS(mat(0, 1, '@', '!')); //  
     CHECK_THROWS(mat(10, 8, '@', 'b'));//
     CHECK_THROWS(mat(10, 4, 'q', '!'));// 
     CHECK(nospaces(mat(7, 1, '@', '-')) == nospaces("@@\n"));
}
TEST_CASE("Bad regarding size of code") {
     //  CHECK_THROWS(mat(-10, 17, '(', ')'));// 
      // CHECK_THROWS(mat(7, -100, '#', '+'));// 
       //CHECK_THROWS(mat(-9, -40, '@', '-'));//
       //CHECK_THROWS(mat(0.5,-7, '$', '%'));
       CHECK_THROWS(mat(10, -1, '$', '%'));
       CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces("@\n"));
}
