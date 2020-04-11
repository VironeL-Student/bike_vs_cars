#ifndef _GREENPLANETLEVEL_H_
#define _GREENPLANETLEVEL_H_
#include "biker.h"

// Structure qui contient la position du rectangle par rapport au nombre de points greenplanet restants

struct Greenplanet
{
    int x;
    int y;
};
typedef struct Greenplanet Greenplanet;
Greenplanet greenplanet;


// Fonction qui affiche le titre GREENPLANET
// PRE : gameoption est une structure contenant l'écran du jeu actuel
// POST : affiche le titre GREENPLANET

void showGreenplanetTitle(GameOption *gameoption);


// Fonction qui affiche le niveau greenplanet
// PRE : biker est une structure contenant le niveau de vie du cycliste, greenplanet est une structure qui contient les points greenplanet, gameoption est une structure contenant l'écran du jeu actuel
// POST : affiche 1 rectangle par point greenplanet

void showGreenplanet(Biker *biker, Greenplanet *greenplanet, GameOption *gameoption);

#endif