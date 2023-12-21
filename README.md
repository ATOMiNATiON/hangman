# hangman

## Purpose
Simple hangman game implemented in the terminal. The purpose of this project is to practice writing C++ code (specifially practicing string arrays). 

## Project Structure
```
hangman
├── README.md
├── doc
│   ├── bibtex.bib
│   ├── designDoc.pdf
│   └── main.tex
└── src
    ├── Makefile
    ├── hangman.cpp
    ├── hangman_helpers.cpp
    ├── hangman_helpers.h
    └── hangman_helpersTest.cpp
```

## How to use the program
First clone this repository and go to the src folder. Once inside the src folder, you can type 'make'. Everything should then compile and you will have new file in your folder. To run the program, you can type './hangman' followed by a secret word or phrase. Note that if the secret is multiple words, you must quote it.

```
make
./hangman <secret word or phrase>
```

