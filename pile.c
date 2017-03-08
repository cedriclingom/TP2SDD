

#ifndef PILE_C
#define PILE_C



#include "./pile.h"


pile_t * initialisation(int taile_pile)
{
	pile_t * Pile = (pile_t *)malloc(sizeof(pile_t));
	if (Pile)													/* si l'allocation est reussite*/
	{
		Pile->taille = taile_pile;								/*fixer la taille de la pile*/
		Pile->tab = (obj *)malloc(taile_pile*(sizeof(obj)));	/* allouer un tableau de donnees de taille taille_pille*/
		if(Pile->tab)											/* si l'allocation du tableau est reussite */
			Pile->sommet = -1;									/* initialisation de la pile à une pile vide */
		else                                                    /* si l'allocation du tableau n'est reussite */
			free(Pile);											/* on désalloue la pile */
	}
	return Pile;
}

void empiler(pile_t ** Ppile, int val , int * ins)
{
	*ins = 0;									       /*initialisation de ins à 0 */
	if((*Ppile)->sommet<(((*Ppile)->taille)-1))	       /*si la pile a un nombre d'element inferieur à sa taille */
	{
		((*Ppile)->tab)[((*Ppile)->sommet) + 1] = val; /*ajouter la valeur à la pile */
		(*Ppile)->sommet = ((*Ppile)->sommet) + 1;	   /*augmenter le nombre d'element de pile */
		* ins = 1;									   /*mettre ins à 1 */
	}
}

int sommet_pile(pile_t * Pile)
{
	return (Pile->tab)[(Pile->sommet)];
}


int depiler(pile_t ** Ppile)
{
	int som = sommet_pile(*Ppile);				/* sauvegarder le sommet*/
	(*Ppile)->sommet = ((*Ppile)->sommet) - 1;  /*deminuer le nombre d'element de la pile */
	return som;
}

void liberer_pile(pile_t ** Ppile)
{
	free((*Ppile)->tab);	/* désallouer le tab de donnees(implicitement la pile))*/
	free(*Ppile);			/* désallouer la structure de pile */
	*Ppile = NULL;
}

void est_vide(pile_t * Pile , int * vide)
{
	*vide = 0;
	if(Pile->sommet == -1)	*vide = 1 ;
}
	
int main()
{
	pile_t * Pile = initialisation(7);
	int ins, vide;
	int som;
	est_vide(Pile,&vide);
	empiler(&Pile,7,&ins);
	empiler(&Pile,14,&ins);
	som = depiler(&Pile);
	printf("\n est vide = %d le ins est %d et le sommet %d le premeier sommet %d \n",vide,ins,sommet_pile(Pile),som);
	liberer_pile(&Pile);	
}



#endif
		
		

		
		
	
