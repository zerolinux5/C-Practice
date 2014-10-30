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

ELEMENT* initElement(int inValue, int inExponent);
void derive(ELEMENT* e1);
void integrate(ELEMENT* e1);
void deriveFunction(FUNCTION* f1);
void integrateFunction(FUNCTION* f1);
void deleteElement(ELEMENT* e1);
FUNCTION* initFunction(int size, ELEMENT** terms);
void deleteFunction(FUNCTION* f1);
void printElement(ELEMENT e1, int newline);
void printFunction(FUNCTION f1);