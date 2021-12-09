#include<stdio.h>
#include<stdlib.h>

#define SIZE 50
int main()
{
	int f[50],p,i,j,k,a,st,len,n;
	char choice='n';

	for( i=0 ; i<SIZE ; i++ )
		f[i] = 0;
	printf("Enter how many blocks that are already allocated : ");
	scanf("%d",&p);

	if(p!=0)
	{
		printf("Enter the block numbers that are already allocated : ");
		for( i=0 ; i<p ; i++ )
		{
			scanf("%d",&a);
			f[a]=1;
		}
	}
	
	
	do
	{
		printf("Enter the starting index block & length : ");
		scanf("%d%d",&st,&len);
		k=len;
		for( j=st ; j<(k+st) ; j++)
		{
			if( f[j]==0)
			{
				f[j]=1;
				printf("%d -> %d\n",j,f[j]);
			}
			else
			{
				printf("%d -> file is already allocated\n",j);
				k++;
			}
		}
		printf("Do you want to continue (y/n) : ");
		scanf("%d",&i);
		scanf("%c",&choice);
	}while(choice == 'y');
	return 0;
}
