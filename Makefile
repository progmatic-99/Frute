main: ./src/*.c ./headers/*.h
	gcc -Iinclude -Idir ./headers/ -o main ./src/*.c
