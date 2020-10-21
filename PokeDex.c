#include <stdio.h>
#include <stdlib.h>

#include "PokeDex.h"
#include "Pokemon.h"
#include "Util.h"

pokemon_t** readPkDex(int *nEntries) {

    pokemon_t** pkdex = NULL;
    FILE *fp;

    fp = fopen (DEXFILE, "r");

    if(fp == NULL)
    {
        fprintf(stderr, "\nFile: %s\n", DEXFILE);
        fprintf(stderr, "\nPOKEDEX FILE NOT FOUND!\n");
        exit(1);
    }
    else
    {
        *nEntries = 0;
        while(!feof(fp))
        {
            char auxMainType[15] = {'\0'};
            char auxSubType[15] = {'\0'};
            pokemon_t auxPkmn;

            *nEntries = (*nEntries) + 1;
            pkdex = (pokemon_t**) realloc(pkdex, sizeof(pokemon_t*)*(*nEntries));

            if(EOF != fscanf (fp, "%d,%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d", &(auxPkmn.dexNumber), auxPkmn.species, auxMainType, auxSubType, &(auxPkmn.hp), &(auxPkmn.atk), &(auxPkmn.def), &(auxPkmn.spatk), &(auxPkmn.spdef), &(auxPkmn.speed)))
            {
                //addStringTerminator(auxPkmn.species);
                auxPkmn.mainType = stringToType(auxMainType);
                auxPkmn.subType = stringToType(auxSubType);
                //printPokemon(&auxPkmn);
                pkdex[*nEntries - 1] = createPokemon(auxPkmn.dexNumber, auxPkmn.species, auxPkmn.hp, auxPkmn.atk, auxPkmn.def,
                                    auxPkmn.spatk, auxPkmn.spdef, auxPkmn.speed, auxPkmn.mainType, auxPkmn.subType);
            }
            else
            {
                *nEntries = (*nEntries) - 1;
                pkdex = (pokemon_t**) realloc(pkdex, sizeof(pokemon_t*)*(*nEntries));
            }

            #ifdef DEBUG
                if((*nEntries)%200 == 0)
                    printf("Still loading... Please Wait\n");
            #endif
        }

        fclose(fp);
    }
    return pkdex;
}
