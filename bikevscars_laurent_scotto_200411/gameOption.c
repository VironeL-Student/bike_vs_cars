#include <stdbool.h>
#include <GL/glut.h>
#include "gameOption.h"

void gameOptionInit(GameOption *gameoption)
{
    gameoption -> screennumber = 0;                // 0 = Ecran d'accueil, 1 = Règles du jeu, 2 = Jeu, 3 = Game Over, 4 = High scores
    gameoption -> screenviewportx = 1280;
    gameoption -> screenviewporty = 720;
    gameoption -> continuegame = false;
    gameoption -> beginnewgame = true;
    gameoption -> gamerules = false;
    gameoption -> difficulty = 0;
    gameoption -> music = true;                    // true = musique ON, false = musique OFF
    gameoption -> scrolling = 0;                   // 0 = horizontal, 1 = vertical
    gameoption -> homeplaybutton = false;
    gameoption -> homeexitbutton = false;
}

int currentScreenRead(GameOption *gameoption)
{
    return gameoption -> screennumber;              // 0 = Ecran d'accueil, 1 = Règles du jeu, 2 = Jeu, 3 = Game Over, 4 = High scores
}

void currentScreenModify(int newscreennumber, GameOption *gameoption)
{
    gameoption -> screennumber = newscreennumber;
}

void currentViewportModify(int w, int h, GameOption *gameoption)
{
    gameoption -> screenviewportx = w;
    gameoption -> screenviewporty = h;
}