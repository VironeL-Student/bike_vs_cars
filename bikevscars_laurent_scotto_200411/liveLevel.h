#ifndef _LIVELEVEL_H_
#define _LIVELEVEL_H_
#include "biker.h"

// Structure qui contient la position du rectangle par rapport au nombre de vie restante

struct Live
{
    int x;
    int y;
};
typedef struct Live Live;
Live live;


// Fonction qui affiche le titre LIVE
// PRE : gameoption est une structure qui contient le numéro de l'écran de jeu actuel
// POST : affiche le titre LIVE

void showLiveTitle(GameOption *gameoption);


// Fonction qui affiche le niveau de vie du cycliste
// PRE : biker est une structure contenant le niveau de vie du cycliste, live est une structure contenant les positions x, y du rectangle de vie, gameoption est une structure qui contient le numéro de l'écran de jeu actuel
// POST : affiche 1 rectangle par vie

void showLive(Biker *biker, Live *live, GameOption *gameoption);

#endif