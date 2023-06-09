all : Animal.o Bird.o SeaCreature.o main.o
	g++ Animal.o Bird.o SeaCreature.o main.o
  
clean :
	rm a.out test *.o

test : Animal.o Bird.o SeaCreature.o test.o
	g++ Animal.o Bird.o SeaCreature.o test.o -o test

main.o : main.cpp Animal.h Bird.h SeaCreature.h
	g++ -c main.cpp -o main.o

test.o : test.cpp Animal.h Bird.h SeaCreature.h
	g++ -c test.cpp -o test.o

Animal.o : Animal.cpp Animal.h
	g++ -c Animal.cpp -o Animal.o

Bird.o : Bird.cpp Bird.h Animal.h
	g++ -c Bird.cpp -o Bird.o

SeaCreature.o : SeaCreature.cpp SeaCreature.h Animal.h
	g++ -c SeaCreature.cpp -o SeaCreature.o
