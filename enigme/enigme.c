#include "enigme.h"



void generer_enigme(enigme *e){
	e->pos_selected=0;//initialement aucune réponse selectionné
	e->background= IMG_Load("img/background.png");//image de back
	e->button= IMG_Load("img/button.png");//boutton avant animation
	e->button_s= IMG_Load("img/button_s.png");//boutton aprés animation

	TTF_Init();
	TTF_Font *police = NULL,*police1=NULL;

	SDL_Color couleur = {0,0,0};//noir

	police = TTF_OpenFont("arial.ttf", 30);
	police1 = TTF_OpenFont("arial.ttf", 20);
	SDL_Surface *texte;

	char questionn[300];//chaine de caractére qui stocke les questions

	srand(time(NULL));//yet3ada mn question l question aléatoirement
	e->num_question=rand()%4;//random question à chaque fois

	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%4;
	}///random question à chaque fois et parcours de num=0

	FILE *fquestion=NULL;
	fquestion=fopen("questions.txt","r+");
	if(fquestion!=NULL){
		int test=1;
		while (fgets(questionn, 300, fquestion) &&(test!=e->num_question)){
			test++;//si c'est pas la question aleatoire
		}
		
		fclose(fquestion);//mettre les questions lus de fquestion dans la chaine de caractére
	}

	char reponse[50];

	int min,max;
    switch(e->num_question)
    {
    	case 1://q1
    	{
    		min=0;
    		max=2;//0,1,2
    		break;
    	}
    	case 2://q2
    	{
    		min=3;
    		max=5;//3,4,5
    		break;
    	}
    	case 3://q3
    	{
    		min=6;
    		max=8;//6,7,8
    		break;
    	}
    }

	FILE *freponse=NULL;
	freponse=fopen("reponses.txt","r+");
	if(freponse!=NULL){
		int test=0;
		while (fgets((reponse), 50, freponse) &&(test<max)){	//parcour
			
			if(test>=min){
				e->reponses[test-min]=TTF_RenderText_Blended(police1, reponse, couleur);
			}
			test++;
		}	
		fclose(freponse);//récupération des deux réponses de freponse(les fausses réponses)
	}


	FILE *fvraireponse=NULL;
	fvraireponse=fopen("vraireponses.txt","r+");
	if(fvraireponse!=NULL){
		int test=1;
		while (fgets((reponse), 50, fvraireponse)){
			
			if(test==e->num_question){
				printf("%s\n",reponse);
				e->reponses[2]=TTF_RenderText_Blended(police1, reponse, couleur);
			}
			test++;
		}
		fclose(freponse);
	}//récupérer la bonne réponse et la mettre à cette surface

	srand(time(NULL));
	e->positionVraiReponse=rand()%4;

	while(e->positionVraiReponse==0){
		srand(time(NULL));
		e->positionVraiReponse=rand()%4;
	}//mettre la bonne réponse à une position aléatoire (entier)
	printf("%d\n",e->positionVraiReponse);

	e->question = TTF_RenderText_Blended(police, questionn, couleur);

	e->pos_question.x=270;//position de la question 
	e->pos_question.y=270;

	e->pos_reponse1.x=375;//position rep1
	e->pos_reponse1.y=522;

	e->pos_reponse2.x=177;//position rep2
	e->pos_reponse2.y=648;

	e->pos_reponse3.x=566;//position rep3
	e->pos_reponse3.y=651;

	e->pos_reponse1txt.x=375+50;//position texte rep1
	e->pos_reponse1txt.y=522+30;

	e->pos_reponse2txt.x=177+50;//position texte rep2
	e->pos_reponse2txt.y=648+30;

	e->pos_reponse3txt.x=566+50;//position texte rep3
	e->pos_reponse3txt.y=651+30;


	Mix_AllocateChannels(20);
	SDL_WM_SetCaption("Enigme1",NULL);
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){

	}
	e->sound=Mix_LoadWAV("clic.wav");
	Mix_VolumeMusic(MIX_MAX_VOLUME);

}

void afficher_enigme(enigme *e,SDL_Surface *ecran){

	SDL_BlitSurface(e->background, NULL, ecran, NULL);//back
	SDL_Flip(ecran);//mise à jour
	SDL_BlitSurface(e->question, NULL, ecran, &e->pos_question);//affichage de la surface question
	SDL_Flip(ecran);

	switch(e->positionVraiReponse){
		case 1:{

			switch(e->pos_selected){
			case 1:
			{
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);//boutton1 seléctionné en bleu 
                                                //les autres en mode normal

				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);//mettre(afficher) la bonne réponse déja préparée dans la pos1
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse2);//a
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);//c1
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse3);//a
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);//c1
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default://quelconque
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);//initialement pas d'animation(bouttons normales)

				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);//c1
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}	
			break;
		}
		case 2:{
			switch(e->pos_selected){
			case 1:
			{
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse1);//a
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);//c2
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse2);//a
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);//c2
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse3);//a
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);//c2
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);//c2
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}
			break;
		}
		case 3:{
			switch(e->pos_selected){
			case 1:
			{
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse1);//a
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);//c3
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse2);//a
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);//c3
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse3);//a
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);//c3
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);//c3
				SDL_Flip(ecran);
				}
			}

			break;
		}
	}
	
	SDL_Delay(100);//attente
}

void free_enigme(enigme *e){//libérer les surfaces utilisées
	SDL_FreeSurface(e->background);
	SDL_FreeSurface(e->question);
	SDL_FreeSurface(e->reponses[0]);
	SDL_FreeSurface(e->reponses[1]);
	SDL_FreeSurface(e->reponses[2]);
	SDL_FreeSurface(e->button);
	SDL_FreeSurface(e->button_s);
}

void verify_enigme(enigme *e,SDL_Surface *ecran)
{       
        
	SDL_Rect pos={160,330};//x,y
	if(e->positionVraiReponse==e->pos_selected)//si la rép choisie est la bonne rép
	{
		printf("You win\n");
                
		SDL_Surface *win;
		win=IMG_Load("img/youwin.png");
		SDL_BlitSurface(win, NULL, ecran,&pos);
		SDL_Flip(ecran);//affichage d'image de win

	}
	else
	{       
                
		SDL_Surface *lost;
		lost=IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran);//affichage de lost
		printf("You lost\n");
	}
	SDL_Delay(2000);
}
