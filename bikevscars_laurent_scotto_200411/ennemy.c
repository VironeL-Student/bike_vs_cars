#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <GL/glut.h>
#include "ennemy.h"
#include "random.h"
#include "collision.h"
#include "imageEnnemy1.c"
#include "imageEnnemy2.c"
#include "biker.h"
#include "imageFlame2.c"

void ennemy1Init(Ennemy *ennemy1, ShootEnnemy *shootennemy1)
{
    ennemy1 -> x = rand_ennemy1_x();
    ennemy1 -> y = rand_ennemy1_y() ;
    ennemy1 -> speed = rand_ennemy1_speed();
    ennemy1 -> collision = false;
    shootennemy1 -> x = ennemy1 -> x + 20;
    shootennemy1 -> y = ennemy1 -> y;
    shootennemy1 -> speed = ennemy1 -> speed + 2;
    shootennemy1 -> collision = false;
}

void showEnnemy1(Ennemy *ennemy1, ShootEnnemy *shootennemy1, Biker *biker, GameOption *gameoption)
{
    if((gameoption -> screennumber) == 2)
    {
        unsigned int texture;
        glGenTextures(0,&texture);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        gluBuild2DMipmaps( GL_TEXTURE_2D, image_ennemy1.bytes_per_pixel,
                image_ennemy1.width, image_ennemy1.height,GL_RGBA, GL_UNSIGNED_BYTE,
                image_ennemy1.pixel_data );
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0, 1.0, 1.0);
        glLoadIdentity();
        glTranslatef(0, 0,-1.75);
        gluOrtho2D(0, 1280, 0, 720);
        glTranslatef(ennemy1->x, ennemy1->y ,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);  glVertex2f(0, 62);
        glTexCoord2f(1.0, 1.0);  glVertex2f(250, 62);
        glTexCoord2f(1.0, 0.0);  glVertex2f(250, -62);
        glTexCoord2f(0.0, 0.0);  glVertex2f(0, -62);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        ennemy1->x = (ennemy1 -> x) - (ennemy1 -> speed);

        if(ennemy1 -> x < -250)
        {
            printf("Ennemy1 non tué - Points Greenplanet = %i\n",biker->greenplanet);
            biker->greenplanet = biker->greenplanet - 1;
            if(biker->greenplanet < 1)
            {
                printf("GAME OVER\n");
                exit(0);
            }
            ennemy1Init(ennemy1, shootennemy1);
        }
    }
}

void shootEnnemy1(ShootEnnemy *shootennemy1, Ennemy *ennemy1, GameOption *gameoption)
{
    if((gameoption -> screennumber) == 2)
    {
        if((ennemy1 -> x < 1280) && (ennemy1 -> x > 0) && shootennemy1 -> collision == false)
        {
            shootennemy1->active = true;
            shootennemy1 -> x = shootennemy1 -> x - ennemy1 -> speed - 5;
        }
        else
        {
            shootennemy1->active = false;
            shootennemy1 -> x = ennemy1 -> x;

        }
        if((shootennemy1 -> active) == true)
        {
            unsigned int texture;
            glGenTextures(0,&texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
            gluBuild2DMipmaps( GL_TEXTURE_2D, image_flame2.bytes_per_pixel,
                    image_flame2.width, image_flame2.height,GL_RGBA, GL_UNSIGNED_BYTE,
                    image_flame2.pixel_data );

            glEnable(GL_TEXTURE_2D);
            glLoadIdentity();
            glTranslatef(0, 0,-1.75);
            gluOrtho2D(0, 1280, 0, 720);
            glTranslatef(shootennemy1->x, shootennemy1->y, 0);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 1.0);  glVertex2f(0, 10);
            glTexCoord2f(1.0, 1.0);  glVertex2f(75, 10);
            glTexCoord2f(1.0, 0.0);  glVertex2f(75, -10);
            glTexCoord2f(0.0, 0.0);  glVertex2f(0, -10);
            glEnd();
            glDisable(GL_TEXTURE_2D);
        }
    }  
}


void ennemy2Init(Ennemy *ennemy2, ShootEnnemy *shootennemy2)
{
    ennemy2 -> x = 1280 + rand_ennemy2_x();
    ennemy2 -> y = rand_ennemy2_y() ;
    ennemy2 -> speed = rand_ennemy2_speed();
    shootennemy2 -> x = ennemy2 -> x + 20;
    shootennemy2 -> y = ennemy2 -> y;
    shootennemy2 -> speed = ennemy2 -> speed + 2;
    shootennemy2 -> collision = false;
}

void showEnnemy2(Ennemy *ennemy2, ShootEnnemy *shootennemy2, Biker *biker, GameOption *gameoption)
{
    if((gameoption -> screennumber) == 2)
    {
        unsigned int texture;
        glGenTextures(0,&texture);
        glGenTextures(0,&texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        gluBuild2DMipmaps( GL_TEXTURE_2D, image_ennemy2.bytes_per_pixel,
                image_ennemy2.width, image_ennemy2.height,GL_RGBA, GL_UNSIGNED_BYTE,
                image_ennemy2.pixel_data );
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0, 1.0, 1.0);
        glLoadIdentity();
        glTranslatef(0, 0,-1.75);
        gluOrtho2D(0, 1280, 0, 720);
        glTranslatef(ennemy2->x, ennemy2->y ,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);  glVertex2f(0, 62);
        glTexCoord2f(1.0, 1.0);  glVertex2f(250, 62);
        glTexCoord2f(1.0, 0.0);  glVertex2f(250, -62);
        glTexCoord2f(0.0, 0.0);  glVertex2f(0, -62);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        ennemy2->x = (ennemy2 -> x) - (ennemy2 -> speed);

        if(ennemy2 -> x < -250)
        {
            printf("Ennemy2 non tué - Points Greenplanet = %i\n",biker->greenplanet);
            biker->greenplanet = biker->greenplanet - 1;
            if(biker->greenplanet < 1)
            {
                printf("GAME OVER\n");
                exit(0);
            }
            ennemy2Init(ennemy2, shootennemy2);
        }
    }
}

void shootEnnemy2(ShootEnnemy *shootennemy2, Ennemy *ennemy2, GameOption *gameoption)
{
    if((gameoption -> screennumber) == 2)
    {
        if((ennemy2 -> x < 1280) && (ennemy2 -> x > 0) && shootennemy2 -> collision == false)
        {
            shootennemy2->active = true;
            shootennemy2 -> x = shootennemy2 -> x - ennemy2 -> speed - 5;
        }
        else
        {
            shootennemy2->active = false;
            shootennemy2 -> x = ennemy2 -> x;

        }
        if((shootennemy2 -> active) == true)
        {
            unsigned int texture;
            glGenTextures(0,&texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
            gluBuild2DMipmaps( GL_TEXTURE_2D, image_flame2.bytes_per_pixel,
                    image_flame2.width, image_flame2.height,GL_RGBA, GL_UNSIGNED_BYTE,
                    image_flame2.pixel_data );

            glEnable(GL_TEXTURE_2D);
            glLoadIdentity();
            glTranslatef(0, 0,-1.75);
            gluOrtho2D(0, 1280, 0, 720);
            glTranslatef(shootennemy2->x, shootennemy2->y, 0);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 1.0);  glVertex2f(0, 10);
            glTexCoord2f(1.0, 1.0);  glVertex2f(75, 10);
            glTexCoord2f(1.0, 0.0);  glVertex2f(75, -10);
            glTexCoord2f(0.0, 0.0);  glVertex2f(0, -10);
            glEnd();
            glDisable(GL_TEXTURE_2D);
        }
    } 
}

