#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Pokemon.h"


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

    resetStatus(pokemon);

    return pokemon;
}

void resetStatus(pokemon_t* pokemon)
{
    pokemon->stageAtk = 0;
    pokemon->stageDef = 0;
    pokemon->stageSpAtk = 0;
    pokemon->stageSpDef = 0;
    pokemon->stageSpeed = 0;
    pokemon->stageAcc = 0;
    pokemon->stageEva = 0;
    pokemon->status = NONE;
    pokemon->nTurnsStatus = 0;
}

void printPokemon(pokemon_t *pokemon)
{
    printf("\nDex#:\t% -5dName: %-25sType: %-20s\n", pokemon->dexNumber, pokemon->species,
           typeToString(pokemon->mainType, pokemon->subType));
    printf("HP:\t% -5dAttack:\t% -5dDefense:\t% -5d\n", pokemon->hp, pokemon->atk, pokemon->def);
    printf("Speed:\t% -5dSpcAtk:\t% -5dSpcDef:\t% -5d\n", pokemon->speed, pokemon->spatk, pokemon->spdef);
}

//Saves pokemon to an already openned savefile
//This is for reading a whole team/pcbox with this function
//Someone needs to open and close the file, not this method!
void savePokemon(pokemon_t *pokemon, FILE* saveFile)
{
    int error;

    unsigned char* crypto = makeCryptoMon(pokemon);

    // write struct to end of file
    error = fwrite (crypto, sizeof(pokemon_t), 1, saveFile);

    if(error == 0)
        fprintf(stderr, "\nERROR SAVING POKEMON!\n");

    free(crypto);

}

//Loads pokemon from an already openned savefile
//This is for reading a whole team/pcbox with this function
//Someone needs to open and close the file, not this method!
pokemon_t* loadPokemon(FILE* saveFile)
{
    unsigned char* crypto;
    pokemon_t *pokemon;

    pokemon = (pokemon_t*) malloc (sizeof(pokemon_t));

    //Read a single Pokemon
    if(0 == fread(pokemon, sizeof(pokemon_t), 1, saveFile))
        pokemon = NULL;

    crypto = makeCryptoMon(pokemon);

    free(pokemon);

    return (pokemon_t*) crypto;
}
