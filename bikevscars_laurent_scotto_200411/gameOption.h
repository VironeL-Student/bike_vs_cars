#ifndef _GAMEOPTION_H_
#define _GAMEOPTION_H_
#include <stdlib.h>
#include <stdbool.h>

// Structure qui définit la position des lignes blanches pour le scrolling

struct GameOption
{
    int screennumber;                // 0 = Ecran d'accueil, 1 = Règles du jeu, 2 = Jeu, 3 = Game Over, 4 = High scores
    int screenviewportx;             // Dimension x réelle de la fenêtre de jeu
    int screenviewporty;             // Dimension y réelle de la fenêtre de jeu
    bool continuegame;
    bool beginnewgame;
    bool gamerules;
    int difficulty;
    bool music;                      // true = musique ON, false = musique OFF
    int scrolling;                   // 0 = horizontal, 1 = vertical
    bool homeplaybutton;
    bool homeexitbutton;
};
typedef struct GameOption GameOption;
GameOption gameoption;


// Fonction qui initialise les valeurs de screen (options du jeu)
// PRE : gameoption est une structure contenant les options et boutons du jeu
// POST : initialise les options du jeu

void gameOptionInit(GameOption *gameoption);


// Fonction qui lit l'écran de jeu en cours
// PRE : gameoption est une structure
// POST : renvoie le numéro d'écran en cours (0 = Ecran d'accueil, 1 = Règles du jeu, 2 = Jeu, 3 = Game Over, 4 = High scores)

int currentScreenRead(GameOption *gameoption);


// Fonction qui modifie le numéro de l'écran de jeu en cours
// PRE : newscreennumber est un entier positif
// POST : modifie *gameoption.screennumber (0 = Ecran d'accueil, 1 = Règles du jeu, 2 = Jeu, 3 = Game Over, 4 = High scores)

void currentScreenModify(int newscreennumber, GameOption *gameoption);


// Fonction qui modifie gameoption.viewport x et y
// PRE : w, h sont des entiers positifs
// POST : modifie gameoption.viewport x et y

void currentViewportModify(int w, int h, GameOption*gameoption);

#endif