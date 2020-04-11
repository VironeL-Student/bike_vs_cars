#ifndef _ENNEMY1_H_
#define _ENNEMY1_H_

#include <stdlib.h>
#include <stdbool.h>
#include "biker.h"

// Structure de ennemis

struct Ennemy
{
    int x;
    int y;
    int speed;
    bool active;
    bool collision;
};
typedef struct Ennemy Ennemy;
Ennemy ennemy1;
Ennemy ennemy2;


// Structure du shoot des ennemis

struct ShootEnnemy
{
    int x;
    int y;
    int speed;
    bool active;
    bool collision;

};
typedef struct ShootEnnemy ShootEnnemy;
ShootEnnemy shootennemy1;


// Fonction qui initialise la position de l'ennemi 1 et le tir de l'ennemi 1
// PRE : ennemy1 est une structure
// POST : initialise les variables de la structure ennemy1

void ennemy1Init(Ennemy *ennemy1, ShootEnnemy *shootennemy1);

// Fonction qui affiche l'ennemi 1
// PRE : ennemy1 est une structure
// POST : affiche ennemy1

void showEnnemy1(Ennemy *ennemy1, ShootEnnemy *shootennemy1, Biker *biker, GameOption *gameoption);


// Fonction qui initialise la position de l'ennemi 2 et le tir de l'ennemi 2
// PRE : ennemy2 est une structure
// POST : initialise les variables de la structure ennemy1

void ennemy2Init(Ennemy *ennemy2, ShootEnnemy *shootennemy2);

// Fonction qui affiche l'ennemi 2
// PRE : ennemy2 est une structure
// POST : affiche ennemy1

void showEnnemy2(Ennemy *ennemy2, ShootEnnemy *shootennemy2, Biker *biker, GameOption *gameoption);


// Fonction qui affiche le tir de l'ennemi 1
// PRE : shootennemy est une structure
// POST : affiche le tir de l'ennemi 1

void shootEnnemy1(ShootEnnemy *shootennemy1, Ennemy *ennemy1, GameOption *gameoption);


// Structure de shootennemy2

ShootEnnemy shootennemy2;

// Fonction qui affiche le tir de l'ennemi 2
// PRE : shootennemy est une structure
// POST : affiche le tir de l'ennemi 2

void shootEnnemy2(ShootEnnemy *shootennemy2, Ennemy *ennemy2, GameOption *gameoption);


#endif