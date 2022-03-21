#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include"struct.h"
struct background
{
 SDL_Rect bckg;
 SDL_Surface *img;
};
typedef struct background background;
void initBack (background * b);
void aficherBack (SDL_Surface * screen, background b);
void animerBackground( Background * e);
int collisionPP( Personne p, SDL_Surface * Masque);
void scrolling (SDL_Rect * b, int direction ,int pasAvancement);


#endif // BACKGROUND_H_INCLUDED
