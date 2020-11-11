#include "Util.h"

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
    return pkdex[rand()%totalPokemon];
}
