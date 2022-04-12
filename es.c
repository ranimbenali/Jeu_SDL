#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "es.h"



void initialiser(Ennemy *e,char *file_name)
{
e->pos.x=780;
e->pos.y=600;
e->frame=0;
e->sprite=IMG_Load(file_name);
}


void Sprit(Ennemy *e,int *y )
{
int i;

for(i=0;i<4;i++){
e->Right[i].x=100*i; //100
e->Right[i].y=*y; //100
e->Right[i].w=100; //100
e->Right[i].h=100; //100
}
}



void afficher(Ennemy *e,SDL_Surface *screen,SDL_Surface *image)
{
image=IMG_Load("EST.png");
SDL_Rect positionEcran;
positionEcran.x=0;
positionEcran.y=0;
SDL_BlitSurface(image,NULL,screen,&positionEcran);
SDL_BlitSurface(e->sprite,&(e->Right[e->frame]),screen,&e->pos);

}

void animation(Ennemy *e,SDL_Surface *screen)
{
	//Sprit(e,&(*sp));
SDL_BlitSurface(e->sprite,&(e->Right[e->frame]),screen,&e->pos);
(e->frame)++;
if(e->frame>=4)
{
e->frame=0;
}
SDL_Delay(500);	
}


void deplacement(Ennemy *e,int *sp,int *x,SDL_Surface *screen)
{
	Sprit(e,&(*sp));
if(*x==1)
	{
		if(e->pos.x<900)
		{
			e->pos.x+=10;
			*sp=200; //200
		}
		else
		{
			*x=-1;

		}
		
    }

else
if(*x==-1)
if(e->pos.x>0)
		{
			e->pos.x-=10;
			*sp=100; //100
		}
		else
		{
			*x=1;
		}

SDL_Flip(screen);
}

int collision(box *b,Ennemy *e)
{
	b->x=698;
	b->y=600;
	b->w=60;
	b->h=75;


	if(e->pos.x>b->x+b->w || b->x > e->pos.x+e->pos.w || b->y + b->h < e->pos.y || b->y > e->pos.y + e->pos.h)
	{
		return 0;
	}
	else
		return 1;

}
