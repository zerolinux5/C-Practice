#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "time.h"
#include "polynomialRep.h"

const int size = 6;

int main(void)
{
	srand(time(NULL));
	ELEMENT* elementArray[size];
	int i = 0;
	for(; i < size; i++){
		int r1;
		int r2;
		if(i < size/2){
			r1 = rand() % 10 + 1;
			r2 = rand() % 10 + 1;
		} else {
			r1 = rand() % 10 - 11;
			r2 = rand() % 10 - 11;
		}
		elementArray[i] = initElement(r1, r2);
		printElement(*elementArray[i], 1);
		derive(elementArray[i]);
		printElement(*elementArray[i], 1);
		integrate(elementArray[i]);
		printElement(*elementArray[i], 1);	
		//deleteElement(elementArray[i]);
	}	
	printf("\n");
	FUNCTION* function = initFunction(size, elementArray);
	printFunction(*function);
	deriveFunction(function);
	printFunction(*function);
	integrateFunction(function);
	printFunction(*function);
	printf("BoundedIntegration value:%d from A:%d to B:%d\n", boundedIntegration(function, 5, 0), 0, 5);
	printf("Solved for x = 5 :%d\n", solveFunction(function, 5));
	deleteFunction(function);
	return 0;
}
