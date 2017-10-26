#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "header.h"

int wordRead (List* list, char* inFile)
{
	FILE *file;	
	int size, run,  error =0;
	char *ch, *token;
	char text[100];
	file = fopen(inFile, "r");
	if(file == NULL)
	{
		perror("ERROR: unable to open file\n");
		error = 1;
	}
	else
	{
/*
		run = fscanf(file, "%s", text);
		if(ferror(file))
		{
			perror("ERROR: unable to read file\n");
			error = 1;
		}
		else
		{
			while( run !=EOF)
			{
				size = strlen(text);
				newNode(list, text, size);
				run = fscanf(file, "%s", text);
			}
		}
*/
		printf("\n\n");
		ch = fgets (text, 100, file);
		if(ferror(file))
		{
			perror("ERROR: unable to read file\n");
			error = 1;
		}
		else
		{
			while(ch !=NULL)
			{
				token = strtok(text, " ");

				while(token !=NULL)
				{			
					size = strlen(token);
					newNode(list, token, size);
					token = strtok(NULL, " ");
				}
	
				ch = fgets(text, 100, file);
			}
			
		}

		if(fclose(file) !=0)
		{
			perror("ERROR: unbale to close file\n");
		}
	}
	return error;
}

		

int spellConf (Conf* conf)
{
	FILE *file;
	char rand1[50], rand2[50], input[3][50];
	int tempSize, run;
	int size =0, error = 0, i =0; 
	int dictionary =-1, max =-1, corrt =-1;
	
	file = fopen(".spellconf", "r");

	if(file == NULL)
	{
		perror("ERROR: unable to open file\n");
		error = 1;
	}
	else
	{
		run = fscanf(file, "%s %s %s ", rand1, rand2, input[i]);
		if(ferror(file))
		{
			perror("ERROR: unable to read from file\n");
			error = 1;
		}
		else
		{
			while( run !=EOF)
			{
				tempSize = strlen(input[i]);
		
				if(tempSize > size)
				{
					size = tempSize;
				}

				if(rand1[0] == 'd' || rand1[0] == 'D')
				{
					dictionary = i;
				}
				else if (rand1[0] == 'm' || rand1[0] == 'M')
				{
					max = i;
				}
				else if(rand1[0] == 'a' || rand1[0] == 'A')
				{
					corrt = i;
				}
		
				i++;
				run = fscanf(file, "%s %s %s ", rand1, rand2, input[i]);	
       	
				}

				if(dictionary == -1)
				{
					printf("dictionary is missing from .spellconf\n");
				}
				else if (max == -1)
				{
					printf("maxdifference is missing from .spellconf \n");
				}
				else if (corrt == -1)
				{
					printf("autocorrect is missing from .spellconf\n");
				}

				conf ->dictFile = (char*)malloc((size +1)*sizeof(char));
				conf ->autoCorr = (char*)malloc((size +1)*sizeof(char));

				strncpy (conf ->dictFile, input[dictionary], size);
				conf->dictFile[size] = '\0';
				strncpy (conf ->autoCorr, input[corrt], size);
				conf->autoCorr[size] = '\0';
				conf ->maxDiff = atoi(input[max]);	
		}
		
		if(fclose(file) !=0)
		{
			perror("ERROR: unable to close file\n");
		}
	}
	return error;
}

void upLoadFile( char **array, char *outfile, int textLength)
{
	FILE *file;
	int i;

	file = fopen (outfile, "w");
		
	if(file == NULL)
	{
		perror("ERROR: unable to open file\n");
	}
	else
	{
		for(i=0; i<textLength; i++)
		{
			fputs(array[i], file);
		}
	}

	if(fclose(file) !=0)
	{
		perror("ERROR: unable to close file\n");
	}
}






		
