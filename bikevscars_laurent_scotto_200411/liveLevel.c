#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "biker.h"
#include "liveLevel.h"
#include "imageLiveTitle.c"
#include "imageOval.c"

void showLiveTitle(GameOption *gameoption)
{
    if((gameoption -> screennumber) == 2)
    {
        unsigned int texture;
        glGenTextures(0,&texture);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        gluBuild2DMipmaps( GL_TEXTURE_2D, image_live_title.bytes_per_pixel,
                image_live_title.width, image_live_title.height,GL_RGBA, GL_UNSIGNED_BYTE,
                image_live_title.pixel_data );
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0, 1.0, 1.0);
        glLoadIdentity();
        glTranslatef(0, 0,-1.7);
        gluOrtho2D(0, 1280, 0, 720);
        glTranslatef(245, 665 ,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
        glTexCoord2f(1.0, 1.0);  glVertex2f(72, 0);
        glTexCoord2f(1.0, 0.0);  glVertex2f(72, 21);
        glTexCoord2f(0.0, 0.0);  glVertex2f(0, 21);
        glEnd();
    }
}

void showLive(Biker *biker, Live *live, GameOption *gameoption)
{   
    if((gameoption -> screennumber) == 2)
    {     
        live -> x = 245;
        live -> y = 633;
        int i;
        for (i = 0; i < biker -> live; i++)
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
            glTranslatef(live -> x + 15 * i, live -> y ,0);
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