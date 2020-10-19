#ifndef _UTIL_H
#define _UTIL_H

#include "Pokemon.h"
#ifdef __linux__
    #define DIRECTORY_NAME "data/"
    #define SPRITE_DIRECTORY "sprites/"
#endif // _WIN32

#ifdef _WIN32
    #define DIRECTORY_NAME "data\\"
    #define SPRITE_DIRECTORY "sprites\\"
#endif

#define DEXFILE DIRECTORY_NAME"pokemon.csv"
#define MOVEDEXFILE DIRECTORY_NAME"moves.csv"
#define SAVEFILE DIRECTORY_NAME"poketeam.dat"
#define ASCIISPRITEDIR DIRECTORY_NAME SPRITE_DIRECTORY
#define ASCIIEXTENSION ".asc"
#define MAXTEAMSIZE 6


//typedef struct _coord_t coord_t;
typedef struct _coord_t
{
    unsigned int x;
    unsigned int y;
}coord_t;

void addStringTerminator(char* myString);
pokemon_t* randPkmn(pokemon_t** pkdex, int totalPokemon);


#endif //_UTIL_H
