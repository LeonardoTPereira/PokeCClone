#ifndef _POKEBOX_H
#define _POKEBOX_H

#include "pokemon.h"
#include "util.h"

#define MAXLINES 5
#define MAXCOLLS 6

typedef enum
{
    SUCCESS=0,
    NOONETHERE=1,
    OCCUPPIED=2
} boxError_t;


typedef pokemon_t* box_t[MAXLINES][MAXCOLLS];

int movePkmn(coord_t curPos, coord_t newPos);
int addPkmn(coord_t pos);
int removePkmn(coord_t pos);
int checkIfOccupied(coord_t pos);


#endif //_POKEMON_H
