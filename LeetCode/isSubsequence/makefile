# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

MAIN: main.o
	c99 -o MAIN main.o

main.o: main.c
	c99 -c -g main.c