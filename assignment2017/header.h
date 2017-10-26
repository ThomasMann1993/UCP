
#ifndef HEADER_H
#define HEADER_H

#include "linkedList.h"
#include "chech.h"

typedef struct Conf
{
	char* dictFile;
	int maxDiff;
	char* autoCorr;
}Conf;

int spellConf (Conf*);
void upLoadFile( char**, char*, int);
ActionFunc* decision(Conf*);
#endif

