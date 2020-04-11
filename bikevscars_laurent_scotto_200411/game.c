#include <stdlib.h>
#include <stdbool.h>
#include <GL/glut.h>
#include "game.h"
#include "gameOption.h"
#include "imageBackgroundGame.c"
#include "imageWhiteLine.c"

void showBackgroundGame()
{
    glColor3f(0.3, 0.35, 0.37);
    glLoadIdentity();
    glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
    glTranslatef(0, 50, 0);

    int i;
    for (i = 0; i < 4; i++)
    {
        glBegin(GL_QUADS);              // Route grise (dégradé de gris)
        glVertex2f(0, 0);
        glVertex2f(1280, 0);
        glColor3f(0.2, 0.25, 0.27);
        glVertex2f(1280, 68);
        glVertex2f(0, 68);
        glEnd();

        glTranslatef(0, 68, 0);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(1280, 0);
        glColor3f(0.3, 0.35, 0.37);
        glVertex2f(1280, 68);
        glVertex2f(0, 68);
        glEnd();
        glTranslatef(0, 68, 0);
    }
        glTranslatef(0, -16, 0);        // Ligne jaune continue supérieure
        glColor3f(1.0, 0.7, 0.0);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(1280, 0);
        glVertex2f(1280, 8);
        glVertex2f(0, 8);
        glEnd();

        glTranslatef(0, -520, 0);       // Ligne jaune continue inférieure
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(1280, 0);
        glVertex2f(1280, 8);
        glVertex2f(0, 8);
        glEnd();

        glTranslatef(0, 268, 0);       // Ligne blanche centrale continue supérieure
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(1280, 0);
        glVertex2f(1280, 8);
        glVertex2f(0, 8);
        glEnd();

        glTranslatef(0, -16, 0);       // Ligne blanche centrale continues inférieure
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(1280, 0);
        glVertex2f(1280, 8);
        glVertex2f(0, 8);
        glEnd();
}

void whiteLineScrollingInit(WhiteLine *whiteline)
{
    whiteline -> x = 0;
    whiteline -> offset1 = 182;
    whiteline -> offset2 = 272;
}

void showWhiteLineScrolling(WhiteLine *whiteline)
{
    if((whiteline -> x) > -1280)
    {
        glColor3f(1.0, 1.0, 1.0);
        glLoadIdentity();
        glTranslatef(0, 0,-1.7);
        gluOrtho2D(0, 1280, 0, 720);
        glTranslatef(whiteline -> x, whiteline -> offset1, 0);

        int i;
        for (i = 0; i < 26; i++)
        {
            glBegin(GL_QUADS);
            glVertex2f(50, 0);
            glVertex2f(50, 8);
            glVertex2f(0, 8);
            glVertex2f(0, 0);
            glEnd();

            glTranslatef(0, whiteline -> offset2, 0);
            glBegin(GL_QUADS);
            glVertex2f(50, 0);
            glVertex2f(50, 8);
            glVertex2f(0, 8);
            glVertex2f(0, 0);
            glEnd();

            glTranslatef(100, -272, 0);
        }
        whiteline -> x = whiteline -> x - 1;
    }
    else
    {
        whiteline -> x = 0;
    }
}