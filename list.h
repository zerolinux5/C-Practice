#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct List {
	int size;

	Node *head;
	Node *tail;
} List;

int list_init(List *list);
int list_destroy(List *list);
int list_insert(List*list, Node *node, int data);
int list_remove(List *list, Node *node);
void list_print(List *list);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define is_head(list, node) ((element) == (list)->head ? 1:0)
#define is_tail(node) ((node)->next == NULL ? 1:0)
#define list_data(node) ((node)->data)
#define list_next(node) ((node)->next)

#endif
