#include <stdlib.h>
#include <GL/glut.h>
#include "rules.h"
#include "gameOption.h"
#include "imageBackgroundRules.c"

void showBackgroundRules(GameOption *gameoption)
{
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    gluBuild2DMipmaps( GL_TEXTURE_2D, image_background_rules.bytes_per_pixel,
            image_background_rules.width, image_background_rules.height,GL_RGB, GL_UNSIGNED_BYTE,
            image_background_rules.pixel_data );
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

void clicMouseRules(int button, int state, int x, int y, GameOption *gameoption)
{
    if(x >= 1108 * gameoption -> screenviewportx / 1280 && x <= 1261 * gameoption -> screenviewportx / 1280 && y >= 661 * gameoption -> screenviewporty / 720 && y <= 701 * gameoption -> screenviewporty / 720 && button == 0 && state == 1)
    {
        currentScreenModify(0, gameoption);        
    }
}