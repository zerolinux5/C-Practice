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
int boundedIntegration(FUNCTION* f1, int a, int b);
void deleteElement(ELEMENT* e1);
FUNCTION* initFunction(int size, ELEMENT** terms);
void deleteFunction(FUNCTION* f1);
void printElement(ELEMENT e1, int newline);
void printFunction(FUNCTION f1);
