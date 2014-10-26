#include <stdio.h>
#include "list.h"

int main(void)
{
	List* l1;
	list_init(l1);
	list_insert(l1,NULL, 5);
	list_insert(l1,list_tail(l1), 10);

	list_print(l1);
}
