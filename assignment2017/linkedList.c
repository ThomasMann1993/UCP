#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"

void newNode (List *list, char* text, int size)
{
	int num;
	Node *new;
	new =(Node*)malloc(sizeof(Node));
	new ->word =(char*)malloc(size+1*sizeof(char));
	if(list ->head == NULL)
	{
		num = list ->count;
		list ->count = num +1;
	
		strncpy(new ->word, text, size);
		list ->head = new;
		list ->tail = new;

		new ->next = NULL;
	}
	else
	{
		num = list ->count;
		list ->count = num +1;

		strncpy(new ->word, text, size);
		new ->next = NULL;
		
		list ->tail ->next = new;
		list ->tail = new;
	}	
	
}

void printLinkedList (List *list)
{
	int num;
	Node *current;
	printf("at printLinkedList \n");
	num = list ->count;
	printf("%d \n", num);
	current = list ->head;
	while(current !=NULL)
	{
		printf("%s", current ->word);
		current = current ->next;
	}
}

void freeLinkedList (List* list)
{
	Node *current;
	current = list ->head;
	printf("at free Linkedlist \n");
	while(current !=NULL)
	{
		free(current ->word);
		list ->head = list ->head ->next;
		free(current);
		current = list ->head;
	}
}	
