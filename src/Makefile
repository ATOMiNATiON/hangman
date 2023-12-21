#------------------------------------------------------------------------------
# Makefile for hangman game
#
# make          		makes hangman
# make clean    		removes all executables and binary files
#------------------------------------------------------------------------------
CC = g++
CFLAGS = -std=c++17 -Wall -g
EXEC = hangman
OBJS = hangman.o hangman_helpers.o

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

clean:
	rm -rf $(EXEC) $(OBJS)

