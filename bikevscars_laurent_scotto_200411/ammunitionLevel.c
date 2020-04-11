#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "biker.h"
#include "ammunitionLevel.h"
#include "imageAmmunitionTitle.c"
#include "imageOval.c"

void showAmmunitionTitle(GameOption *gameoption)
{
    if((gameoption -> screennumber) == 2)
    {
        unsigned int texture;
        glGenTextures(0,&texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        gluBuild2DMipmaps( GL_TEXTURE_2D, image_ammunition_title.bytes_per_pixel,
                image_ammunition_title.width, image_ammunition_title.height,GL_RGBA, GL_UNSIGNED_BYTE,
                image_ammunition_title.pixel_data );
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0, 1.0, 1.0);
        glLoadIdentity();
        glTranslatef(0, 0,-1.7);
        gluOrtho2D(0, 1280, 0, 720);
        glTranslatef(845, 606 ,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
        glTexCoord2f(1.0, 1.0);  glVertex2f(196, 0);
        glTexCoord2f(1.0, 0.0);  glVertex2f(198, 80);
        glTexCoord2f(0.0, 0.0);  glVertex2f(0, 80);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
}

void showAmmunition(Biker *biker, Ammunition *ammunition, GameOption *gameoption)
{   
    if((gameoption -> screennumber) == 2)
    {
        ammunition -> x =900;
        ammunition -> y = 633;
        int i;
        for (i = 0; i < biker -> ammunition1; i++)
        {
            unsigned int texture;
            glGenTextures(0,&texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
            gluBuild2DMipmaps( GL_TEXTURE_2D, image_oval.bytes_per_pixel,
                    image_oval.width, image_oval.height,GL_RGBA, GL_UNSIGNED_BYTE,
                    image_oval.pixel_data );
            glEnable(GL_TEXTURE_2D);
            glColor3f(1.0, 1.0, 1.0);
            glLoadIdentity();
            glTranslatef(0, 0,-1.7);
            gluOrtho2D(0, 1280, 0, 720);
            glTranslatef(ammunition -> x + 15 * i, ammunition -> y ,0);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
            glTexCoord2f(1.0, 1.0);  glVertex2f(12, 0);
            glTexCoord2f(1.0, 0.0);  glVertex2f(12, 20);
            glTexCoord2f(0.0, 0.0);  glVertex2f(0, 20);
            glEnd();
            glDisable(GL_TEXTURE_2D);
        }
    }
}