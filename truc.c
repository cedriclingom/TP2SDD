/*----------------------------------------------------------------------------------------------------*/
/*                                              truc.c                                                */
/*                                                                                                    */
/* Role : Définition des fonctions et procédures permettant de générer toutes les permutations d'un   */
/*        ensemble de valeurs de manière récursive et de manière itérative.                           */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/







#include "./truc.h"













/*----------------------------------------------------------------------------------------------------*/
/* LectureTableau    Permet d'entrer les vaeurs qui vont etre permuter dans le tableau.               */
/*                                                                                                    */
/* En entrée :             tab - Pointeur sur un tableau de valeurs.                                  */
/*                      taille - La taille du tableau.                                                */
/*                 CodeLecture - Pointeur sur la case contenant une valeur permettant de déterminer   */
/*                               si lecture à reussit ou pas.                                         */
/*                                                                                                    */
/* En sortie :     CodeLecture - Pointeur sur la case contenant une valeur permettant de déterminer   */
/*                               si lecture à reussit ou pas.                                         */
/*                                                                                                    */
/* Variable(s) locale(s) :     i - Variable servant de compteur dans la boucle.                       */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/




void LectureTableau(objet_t * tab, int taille, int * CodeLecture)
{

  int i;

  printf("Veuillez les éléments à permuter dans le tableau.\n");

  for(i=0; (i < taille) && (*CodeLecture); ++i)
    {

      printf("Veuillez entrer l'élément %d\n", i + 1);

      *CodeLecture = scanf("%d", tab + i);

    } 

}



/*----------------------------------------------------------------------------------------------------*/
/* AfficherTableau    Affiche les valeurs contenu dans le tableau.                                    */
/*                                                                                                    */
/* En entrée :        tab - Pointeur sur un tableau de valeurs.                                       */
/*                 taille - La taille du tableau.                                                     */
/*                                                                                                    */
/* En sortie :     Rien en sortie.                                                                    */
/*                                                                                                    */
/* Variable(s) locale(s) :     j - Variable servant de compteur dans la boucle.                       */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/





void AfficherTableau(objet_t * tab, int taille)
{

  int j;

  for(j=0; j < taille; ++j)
    {
      
      printf("%d\t", tab[j]);
      
    }
  
  printf("\n");

}








/*----------------------------------------------------------------------------------------------------*/
/* echanger          Fait l'échange entre deux valeurs.                                               */
/*                                                                                                    */
/* En entrée :     a - Pointeur sur la première valeur.                                               */
/*                 b - Pointeur sur la deuxième valeur.                                               */
/*                                                                                                    */
/* En sortie :     a - Pointeur sur la première valeur.                                               */
/*                 b - Pointeur sur la deuxième valeur.                                               */
/*                                                                                                    */
/* Variable(s) locale(s) :     temp - Servant de variable temporaire pour l'échange.                  */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/





void echanger(objet_t * a, objet_t * b)
{

  objet_t temp;
  
  temp = *a;

  *a = *b;

  *b = temp;

}








/*----------------------------------------------------------------------------------------------------*/
/* TrucRecursive        Donne toutes les permutation des valeurs contenu dans le tableau.             */
/*                                                                                                    */
/* En entrée :       i - Servant dans la condition d'affichage et d'initialisation de boucle.         */
/*                   n - La taille du tableau.                                                        */
/*                 tab - Pointeur sur le tableau de valeurs devrant etre permuter.                    */
/*                                                                                                    */
/* En sortie :     Rien en sortie.                                                                    */
/*                                                                                                    */
/* Variable(s) locale(s) :    j - Variable servant de compteur de boucle.                             */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/





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
	  
	  echanger(tab + (i-1), tab + (j-1));
	  
	  TrucRecursive(i + 1, n, tab);
	  
	  echanger(tab + (i-1), tab + (j-1));
	  
	}
    }
}








/*----------------------------------------------------------------------------------------------------*/
/* TrucIterative        Donne toutes les permutation des valeurs contenu dans le tableau.             */
/*                                                                                                    */
/* En entrée :      i - Indice de départ dans le tableau.                                             */
/*                  n - La taille  du tableau.                                                        */
/*                tab - Pointeur sur le tableau des valeurs.                                          */
/*                                                                                                    */
/* En sortie :    Rien en sortie.                                                                     */
/*                                                                                                    */
/* Variable(s) locale(s) :    indice_i - Variable servant de condition de boucle.                     */
/*                            indice_j - Variable servant de condition de boucle.                     */
/*                                 fin - Variable contenant vrai pour dire la pile vide donc nous     */
/*                                       avons donner toute les permutations.Par contre faux veux     */
/*                                       la pile n'est pas encore vide nous avons pas donné toute les */
/*                                       les permutations.                                            */
/*                                pile - Pointeur sur la structure de pile.                           */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/





void TrucIterative(int i, int n, objet_t * tab)
{
  
  objet_t indice_i, indice_j;
  
  enum BOOL fin;

  pile_t * pile;

  indice_i = i;
  
  indice_j = i;

  fin = faux;

  pile = InitialisationPile(2*(n-1));

  if(pile != NULL)                                       /*pile alloué et bien initialiser*/
    {

      while(!fin)
	{

	  while((indice_i < n) && (indice_j <= n))
	    {
	      
	      echanger(tab + (indice_i - 1), tab + (indice_j - 1));

	      empiler(pile, indice_i);

	      empiler(pile, indice_j);

	      ++indice_i;

	      indice_j = indice_i;

	    }

	  if(indice_i == n)
	    {

	      AfficherTableau(tab, n);

	    }

	  EstVide(pile, &fin);                                       /*vérifie si la pile est vide*/

	  if(!fin)
	    {

	      indice_j = depiler(pile);

	      indice_i = depiler(pile);

	      echanger(tab + (indice_i - 1), tab + (indice_j -1));

	      ++indice_j;

	    }
	}

      LibererPile(&pile);

    }

}

