#include "list.h"

int list_init(List *list) {
	printf("Initializing..\n");
	list = (List *)malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	printf("Hello\n");

	return 0;
}

int list_insert(List *list, Node *node, int data){
	printf("Inserting:%d\n",data);
	Node *new_node;
	if ((new_node = (Node *)malloc(sizeof(Node))) == NULL){
		return -1;
	}
	new_node->data = data;
	if (node == NULL) {
		if (list_size(list) == 0)
			list->tail = new_node;
		new_node->next = list->head;	
		list->head = new_node;
	} else {
		if (node->next == NULL)
			list->tail = new_node;
		new_node->next = node->next;
		node->next = new_node;
	}
	list->size++;
	
	return 0;
}

int list_remove(List *list, Node *node){
	Node *old_node;
	if(list_size(list) == 0)
		return -1;
	if (node == NULL){
		old_node = list->head;
		list->head = list->head->next;
		if(list_size(list) == 1)
			list->tail = NULL;
	} else {
		if (node->next == NULL)
			return -1;
		old_node = node->next;
		node->next = node->next->next;
		if(node->next == NULL)
			list->tail = node;
	}
	free(old_node);
	list->size--;
		
	return 0;
}

int list_destroy(List *list){
	while(list_size(list) > 0){
		list_remove(list, NULL);
	}
	return 0;
}

void list_print(List *list){
	Node *iterator;
	iterator = list_head(list);
	while(iterator != list_tail(list)){
		printf("Data:%d ", list_data(iterator));
		iterator=list_next(iterator);
	}
	printf("Data:%d",list_data(iterator));
}
