/*

#ifndef TRUC_C	
#define TRUC_C
#include "truc.h"


void truc_recursive(int i,int n,int * tab)
{
	int j,temp;
	if(i==n)
	{
		for(j=0;j<n;j++)
						printf("%d\n",tab[j]);
		printf("\n");
	}
	else
	{
		for(j=i-1;j<n;j++)
		{
			temp = tab[i-1];
			tab[i-1] = tab[j];
			tab[j] = temp;
			truc_recursive(i+1,n,tab);
			temp = tab[i-1];
			tab[i-1] = tab[j];
			tab[j] = temp;
		}
	}
}
void main()
{
	int tab[3] = {1,2,3};
	truc_recursive(1,3,tab);
}



#endif
*/		
