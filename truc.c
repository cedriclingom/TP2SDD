#include "./truc.h"











void AfficherTableau(objet_t * tab, int taille)
{

  int j;

  for(j=0; j <= taille; j++)
    {
      
      printf("%d\t", tab[j]);
      
    }
  
  printf("\n");

}





void echanger(objet_t * a, objet_t * b)
{

  objet_t temp;
  
  temp = *a;

  *a = *b;

  *b = temp;

}



void TrucRecursive(int i, int n, objet_t * tab)
{

  int j;
  
  if(i == n)
    {
      
      AfficherTableau(tab, n);
      
    }
  else
    {
      
      for(j = i; j <= n; ++j)
	{
	  
	  echanger(tab + i, tab + j);
	  
	  TrucRecursive(i + 1, n, tab);
	  
	  echanger(tab + i, tab + j);
	  
	}
    }
}








void TrucIterative(int i, int n, objet_t * tab)
{
  
  objet_t indice_i, indice_j;
  
  enum BOOL fin;

  pile_t * pile;

  indice_i = i;
  
  indice_j = i;

  fin = faux;

  pile = InitialisationPile(TAILLE_PILE);

  if(pile != NULL)
    {

      while(!fin)
	{

	  while((indice_i < n) && (indice_j <= n))
	    {
	      
	      echanger(tab + indice_i, tab + indice_j);

	      empiler(pile, indice_i);

	      empiler(pile, indice_j);

	      ++indice_i;

	      indice_j = indice_i;

	    }

	  if(indice_i == n)
	    {

	      AfficherTableau(tab, n);

	    }

	  EstVide(pile, &fin);

	  if(!fin)
	    {

	      indice_j = depiler(pile);

	      indice_i = depiler(pile);

	      echanger(tab + indice_i, tab + indice_j);

	      ++indice_j;

	    }
	}

      LibererPile(&pile);

    }

}
