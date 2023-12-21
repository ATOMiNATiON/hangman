//-----------------------------------------------------------------------------
// Adam Wu
// 2023 December 20
// hangman_helpersTest.cpp
// A test harness for the hangman_helpers file.
//-----------------------------------------------------------------------------
#include <iostream>
#include <cassert>
#include "hangman_helpers.h"

int main() {
    // run test on string_conatins_character()
    std::string A = "this is a test";
    std::string B = "\t ThIS iSmY KiTTyCaT";
    assert(string_contains_character(A, 'a'));
    assert(string_contains_character(A, '\t') == false);
    assert(string_contains_character(B, 'T'));
    assert(string_contains_character(B, '\n') == false);

    // run test on validate secret
    assert(validate_secret(A));
    assert(validate_secret(B) == false);

    // run test on is_lowercase_letter()
    char first = 'a';
    char second = 'A';
    assert(is_lowercase_letter(first));
    assert(is_lowercase_letter(second) == false);

    return EXIT_SUCCESS;
}
