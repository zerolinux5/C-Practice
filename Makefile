all: listTest polynomialRepTest

polynomialRepTest: polynomialRepTest.o
	gcc -o polynomialRepTest polynomialRep.o polynomialRepTest.o  

polynomialRepTest.o: polynomialRep.h polynomialRep.c polynomialRepTest.c
	gcc -c polynomialRep.h polynomialRep.c polynomialRepTest.c

listTest: listTest.o
	gcc -o listTest list.o listTest.o

listTest.o: listTest.c
	gcc -c list.h list.c listTest.c

clean:
	rm *.o *.gch listTest polynomialRepTest
