#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "backg.h"
#include "collision.h"

/////compilation gcc *.h *.c -lm -lSDL -lSDL_image  -lSDL_ttf -lSDL_mixer -o pr0 -g
int main(int argc, char *argv[])
{


SDL_Surface *ecran;
SDL_Surface *back2;//mask
SDL_Surface *back3;//perso

background b,b2;
SDL_Rect perso;
perso.x=0;
perso.y=200;
SDL_Rect per;
per.x=0;
per.y=200;


int cbn=0;//lel animation yaaref li animation saret 
SDL_Event event;
int x,xx=0; //xx lel detect colli
int direction=0;
int vitesse_perso=0; 
Mix_Music *music;

int a=0;
if (SDL_Init (SDL_INIT_VIDEO) == -1)
    {
     printf ("Can't init SDL: %s\n", SDL_GetError ());
     return EXIT_FAILURE;
    }

ecran = SDL_SetVideoMode (CAMERA_W,CAMERA_H, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
back2=IMG_Load("11mask.bmp");//image mask
back3=IMG_Load("C.png");//image de perso
initialiser_background(&b);
initialiser_background(&b2);
b2.img_b=IMG_Load("11mask.bmp");
int lvl=0;
int continuer =0;
while (!continuer)
   {
	afficher_background(b,ecran);
	SDL_PollEvent (&event);
       
            switch (event.type)
            {
	case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
               case SDLK_ESCAPE:
                	continuer = 1;
                		break;

                case SDLK_LEFT:
			xx=detectCollPP(back2,perso);
			printf("perso.x: %d -:per.x %d scroll: %d vitesse_perso:%d\n",perso.x,per.x,b.scroll.x,vitesse_perso);
			direction=1;
			if(xx==0){
                   	vitesse_perso-=5;
			perso.x-=5;
			if(per.x>0){ 
			per.x-=1;
			perso.x-=1;
                  	scrolling(&b,direction,&vitesse_perso);	
				}
			
			
								}
                    break;
                case SDLK_RIGHT:
                    	direction=2;
			printf("perso.x: %d -:per.x %d scroll: %d vitesse_perso:%d\n",perso.x,per.x,b.scroll.x,vitesse_perso);
			xx=detectCollPP(back2,perso); 
			if(xx==0){
			vitesse_perso+=5;
			per.x+=1; //// distance bin awwel l ecran wl perso 
			perso.x=vitesse_perso+per.x;
			if(b.scroll.x>3000-800){
			lvl=+1;
			b.scroll.x=0;
			printf("per.x=%d\n",per.x);
			perso.x=per.x;
			vitesse_perso=0;}
                     	scrolling(&b,direction,&vitesse_perso);
			if(lvl==1){//yaani kamel l background loula 
			if(cbn==0){
			animerBackground(&b,ecran);
			cbn=1;///l animation saret
						}

			}	   	
			}


                    break;



               case SDLK_UP:
		    xx=detectCollPP (back2,perso);
		    direction=3;
		  
		    printf("a: %d\n",b.scroll.y);		
		    printf("perso: x:%d y:%d scroll: %d\n",perso.x,perso.y,b.scroll.x);
			
		    if(xx==0)
                    { 
		    if(perso.y>=80){//110
                    perso.y-=5;
                    per.y-=5;}
		    scrolling(&b,direction,&vitesse_perso);	                    
                    }   
		 
                    break;


               case SDLK_DOWN:
		    xx=detectCollPP (back2,perso);
                    printf("perso: x:%d y:%d scroll: %d\n",perso.x,perso.y,b.scroll.x);
                    direction=0;
		    if(xx==0)
		{
		    if(perso.y<200){
                    perso.y+=5;
                    per.y+=5;}
		    scrolling(&b,direction,&vitesse_perso);   	
		  }
                    break;

}///switch2
////////////////////////besh l perso yarjaa wahdoou lel 9aaa3 (gravite)

		
		case SDL_KEYUP:
                if(event.key.keysym.sym==SDLK_UP)
                {
		  if(xx==0)
                    { 
		//b.scroll.y=0;
		if(perso.y<200){
			perso.y+=1;
			per.y+=1;}}
		printf("b.scroll.y: %d\n",b.scroll.y);
                   }
		else if(event.key.keysym.sym==SDLK_DOWN)
                {

  if(xx==0)
                    { 
	
		if(perso.y<200){
			perso.y+=1;
			per.y+=1;}
	//b.scroll.y=0;
}
                   

}


		else if(event.key.keysym.sym==SDLK_LEFT)
                {

  if(xx==0)
                    { 
		if(perso.y<200){
			perso.y+=1;
			per.y+=1;}}
                   }

	        else if(event.key.keysym.sym==SDLK_RIGHT)
                {

  if(xx==0)
                    { 
		if(perso.y<200){
			perso.y+=1;
			per.y+=1;}}
                   }
break;///break taa case lkbira 
}/////swtchloula			
afficher_background(b,ecran);
SDL_BlitSurface(back3,NULL,back2,&perso);///l peso fl back 2
SDL_BlitSurface(back3,NULL,ecran,&per);///perso
SDL_Flip (ecran);


}/////while

SDL_FreeSurface(ecran);

}
