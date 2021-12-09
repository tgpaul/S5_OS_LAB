#include<stdio.h>
#include<stdlib.h>

int main()
{
	int reqseq[100],i,j,n,totheadmov=0,init,dsize,index;

	printf("Enter the number of requests : ");
	scanf("%d",&n);
	printf("\nEnter the request sequence :-\n");
	for( i=0;i<n;i++ )	
		scanf("\t%d",&reqseq[i]);
	printf("\nEnter the initial head position : ");
	scanf("%d",&init);
	printf("\nEnter the total disk size : ");
	scanf("%d",&dsize);
	
	for( i=0;i<n;i++ )
		for( j=0;j<n-i-1;j++ )
			if(reqseq[j]>reqseq[i+1])
			{
				int temp;
				temp = reqseq[j];
				reqseq[j] = reqseq[j+1];
				reqseq[j+1] = temp;
			}

	for( i=0;i<n;i++ )
		if(init<reqseq[i])
		{
			index=i;
			break;
		}

	for( i=index ; i<n ; i++)
	{
		totheadmov = totheadmov + abs(reqseq[i]-init);
		init = reqseq[i];
	}

	totheadmov = totheadmov + abs(dsize-reqseq[i-1]-1);
	init = dsize-1;
	
	for( i=index-1 ; i>=0 ; i-- )
	{
		totheadmov = totheadmov + abs(reqseq[i]-init);
		init = reqseq[i];
	}

	printf("Total Head Movement = %d",totheadmov);
	return 0;
}
