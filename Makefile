CC = clang
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c23 -O2
LDFLAGS = -lm
OUT = app

.PHONY: all build run clean

all: build

build:
	$(CC) $(CFLAGS) -o $(OUT) $(FILE) $(LDFLAGS)

run: build
	@./$(OUT)

clean:
	rm -f $(OUT)
