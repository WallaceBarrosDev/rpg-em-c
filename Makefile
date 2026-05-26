CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))

TARGET = build/game-rpg

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	@clear
	@./$(TARGET)

clean:
	rm -f build/*.o $(TARGET)
