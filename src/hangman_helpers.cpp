//-----------------------------------------------------------------------------
// Adam Wu
// 2023 December 20
// hangman_helpers.cpp
// Implementation of hangman_helpers header file.
//-----------------------------------------------------------------------------
#include "hangman_helpers.h"

bool string_contains_character(const std::string& s, char c) {
    for (std::size_t i = 0; i < s.length(); ++i) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

char read_letter() {
    std::string stream;
    std::getline(std::cin, stream);
    return stream[0];
}

bool validate_secret(const std::string& secret) {
    if (secret.length() > MAX_LENGTH) {
        std::cout << "The secrect phrase is over 256 characters." << std::endl;
        return false;
    }

    for (int i = 0; secret[i]; i++) {
        char letter = secret[i];
        if (!is_lowercase_letter(letter) && 
            (letter != punctuation[0]) &&
            (letter != punctuation[1]) &&
            (letter != punctuation[2]) ) {
            std::cout << "Invalid character: '" << letter << "'" << std::endl; 
            std::cout << "the secret phrase must contain only lowercase letters, spaces, hyphens, and apostrophes" << std::endl;
            return false;
        }
    }

    return true;
}

bool is_lowercase_letter(char c) {
    return (c >= 97 && c <= 122);
}
