#include "./truc.h"











void AfficheTableau(objet_t * tab, int taille)
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

	int j, temp;

	if(i == n)
	{

	  AfficheTableau(tab, n);

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
