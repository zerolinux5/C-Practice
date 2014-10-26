all: listTest

listTest: listTest.o
	gcc -o listTest list.o listTest.o

listTest.o: listTest.c
	gcc -c list.h list.c listTest.c

clean:
	rm *.o *.gch listTest
