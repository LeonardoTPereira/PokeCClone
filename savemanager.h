#ifndef _SAVEMANAGER_H
#define _SAVEMANAGER_H

#include "Pokemon.h"

void saveTeam(pokemon_t** pokeTeam, char*saveFile);
pokemon_t** loadTeam(char* saveFile);
unsigned char* makeCryptoMon(pokemon_t* pokemon);


#endif //_SAVEMANAGER_H
