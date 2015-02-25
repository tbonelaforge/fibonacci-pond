all: pond_test.bin codility_version.bin

pond_test.bin: pond_test.c pond.o pond.h
	gcc -I ./ pond_test.c pond.o -o pond_test.bin

pond.o: pond.c pond.h
	gcc -I ./ -c pond.c -o pond.o

codility_version.bin: codility_version.c
	gcc codility_version.c -o codility_version.bin
