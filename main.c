/*
############################################################
#                                                          #
#             Made by: Leonardo Tórtoro Pereira            #
#                   leonardop@usp.br                       #
#                                                          #
#      “you have something called "determination."         #
#       so as long as you hold on...                       #
#       so as long as you do what's in your heart...       #
#       i believe you can do the right thing.”             #
#                                                          #
#                   'll0MMMMMMMMMMMMMOll'                  #
#                 .OMMMMMMMMMMMMMMMMMMM0l'                 #
#                'OMMMMMMMMMMMMMMMMMMMMMM0'                #
#               '0MMMMMMMMMMMMMMMMMMMMMMMM0'               #
#              '0MMMMMMMMMMMMMMMMMMMMMMMMMM0'              #
#              lMMMMMMMMMMMMMMMMMMMMMMMMMMMMl              #
#              0MMMMMMMMMMMMMMMMMMMMMMMMMMMM0              #
#              MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM              #
#              MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM              #
#              MMMM0lllllOMMMMMMMM0lllll0MMMM              #
#              MM0l'     .OMMMMMM0'     'l0MM              #
#              M0'        lMMMMMMl        '0M              #
#              Ml    'l'  lMMMMMMl  'l'    lM              #
#              Ml    lMl  lMMMMMMl  lMl    lM              #
#              00'   'l' '0M0ll0M0' 'l'   '00              #
#              lM0l'     lMMl  lMMl     'l0Ml              #
#              '0MM0lll''0M0'  '0M0''lll0MM0'              #
#               lMMMM0ll0MMl    lMM0ll0MMMMl               #
#              '0MM000l0MMMl    lMMM0lOO0MMO.              #
#              lMM0'lMMMMMMOllll0MMMMMMl'0MMl              #
#              lM0' 'l0MMMMMMMMMMMMMM0l' '0Ml              #
#              lM0l' 'llllllllllllllll' 'l0Ml              #
#              lMMMl ll              ll lMMMl              #
#              '0MM0'll'l''l''lll''l'll'0MM0'              #
#               lMMM0l'lMllMllMMMllMl'l0MMMl               #
#               '0MMMO''0llMllMMMll0''0MMM0'               #
#                '0MMM0ll''l''lll''ll0MMM0'                #
#                 'l0MMM0llllllllll0MMMOl'                 #
#                   'l0MMMMMMMMMMMMMM0l'                   #
#                     lMMMMMMMMMMMMMMl                     #
#                                                          #
############################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Util.h"
#include "Poketype.h"
#include "Pokemon.h"
#include "PokeBox.h"
#include "PokeDex.h"
#include "SaveManager.h"
#include "Moves.h"

int main()
{
    //pokemon_t** team = NULL;
    pokemon_t** pkdex = NULL;
    #ifdef DEBUG
        pokebox_t box;
    #endif
        srand(time(NULL));
    //box_t* pcBox = NULL;
    //int actualTeamSize = 6;
    int totalPkmn = 0;

    #ifdef DEBUG
        printf("Loading Pokedex, please wait\n");
    #endif
    pkdex = readPkDex(&totalPkmn);
    #ifdef DEBUG
        printf("Pokedex Loaded!\n");
    #endif
    /*team = (pokemon_t**) malloc(sizeof(pokemon_t*)*actualTeamSize);
    for(int i = 0; i < actualTeamSize; ++i)
    {
        team[i] = randPkmn(pkdex, totalPkmn);
        printPokemon(team[i]);
    }*/

    #ifdef DEBUG
        for (int i = 0; i < BOXSIZE; i++) {
            box[i] = randPkmn(pkdex, totalPkmn);
        }

        box[3] = NULL;

        printBox(box);
    #endif

    for(int i = 0; i < totalPkmn; ++i)
    {
        free(pkdex[i]);
    }
    free(pkdex);


    /*saveTeam(team, "data/player2.dat");

    team = loadTeam("data/player2.dat");
    for(int i = 0; i < actualTeamSize; ++i)
    {
        if(team[i] != NULL)
            printPokemon(team[i]);
        else
            printf("NULL POKEMON\n");
    }*/

    //team[0]->moves[0] = createMove("Ember", FIRE, SPECIAL, 25, 40, 100, applyBurn, ENEMY);
    //team[0]->moves[0]->effectFunction(team[1], 100);
}
