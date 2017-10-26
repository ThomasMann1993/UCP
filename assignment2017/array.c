#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"

void createArray (List *list, char*array[])
{
	int size =0, i =0;
	Node *current =NULL;


	current = list ->head;
	while(current !=NULL)
	{
		size = strlen(current ->word);
		array[i] = (char*)malloc(size+1*sizeof(char));
		strncpy(array[i], current ->word, size);
		array[i][size] = '\0';
		current = current ->next;
		i++;
	}
}

void printArray (char *array[], int size)
{
	int i;
	printf("\n");
	for(i=0; i <size; i++)
	{
		printf("%s ", array[i]);
	}
}

void freeArray (int size, char *array[])
{
	int i;
	for(i=0; i <size; i++)
	{
		free(array[i]);
	}
}
