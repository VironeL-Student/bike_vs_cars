#ifndef _RULES_H_
#define  _RULES_H_
#include "gameOption.h"

// Fonction qui affiche le fond d'écran de la page d'accueil
// PRE : gameoption est une structure contenant l'écran du jeu actuel
// POST : affiche le background d'accueil du jeu

void showBackgroundRules(GameOption *gameoption);


// Fonction qui gère le clic de la souris dans l'écran des règles de jeu
// PRE : x et y sont des entiers positifs, gameoption est une structure contenant l'écran du jeu actuel
// Modifie gameoption.screen

void clicMouseRules(int button, int state, int x, int y, GameOption *gameoption);


#endif