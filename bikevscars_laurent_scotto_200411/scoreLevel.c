#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include "imageNumber0.c"
#include "imageNumber1.c"
#include "imageNumber2.c"
#include "imageNumber3.c"
#include "imageNumber4.c"
#include "imageNumber5.c"
#include "imageNumber6.c"
#include "imageNumber7.c"
#include "imageNumber8.c"
#include "imageNumber9.c"
#include "scoreLevel.h"
#include "biker.h"
#include "imageScoreTitle.c"


void lengthStringInit(LengthString *lengthstring)
{
    lengthstring -> score_x = 125;
    lengthstring -> score_y = 635;
}

void showScoreTitle(GameOption *gameoption)
{  
	if((gameoption -> screennumber) == 2)
    {      
        unsigned int texture;
		glGenTextures(0,&texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        gluBuild2DMipmaps( GL_TEXTURE_2D, image_score_title.bytes_per_pixel,
                image_score_title.width, image_score_title.height,GL_RGBA, GL_UNSIGNED_BYTE,
                image_score_title.pixel_data );
        glEnable(GL_TEXTURE_2D);
        glColor3f(1.0, 1.0, 1.0);
        glLoadIdentity();
        glTranslatef(0, 0,-1.7);
        gluOrtho2D(0, 1280, 0, 720);
        glTranslatef(40, 665 ,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
        glTexCoord2f(1.0, 1.0);  glVertex2f(113, 0);
        glTexCoord2f(1.0, 0.0);  glVertex2f(113, 21);
        glTexCoord2f(0.0, 0.0);  glVertex2f(0, 21);
        glEnd();
        glDisable(GL_TEXTURE_2D);
	}
}

void showNumber0(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number0.bytes_per_pixel,
			image_number0.width, image_number0.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number0.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number0.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number0.width, image_number0.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number0.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number0.width;
}

void showNumber1(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number1.bytes_per_pixel,
			image_number1.width, image_number1.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number1.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number1.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number1.width,  image_number1.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0,  image_number1.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number1.width;
}

void showNumber2(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number2.bytes_per_pixel,
			image_number2.width, image_number2.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number2.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number2.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number2.width,  image_number2.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number2.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number2.width;
}

void showNumber3(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number3.bytes_per_pixel,
			image_number3.width, image_number3.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number3.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number3.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number3.width,  image_number3.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number3.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number3.width;
}

void showNumber4(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number4.bytes_per_pixel,
			image_number4.width, image_number4.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number4.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number4.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number4.width,  image_number4.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number4.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number4.width;
}

void showNumber5(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number5.bytes_per_pixel,
			image_number5.width, image_number5.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number5.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number5.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number5.width,  image_number5.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number5.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number5.width;
}

void showNumber6(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number6.bytes_per_pixel,
			image_number6.width, image_number6.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number6.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number6.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number6.width,  image_number6.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number6.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number6.width;
}

void showNumber7(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number7.bytes_per_pixel,
			image_number7.width, image_number7.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number7.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number7.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number7.width,  image_number7.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number7.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number7.width;
}

void showNumber8(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number8.bytes_per_pixel,
			image_number8.width, image_number8.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number8.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number8.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number8.width,  image_number8.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number8.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number8.width;
}

void showNumber9(LengthString *lengthstring)
{
	unsigned int texture;
	glGenTextures(0,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, image_number9.bytes_per_pixel,
			image_number9.width, image_number9.height,GL_RGBA, GL_UNSIGNED_BYTE,
			image_number9.pixel_data );
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
	glTranslatef(0, 0,-1.7);
    gluOrtho2D(0, 1280, 0, 720);
	glTranslatef(lengthstring -> score_x, lengthstring -> score_y, 0.0);
    glBegin(GL_QUADS);
  	glTexCoord2f(0.0, 1.0);  glVertex2f(0, 0);
  	glTexCoord2f(1.0, 1.0);  glVertex2f(image_number9.width, 0);
  	glTexCoord2f(1.0, 0.0);  glVertex2f(image_number9.width,  image_number9.height);
  	glTexCoord2f(0.0, 0.0);  glVertex2f(0, image_number9.height);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	lengthstring -> score_x = lengthstring -> score_x - image_number9.width;
}

void showScore(LengthString *lengthstring, Biker *biker, GameOption *gameoption)
{
	if((gameoption -> screennumber) == 2)
    {
		int i;
		int j;
		for(i = biker -> score; i >=1.0; i = i/10 )
		{
			j = i%10;
			switch (j)
			{
				case 0 :
				showNumber0(lengthstring);
				break;

				case 1 :
				showNumber1(lengthstring);
				break;

				case 2 :
				showNumber2(lengthstring);
				break;

				case 3 :
				showNumber3(lengthstring);
				break;

				case 4 :
				showNumber4(lengthstring);
				break;

				case 5 :
				showNumber5(lengthstring);
				break;

				case 6 :
				showNumber6(lengthstring);
				break;

				case 7 :
				showNumber7(lengthstring);
				break;

				case 8 :
				showNumber8(lengthstring);
				break;

				case 9 :
				showNumber9(lengthstring);
				break;
			}
			j = biker -> score/10;
		}
		lengthStringInit(lengthstring);
	}
}