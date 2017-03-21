/*----------------------------------------------------------------------------------------------------*/
/*                                              main.c                                                */
/*                                                                                                    */
/* Role : La fonction principale faisant appelle à des fonctions qui test les fonctions, qui donne    */
/*        qui donne toute les permutations de manière récursive et aussi toute les permutation de     */
/*        manière itérative.Ces fonctions ne sont pas appelé toutes en meme temps mais plutot au      */
/*        choix grace au ménu.                                                                        */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/







#include "./truc.h"




int main()
{

  int choix, continuer, CodeLecture = 1;

  objet_t tab[TAILLETAB];

  do
    {
    
       printf("Que voulez vous faire?\n\n");
       
       printf("1. Tester les fonctions et procédures de pile.\n");
       
       printf("2. Exécuter la version récursive de TRUC.\n");

       printf("3. Exécuter la version itérative de TRUC.\n");
       
       CodeLecture = scanf("%d", &choix);

       if(CodeLecture)                                                  /*si la lecture c'est bien passé*/
	 {
	   
	   switch(choix)
	     {
	       
	     case 1:
	       
	       TestFonctionPile(&CodeLecture);
	       
	       if(!CodeLecture)
		 {
		   
		   printf("Erreur de lecture!\n");
		   
		 }
	       
	       break;
	       
	     case 2:
	       
	       LectureTableau(tab, TAILLETAB, &CodeLecture);

	       if(CodeLecture)
		 {
	       
		   TrucRecursive(1, TAILLETAB, tab);
		 }
	       else
		 {
		   
		   printf("Erreur de lecture.\n");

		 }
	       
	       break;
	       
	     case 3:
	       
	       LectureTableau(tab, TAILLETAB, &CodeLecture);
	       
	       if(CodeLecture)
		 {
		   
		   TrucIterative(1, TAILLETAB, tab);
		 }
	       else
		 {
		   
		   printf("Erreur de lecture.\n");
		   
		 }		
	       
	       break;
	       
	     default:
	       
	       printf("Vous avez fait le mauvais choix.\n");
	       
	     }

	 }
	   
       printf("Voulez vous continuer? 1 = OUI   0 = NON\n\n");
       
       CodeLecture = scanf("%d", &continuer);
	   
    }while(continuer && CodeLecture);
  
  return 0;
  
}
