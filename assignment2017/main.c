#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "header.h"
#include "chech.h"

int main (int argc, char *argv[])
{
	List *dict =NULL; 
	List *userFile =NULL;
	Conf *conf =NULL;
/*	ActionFunc *action;	*/
	int good =0 ,textLength, dictLength;
	char **dictArray =NULL, **userFileArray =NULL;

    if(argc != 3)
    {
		printf("Error:  command inputs\n");
		good = 1; 
    }

	while( good != 1)
	{

		dict = (List*)malloc(sizeof(List));
		userFile = (List*)malloc(sizeof(List));
		conf = (Conf*)malloc(sizeof(Conf));
		
		dict ->head =NULL;
		dict ->tail =NULL;
		dict ->count =0;

		userFile ->head =NULL;
		userFile ->tail =NULL;
		userFile ->count =0;


		good = spellConf(conf);
	
		good = wordRead(dict, conf ->dictFile);
		good = wordRead(userFile, argv[1]);

		dictLength = dict ->count;
		textLength = userFile ->count;

		dictArray = (char**)malloc(dictLength * sizeof(char*));
		userFileArray = (char**)malloc(textLength * sizeof(char*));
			
		createArray(dict, dictArray);	
		createArray(userFile, userFileArray);

		upLoadFile(userFileArray, argv[2], textLength);
/*
		action = decission(conf);
		check(userFileArray, textLength, dictArray, dictLength, conf ->maxDiff, action);
*/		
		good = 1;
	}

	freeArray(dictLength, dictArray);
	freeArray(textLength, userFileArray);
	freeLinkedList(dict);
	freeLinkedList(userFile);
	free(dictArray);
	free(userFileArray);
	free(dict);
	free(userFile);
	free(conf ->dictFile);
	free(conf ->autoCorr);
	free(conf);

	return 0;
}
