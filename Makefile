CC = gcc
CFLAGS = -pedantic -Wall -Wextra -std=c11 -O2

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))

.PHONY: build clean

run: build
	@clear
	@./build/game

build: build/game

build/game: $(OBJ)
	@$(CC) $(OBJ) -o $@

build/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*.o build/game
