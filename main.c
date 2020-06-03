#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "util.h"
#include "poketype.h"
#include "pokemon.h"
#include "pokebox.h"
#include "pkdex.h"

int main()
{
    pokemon_t** team = NULL;
    pokemon_t** pkdex = NULL;
    srand(time(NULL));
    //box_t* pcBox = NULL;
    int actualTeamSize = 6;
    int totalPkmn = 0;

    printf("Loading Pokedex, please wait\n");
    pkdex = readPkDex(&totalPkmn);
    printf("Pokedex Loaded!\n");
    team = (pokemon_t**) malloc(sizeof(pokemon_t*)*actualTeamSize);
    for(int i = 0; i < actualTeamSize; ++i)
    {
        team[i] = randPkmn(pkdex, totalPkmn);
        printPokemon(team[i]);
    }
    //team[0] = createPokemon(92, "Ghastly", 30, 35, 30, 100, 35, 80, GHOST, POISON);
    //printPokemon(team[0]);
}
