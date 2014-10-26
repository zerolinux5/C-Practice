all: listTest polynomialRep

polynomialRep: polynomialRep.o
	gcc -o polynomialRep polynomialRep.o

polynomialRep.o: polynomialRep.c
	gcc -c polynomialRep.c

listTest: listTest.o
	gcc -o listTest list.o listTest.o

listTest.o: listTest.c
	gcc -c list.h list.c listTest.c

clean:
	rm *.o *.gch listTest polynomialRep
