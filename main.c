#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "es.h"

int main(){
Ennemy e;
box b;
int x=1;
int sp=200;
//intialisation//
int continuer=1;
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
SDL_Surface *screen=NULL;
SDL_Surface *image=NULL;
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("impossible d'initialiser sdl :%s",SDL_GetError());
return 1;
}
screen =SDL_SetVideoMode(1200,800,32,SDL_HWSURFACE |SDL_DOUBLEBUF|SDL_RESIZABLE);
if(screen==NULL)
{ printf("Unable to set video mod :%s\n",SDL_GetError());
return 1;
}
//image=IMG_Load("EST.png");
initialiser(&e,"2.png");
while(continuer)
{
   	
afficher(&e,screen,image);
animation(&e,screen);
deplacement(&e,&sp,&x,screen);
if (collision(&b,&e)==1)
	break;

SDL_Event event;

while(SDL_PollEvent(&event))
{

switch(event.type)
{
case SDL_QUIT://croix rouge quitter
continuer=0;
break;



}

}
}
return 0;
}
