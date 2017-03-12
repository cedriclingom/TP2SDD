
#include "./pile.h"






pile_t * InitialisationPile (int TaillePile)
{

	pile_t * pile = (pile_t *)malloc(sizeof(pile_t));

	if(pile != NULL)	                                                /* si l'allocation est reussite*/
	{
		pile->taille = TaillePile;				        /*fixer la taille de la pile*/

		pile->NumeroSommet = -1;

		pile->tab = (objet_t *)malloc(TaillePile * sizeof(objet_t));	/* allouer un tableau de donnees de taille TaillePile */

		if(pile->tab == NULL)						/* si l'allocation de tab est echouée*/
		  {
		    
		    free(pile);							/* on libere la Pile */

		    pile = NULL;

		  }
	}

	return pile;
}		
		

		
		
void EstPleine(pile_t * pile, enum BOOL * pleine) 
{
  
  *pleine = vrai;                                        /*suposons qu'elle est pleine*/

  if(pile->NumeroSommet < ((pile->taille)-1))	         /*si la pile n'est pas pleine */
    {
      *pleine = faux;

    }

}

  
void empiler(pile_t * pile, int val)
{	

	  (pile->tab)[pile->NumeroSommet + 1] = val;             /*ajouter la valeur à la pile */

	  ++pile->NumeroSommet;	                                 /*augmenter le nombre d'element de la pile */

}



void EstVide(pile_t * pile , enum BOOL * vide)
{
	*vide = faux;	

	if(pile->NumeroSommet == -1)
	  {

	    *vide = vrai ;

	  }

}



objet_t depiler(pile_t * pile)
{
  objet_t sommet = (pile->tab)[pile->NumeroSommet];   /* sauvegarder le sommet*/

  --pile->NumeroSommet;                             /*deminuer le nombre d'element de la pile */

  return sommet;

}



objet_t SommetPile(pile_t * pile)
{

	return (pile->tab)[pile->NumeroSommet];

}




void LibererPile(pile_t ** ppile)
{

  free((*ppile)->tab);	/* désallouer le tab de donnees(implicitement la pile))*/

  free(*ppile);		/* désallouer la structure de pile */

  *ppile = NULL;

}




void AfficherPile(pile_t * pile)
{

  int i;
  
  for(i = pile->NumeroSommet; i > -1; --i)
    {

      printf("%d\n", (pile->tab)[i]);

    }

}


void TestFonctionPile()
{

  int choix, continuer;

  objet_t valeur;

  pile_t * pile = InitialisationPile(7);
  
  enum BOOL vide, pleine;
 
  
  if(pile != NULL)
    {
      
      do
	{
	  
	  printf("Veuillez faire un choix!\n");
	  
	  printf("1. Tester si la pile est vide.\n");
	  
	  printf("2. Tester si la pile est pleine.\n");
	  
	  printf("3. Empiler.\n");
	  
	  printf("4. Depiler.\n");
	  
	  printf("5. Sommet de la pile.\n");
	  
	  scanf("%d", &choix);
	  
	  switch(choix)
	    {
	      
	    case 1:
	      
	      EstVide(pile,&vide);
	      
	      if(vide)
		{
		  
		  printf(" La pile est vide. ");
		  
		}
	      else
		{
		  
		  printf("La pile n'est pas vide.\n");
		  
		}
	      
	      break;
	      
	    case 2:
	      
	      EstPleine(pile,&pleine);
	      
	      if(pleine)
		{
		  
		  printf(" La pile est pleine. ");
		  
		}
	      else
		{
		  
		  printf("La pile n'est pas pleine.\n");
		  
		}
	      
	      break;
	      
	    case 3:
	      
	      EstPleine(pile, &pleine);
	      
	      if(!pleine)
		{
		  printf("Le cotenu de la pile avant d'empiler.\n");
		  
		  AfficherPile(pile);
		  
		  printf("Veuillez entrer la valeur à empiler\n");
		  
		  scanf("%d", &valeur);
		  
		  empiler(pile, valeur);

		  printf("Le cotenu de la pile après avoir empiler.\n");
	      
		  AfficherPile(pile);
		  
		}
	      else
		{
		  
		  printf("La pile est pleine.\n");
		  
		}
	      
	      break;
	      
	    case 4:
	      
	      EstVide(pile, &vide);
	      
	      if(!vide)
		{

		  printf("Le cotenu de la pile avant d'empiler.\n\n");
		  
		  AfficherPile(pile);
		  
		  printf("La valeur dépiler est:\n %d\n\n", depiler(pile));

		  printf("Le cotenu de la pile après avoir depiler.\n\n");
	      
		  AfficherPile(pile);
		  
		}
	      else
		{
		  
		  printf("La pile est vide.\n");
		  
		}
	      
	      break;
	      
	    case 5:
	      
	      EstVide(pile, &vide);
	      
	      if(!vide)
		{
		  printf("Le cotenu de la pile avant d'empiler.\n\n");
		  
		  AfficherPile(pile);
		  
		  printf("Le sommet de la pile est:\n %d\n", SommetPile(pile));
		  
		}
	      else
		{
		  
		  printf("La pile est vide.\n");
		  
		}
	      
	      break;
	      
	    default:
	      
	      printf("Veuillez entrer le bon numéro!\n");
	    }
	  
	  printf("\nVoulez-vous continuer?\n Tapez: 1 = Oui  0 = Non\n");
	  
	  scanf("%d", &continuer);
	  
	}while(continuer);
      
      LibererPile(&pile);
      
    }
  
}
