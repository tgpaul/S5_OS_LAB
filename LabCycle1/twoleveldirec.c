//C Program to simulate a Two Level Directory
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 30
#define MINSIZE 10
struct{
	char dname[MINSIZE],fname[MINSIZE][MINSIZE];
	int fcnt;
}dir[MINSIZE];

void main()
{
	int i,ch,dcnt,k;
	char f[MAXSIZE], d[MAXSIZE];
	dcnt=0;
	while(1)
	{
		printf("\n\n----------- MENU -----------\n1. Create Directory\n2. Create File\n3. Delete File\n");
		printf("4. Search File\n5. Display\n6. Exit\nEnter your choice (1-6) : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter name of directory : ");
				scanf("%s", dir[dcnt].dname);
				dir[dcnt].fcnt=0;
				dcnt++;
				printf("Directory created");
				break;
			
			case 2: printf("\nEnter name of the directory : ");
				scanf("%s",d);
				for(i=0;i<dcnt;i++)
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter name of the file : ");
						scanf("%s",dir[i].fname[dir[i].fcnt++]);
						printf("File created");
						break;
					}
				if(i==dcnt)
				printf("Directory \"%s\" not found",d);
				break;

			case 3: printf("\nEnter name of the directory : ");
				scanf("%s",d);
				for(i=0;i<dcnt;i++)
				{
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter name of the file : ");
						scanf("%s",f);
						for(k=0;k<dir[i].fcnt;k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File \"%s\" is deleted ",f);
								dir[i].fcnt--;
								strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
								goto jmp;
							}
						}
						printf("File \"%s\" not found",f);
						goto jmp;
					}
				}	
				printf("Directory \"%s\" not found",d);
				jmp : break;
			
			case 4: printf("\nEnter name of the directory : ");
				scanf("%s",d);
				for(i=0;i<dcnt;i++)
				{
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter the name of the file : ");
						scanf("%s",f);
						for(k=0;k<dir[i].fcnt;k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File \"%s\" is found ",f);
								goto jmp1;
							}
						}
						printf("File \"%s\" not found",f);
						goto jmp1;
					}
				}
				printf("Directory \"%s\" not found",d);
				jmp1: break;
				
			case 5: if(dcnt==0)
					printf("\nNo Directory's ");
				else
				{
					printf("\nDirectory\tFiles");
					for(i=0;i<dcnt;i++)
					{
						printf("\n%s\t\t",dir[i].dname);
						for(k=0;k<dir[i].fcnt;k++)
							printf("%s ",dir[i].fname[k]);
						printf("\n");
					}
				}
				break;
			default:exit(0);
		}
	}
}

