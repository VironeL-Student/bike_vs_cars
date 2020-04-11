#ifndef _HOME_H_
#define  _HOME_H_
#include "gameOption.h"

// Fonction qui affiche le fond d'écran de la page d'accueil
// PRE : gameoption est une structure contenant l'écran du jeu actuel
// POST : affiche le background d'accueil du jeu

void showBackgroundHome(GameOption *gameoption);


// Fonction qui affiche la position de la souris dans la console de commande
// PRE : x et y sont des entiers positifs
// POST : la position de la souris dans la console de commande

void movementMouseHome (int x, int y);

// Fonction qui gère le clic de la souris dans l'écran home
// PRE : button est un entier, x et y sont des entiers positifs, gameoption est une structure contenant l'écran du jeu actuel
// Renvoie 0,1,2 en fonction du bouton appuyé

void clicMouseHome(int button, int state, int x, int y, GameOption *gameoption);


#endif