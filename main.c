#include "./truc.h"




int main()
{

  int choix, continuer;

  objet_t tab[4];

  do
    {
    
       printf("Que voulez vous faire?\n\n");
       
       printf("1. Tester les fonctions et procédures de pile.\n");
       
       printf("2. Exécuter la version récursive de TRUC.\n");

       printf("3. Exécuter la version itérative de TRUC.\n");
       
       scanf("%d", &choix);
       
       switch(choix)
	 {
	   
	 case 1:
	   
	   TestFonctionPile();
	   
	   break;
	   
	 case 2:
	   
	   tab[0] = 1;
	   
	   tab[1] = 2;
	   
	   tab[2] = 3;

	   tab[3] = 4;
	   
	   TrucRecursive(0, 3, tab);		
	   
	   break;

	 case 3:

	   tab[0] = 1;
	   
	   tab[1] = 2;
	   
	   tab[2] = 3;

	   tab[3] = 4;
	   
	   TrucIterative(0, 3, tab);		
	   
	   break;
	   
	 default:
	   
	   printf("Vous avez fait le mauvais choix.\n");
	   
	 }
       
       printf("Voulez vous continuer? 1 = OUI   0 = NON\n\n");
       
       scanf("%d", &continuer);

    }while(continuer);
  
  return 0;
  
}
