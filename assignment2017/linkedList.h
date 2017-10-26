
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "header.h"
 
typedef struct Node
{
	void * word;
	struct Node *next;
}Node;

typedef struct List 
{
	int count;
	Node *head;
	Node *tail;
}List;

int wordRead (List*, char*);
void newNode(List*, char*, int);
void printLinkedList(List*);
void freeLinkedList(List*);
void createArray (List*, char**);
void printArray (char*[], int);
void freeArray (int, char*[]);
#endif
