/*----------------------------------------------------------------------------------------------------*/
/*                                              truc.h                                                */
/*                                                                                                    */
/* Role : Déclaration des directives de compilation et prototypes.                                    */
/*                                                                                                    */
/*----------------------------------------------------------------------------------------------------*/





#ifndef DERECURSIFICATION_TRUC_H	
#define DERECURSIFICATION_TRUC_H








#include "./pile.h"








void AfficherTableau(objet_t *, int);

void echanger(objet_t *, objet_t *);

void TrucRecursive(int, int, objet_t *);

void TrucIterative(int, int, objet_t *);






#endif


