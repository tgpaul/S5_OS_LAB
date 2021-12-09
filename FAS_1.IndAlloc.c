#include<stdio.h>
#include<stdlib.h>

void main()
{
	int f[50],i,k,j,inde[50],n,count=0,p;
	char c='y';

	for( i=0 ; i<50 ; i++)
		f[i]=0;

	x:
	printf("Enter index block : ");
	scanf("%d",&p);

	if(f[p]==0)
	{
		f[p]=1;
		printf("Enter number of files on index : ");
		scanf("%d",&n);
	}
	else
	{
		printf("Block already allocated\n");
		goto x;
	}

	for(i=0 ; i<n ; i++)
		scanf("%d",&inde[i]);

	for(i=0 ; i<n ; i++)
	{
		if(f[inde[i]]==1)
		{
			printf("Block already allocated\n");
			goto x;
		}
	}

	for(i=0 ; i<n ; i++)
		f[inde[i]]=1;

	printf("Allocated\nFile indexed\n");
	
	for(k=0;k<n;k++)
		printf("%d->%d:%d\n",p,inde[k],f[inde[k]]);
	
	printf("Do you want to continue? (y/n) : ");
	scanf("%d",&i);
	scanf("%c",&c);
	
	if(c=='y')
		goto x;
	else
		exit(0);	
}
