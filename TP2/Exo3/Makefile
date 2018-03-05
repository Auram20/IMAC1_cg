CC = gcc
FRAMEWORKS = -framework SDL -framework Cocoa -framework OpenGL
TARGET = minimal.c

all: build run clean

run:
	./out

build: 
	$(CC) $(FRAMEWORKS) $(TARGET) "./SDLMain.m" -o out

clean:
	rm -rf ./*.o
