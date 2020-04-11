#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "home.h"
#include "gameOption.h"
#include "imageBackgroundHome.c"

void showBackgroundHome(GameOption *gameoption)
{
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    gluBuild2DMipmaps( GL_TEXTURE_2D, image_background_home.bytes_per_pixel,
            image_background_home.width, image_background_home.height,GL_RGB, GL_UNSIGNED_BYTE,
            image_background_home.pixel_data );
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
    glTexCoord2f(1.0, 1.0);  glVertex2f(1280, 0);
    glTexCoord2f(1.0, 0.0);  glVertex2f(1280, 720);
    glTexCoord2f(0.0, 0.0);  glVertex2f(0, 720);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void clicMouseHome(int button, int state, int x, int y, GameOption *gameoption)
{
    if(x >= 331 * gameoption -> screenviewportx / 1280 && x <= 585 * gameoption -> screenviewportx / 1280 && y >= 141 * gameoption -> screenviewporty / 720 && y <= 164 * gameoption -> screenviewporty / 720 && button == 0 && state == 1)           // Position du titre REGLES DU JEU
    {
        currentScreenModify(1, gameoption);        
    }
    else if(x >= 1108 * gameoption -> screenviewportx / 1280 && x <= 1260 * gameoption -> screenviewportx / 1280 && y >= 661 * gameoption -> screenviewporty / 720 && y <= 703 * gameoption -> screenviewporty / 720 && button == 0 && state == 1)    // Position du bouton PLAY
    {
        currentScreenModify(2, gameoption);        
    }
}