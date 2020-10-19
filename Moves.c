#include "Moves.h"

#include <stdlib.h>
#include <string.h>


void useMove(move_t* usedMove, pokemon_t* userPoke, pokemon_t* enemyPoke)
{
    if(usedMove->actualPP > 0) //Not accounting for pressure
    {
        float damage;
        pokemon_t* target;
        target = checkTarget(usedMove, userPoke, enemyPoke);
        if(checkAccuracy(usedMove->accuracy, userPoke->stageAcc, target->stageEva) > 0)
        {
            if(usedMove->category == PHYSICAL)
            {
                damage = calcDamage(userPoke->atk, userPoke->stageAtk, target->def, target->stageDef,
                            usedMove->power, usedMove->type, target->mainType, target->subType, userPoke->status);
                target->hp-=damage;
            }
            else if(usedMove->category == SPECIAL)
            {
                damage = calcDamage(userPoke->spatk, userPoke->stageSpAtk, target->spdef, target->stageSpDef,
                            usedMove->power, usedMove->type, target->mainType, target->subType, userPoke->status);
                target->hp-=damage;
            }
            //TODO STATUS MOVES
        }
        else
            printf("\nOH THE ATTACK MISSED\n");


    }

}

pokemon_t* checkTarget(move_t* usedMove, pokemon_t* userPoke, pokemon_t* enemyPoke)
{
    pokemon_t* target;
    if(usedMove->target == ENEMY)
        target = enemyPoke;
    else if (usedMove->target == SELF)
        target = userPoke;
    else
        fprintf(stderr, "\nNO VALID TARGET\n");
    return target;
}

int checkAccuracy(int moveAcc, int userAcc, int targetEva)
{
    if(rand()%100 < moveAcc) //TODO use ACC and EVASION
        return 1;
    return 0;
}

//TODO consider critical
float calcDamage(int atk, int stageAtk, int def, int stageDef, int power,
                 type_t moveType, type_t defenderType1, type_t defenderType2, statusEffect_t userStatus)
{
    int totalDamage = 0;
    float modifier;
    float finalAtk, finalDef;
    modifier = calcDamageModifier(moveType, defenderType1, defenderType2, userStatus);
    finalAtk = calcStageMult(atk, stageAtk);
    finalDef = calcStageMult(def, stageDef);

    //We'll consider level 1 for now
    totalDamage = ((((((2*1)/5.0) + 2) * power * finalAtk/finalDef)/50) + 2)*modifier;
    return totalDamage;


}

//TODO STAB
float calcDamageModifier(type_t moveType, type_t defenderType1, type_t defenderType2, statusEffect_t userStatus)
{
    float modifier = 1.0;

    if(userStatus == BURN) //TODO CHECK ABILITIES LIKE GUTS
        modifier *= 0.5;
    modifier *= calculateAdvantage(moveType, defenderType1, defenderType2);

    return modifier;
}

float calcStageMult(int stats, int stage)
{
    if (stage == 0)
        return 1.0;
    else if(stage > 0)
        return (2+stage)/2.0;
    else
        return 2/(stage*(-1)+2.0);
}

void applyBurn(pokemon_t* target, int burnChance)
{

    if(target->mainType != FIRE && target->subType != FIRE)
    {
        if(target->status != PARALYZE && target->status != POISONED && target->status != SLEEP
                && target->status != FROZEN && target->status != TOXIC)
        {
            if(burnChance >= rand()%100)
            {
                target->status = BURN;
                printf("\nTHE TARGET IS NOW BURNED!\n");
            }
        }
    }
}


move_t* createMove(char* name, type_t type, category_t category, int maxPP, int power, int accuracy, void (*effectFun)(pokemon_t*, int), target_t target)
{
    move_t* move;
    move = (move_t*) malloc(sizeof(move_t));

    strcpy(move->name,name);
    move->type = type;
    move->category = category;
    move->maxPP = maxPP;
    move->actualPP = maxPP;
    move->power = power;
    move->accuracy = accuracy;
    move->effectFunction = effectFun;
    move->target = target;

    return move;
}

/*move_t** readMoveDex(int* nMoves)
{

    move_t** moveDex = NULL;
    FILE *fp;

    fp = fopen (MOVEDEXFILE, "r");

    if(fp == NULL)
    {
        fprintf(stderr, "\MOVEDEX FILE NOT FOUND!\n");
        exit(1);
    }
    else
    {
        *nMoves = 0;
        while(!feof(fp))
        {
            char auxType[15] = {'\0'};
            char auxCategory[15] = {'\0'};
            move_t auxPkmn;

            *nMoves = (*nMoves) + 1;
            moveDex = (move_t**) realloc(moveDex, sizeof(move_t*)*(*nMoves));

            if(EOF != fscanf (fp, "%d,%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d", &(auxPkmn.dexNumber), auxPkmn.species, auxMainType, auxSubType, &(auxPkmn.hp), &(auxPkmn.atk), &(auxPkmn.def), &(auxPkmn.spatk), &(auxPkmn.spdef), &(auxPkmn.speed)))
            {
                //addStringTerminator(auxPkmn.species);
                auxPkmn.mainType = stringToType(auxMainType);
                auxPkmn.subType = stringToType(auxSubType);
                //printPokemon(&auxPkmn);
                moveDex[*nMoves - 1] = (move_t*) malloc(sizeof(move_t));
                moveDex[*nMoves - 1] = createPokemon(auxPkmn.dexNumber, auxPkmn.species, auxPkmn.hp, auxPkmn.atk, auxPkmn.def,
                                    auxPkmn.spatk, auxPkmn.spdef, auxPkmn.speed, auxPkmn.mainType, auxPkmn.subType);
            }
            else
            {
                *nMoves = (*nMoves) - 1;
                moveDex = (move_t**) realloc(moveDex, sizeof(move_t*)*(*nMoves));
            }

            if((*nMoves)%200 == 0)
                printf("Still loading... Please Wait\n");
        }

        fclose(fp);
    }
    return pkdex;

}*/
