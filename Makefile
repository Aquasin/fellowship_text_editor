CC = g++
OBJS = main.o 
CFLAGS = -Idep/include
LDFLAGS = -Ldep/lib -lsfml-graphics -lsfml-window -lsfml-system

all: compile link run

compile:
	$(CC) $(CFLAGS) -c  -O3 main.cpp src/editor.cpp src/cursor.cpp src/input_events.cpp src/document.cpp

link:
	$(CC) main.o editor.o cursor.o input_events.o document.o -o main $(LDFLAGS)

run:
	./main.exe