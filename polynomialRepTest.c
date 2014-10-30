#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "time.h"
#include "polynomialRep.h"

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