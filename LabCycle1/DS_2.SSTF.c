#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

int main()
{
	int reqseq[100],i,n,totheadmov=0,init,count=0;

	printf("Enter the number of requests : ");
	scanf("%d",&n);
	printf("Enter the request sequence :-\n");
	for( i=0;i<n;i++ )	
		scanf("\t%d",&reqseq[i]);
	printf("Enter the initial head position : ");
	scanf("%d",&init);
	
	while(count!=n)
	{
		int min=MAX,d,index;
		for( i=0;i<n;i++)
		{
			d=abs(reqseq[i]-init);
			if(min>d)
			{
				min=d;
				index=i;
			}
		}
		totheadmov = totheadmov + min;
		init = reqseq[index];

		reqseq[index] = MAX;	//Makes the element we selected into MAX so that it doesnt get selected again
		count++;
	}

	printf("Total head movement : %d\n",totheadmov);
	return 0;
}
