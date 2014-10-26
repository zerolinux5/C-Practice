#include "stdio.h"

typedef struct element{
	int value;
	int exponent;
} ELEMENT;

void printElement(ELEMENT e1)
{
	printf("%dx^%d\n", e1.value, e1.exponent);
}

int main(void)
{
	ELEMENT e1;
	e1.value = 5;
	e1.exponent = 3;

	printElement(e1);
	return 0;
}
