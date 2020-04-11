#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "gameOption.h"
#include "biker.h"
#include "collision.h"
#include "imageBiker.c"
#include "imageFlame1.c"


ShootBikerList newShootBikerList(void)
{
     printf("Création newShootBikerList = NULL\n");
     return NULL;
}

bool isEmptyShootBikerList(ShootBikerList shootbikerlist)
{
     if(shootbikerlist == NULL)
     {
          return true;
     }
	return false;
}

int shootBikerListLength(ShootBikerList shootbikerlist)
{
     if(isEmptyShootBikerList(shootbikerlist))
     {
          return 0;
     }
	return shootbikerlist -> length;

}

ShootBikerList pushFrontShootBikerList(Biker *biker, ShootBikerList shootbikerlist)
{
     if(biker -> ammunition1 > 0)
     {
          biker -> ammunition1 = biker -> ammunition1 - 1;
          printf("ShootBiker - Ammunition 1 = %i\n",biker -> ammunition1);
          ShootBiker *element;
          element = malloc(sizeof(*element));

          if(element == NULL)
          {
               printf("Erreur : probleme allocation dynamique PushFrontShootBikerList.\n");
               exit(EXIT_FAILURE);
          }

          element->active = true;
          element->x = biker->x + 120;
          element->y = biker->y;
          element->next = NULL;
          element->back = NULL;

          if(isEmptyShootBikerList(shootbikerlist))
          {
               shootbikerlist = malloc(sizeof(*shootbikerlist));

               if(shootbikerlist == NULL)
               {
                    printf("Erreur : probleme allocation dynamique. shootbikerlist\n");
                    exit(EXIT_FAILURE);
               }

               shootbikerlist->length = 0;
               shootbikerlist->begin = element;
               shootbikerlist->end = element;
          }
          else
          {
               shootbikerlist->begin->back = element;
               element->next = shootbikerlist->begin;
               shootbikerlist->begin = element;
          }

          shootbikerlist->length++;
     }
     else
     {
          printf("ShootBiker - Tir impossible - Plus de munition1\n");
     }
     return shootbikerlist;
}

void bikerInit(Biker *biker){
     biker -> x = 100;
     biker -> y = 360;
     biker -> live = 5;
     biker -> greenplanet = 20;
     biker -> ammunition1 = 20;
     biker -> ammunition2 = 0;
     biker -> score = 0;
}

void showBiker(Biker *biker, GameOption *gameoption)
{
     glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
     gluBuild2DMipmaps( GL_TEXTURE_2D, image_biker.bytes_per_pixel,
               image_biker.width, image_biker.height,GL_RGBA, GL_UNSIGNED_BYTE,
               image_biker.pixel_data );

     glEnable(GL_TEXTURE_2D);
     glLoadIdentity();
     glTranslatef(0, 0,-1.75);
     gluOrtho2D(0, 1280, 0, 720);
     glTranslatef(biker->x, biker->y ,0);
     glBegin(GL_QUADS);
     glTexCoord2f(0.0, 1.0);  glVertex2f(0, 32);
     glTexCoord2f(1.0, 1.0);  glVertex2f(140, 32);
     glTexCoord2f(1.0, 0.0);  glVertex2f(140, -32);
     glTexCoord2f(0.0, 0.0);  glVertex2f(0, -32);
     glEnd();
     glDisable(GL_TEXTURE_2D);
}


void keyLeft(Biker *biker)
{
     if ((*biker).x > 10)
     {
          (*biker).x = (*biker).x - 10;
     }
     else
     {
          (*biker).x = (*biker).x;
     }
}

void keyRight(Biker *biker)
{
     if ((*biker).x < 540)
     {
          (*biker).x = (*biker).x + 10;
     }
     else
     {
          (*biker).x = (*biker).x;
     }
}

void keyUp(Biker *biker)
{
     if ((*biker).y < 600)
     {
          (*biker).y = (*biker).y + 10;
     }
     else
     {
          (*biker).y = (*biker).y;
     }
}

void keyDown(Biker *biker)
{
     if ((*biker).y > 50)
     {
          (*biker).y = (*biker).y - 10;
     }
     else
     {
          (*biker).y = (*biker).y;
     }
}

void Specialkey(int key, int x, int y)
{
     switch (key)
     {
     case GLUT_KEY_LEFT:
          keyLeft(&biker);
          break;

     case GLUT_KEY_RIGHT:
          keyRight(&biker);
          break;

     case GLUT_KEY_UP:
          keyUp(&biker);
          break;

     case GLUT_KEY_DOWN:
          keyDown(&biker);
          break;

     case 27 :
     exit(0);
     }
}

void Keyboard(unsigned char key, int x, int y)
{
     switch (key)
     {
     case ' ':
          myshootbikerlist = pushFrontShootBikerList(&biker, myshootbikerlist);
          showShootBiker(myshootbikerlist, &biker, &gameoption);
          break;

     case 27:
          exit(0);
     }
}

void printShootBikerList(ShootBikerList myshootbikerlist)
{
     if(isEmptyShootBikerList(myshootbikerlist))
	{
          return;
	}

	ShootBiker *temp = myshootbikerlist -> begin;

	while(temp != NULL)
	{
		temp = temp -> next;
	}
}

void showShootBiker(ShootBikerList myshootbikerlist, Biker *biker, GameOption *gameoption)
{
     if(isEmptyShootBikerList(myshootbikerlist))
	{
		return;
     }

     ShootBiker *temp = myshootbikerlist -> begin;

     while(temp != NULL)
     {
          if((gameoption -> screennumber) == 2)
          {
               if (temp->active == true)
               {        
                    unsigned int texture;
                    glGenTextures(0,&texture);
                    glBindTexture(GL_TEXTURE_2D, texture);
                    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
                    gluBuild2DMipmaps( GL_TEXTURE_2D, image_flame1.bytes_per_pixel,
                              image_flame1.width, image_flame1.height,GL_RGBA, GL_UNSIGNED_BYTE,
                              image_flame1.pixel_data );

                    glEnable(GL_TEXTURE_2D);
                    glLoadIdentity();
                    glTranslatef(0, 0,-1.75);
                    gluOrtho2D(0, 1280, 0, 720);
                    glTranslatef(temp->x, temp->y, 0);
                    glBegin(GL_QUADS);
                    glTexCoord2f(0.0, 1.0);  glVertex2f(0, 10);
                    glTexCoord2f(1.0, 1.0);  glVertex2f(75, 10);
                    glTexCoord2f(1.0, 0.0);  glVertex2f(75, -10);
                    glTexCoord2f(0.0, 0.0);  glVertex2f(0, -10);
                    glEnd();
                    glDisable(GL_TEXTURE_2D);
                    collisionShootBikerEnnemy1(&ennemy1, &shootennemy1, temp, biker);
                    collisionShootBikerEnnemy2(&ennemy2, &shootennemy2, temp, biker);
                    if (temp->x > 1280)
                    {
                         temp -> active = false;
                    }
                    if (temp -> x > 1280 && temp -> active == false)
                    {
                         popBackShootBikerList(myshootbikerlist);
                    }
               }
          }
          temp->x = temp->x + 10;
          temp->y = temp->y;
          temp = temp -> next;
     }
}

ShootBikerList popBackShootBikerList(ShootBikerList myshootbikerlist)
{
	if(isEmptyShootBikerList(myshootbikerlist))
	{
		printf("Rien à supprimer, la liste est déjà vide.\n");
		return newShootBikerList();
	}

	if(myshootbikerlist -> begin == myshootbikerlist -> end)
	{
          printf("306 Dernier node shootbiker supprimé.\n");
		//free(myshootbikerlist);
		myshootbikerlist = NULL;
          printf("309 Dernier node shootbiker supprimé.\n");
		return newShootBikerList();
	}

	ShootBiker *temp = myshootbikerlist -> end;

	myshootbikerlist -> end = myshootbikerlist -> end -> back;
	myshootbikerlist -> end -> next = NULL;
	temp->next = NULL;
	temp->back = NULL;
     printf("Node shootbiker supprimé.\n");
	free(temp);
	temp = NULL;

	myshootbikerlist -> length--;

	return myshootbikerlist;
}
