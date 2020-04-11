#ifndef _TREE_H_
#define _TREE_H_

#include <stdlib.h>
#include <stdbool.h>

// Structure des arbres

struct Tree
{
    int number[6];
    int x;
    int y1;
    int y2;
};
typedef struct Tree Tree;
Tree tree;


// Fonction qui initialise la position du premier arbre
// PRE : tree est une structure
// POST : initialise les variables de la structure tree

void treeInit(Tree *tree);


// Fonction qui affiche les arbres
// PRE : tree est une structure
// POST : affiche l'arbre du haut et du bas

void showTree(Tree *tree);


#endif