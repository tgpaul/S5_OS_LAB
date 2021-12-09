#include<stdio.h>
#include<stdlib.h>

int main()
{
	int f[50],st,len,k,i,j;
	char c='y';
	for( i=0 ; i<50 ; i++ )
		f[i]=0;
	
	do{
		printf("Enter Starting Block and Length of File : ");
		scanf("%d%d",&st,&len);
		for( j=st ; j<(st+len) ;j++ )
		{
			if(f[j]==0)
			{
				f[j]=1;
				printf("%d->%d\n",j,f[j]);
			}
			else
			{
				printf("Block already allocated\n");
				break;
			}
		}
		if( j==(st+len) )
			printf("the file is allocated to disk\n");
	
		printf("Do you want to enter more files? (y/n) : ");
		scanf("%d",&i);
		scanf("%c",&c);
	}while(c=='y');
	return 0;
}
