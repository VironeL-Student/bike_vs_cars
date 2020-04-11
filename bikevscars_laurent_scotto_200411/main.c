#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "gameOption.h"
#include "home.h"
#include "rules.h"
#include "game.h"
#include "biker.h"
#include "random.h"
#include "ennemy.h"
#include "collision.h"
#include "scoreLevel.h"
#include "liveLevel.h"
#include "greenplanetLevel.h"
#include "ammunitionLevel.h"
#include "tree.h"

void Display()
{
    int currentscreen = currentScreenRead(&gameoption);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    switch (currentscreen)
    {
        case 0 :
            showBackgroundHome(&gameoption);
            break;

        case 1 :
            showBackgroundRules(&gameoption);
            break;
        
        case 2 :
            showBackgroundGame();
            showWhiteLineScrolling(&whiteline);
            showBiker(&biker, &gameoption);
            showShootBiker(myshootbikerlist, &biker, &gameoption);
            printShootBikerList(myshootbikerlist);
            showEnnemy1(&ennemy1, &shootennemy1, &biker, &gameoption);
            shootEnnemy1(&shootennemy1, &ennemy1, &gameoption);
            collisionShootEnnemy1Biker(&biker, &shootennemy1, &ennemy1);
            showEnnemy2(&ennemy2, &shootennemy2, &biker, &gameoption);
            shootEnnemy2(&shootennemy2, &ennemy2, &gameoption);
            collisionShootEnnemy2Biker(&biker, &shootennemy2, &ennemy2);
            collisionEnnemy1Biker(&biker, &ennemy1);
            collisionEnnemy2Biker(&biker, &ennemy2);
            showTree(&tree);
            showScoreTitle(&gameoption);
            showScore(&lengthstring, &biker, &gameoption);
            showLiveTitle(&gameoption);
            showLive(&biker, &live, &gameoption);
            showGreenplanetTitle(&gameoption);
            showGreenplanet(&biker, &greenplanet, &gameoption);
            showAmmunitionTitle(&gameoption);
            showAmmunition(&biker, &ammunition, &gameoption);
            break;
    }
    glutSwapBuffers();
}

void movementMouse(int x, int y)
{
    //printf("movementMouse :x = %i, y = %i\n",x, y);
}

void buttonMouse(int button, int state, int x, int y)
{
    int currentscreen = currentScreenRead(&gameoption);

    switch (currentscreen)
    {
        case 0 :
            clicMouseHome(button, state, x, y, &gameoption);
            break;
        case 1 :
            clicMouseRules(button, state, x, y, &gameoption);
            break;
    }
}

void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    currentViewportModify(w, h, &gameoption);
    printf("glviewPort : w = %i, h = %i\n",w,h);
}

int main(int argc, char ** argv)
{
    // Fonctions d'initialisation
    gameOptionInit(&gameoption);
    whiteLineScrollingInit(&whiteline);
    treeInit(&tree);
    bikerInit(&biker);
    myshootbikerlist = newShootBikerList();
    ennemy1Init(&ennemy1, &shootennemy1);
    ennemy2Init(&ennemy2, &shootennemy2);
    lengthStringInit(&lengthstring);

    // Fonctions d'initialisation Glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Bike vs. Cars");
    glutFullScreen();
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(60.0,1.0,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    // Fonctions callback Glut
    glutDisplayFunc(Display);
    glutSpecialFunc(Specialkey);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(&buttonMouse);
    glutPassiveMotionFunc(&movementMouse);
    glutIdleFunc(Display);
    glutReshapeFunc(Reshape);

    // Fonction loop Glut
    glutMainLoop();

    return 0;
}