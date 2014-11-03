#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "time.h"
#include "polynomialRep.h"

int main(void)
{
	srand(time(NULL));
	int size = 4;
	ELEMENT* elementArray[size];
	for(int i = 0; i < size; i++){
		int r1;
		int r2;
		if(i < 2){
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
	deleteFunction(function);
	return 0;
}
