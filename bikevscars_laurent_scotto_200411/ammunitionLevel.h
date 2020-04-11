#ifndef _AMMUNITIONLEVEL_H_
#define _AMMUNITIONTLEVEL_H_
#include "biker.h"

// Structure qui contient la position du rectangle par rapport au nombre de points greenplanet restants

struct Ammunition
{
    int x;
    int y;
};
typedef struct Ammunition Ammunition;
Ammunition ammunition;


// Fonction qui affiche le titre AMMUNITION
// PRE : gameoption est une structure qui contient le numéro de l'écran actif
// POST : affiche le titre AMMUNITION

void showAmmunitionTitle(GameOption *gameoption);


// Fonction qui affiche le niveau des munitions 1 et 2
// PRE : biker est une structure contenant le niveau de vie du cycliste, ammunition est une structure contenant les coordonnées de la pastille, gameoption est une structure qui contient le numéro de l'écran actif
// POST : affiche 1 ovale par munition

void showAmmunition(Biker *biker, Ammunition *ammunition, GameOption *gameoption);

#endif