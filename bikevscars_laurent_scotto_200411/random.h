#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <time.h>

// Initialisation de rand

void srand(unsigned int seed);


// Génération d'un nombre aléatoire pour l'apparition aléatoire de l'ennemi 1 (x)
// PRE : -
//POST : renvoie un entier entre 0 et 500 + 1280

int rand_ennemy1_x(void);


// Génération d'un nombre aléatoire pour l'apparition aléatoire de l'ennemi 2 (x)
// PRE : -
//POST : renvoie un entier entre 0 et 500 + 1280

int rand_ennemy2_x(void);


// Génération d'un nombre aléatoire pour l'apparition aléatoire de l'ennemi 1 (y)
// PRE : -
//POST : renvoie un entier entre 0 et 200 + 70

int rand_ennemy1_y(void);


// Génération d'un nombre aléatoire pour l'apparition aléatoire de l'ennemi 2 (y)
// PRE : -
//POST : renvoie un entier entre 0 et 200 + 320

int rand_ennemy2_y(void);



// Génération d'un nombre aléatoire pour la vitesse de l'ennemi 1
// PRE : -
//POST : renvoie un entier entre 0 et 10 + 5

int rand_ennemy1_speed(void);


// Génération d'un nombre aléatoire pour la vitesse de l'ennemi 2
// PRE : -
//POST : renvoie un entier entre 0 et 10 + 5

int rand_ennemy2_speed(void);


// Génération d'un nombre aléatoire pour faire défiler les 5 dessins arbres aléatoirement
// PRE : -
//POST : renvoie un entier entre 0 et 4 + 1

int rand_tree(void);

#endif