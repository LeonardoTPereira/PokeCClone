#include "util.h"

#include <stdlib.h>

void addStringTerminator(char* myString)
{
    int idx = 0;
    while ((myString[idx] != '\0') && (myString[idx] != '\r') && (myString[idx] != '\n') )
    {
        idx++;
    }
    myString[idx] = '\0';
}

pokemon_t* randPkmn(pokemon_t** pkdex, int totalPokemon)
{
    pokemon_t auxPkmn;
    auxPkmn = *(pkdex[rand()%totalPokemon]);
    return createPokemon(auxPkmn.dexNumber, auxPkmn.species, auxPkmn.hp, auxPkmn.atk, auxPkmn.def,
                                    auxPkmn.spatk, auxPkmn.spdef, auxPkmn.speed, auxPkmn.mainType, auxPkmn.subType);
}
