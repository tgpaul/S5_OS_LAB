#include<stdio.h>
#include<stdlib.h>

int main()
{
	int reqseq[100],i,n,totheadmov=0,init;

	printf("Enter the number of requests : ");
	scanf("%d",&n);
	printf("Enter the request sequence :-\n");
	for( i=0;i<n;i++ )	
		scanf("%d",&reqseq[i]);
	printf("Enter the initial head position : ");
	scanf("%d",&init);

	for( i=0;i<n;i++)
	{
		totheadmov = totheadmov + abs(reqseq[i]-init);
		init = reqseq[i];
	}

	printf("Total Head Movement = %d\n",totheadmov);
	return 0;
}
