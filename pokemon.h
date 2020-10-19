#ifndef _POKEMON_H
#define _POKEMON_H

#include <stdio.h>

#define MAXMOVES 4

typedef struct _pokemon_t pokemon_t;

#include "PokeType.h"
#include "Moves.h"
#include "SaveManager.h"
#include "SpriteManager.h"

struct _pokemon_t{
    int dexNumber;
    char species[30];
    int hp;
    int atk;
    int stageAtk;
    int def;
    int stageDef;
    int spatk;
    int stageSpAtk;
    int spdef;
    int stageSpDef;
    int speed;
    int stageSpeed;
    int stageAcc;
    int stageEva;
    type_t mainType;
    type_t subType;
    statusEffect_t status;
    int nTurnsStatus; //To count turns from toxic, frozen, sleep, etc.
    move_t* moves[4];
};


pokemon_t* createPokemon(int dexNumber, char *name, int hp, int atk, int def, int spatk, int spdef, int speed, type_t mainType, type_t subType);
void resetStatus(pokemon_t* pokemon);
void printPokemon(pokemon_t *pokemon);
pokemon_t* loadPokemon(FILE* saveFile);
void savePokemon(pokemon_t *pokemon, FILE* saveFile);

#endif //_POKEMON_H
