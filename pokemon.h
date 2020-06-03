#ifndef _POKEMON_H
#define _POKEMON_H

#include "poketype.h"

typedef struct _pokemon_t{
    int dexNumber;
    char species[30];
    int hp;
    int atk;
    int def;
    int spatk;
    int spdef;
    int speed;
    type_t mainType;
    type_t subType;
} pokemon_t;

pokemon_t* createPokemon(int dexNumber, char *name, int hp, int atk, int def, int spatk, int spdef, int speed, type_t mainType, type_t subType);
void printPokemon(pokemon_t *pokemon);

#endif //_POKEMON_H
