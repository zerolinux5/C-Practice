#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

typedef struct element{
	int value;
	int exponent;
} ELEMENT;

typedef struct function{
	int terms;
	ELEMENT** elementArray;
} FUNCTION;

ELEMENT* initElement(int inValue, int inExponent){
	ELEMENT* e1 = malloc(sizeof(ELEMENT*));
	assert(e1 != NULL);
	e1->value = inValue;
	e1->exponent = inExponent;
	return e1;
}

void deleteElement(ELEMENT* e1){
	e1->value = 0;
	e1->exponent = 0;
	free(e1);
}

void printElement(ELEMENT e1)
{
	printf("%dx^%d\n", e1.value, e1.exponent);
}

void printFunction(FUNCTION f1)
{
	for(int i = 0; i < f1.terms;i++){
		printElement(*f1.elementArray[i]);
		(i == (f1.terms -1)) ? printf("") : printf(" + ");
	}
}

int main(void)
{
	int size = 2;
	ELEMENT* elementArray[size];
	for(int i = 0; i < size; i++){
		elementArray[i] = initElement(3, 5);
		printElement(*elementArray[i]);
		deleteElement(elementArray[i]);
	}	

	return 0;
}
