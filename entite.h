# Jeu_SDL
Jeu 2D
#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct{
SDL_Surface *sprite;
SDL_Rect pos;
int frame;
SDL_Rect Right[4];
}Ennemy;



typedef struct
{
int x;
int y;
int w;
int h;
}box;

void initialiser(Ennemy *e,char *file_name);
void Sprit(Ennemy *e,int *y );
void afficher(Ennemy *e,SDL_Surface *screen,SDL_Surface *image);
void animation(Ennemy *e,SDL_Surface *screen);
void deplacement(Ennemy *e,int *sp,int *x,SDL_Surface *screen);


int collision(box *b,Ennemy *e);


#endif // FONCTION_H_INCLUDED

