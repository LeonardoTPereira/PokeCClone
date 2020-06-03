#ifndef _POKETYPE_H
#define _POKETYPE_H

#define TOTALTYPES 18

extern const float typeChart[TOTALTYPES][TOTALTYPES];
extern const char typeStrings[TOTALTYPES][10];

typedef enum _type_t
{
      NORMAL=0,
      FIGHTING=1,
      FLYING=2,
      POISON=3,
      GROUND=4,
      ROCK=5,
      BUG=6,
      GHOST=7,
      STEEL=8,
      FIRE=9,
      WATER=10,
      GRASS=11,
      ELECTRIC=12,
      PSYCHIC=13,
      ICE=14,
      DRAGON=15,
      DARK=16,
      FAIRY=17
} type_t;



float checkAdvantage(type_t atkType, type_t defType);
float calculateAdvantage(type_t atkType, type_t mainDefType, type_t subDefType);
//Converte tipo e subtipo em uma string propria para impressao
char* typeToString(type_t mainType, type_t subType);
type_t stringToType(char* typeString);



#endif // _POKETYPE_H
