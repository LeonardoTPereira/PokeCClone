#ifndef _MOVES_H
#define _MOVES_H

#include <stdio.h>

typedef enum _statusEffect_t
{
    NONE = 0,
    POISONED = 1,
    BURN = 2,
    PARALYZE = 3,
    CONFUSION = 4,
    TOXIC = 5,
    FROZEN = 6,
    SLEEP = 7
} statusEffect_t;

typedef enum _category_t
{
    PHYSICAL = 0,
    SPECIAL = 1,
    STATUS = 2
} category_t;

typedef enum _target_t
{
    SELF = 0,
    ENEMY = 1
} target_t;

typedef struct _move_t move_t;

#include "PokeType.h"
#include "Pokemon.h"
#include "Util.h"

struct _move_t
{
    int id;
    char name[30];
    type_t type;
    category_t category;
    int maxPP;
    int actualPP;
    int power;
    int accuracy;
    target_t target;
    void (*effectFunction)(pokemon_t*, int);
};


void useMove(move_t* usedMove, pokemon_t* userPoke, pokemon_t* enemyPoke);
pokemon_t* checkTarget(move_t* usedMove, pokemon_t* userPoke, pokemon_t* enemyPoke);
int checkAccuracy(int moveAcc, int userAcc, int targetEva);
float calcDamage(int atk, int stageAtk, int def, int stageDef, int power,
                 type_t moveType, type_t defenderType1, type_t defenderType2, statusEffect_t userStatus);
float calcDamageModifier(type_t moveType, type_t defenderType1, type_t defenderType2, statusEffect_t userStatus);
float calcStageMult(int stats, int stage);
void applyBurn(pokemon_t* target, int burnChance);
move_t* createMove(char* name, type_t type, category_t category, int maxPP, int power, int accuracy, void (*effectFun)(), target_t target);
//move_t** readMoveDex(int* nMoves);


#endif //_MOVES_H
