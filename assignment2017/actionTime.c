#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chech.h"
#include "header.h"

/* this fucntion is when autocorrect is yes, it will check to see if the suggestion word is NULL and then set the return to false
 * which is zero, other wise it will return 1 which is true, and the word will be corrected
 */
int actionYes(char *word, char *suggestion)
{
	int act;

	if(suggestion == NULL)
	{
		act = 0;
	}
	else
	{
		act = 1;
	}
/*return returns the value of act which could be 1 for true or 0 for false
 */
	return act;
}

/*this fuction is when autocorrect is no, it will first check to see if suggestion is NULL, else it will go on to ask the user
 * would they like the word swapped with ther correction
 */

int actionNo(char *word, char *suggestion)
{
	int act, run = 0;
	char answer[50];

	if(suggestion == NULL)
	{
		act = 0;
	}
	else
	{
		printf("orignal word %s, Correction word %s\n", word, suggestion);
		while(run !=1)
		{
			printf("Do you approve correction? y or n :");
			scanf("%s", answer); 
/* once the user has given an answer it will check the first character to see if its a y for yes of n for no, in either case or
 * chapital case, if no match is made it will ask the use to re-enter their answer, this will contnue untill one of the ifs 
 * statements is met
 */		
			if(answer[0] == 'y' || answer[0] == 'Y')
			{
				act = 1;
				run = 1;
			}
			else if(answer[0] == 'n' || answer[0] == 'N')
			{
				act = 0;
				run = 1;
			}
			else
			{
				printf("incorrect input, please type yes or no\n");
			}
		}
	}
	return act;
}

ActionFunc* decision(Conf *conf)
{
	ActionFunc* address;

	if(conf ->autoCorr[0] == 'y')
	{
		address = &actionYes;
	}
	else
	{
		address = &actionNo;
	}
	return address;
}
