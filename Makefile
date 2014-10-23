all: polynomialRep

polynomialRep: polynomialRep.o
	gcc -o polynomialRep polynomialRep.o

polynomialRep.o: polynomialRep.c
	gcc -c polynomialRep.c

clean:
	rm *.o polynomialRep
