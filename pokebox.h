#ifndef _POKEBOX_H
#define _POKEBOX_H

#include "Pokemon.h"
#include "Util.h"

#define BOXLINES 3
#define BOXCOLLS 3
#define BOXSIZE BOXLINES*BOXCOLLS

typedef enum
{
    SUCCESS=0,
    NOONETHERE=1,
    OCCUPPIED=2
} boxError_t;


typedef pokemon_t* pokebox_t[BOXSIZE];

int movePkmn(coord_t curPos, coord_t newPos);
int addPkmn(coord_t pos);
int removePkmn(coord_t pos);
int checkIfOccupied(coord_t pos);
void printBox(pokebox_t box);

#endif //_POKEMON_H
