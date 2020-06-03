#include "poketype.h"
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
    {"NORMAL"}, {"FIGHTING"}, {"FLYING"}, {"POISON"}, {"GROUND"}, {"ROCK"}, {"BUG"},
    {"GHOST"}, {"STEEL"}, {"FIRE"}, {"WATER"}, {"GRASS"}, {"ELECTRIC"}, {"PSYCHIC"},
    {"ICE"}, {"DRAGON"}, {"DARK"}, {"FAIRY"}
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
        printf("\nTIPO INEXISTENTE\n");
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
    else if(0 == strcmp(typeString, "Normal"))
        return NORMAL;
    else if(0 == strcmp(typeString, "Fighting"))
        return FIGHTING;
    else if(0 == strcmp(typeString, "Flying"))
        return FLYING;
    else if(0 == strcmp(typeString, "Poison"))
        return POISON;
    else if(0 == strcmp(typeString, "Ground"))
        return GROUND;
    else if(0 == strcmp(typeString, "Rock"))
        return ROCK;
    else if(0 == strcmp(typeString, "Bug"))
        return BUG;
    else if(0 == strcmp(typeString, "Ghost"))
        return GHOST;
    else if(0 == strcmp(typeString, "Steel"))
        return STEEL;
    else if(0 == strcmp(typeString, "Fire"))
        return FIRE;
    else if(0 == strcmp(typeString, "Water"))
        return WATER;
    else if(0 == strcmp(typeString, "Grass"))
        return GRASS;
    else if(0 == strcmp(typeString, "Electric"))
        return ELECTRIC;
    else if(0 == strcmp(typeString, "Psychic"))
        return PSYCHIC;
    else if(0 == strcmp(typeString, "Ice"))
        return ICE;
    else if(0 == strcmp(typeString, "Dragon"))
        return DRAGON;
    else if(0 == strcmp(typeString, "Dark"))
        return DARK;
    else if(0 == strcmp(typeString, "Fairy"))
        return FAIRY;
    else
    {
        printf("\nTipo Inexistente!\n");
        exit(1);
    }
    return -2;
}
