//C program for CSCAN - Disk Scheduling

#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

void scanvalues();
void sortvalues();
void move();

//void test();

int reqseq[SIZE],totheadmov=0,initial,dsize,n,ind;

int main()
{

	scanvalues();	
	sortvalues();

//	test();

	move();

	printf("Total Head Movement : %d\n",totheadmov);

	return 0;
}

void scanvalues() // Function to enter the required values
{
	int i;	

	printf("Enter the number of requests : ");
	scanf("%d",&n);
	printf("Enter the request sequence :-\n");
	for( i=0 ; i<n ; i++ )
		scanf("%d",&reqseq[i]);
	printf("Enter initial head position : ");
	scanf("%d",&initial);
	printf("Enter the disk size : ");
	scanf("%d",&dsize);
}

void sortvalues()//Function to read values from User
{
	int i,j,temp;

	for( i=0 ; i<n ; i++)
		for( j=0 ; j<n-i-1 ; j++ )
			if(reqseq[j]>reqseq[j+1])
			{
				temp	    = reqseq[j];
				reqseq[j]   = reqseq[j+1];
				reqseq[j+1] = temp;
			}
	for( i=0 ; i<n ; i++ )
		if( initial < reqseq[i] )
		{
			ind = i;
			break;
		}
}

void move()//Function to move head and calculate 'totheadmov'
{	
	int i;

	for( i=ind ; i<n ; i++ )//Moving to HIGH
	{
		totheadmov = totheadmov + abs(reqseq[i] - initial);
		initial = reqseq[i];
	}
	totheadmov = totheadmov + abs(dsize - reqseq[i-1] - 1);
	initial = dsize-1;
	for( i=ind-1 ; i>=0 ; i-- )//Moving to LOW
	{
		totheadmov = totheadmov + abs(reqseq[i] - initial);//Last req: on HIGH side - max: SIZE
		initial = reqseq[i];
	}
	
}

/*void test()
{
for(int i=0;i<n;i++)
	printf("%d ",reqseq[i]);
}*/

