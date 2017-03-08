

#ifndef PILE_H
#define PILE_H

#define TAILLE_MAXX 100

typedef int obj;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pile
{
    int taille;
    int sommet;
    obj* tab;
} pile_t;

pile_t * initialisation(int );
void empiler(pile_t **, int, int * );
int sommet_pile(pile_t *);
int depiler(pile_t **);
void liberer_pile(pile_t **);
void est_vide(pile_t *, int *);

#endif
	


	
