CC=gcc

all: fps_counter rotate_cube

fps_counter:
	$(CC) fps_counter.c -lglfw -lGL -o fps_counter

rotate_cube:
	$(CC) rotate_cube.c -lglfw -lGL -o rotate_cube.exe
