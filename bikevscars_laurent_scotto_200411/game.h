#ifndef _GAME_H_
#define _GAME_H_
#include "gameOption.h"


// Structure qui stocke la position des lignes blanches discontinues pour le scrolling

struct WhiteLine
{
    int x;
    int offset1;
    int offset2;
};
typedef struct WhiteLine WhiteLine;
WhiteLine whiteline;


// Fonction qui affiche la route et les lignes continues pendant la partie;
// PRE : -
// POST : affiche la route et les lignes continues jaunes et blanches dessinées en vertex pendant la partie

void showBackgroundGame();


// Fonction qui initialise la position des lignes blanches discontinues pour le scrolling
// PRE : whiteline est une structure contenant la ligne blanche discontinue
// POST : initialise le x à 1280;

void whiteLineScrollingInit(WhiteLine *whiteline);


// Fonction qui fait défiler les lignes blanches discontinues du background pendant la partie
// PRE : whiteline est une structure contenant la ligne blanche discontinue
// POST : fait défiler les lignes blanches discontinues pour simuler le scrolling

void showWhiteLineScrolling(WhiteLine *whiteline);


#endif