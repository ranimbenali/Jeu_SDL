#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <time.h>
typedef struct 
{
	int id;
	char name[50];
	int maxHP;
	int maxAP;
	int currentHP;
	int currentAP;
	SDL_Surface* upImage[4];
	SDL_Surface* downImage[4];
	SDL_Surface* rightImage[4];
	SDL_Surface* leftImage[4];
	SDL_Surface* battleImage;
}personnage;
void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void deplacerPerso (Personne *p, , int dt);
void animerPerso (Personne* p);
void saut (Personne* p);
