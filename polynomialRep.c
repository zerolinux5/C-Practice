#include "stdio.h"

typedef struct element{
	int value;
	int exponent;
} ELEMENT;

typedef struct function{
	int terms;
	ELEMENT* elementArray;
} FUNCTION;

void printElement(ELEMENT e1)
{
	printf("%dx^%d\n", e1.value, e1.exponent);
}

void printFunction(FUNCTION f1)
{
	for(int i = 0; i < f1.terms;i++){
		printElement(f1.elementArray[i]);
		(i == (f1.terms -1)) ? printf("") : printf(" + ");
	}
}

int main(void)
{
	int size = 2;
	ELEMENT elementArray[size];
	for(int i = 0; i < size; i++){
		elementArray[i].value = 3;
		elementArray[i].exponent = 4;
		printElement(elementArray[i]);
	}	

	return 0;
}
