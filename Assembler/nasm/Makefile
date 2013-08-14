#
# helloworld for nasm assembler
#
SOURCE = helloworld.asm
BIN    = $(basename $SOURCE) 
NASM   = nasm
CC     = gcc

.PHONY : all elf32 elf64 win32 win64 clean

all: elf32 elf64 win32 win64

elf32 : 
	$(NASM) -f elf32 -l $(SOURCE)

%.lst : %
	gcc -o $@ -c $<

clean:
	rm -rf *.lst *.o