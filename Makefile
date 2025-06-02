# Makefile para compilar el Juego de la Vida
CC = gcc
CFLAGS = -Wall -O2 -fopenmp -Iinclude
LDFLAGS = -fopenmp
SRC = src/main.c src/bitboard.c src/game.c src/util.c
OBJ = $(SRC:.c=.o)
EXEC = game_of_life

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean