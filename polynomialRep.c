#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "time.h"
#include "polynomialRep.h"
#include "math.h"

#define value(f1) (f1->elementArray[i]->value)
#define exponent(f1) (f1->elementArray[i]->exponent)

ELEMENT* initElement(int inValue, int inExponent)
{
	ELEMENT* e1 = malloc(sizeof(ELEMENT*));
	assert(e1 != NULL);
	e1->value = inValue;
	e1->exponent = inExponent;
	return e1;
}

int solve(ELEMENT* e1, int inputX)
{
	int solution = e1->value * pow(inputX, e1->exponent);
	return solution;
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
	int i = 0;
	for(; i < f1->terms;i++){
		derive(f1->elementArray[i]);
	}
}

void integrateFunction(FUNCTION* f1)
{
	int i = 0;
	for(; i < f1->terms;i++){
		integrate(f1->elementArray[i]);
	}
}

int boundedIntegration(FUNCTION* f1, int a, int b){
	int i = 0;
	int result = 0;
	for(;i < f1->terms;i++){
		int term = pow(b, exponent(f1));
		term *= value(f1);
		result += term;
	}
	for(i = 0;i < f1->terms;i++){
		int term = pow(a, exponent(f1));
		term *= value(f1);
		result -= term;
	}
	return result;
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
	int i = 0;
	for(; i < f1->terms; i++){
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
	int i = 0;
	for(; i < f1.terms;i++){
		printElement(*f1.elementArray[i], 0);
		(i == (f1.terms -1)) ? printf("") : printf(" + ");
	}
	printf("\n");
}
