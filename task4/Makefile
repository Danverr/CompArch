all: main.c lib.o
	gcc -g -o bin/task4 main.c lib.o -no-pie -lm
lib.o: lib.asm
	nasm -f elf64 -g -F dwarf lib.asm -l lib.lst