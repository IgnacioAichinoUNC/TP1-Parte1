NASM= nasm -f elf
GCC= gcc
M32= -m32

execute: calc.o sum.o sub.o
	$(GCC) $(M32) -o execute calc.o sum.o sub.o -lm
calc.o: calc.c macros.h
	$(GCC) -c $(M32) calc.c -lm
sum.o: sum.asm 
	$(NASM) sum.asm	
sub.o: sub.asm
	$(NASM) sub.asm
clean:
	rm *.o execute

