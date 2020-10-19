#include "SaveManager.h"
#include "Util.h"
#include "Pokemon.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void saveTeam(pokemon_t** pokeTeam, char* fileName)
{
    FILE *saveFile;

    // open file for appending
    saveFile = fopen (fileName, "a");

    if (saveFile == NULL)
    {
        fprintf(stderr, "\nERROR OPENING SAVE FILE TO SAVE!\n");
        exit (1);
    }

    for(int i = 0; i < MAXTEAMSIZE; ++i)
    {
        if(pokeTeam[i] != NULL)
        {
            savePokemon(pokeTeam[i], saveFile);
        }
    }

    // close file
    fclose (saveFile);
}

pokemon_t** loadTeam(char* fileName)
{
    pokemon_t** pokeTeam;
    int i = 0;
    pokeTeam = (pokemon_t**) malloc (sizeof(pokemon_t*)*MAXTEAMSIZE);

    FILE *saveFile;

    // open file for appending
    saveFile = fopen (fileName, "r");
    if (saveFile == NULL)
    {
        fprintf(stderr, "\nERROR OPENING SAVE FILE TO SAVE!\n");
        exit (1);
    }

    do
    {
        pokeTeam[i++] = loadPokemon(saveFile);
    } while(pokeTeam[i-1] != NULL && (i < MAXTEAMSIZE));

    for(;i < MAXTEAMSIZE;++i)
        pokeTeam[i] = NULL;


    // close file
    fclose (saveFile);

    return pokeTeam;
}

unsigned char* makeCryptoMon(pokemon_t* pokemon)
{
    int size = sizeof(pokemon_t);
    unsigned char* cryptomon;

    cryptomon = (unsigned char*) malloc(sizeof(pokemon_t));

    memcpy(cryptomon, pokemon, size);

    for(int i = 0; i < size; ++i)
        cryptomon[i] = cryptomon[i]^200;

    return cryptomon;
}
