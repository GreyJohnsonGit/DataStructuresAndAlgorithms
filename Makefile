CC = gcc
CPPFLAGS = -Iinclude -MMD -MP
CFLAGS = -g -std=c11 -Wall

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
BIN := $(BIN_DIR)/exe

.PHONY: clean default run

default: $(BIN)

run:
	./bin/exe

$(BIN): $(OBJ)
	$(CC) -o $@ $^ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(BIN_DIR)/*

-include $(OBJ:.o=.d)