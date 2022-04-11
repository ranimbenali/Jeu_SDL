#define CAMERA_W 800   ///// la largeur/hauteur du screen dans setvideomod
#define CAMERA_H 600
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


typedef struct
{
SDL_Surface *img_b;
SDL_Rect position_b; 
SDL_Rect scroll; 
Mix_Music *music;
}background;

void initialiser_background(background *b);
void afficher_background(background b, SDL_Surface *ecran);
void animerBackground(background *e,SDL_Surface *ecran);
void scrolling(background *b,int dire,int *pasavancement);



