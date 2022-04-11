
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "backg.h"



void initialiser_background(background *b)
{
b->img_b=IMG_Load("11.bmp");
b->position_b.x=0;
b->position_b.y=-10;
b->scroll.x=0;
b->scroll.y=0;
b->scroll.w=3000;
b->scroll.h=380;



if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

b->music=Mix_LoadMUS("music.mp3");

Mix_PlayMusic(b->music, -1);


}

void afficher_background(background b, SDL_Surface *ecran)
{
SDL_BlitSurface(b.img_b,&b.scroll,ecran,&b.position_b);//background orgl
}



void scrolling(background *b, int dire , int *pasavancement)
{

	 if(dire==2)//droite
	{
		b->scroll.x=*pasavancement;
	}	
	
	else if(dire==1)//gauche
	{	
		b->scroll.x=*pasavancement;						
	}
    
	else if(dire==3)//
	{
		
		b->scroll.y=-10;

		
	}

	else if (dire == 0)
	{
		b->scroll.y=+10;
              
	}

	
}

void animerBackground(background *e,SDL_Surface *ecran){
for(int j=0;j<5;j++)
{	
switch (j)
{
case 0:
	SDL_FreeSurface(e->img_b);
	e->img_b=IMG_Load("11night0.bmp");	
break;
case 1:
	SDL_FreeSurface(e->img_b);
	e->img_b=IMG_Load("11night1.bmp");
case 2:
	SDL_FreeSurface(e->img_b);
	e->img_b=IMG_Load("11night2.bmp");
break;
case 3:
	SDL_FreeSurface(e->img_b);
	e->img_b=IMG_Load("11night3.bmp");
break;
case 4:
	SDL_FreeSurface(e->img_b);
	e->img_b=IMG_Load("11night4.bmp");
break;

}
SDL_BlitSurface(e->img_b,&e->scroll,ecran,NULL);
SDL_Flip (ecran);
SDL_Delay(100);}
}


