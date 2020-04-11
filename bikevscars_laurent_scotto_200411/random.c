#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "random.h"

void srand(unsigned int seed);

int rand_ennemy1_x(void)
{
    return (rand() % 500) + 1280;
}

int rand_ennemy2_x(void)
{
    return (rand() % 500) + 1280;
}

int rand_ennemy1_y(void)
{
    return (rand()% 200 ) + 70;
}

int rand_ennemy2_y(void)
{
    return (rand()% 200 ) + 320;

}

int rand_ennemy1_speed(void)
{
    return (rand() % 10) + 5;
}

int rand_ennemy2_speed(void)
{
    return (rand() % 10) + 5;
}

int rand_tree(void)
{
    return (rand() % 5) + 1;
}
