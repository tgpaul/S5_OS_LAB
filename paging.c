#include<stdio.h>
#include<stdlib.h>

int main()
{
	int np,ps,i;
	int *sa;

	printf("Enter the number of pages : ");
	scanf("%d",&np);
	printf("Enter the page size : ");
	scanf("%d",&ps);

	sa = (int *)malloc(2*np);

	for( i=0; i<np; i++ )
	{
		sa[i]= (long)malloc(ps);
		printf("Page %d\tAddress %u\n",i+1,sa[i]);
	}	
	return 0;
}
