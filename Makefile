main: main.o
	g++ -o main main.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o



main.o: main.cpp profile.h

tests.o: tests.cpp doctest.h

clean:
	rm -f main.o funcs.o tests.o
