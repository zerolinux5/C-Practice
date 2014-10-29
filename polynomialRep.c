#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "time.h"

typedef struct element{
	int value;
	int exponent;
} ELEMENT;

typedef struct function{
	int terms;
	ELEMENT** elementArray;
} FUNCTION;

ELEMENT* initElement(int inValue, int inExponent)
{
	ELEMENT* e1 = malloc(sizeof(ELEMENT*));
	assert(e1 != NULL);
	e1->value = inValue;
	e1->exponent = inExponent;
	return e1;
}

void derive(ELEMENT* e1)
{
	int power = e1->exponent;
	e1->value *= power;
	if(power != 0)
		e1->exponent--;
}

void integrate(ELEMENT* e1)
{
	if(e1->exponent == 0) {
		return;
	} else {
		e1->exponent++;
		e1->value /= e1->exponent;
	}
}

void deriveFunction(FUNCTION* f1)
{
	for(int i = 0; i < f1->terms;i++){
		derive(f1->elementArray[i]);
	}
}

void integrateFunction(FUNCTION* f1)
{
	for(int i = 0; i < f1->terms;i++){
		integrate(f1->elementArray[i]);
	}
}

void deleteElement(ELEMENT* e1)
{
	e1->value = 0;
	e1->exponent = 0;
	e1 = NULL;
	free(e1);
}

FUNCTION* initFunction(int size, ELEMENT** terms)
{
	FUNCTION* f1 = malloc(sizeof(FUNCTION*));
	assert(f1 != NULL);
	f1->terms = size;
	f1->elementArray = terms;
	return f1;
}

void deleteFunction(FUNCTION* f1)
{	
	for(int i = 0; i < f1->terms; i++){
		if (f1->elementArray[i] != NULL) 
			deleteElement(f1->elementArray[i]);	
	}
	f1->terms = 0;
	free(f1);
}

void printElement(ELEMENT e1, int newline)
{
	if(e1.exponent == 0){
		printf("0");
	} else {
		printf("%dx^%d", e1.value, e1.exponent);
	}
	if(newline)
		printf("\n");
}

void printFunction(FUNCTION f1)
{
	for(int i = 0; i < f1.terms;i++){
		printElement(*f1.elementArray[i], 0);
		(i == (f1.terms -1)) ? printf("") : printf(" + ");
	}
	printf("\n");
}

int main(void)
{
	srand(time(NULL));
	int size = 2;
	ELEMENT* elementArray[size];
	for(int i = 0; i < size; i++){
		int r1 = rand() % 10 + 1;
		int r2 = rand() % 10 + 1;
		elementArray[i] = initElement(r1, r2);
		printElement(*elementArray[i], 1);
		derive(elementArray[i]);
		printElement(*elementArray[i], 1);
		integrate(elementArray[i]);
		printElement(*elementArray[i], 1);	
		//deleteElement(elementArray[i]);
	}	
	printf("\n");
	FUNCTION* function = initFunction(2, elementArray);
	printFunction(*function);
	deriveFunction(function);
	printFunction(*function);
	integrateFunction(function);
	printFunction(*function);
	deleteFunction(function);
	return 0;
}
