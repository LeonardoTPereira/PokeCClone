#include "PokeType.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const float typeChart[TOTALTYPES][TOTALTYPES] = {
         //NRM FGHT FLY PSON GRND ROCK BUG GHST STL  FIRE WTR GRS ELEC PSY ICE DRA DARK FAIRY
/*NRM*/   {1,  1,   1,  1,   1,   0.5, 1,  0,   0.5, 1,   1,  1,  1,   1,  1,  1,  1,   1  },
/*FGHT*/  {2,  1,   0.5,0.5, 1,   2,   1,  0,   2,   1,   1,  1,  1,   0.5,2,  1,  2,   0.5},
/*FLY*/   {1,  2,   1,  1,   1,   0.5, 1,  1,   0.5, 1,   1,  2,  0.5, 1,  1,  1,  1,   1  },
/*PSON*/  {1,  1,   1,  0.5, 0.5, 0.5, 1,  0.5, 0,   1,   1,  2,  1,   1,  1,  1,  1,   2  },
/*GRND*/  {1,  1,   0,  2,   1,   2,   1,  1,   2,   2,   1,  0.5,2,   1,  1,  1,  1,   1  },
/*ROCK*/  {1,  0.5, 2,  1,   0.5, 1,   1,  1,   0.5, 2,   1,  1,  1,   1,  2,  1,  1,   1  },
/*BUG*/   {1,  0.5, 0.5,0.5, 1,   1,   1,  0.5, 0.5, 0.5, 1,  2,  1,   2,  1,  1,  2,   0.5},
/*GHST*/  {0,  1,   1,  1,   1,   1,   1,  2,   1,   1,   1,  1,  1,   2,  1,  1,  0.5, 1  },
/*STL*/   {1,  1,   1,  1,   1,   2,   1,  1,   0.5, 0.5, 0.5,1,  0.5, 1,  2,  1,  1,   2  },
/*FIRE*/  {1,  1,   1,  1,   1,   0.5, 1,  1,   2,   0.5, 0.5,2,  1,   1,  2,  0.5,1,   1  },
/*WTR*/   {1,  1,   1,  1,   2,   2,   1,  1,   1,   2,   0.5,0.5,1,   1,  1,  0.5,1,   1  },
/*GRS*/   {1,  1,   0.5,0.5, 2,   2,   0.5,1,   0.5, 0.5, 2,  0.5,1,   1,  1,  0.5,1,   1  },
/*ELEC*/  {1,  1,   2,  1,   0,   1,   1,  1,   1,   1,   2,  0.5,0.5, 1,  1,  0.5,1,   1  },
/*PSY*/   {1,  2,   1,  2,   1,   1,   1,  1,   0.5, 1,   1,  1,  1,   0.5,1,  1,  0,   1  },
/*ICE*/   {1,  1,   2,  1,   2,   1,   1,  1,   0.5, 0.5, 0.5,2,  1,   1,  0.5,2,  1,   1  },
/*DRA*/   {1,  1,   1,  1,   1,   1,   1,  1,   0.5, 1,   1,  1,  1,   1,  1,  2,  1,   0  },
/*DARK*/  {1,  0.5, 1,  1,   1,   1,   1,  2,   1,   1,   1,  1,  1,   2,  1,  1,  0.5, 0.5},
/*FAIRY*/ {1,  2,   1,  0.5, 1,   1,   1,  1,   0.5, 0.5, 1,  1,  1,   1,  1,  2,  2,   1  }
};

const char typeStrings[TOTALTYPES][10] = {
    {"normal"}, {"fighting"}, {"flying"}, {"poison"}, {"ground"}, {"rock"}, {"bug"},
    {"ghost"}, {"steel"}, {"fire"}, {"water"}, {"grass"}, {"electric"}, {"psychic"},
    {"ice"}, {"dragon"}, {"dark"}, {"fairy"}
};

float checkAdvantage(type_t atkType, type_t defType)
{
    if((int)defType == -1)
        return 1;
    return typeChart[atkType][defType];
}
float calculateAdvantage(type_t atkType, type_t mainDefType, type_t subDefType)
{
    return (checkAdvantage(atkType, mainDefType)*checkAdvantage(atkType, subDefType));
}

//TODO
static char* typeToStringAux(type_t type)
{
    if((int)type == -1)
        return NULL;
    else if(((int)type < -1) || ((int)type > TOTALTYPES))
    {
        fprintf(stderr, "\nNON-EXISTING TYPE\n");
        exit(1);
    }
    else
    {
        char* resString;
        resString = (char*) malloc (sizeof(char)*(strlen(typeStrings[type])+1));
        return strcpy(resString, typeStrings[type]);
    }

}

char* typeToString(type_t mainType, type_t subType)
{
    char *typeString, *auxString;
    typeString = (char*) calloc(sizeof(char),20);
    auxString = typeToStringAux(mainType);
    strcat(typeString, auxString);
    auxString = typeToStringAux(subType);
    if(auxString != NULL)
    {
        strcat(typeString, "\\");
        strcat(typeString, typeToStringAux(subType));
    }
    return typeString;
}

type_t stringToType(char* typeString)
{
    if(0 == strcmp(typeString, "nan"))
        return -1;
    else if(0 == strcmp(typeString, typeStrings[NORMAL]))
        return NORMAL;
    else if(0 == strcmp(typeString, typeStrings[FIGHTING]))
        return FIGHTING;
    else if(0 == strcmp(typeString, typeStrings[FLYING]))
        return FLYING;
    else if(0 == strcmp(typeString, typeStrings[POISON]))
        return POISON;
    else if(0 == strcmp(typeString, typeStrings[GROUND]))
        return GROUND;
    else if(0 == strcmp(typeString, typeStrings[ROCK]))
        return ROCK;
    else if(0 == strcmp(typeString, typeStrings[BUG]))
        return BUG;
    else if(0 == strcmp(typeString, typeStrings[GHOST]))
        return GHOST;
    else if(0 == strcmp(typeString, typeStrings[STEEL]))
        return STEEL;
    else if(0 == strcmp(typeString, typeStrings[FIRE]))
        return FIRE;
    else if(0 == strcmp(typeString, typeStrings[WATER]))
        return WATER;
    else if(0 == strcmp(typeString, typeStrings[GRASS]))
        return GRASS;
    else if(0 == strcmp(typeString, typeStrings[ELECTRIC]))
        return ELECTRIC;
    else if(0 == strcmp(typeString, typeStrings[PSYCHIC]))
        return PSYCHIC;
    else if(0 == strcmp(typeString, typeStrings[ICE]))
        return ICE;
    else if(0 == strcmp(typeString, typeStrings[DRAGON]))
        return DRAGON;
    else if(0 == strcmp(typeString, typeStrings[DARK]))
        return DARK;
    else if(0 == strcmp(typeString, typeStrings[FAIRY]))
        return FAIRY;
    else
    {
        printf("\nTipo Inexistente!\n");
        exit(1);
    }
    return -2;
}
