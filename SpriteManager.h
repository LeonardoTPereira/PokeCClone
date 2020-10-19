#ifndef _SPRITEMANAGER_H
#define _SPRITEMANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "Util.h"

int getNDigits(int number);
int getFileSize(char* fileName);
char* getFilePathFromDexNumber(int dexNumber);
char* loadASCII(int dexNumber);
void printBoxLine(pokemon_t **pokeBoxLine, int lineSize);


#endif // _SPRITEMANAGER_H
