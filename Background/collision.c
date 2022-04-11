#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "collision.h"
#include <time.h>

SDL_Color GetPixel(SDL_Surface *background_mask,int x,int y)
{

SDL_Color color;
Uint32 col=0;
char* pPosition=(char* ) background_mask->pixels;
pPosition+= (background_mask->pitch * y);
pPosition+= (background_mask->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,background_mask->format->BytesPerPixel);
SDL_GetRGB(col,background_mask->format, &color.r, &color.g, &color.b);
return (color);
}



 int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect Personnage){
  SDL_Color colobs;
  SDL_Color colgotten;
  SDL_Rect Pos[8];
  int collision = 0, i = 0;




colobs.r=255;
colobs.g=255;
colobs.b=255;

  Pos[0].x = Personnage.x;

  Pos[0].y = Personnage.y;

  Pos[1].x = Personnage.x + (Personnage.w /2);

  Pos[1].y = Personnage.y;

  Pos[2].x = Personnage.x + Personnage.w;

  Pos[2].y = Personnage.y;

  Pos[3].x = Personnage.x;

  Pos[3].y =  Personnage.y + (Personnage.h/2);

  Pos[4].x = Personnage.x;

  Pos[4].y = Personnage.y + Personnage.h;

  Pos[5].x = Personnage.x + (Personnage.w /2);

  Pos[5].y =  Personnage.y + Personnage.h;

  Pos[6].x = Personnage.x + Personnage.w;

  Pos[6].y = Personnage.y + Personnage.h;

  Pos[7].x = Personnage.x + Personnage.w;

  Pos[7].y = Personnage.y + (Personnage.h/2);



while ((i<=7) && (collision == 0)) {

colgotten = GetPixel(BackgroundMasque,Pos[i].x,Pos[i].y);

printf("position %d- x: %d y: %d R:%d G:%d B:%d\n",i,Pos[i].x,Pos[i].y,colgotten.r,colgotten.g,colgotten.b);

    if ((colobs.r == colgotten.r) &&  (colobs.b == colgotten.b) &&

  (colobs.g == colgotten.g)){
      collision = 1;

    }
	else{

      i++;

    }

}

return collision;
}

