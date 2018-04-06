# Clang

CC = gcc
CFLAGS = -Wall -g



# Binary name

APP_BIN = binary



# Paths

SRC_PATH = src
OBJ_PATH = obj
INC_PATH = -I include
BIN_PATH = bin
LIB_PATH = lib



# File grabbers

SRC_FILES = $(shell find $(SRC_PATH) -type f -name '*.c')
OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))



# Detect OS

# Linux
UNAME := $(shell uname -s)
ifeq ($(UNAME),Linux)
    CFLAGS += -D Linux
    LDFLAGS = -lSDL -lGLU -lGL -lm
endif

# MacOS
ifeq ($(UNAME),Darwin)
    CFLAGS += -D MacOS
    LDFLAGS = -framework OpenGL -framework GLUT -framework Cocoa
endif



# Commands

all: $(APP_BIN)

$(APP_BIN): $(OBJ_FILES)
	@mkdir -p $(BIN_PATH)
	$(CC) -o $(BIN_PATH)/$(APP_BIN) $(OBJ_FILES) $(LDFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p "$(@D)"
	$(CC) -c -v $< -o $@ $(CFLAGS) $(INC_PATH)



run:
	$(BIN_PATH)/$(APP_BIN)



clean:
	rm $(OBJ_FILES) $(BIN_PATH)/$(APP_BIN)
