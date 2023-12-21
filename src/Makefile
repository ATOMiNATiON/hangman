#------------------------------------------------------------------------------
# Makefile for hangman game
#
# make                          makes hangman
# make hangman_helpersTest      makes hangman_helpersTest
# make clean                    removes all executables and binary files
#------------------------------------------------------------------------------
CC = g++
CFLAGS = -std=c++17 -Wall -g

EXEC = hangman
OBJS = hangman.o hangman_helpers.o

TEST = hangman_helpersTest
OBJS2 = hangman_helpers.o hangman_helpersTest.o

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)
	
$(TEST): $(OBJS2)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJS2)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(EXEC) $(TEST) *.o 

