#ifndef _BIKER_H_
#define _BIKER_H_

#include <stdlib.h>
#include <stdbool.h>
#include "gameOption.h"

// Structure du cycliste

struct Biker
{
    int x;
    int y;
    int live;
    int greenplanet;
    int ammunition1;
    int ammunition2;
    int score;
};
typedef struct Biker Biker;
Biker biker;


// Structure d'un noeud de la chaîne du shoot du cycliste

struct ShootBiker
{
    int value;
    bool active;
    int x;
    int y;
    struct ShootBiker *back;
    struct ShootBiker *next;
};
typedef struct ShootBiker ShootBiker;
ShootBiker shootbiker;


// Structure de la liste chaînée du shoot du cycliste

typedef struct ShootBikerList
{
    int length;
    struct ShootBiker *begin;
    struct ShootBiker *end;
}*ShootBikerList;

ShootBikerList myshootbikerlist;


// Fonction qui crée la liste chaînée du shoot du cycliste
// PRE : -
// POST : crée la liste chaînée NULL

ShootBikerList newShootBikerList(void);


// Fonction qui indique si la liste est vide ou non
// PRE : shootbikerlist est une structure
// POST : renvoie false si newshootbikerlist est vide, true si pas

bool isEmptyShootBikerList(ShootBikerList shootbikerlist);


// Fonction qui définit la longueur de la liste chaînée du shoot du cycliste
// PRE : shootbikerlist est une structure
// POST : renvoie un entier qui est le nombre d'éléments de la liste chaînée

int shootBikerListLength(ShootBikerList shootbikerlist);


// Impression de la liste chaînée dans la console
// PRE : shootbikerlist est une structure
// POST : impression des éléments de la liste chaînée
void printShootBikerList(ShootBikerList shootbikerlist);


// Ajout d'un noeud au début de la liste chaînée du shoot du cycliste
// PRE biker est une structure contenant les informations du cycliste, shootbikerlist est la liste chaînée des tirs du cycliste
// POST : ajoute un noeud dans la liste chaînée des tirs du cycliste

ShootBikerList pushFrontShootBikerList(Biker *biker, ShootBikerList shootbikerlist);


// Fonction qui initialise la position dy cycliste
// PRE : *biker est un pointeur sur une structure
// POST : Initialise les informations du cycliste

void bikerInit(Biker *biker);

// Fonction qui affiche le cycliste
// PRE : *biker est un pointeur sur une structure
// POST : affiche le cycliste

void showBiker(Biker *biker, GameOption *gameoption);


// Fonction qui gère les déplacements du cycliste avec les touches spéciales flèches gauche, droite, haut, bas
// PRE : int est une touche spéciale du clavier, x et y sont obligatoires pour la fonction glutSpecialkeyFunc
// POST : renvoie les touches clavier des flèches pour le déplacement du cycliste

void Specialkey(int key, int x, int y);


// Fonction qui teste si le cycliste peut aller à gauche
// PRE : *biker est un pointeur sur une structure
// POST : -

void keyLeft(Biker *biker);


// Fonction qui teste si le cycliste peut aller à droite
// PRE : *biker est un pointeur sur une structure
// POST : applique un déplacement du cycliste

void keyRight(Biker *biker);


// Fonction qui teste si le cycliste peut aller en haut
// PRE : *biker est un pointeur sur une structure
// POST : applique un déplacement du cycliste

void keyUp(Biker *biker);


// Fonction qui teste si le cycliste peut aller àen bas
// PRE : *biker est un pointeur sur une structure
// POST : applique un déplacement du cycliste

void keyDown(Biker *biker);


// Fonction qui gère les touches du clavier
// PRE : char est une touche "normale" du clavier, x et y sont des entiers
// POST : applique un déplacement du cycliste


void Keyboard(unsigned char key, int x, int y);

// Fonction qui affiche le tir du cycliste
// PRE : myshootbikerlist est une structure
// POST : -

void showShootBiker(ShootBikerList myshootbikerlist, Biker *biker, GameOption *gameoption);


// Fonction qui supprime les tirs du cycliste dès qu'ils sortent à droite de l'écran
// PRE : myshootbikerlist est une structure
// POST : supprime le noeud de la liste chaînée

ShootBikerList popBackShootBikerList(ShootBikerList myshootbikerlist);


// Fonction qui supprime la liste
// PRE : myshootbikerlist est la structure contenant la liste chaînée
// POST : supprime (free) la liste chaînée

ShootBikerList clearShootBikerList(ShootBikerList myshootbikerlist);

#endif