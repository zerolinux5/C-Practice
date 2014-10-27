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
	}
}

int main(void)
{
	ELEMENT e1;
	e1.value = 5;
	e1.exponent = 3;

	printElement(e1);
	return 0;
}
