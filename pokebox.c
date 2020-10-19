#include "PokeBox.h"

int movePkmn(coord_t curPos, coord_t newPos)
{
    return NOONETHERE;
}
int addPkmn(coord_t pos)
{
    return NOONETHERE;
}
int removePkmn(coord_t pos)
{
    return NOONETHERE;
}
int checkIfOccupied(coord_t pos)
{
    return NOONETHERE;
}

void printBox(pokebox_t box)
{
    pokemon_t **boxLinePokemon;
    boxLinePokemon = (pokemon_t**) malloc(sizeof(pokemon_t*)*BOXCOLLS);

    for (int i = 0; i < BOXLINES; i++)
    {
        for(int j = 0; j < BOXCOLLS; ++j)
            boxLinePokemon[j] = box[BOXCOLLS*i+j];
        printBoxLine(boxLinePokemon, BOXCOLLS);
        printf("\n");
    }

}
