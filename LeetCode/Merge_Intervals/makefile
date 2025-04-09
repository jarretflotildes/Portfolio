# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

MAIN: main.o
	g++ -o MAIN main.o -lm

main.o: main.cpp
	g++ -c -g main.cpp

clean:
	rm -f MAIN *.o
