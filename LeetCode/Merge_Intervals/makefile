# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

MAIN: main.o
	gcc -o MAIN main.o -lm

main.o: main.c
	gcc -c -g main.c