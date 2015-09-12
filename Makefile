CC=gcc

all: fps_counter

fps_counter:
	$(CC) fps_counter.c -lglfw -lGL -o fps_counter
