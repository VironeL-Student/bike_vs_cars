#ifndef _TEXT_H_
#define _TEXT_H_
#include "biker.h"

// Structure qui contient la longueur des textes à afficher à l'écran lettre par lettre

struct LengthString
{
    int score_x;
    int score_y;
};

typedef struct LengthString LengthString ;
LengthString lengthstring;

// Fonction qui affiche le titre SCORE
// PRE : gameoption est une structure qui contient le numéro de l'écran actif
// POST : affiche le titre SCORE

void showScoreTitle(GameOption *gameoption);


// Fontion qui initialise les positions x et y sur l'écran des différents textes à afficher
// PRE : lengthstring est une structure contenant les x et y des score, live, greenplanet, munitions 1 et 2
// POST : initialise les valeurs x et y des score, live, greenplanet, munitions 1 et 2

void lengthStringInit(LengthString *lengthstring);


// Fonctions qui affichent le dessin d'un caractère
// PRE : lengthstring est une structure contenant les x et y des score, live, greenplanet, munitions 1 et 2
// POST : affiche à l'écran le caractère correspondant

void showNumber0(LengthString *lengthstring);
void showNumber1(LengthString *lengthstring);
void showNumber2(LengthString *lengthstring);
void showNumber3(LengthString *lengthstring);
void showNumber4(LengthString *lengthstring);
void showNumber5(LengthString *lengthstring);
void showNumber6(LengthString *lengthstring);
void showNumber7(LengthString *lengthstring);
void showNumber8(LengthString *lengthstring);
void showNumber9(LengthString *lengthstring);


// Fonction qui affiche le score du cycliste
// PRE : lengthstring est une structure contenant la position x et y des éléments à afficher, biker est une structure contenant les éléments à afficher
// POST : appelle pour chaque caractère à afficher la fonction d'affichage correspondante

void showScore(LengthString *lengthstring, Biker *biker, GameOption *gameoption);

#endif