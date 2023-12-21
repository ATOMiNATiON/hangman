//-----------------------------------------------------------------------------
// Adam Wu
// 2023 December 20
// hangman.cpp
// Main file for hangman.
//-----------------------------------------------------------------------------
#include <iostream>
#include "hangman_helpers.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "wrong number of arguments" << std::endl;
        std::cout << "usage: " << argv[0] << " <secret word or phrase>" << std::endl;
        std::cout << "if the secret is multiple words, you must quote it" << std::endl;
        exit(EXIT_FAILURE);
    }

    int mistakes = 0;
    const std::string SECRET = argv[1];
    std::string phrase;
    std::string eliminated;

    // Check the validity of phrase
    if (!validate_secret(argv[1])) return EXIT_FAILURE;

    // if valid
    // then assign each character into the phrase
    for (int i = 0; argv[1][i]; i++) {
        char c = argv[1][i];
        if (c == punctuation[0]) {
            phrase += ' ';
        } else if (c == punctuation[1]) {
            phrase += '\'';
        } else if (c == punctuation[2]) {
            phrase += '-';
        } else {
            phrase += '_';
        }
    }

    // Game loop
    while (mistakes != LOSING_MISTAKE) {
        
        // print clear the screen
        std::cout << CLEAR_SCREEN << std::endl;

        // print the current art
        std::cout << arts[mistakes] << std::endl;

        // print the Phrase & Eliminated
        std::cout << "    Phrase: " << phrase << std::endl;
        std::cout << "Eliminated: " << eliminated << std::endl;
        std::cout << std::endl;

        char read;
        do {
        std::cout << "Guess a letter: ";
        read = read_letter();
        } while ((string_contains_character(phrase, read)) || 
                 (string_contains_character(eliminated, read)) ||
                 (read == ' ') ||
                 (read == '\t'));

        if (string_contains_character(SECRET, read)) {
            // update the phrase
            for (std::size_t i = 0; i < SECRET.length(); i++) {
                if (SECRET[i] == read) {
                    phrase[i] = read;
                }
            }
        } else {
            // Check if the letter is already in 'eliminated'
            if (!string_contains_character(eliminated, read)) {
                // Update eliminated only if the letter is not already there
                if (eliminated.empty()) {
                    eliminated += read;
                    mistakes++;
                } else {
                    size_t i = 0;
                    while (i < eliminated.length() && read > eliminated[i]) {
                        ++i;
                    }
                    // Insert the character at the correct position
                    eliminated.insert(i, 1, read);
                    mistakes++; 
                }

            }
        }
        if (phrase == SECRET) {
            std::cout << CLEAR_SCREEN << std::endl;
            std::cout << arts[mistakes] << std::endl;
            std::cout << "    Phrase: " << phrase << std::endl;
            std::cout << "Eliminated: " << eliminated << std::endl;
            std::cout << std::endl;
            std::cout << "You win!" << std::endl;
            return EXIT_SUCCESS;
        }

    }

    // they lost
    std::cout << CLEAR_SCREEN << std::endl;
    std::cout << arts[mistakes] << std::endl;
    std::cout << "    Phrase: " << phrase << std::endl;
    std::cout << "Eliminated: " << eliminated << std::endl;
    std::cout << std::endl;
    std::cout << "You lose! The secret phrase was: "<< SECRET << std::endl;

    return EXIT_SUCCESS;
}
