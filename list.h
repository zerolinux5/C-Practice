#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct Node {
	void *data;
	struct Node *next;
} Node;

typedef struct List {
	int size;
	int (*match)(*const void *key1, const void *key2);
	void (*destroy)(void *data);

	Node *head;
	Node *tail;
} List;

void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_insert(List*list, Node *node, const void *data);
int list_remove(List *list, Node *node, void **data);
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, node) ((element) == (list)->head ? 1:0)
#define list_is_tail(node) ((node)->next == NULL ? 1:0)
#define list_data(node) ((node)->data)
#define list_next(node) ((node)->next)

#endif
