name=qq

all: file

file: file.o
	ld -o $(name) $(name).o

file.o:
	yasm -f elf64 $(name).asm
