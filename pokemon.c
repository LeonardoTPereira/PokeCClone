#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "pokemon.h"


pokemon_t* createPokemon(int dexNumber, char* name, int hp, int atk, int def, int spatk, int spdef, int speed, type_t mainType, type_t subType)
{
    pokemon_t *pokemon = (pokemon_t*) malloc(sizeof(pokemon_t));
    pokemon->dexNumber = dexNumber;
    strcpy(pokemon->species, name);
    pokemon->hp = hp;
    pokemon->atk = atk;
    pokemon->def = def;
    pokemon->spatk = spatk;
    pokemon->spdef = spdef;
    pokemon->speed = speed;
    pokemon->mainType = mainType;
    pokemon->subType = subType;
    return pokemon;
}

void printPokemon(pokemon_t *pokemon)
{
    printf("\nDex#:\t% -5dName: %-25sType: %-20s\n", pokemon->dexNumber, pokemon->species,
           typeToString(pokemon->mainType, pokemon->subType));
    printf("HP:\t% -5dAttack:\t% -5dDefense:\t% -5d\n", pokemon->hp, pokemon->atk, pokemon->def);
    printf("Speed:\t% -5dSpcAtk:\t% -5dSpcDef:\t% -5d\n", pokemon->speed, pokemon->spatk, pokemon->spdef);
}
