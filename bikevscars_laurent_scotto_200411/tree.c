#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <GL/glut.h>
#include "ennemy.h"
#include "random.h"
#include "tree.h"
#include "imageTree1.c"
#include "imageTree2.c"
#include "imageTree3.c"
#include "imageTree4.c"
#include "imageTree5.c"

void treeInit(Tree *tree)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        tree -> number[i] = rand_tree();
    }
    tree -> x = 0;
    tree -> y1 = 725;
    tree -> y2 = 0;
}

void showTree(Tree *tree)
{
    int i;
    int currentx = tree -> x;
    int currentimagewidth = 0;
    int currentimageheight = 0;

    while(currentx < 1280)
    {    
        for(i = 0 ; i < 6 ; i++)
        {
            unsigned int texture;
            glGenTextures(0,&texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
            switch (tree -> number [i])
            {
                case 1 :
                    gluBuild2DMipmaps( GL_TEXTURE_2D, image_tree1.bytes_per_pixel,
                            image_tree1.width, image_tree1.height,GL_RGBA, GL_UNSIGNED_BYTE,
                            image_tree1.pixel_data );
                    currentimagewidth = image_tree1.width;
                    currentimageheight = image_tree1.height;
                    break;
                case 2 :
                    gluBuild2DMipmaps( GL_TEXTURE_2D, image_tree2.bytes_per_pixel,
                            image_tree2.width, image_tree2.height,GL_RGBA, GL_UNSIGNED_BYTE,
                            image_tree2.pixel_data );
                    currentimagewidth = image_tree2.width;
                    currentimageheight = image_tree2.height;
                    break;
                case 3 :
                    gluBuild2DMipmaps( GL_TEXTURE_2D, image_tree3.bytes_per_pixel,
                            image_tree3.width, image_tree3.height,GL_RGBA, GL_UNSIGNED_BYTE,
                            image_tree3.pixel_data );
                    currentimagewidth = image_tree3.width;
                    currentimageheight = image_tree3.height;
                    break;
                case 4 :
                    gluBuild2DMipmaps( GL_TEXTURE_2D, image_tree4.bytes_per_pixel,
                            image_tree4.width, image_tree4.height,GL_RGBA, GL_UNSIGNED_BYTE,
                            image_tree4.pixel_data );
                    currentimagewidth = image_tree4.width;
                    currentimageheight = image_tree4.height;
                    break;
                case 5 :
                    gluBuild2DMipmaps( GL_TEXTURE_2D, image_tree5.bytes_per_pixel,
                            image_tree5.width, image_tree5.height,GL_RGBA, GL_UNSIGNED_BYTE,
                            image_tree5.pixel_data );
                    currentimagewidth = image_tree5.width;
                    currentimageheight = image_tree5.height;
                    break;
            }
            glEnable(GL_TEXTURE_2D);
            glLoadIdentity();
            glTranslatef(0, 0,-1.75);
            gluOrtho2D(0, 1280, 0, 720);
            glTranslatef(currentx, tree -> y1 - currentimageheight ,0);                     // Arbres du dessus
            glBegin(GL_QUADS);
            glTexCoord2f(1.0, 0.0);  glVertex2f(0, currentimageheight);
            glTexCoord2f(1.0, 1.0);  glVertex2f(0, 0);
            glTexCoord2f(0.0, 1.0);  glVertex2f(currentimagewidth, 0);
            glTexCoord2f(0.0, 0.0);  glVertex2f(currentimagewidth, currentimageheight);
            glEnd();

            glTranslatef(0,-684,0);                                                        // Arbres du dessous
            glBegin(GL_QUADS);
            glTexCoord2f(1.0, 0.0);  glVertex2f(0, currentimageheight);
            glTexCoord2f(1.0, 1.0);  glVertex2f(0, 0);
            glTexCoord2f(0.0, 1.0);  glVertex2f(currentimagewidth, 0);
            glTexCoord2f(0.0, 0.0);  glVertex2f(currentimagewidth, currentimageheight);
            glEnd();
              
            glDisable(GL_TEXTURE_2D);
            currentx = currentx + currentimagewidth;
        }
    }
    tree -> x = tree -> x - 1;
}