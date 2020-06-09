#ifndef _SAVEMANAGER_H
#define _SAVEMANAGER_H

#include "pokemon.h"

void saveTeam(pokemon_t** pokeTeam, char*saveFile);
pokemon_t** loadTeam(char* saveFile);



#endif //_SAVEMANAGER_H
