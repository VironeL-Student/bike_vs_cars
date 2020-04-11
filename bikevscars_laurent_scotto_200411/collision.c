#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "collision.h"
#include "biker.h"
#include "ennemy.h"
#include "random.h"

void collisionShootBikerEnnemy1(Ennemy *ennemy1, ShootEnnemy *shootennemy1, ShootBiker *temp, Biker *biker)
{
    if (temp -> x >= ennemy1 -> x + 25 && temp -> y > ennemy1 -> y - 62 && temp -> y < ennemy1 -> y + 62 )
    {
        biker->score = biker->score + 5;
        printf("Collision shootBiker vs. ennemy1 - Score biker = %i\n", biker->score);
        ennemy1Init(ennemy1, shootennemy1);
        temp -> active = false;
    }
}

void collisionShootBikerEnnemy2(Ennemy *ennemy2, ShootEnnemy *shootennemy2, ShootBiker *temp, Biker *biker)
{
    if (temp -> x >= ennemy2 -> x + 25 && temp -> y > ennemy2 -> y - 62 && temp -> y < ennemy2 -> y + 62 )
    {
        biker->score = biker->score + 5;
        printf("Collision shootBiker vs. ennemy2 - Score biker = %i\n", biker->score);
        ennemy2Init(ennemy2, shootennemy2);
        temp -> active = false;
    }
}

void collisionShootEnnemy1Biker(Biker *biker, ShootEnnemy *shootennemy1, Ennemy *ennemy1)
{
    if (shootennemy1 -> x < biker -> x + 100 && shootennemy1 -> x > biker -> x && shootennemy1 -> y > biker -> y - 32 && shootennemy1 -> y < biker -> y + 32 && shootennemy1 -> collision == false)
    {
        if (biker -> live >= 1)
        {
            biker -> live = biker -> live - 1;
            printf("Collision ShootEnnemy1 vs. Bike - live = %i\n",biker -> live);
            shootennemy1 -> collision = true ;
        }
    if (biker -> live < 1)
        {
            printf("GAME OVER\n");
            exit(0);
        }
    }
}

void collisionShootEnnemy2Biker(Biker *biker, ShootEnnemy *shootennemy2, Ennemy *ennemy2)
{
    if (shootennemy2 -> x < biker -> x + 100 && shootennemy2 -> x > biker -> x && shootennemy2 -> y > biker -> y - 32 && shootennemy2 -> y < biker -> y + 32 && shootennemy2 -> collision == false)
    {
        if (biker -> live >= 1)
        {
            biker -> live = biker -> live - 1;
            printf("Collision ShootEnnemy2 vs. Bike - live = %i\n",biker -> live);
            shootennemy2 -> collision = true ;
        }
    if (biker -> live < 1)
        {
            printf("GAME OVER\n");
            exit(0);
        }
    }
}

void collisionEnnemy1Biker(Biker *biker, Ennemy *ennemy1)
{
    if (ennemy1 -> x < biker -> x + 140 && ennemy1 -> collision == false)
    {
        if (biker -> y >= ennemy1 -> y && biker -> y - ennemy1 -> y < 82)
        {
            ennemy1 -> collision = true;
        }
        if (biker -> y < ennemy1 -> y && ennemy1 -> y - biker -> y < 82)
        {
            ennemy1 -> collision = true;
        }
        if(ennemy1 -> collision == true)
        {
            if (biker -> live > 1)
            {
                biker -> live = biker -> live - 1;
                printf("Collision Ennemy1 vs. Bike - live = %i\n",biker -> live);
            }
            else
            {
                printf("GAME OVER\n");
                exit(0);
            }
        }
    }
}

void collisionEnnemy2Biker(Biker *biker, Ennemy *ennemy2)
{
    if (ennemy2 -> x < biker -> x + 140 && ennemy2 -> collision == false)
    {
        if (biker -> y >= ennemy2 -> y && biker -> y - ennemy2 -> y < 95)
        {
            ennemy2 -> collision = true;
        }
        if (biker -> y < ennemy2 -> y && ennemy2 -> y - biker -> y < 95)
        {
            ennemy2 -> collision = true;
        }
        if(ennemy2 -> collision == true)
        {
            if (biker -> live > 1)
            {
                biker -> live = biker -> live - 1;
                printf("Collision Ennemy1 vs. Bike - live = %i\n",biker -> live);
            }
            else
            {
                printf("GAME OVER\n");
                exit(0);
            }
        }
    }
}