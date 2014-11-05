typedef struct element{
	int value;
	int exponent;
} ELEMENT;

typedef struct function{
	int terms;
	ELEMENT** elementArray;
} FUNCTION;

/*
   Initialize the element using 2 integers
   first for the base value and the second
   for the exponent
*/
ELEMENT* initElement(int inValue, int inExponent);

//Input value for x and solve polynomial expression
int solve(ELEMENT *e1, int inputX);

//Use the power rule on the given element
void derive(ELEMENT* e1);

//Integrate the element by adding to exponent and dividing
void integrate(ELEMENT* e1);

//Derive the whole function
void deriveFunction(FUNCTION* f1);

//Integrate the whole function but dont add c
void integrateFunction(FUNCTION* f1);

//calculate the integration using bounded values to return an integer
int boundedIntegration(FUNCTION* f1, int a, int b);

//Free up the pointer
void deleteElement(ELEMENT* e1);

//Initialize the function and malloc a block for it
FUNCTION* initFunction(int size, ELEMENT** terms);

//Free up the pointer
void deleteFunction(FUNCTION* f1);

//Print out the element by value, x and the exponent
//take in 1 or 0 for newline or no for format
void printElement(ELEMENT e1, int newline);

//print out the function and end with a 
//newline
void printFunction(FUNCTION f1);
