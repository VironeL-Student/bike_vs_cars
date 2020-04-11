#ifndef _SHOWENNEMY1_H_
#define _SHOWENNEMY1_H_
#include "biker.h"
#include "ennemy.h"

// Fonction qui gère la collision entre le tir du cycliste et ennemi1
// PRE : ennemy1, shootennemy1, shootbiker, biker sont des structures
// POST : si collision, détruit ennemi 1, réinitialise ennemy 1 et augmente le score du cycliste

void collisionShootBikerEnnemy1(Ennemy *ennemy1, ShootEnnemy *shootennemy1, ShootBiker *temp, Biker *biker);


// Fonction qui gère la collision entre le tir du cycliste et ennemi2
// PRE : ennemy2, shootennemy2, shootbiker, biker sont des structures
// POST : si collision, détruit ennemi 2, réinitialise ennemy 2 et augmente le score du cycliste

void collisionShootBikerEnnemy2(Ennemy *ennemy1, ShootEnnemy *shootennemy2, ShootBiker *temp, Biker *biker);


// Fonction qui gère la collision entre le tir ennemi1 et le cycliste
// PRE : biker, shootennemy1, ennemy1 sont des structures
// POST : si collision, enlève un point de vie au cycliste

void collisionShootEnnemy1Biker(Biker *biker, ShootEnnemy *shootennemy1, Ennemy *ennemy1);


// Fonction qui gère la collision entre le tir ennemi2 et le cycliste
// PRE : biker, shootennemy2, ennemy2 sont des structures
// POST : si collision, enlève un point de vie au cycliste

void collisionShootEnnemy2Biker(Biker *biker, ShootEnnemy *shootennemy2, Ennemy *ennemy2);


// Fonction qui gère la collision entre ennemi 1 (la voiture, pas le tir) et le cycliste
// PRE : biker est une structure, ennemy1 est une structure
// POST : si collision, enlève un point de vie au cycliste

void collisionEnnemy1Biker(Biker *biker,Ennemy *ennemy1);


// Fonction qui gère la collision entre ennemi 2 (la voiture, pas le tir) et le cycliste
// PRE : biker est une structure, ennemy1 est une structure
// POST : si collision, enlève un point de vie au cycliste

void collisionEnnemy2Biker(Biker *biker,Ennemy *ennemy2);


#endif