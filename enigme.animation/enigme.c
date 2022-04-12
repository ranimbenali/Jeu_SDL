#include "enigme.h"



void generer_enigme(enigme *e){
	e->pos_selected=0;
	e->background= IMG_Load("img/background.png");
	e->button= IMG_Load("img/button.png");
	e->button_s= IMG_Load("img/button_s.png");

	  //animation 
	e->pos_timer.x=772;
	e->pos_timer.y=50;
	e->num_animation=0;
	e->time_over=0;
	e->timer[0]=IMG_Load("timer0.png");
	e->timer[1]=IMG_Load("timer1.png");
	e->timer[2]=IMG_Load("timer2.png");
	e->timer[3]=IMG_Load("timer3.png");
	e->timer[4]=IMG_Load("timer4.png");
	e->timer[5]=IMG_Load("timer5.png");
	e->timer[6]=IMG_Load("timer6.png");
	e->timer[7]=IMG_Load("timer7.png");
	e->timer[8]=IMG_Load("timer8.png");
	e->timer[9]=IMG_Load("timer9.png");
	e->timer[10]=IMG_Load("timer10.png");
	e->timer[11]=IMG_Load("timer11.png");

	TTF_Init();
	TTF_Font *police = NULL,*police1=NULL;

	SDL_Color couleur = {0,0,0};//noir

	police = TTF_OpenFont("arial.ttf", 30);
	police1 = TTF_OpenFont("arial.ttf", 20);
	SDL_Surface *texte;

	char questionn[300];

	srand(time(NULL));//yet3ada mn question l question aléatoirement
	e->num_question=rand()%4;//random question kol marra

	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%4;
	}

	FILE *fquestion=NULL;
	fquestion=fopen("questions.txt","r+");
	if(fquestion!=NULL){
		int test=1;
		while (fgets(questionn, 300, fquestion) &&(test!=e->num_question)){
			test++;//si c'est pas la question aleatoire
		}
		
		fclose(fquestion);
	}//il cherche le numéro aléatoire et réccupére la question dans une chaine de caractére

	char reponse[50];

	int min,max;
    switch(e->num_question)
    {
    	case 1://q1
    	{
    		min=0;
    		max=2;
    		break;
    	}
    	case 2://q2
    	{
    		min=3;
    		max=5;
    		break;
    	}
    	case 3://q3
    	{
    		min=6;
    		max=8;
    		break;
    	}
    }

	FILE *freponse=NULL;
	freponse=fopen("reponses.txt","r+");
	if(freponse!=NULL){
		int test=0;
		while (fgets((reponse), 50, freponse) &&(test<max)){	//parcour
			//il réccupére les deux réponses fausses
			if(test>=min){
				e->reponses[test-min]=TTF_RenderText_Blended(police1, reponse, couleur);
			}
			test++;
		}	
		fclose(freponse);
	}

	FILE *fvraireponse=NULL;
	fvraireponse=fopen("vraireponses.txt","r+");
	if(fvraireponse!=NULL){
		int test=1;
		while (fgets((reponse), 50, fvraireponse)){
			
			if(test==e->num_question){
				printf("%s\n",reponse);
				e->reponses[2]=TTF_RenderText_Blended(police1, reponse, couleur);
			}// ecrire le texte sur surface
			test++;
		}
		fclose(freponse);
	}

	srand(time(NULL));
	e->positionVraiReponse=rand()%4;

	while(e->positionVraiReponse==0){
		srand(time(NULL));
		e->positionVraiReponse=rand()%4;
	}//mettre la bonne réponse à une position aléatoire (entier)
	printf("%d\n",e->positionVraiReponse);

	e->question = TTF_RenderText_Blended(police, questionn, couleur);

	e->pos_question.x=320; 
	e->pos_question.y=230;

	e->pos_reponse1.x=475;
	e->pos_reponse1.y=422;

	e->pos_reponse2.x=277;
	e->pos_reponse2.y=548;

	e->pos_reponse3.x=666;
	e->pos_reponse3.y=548;

	e->pos_reponse1txt.x=475+50;
	e->pos_reponse1txt.y=422+30;

	e->pos_reponse2txt.x=277+50;
	e->pos_reponse2txt.y=548+30;

	e->pos_reponse3txt.x=666+50;
	e->pos_reponse3txt.y=548+30;


	Mix_AllocateChannels(20);
	SDL_WM_SetCaption("Enigme",NULL);
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){

	}
	e->sound=Mix_LoadWAV("clic.wav");
	Mix_VolumeMusic(MIX_MAX_VOLUME);

}

void afficher_enigme(enigme *e,SDL_Surface *ecran){

	SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);
	SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
	SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
	SDL_Flip(ecran);	
}


void verify_enigme(enigme *e,SDL_Surface *ecran)
{       
        
	SDL_Rect pos={160,330};
	if(e->positionVraiReponse==e->pos_selected)
	{

		SDL_Surface *win;
		win=IMG_Load("img/youwin.png");
		SDL_BlitSurface(win, NULL, ecran,&pos);
		SDL_Flip(ecran);

	}

     //time over
	else if (e->pos_selected==-1)
	{       
                
		SDL_Surface *lost;
		lost=IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran); 
		
	}


	else 
	{       
                
		SDL_Surface *lost;
		lost=IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran);
	}


	SDL_Delay(200);//attente pour éviter l'encombrement
}



void animer (enigme *e){
		e->num_animation++;

		if(e->num_animation==12){
			e->num_animation=0;
			e->time_over=1;	
		}	

}
