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

