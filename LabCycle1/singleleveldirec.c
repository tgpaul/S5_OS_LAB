#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 30

struct directory{
	char fileName[MAXSIZE][MAXSIZE];
	char dirName[MAXSIZE];
	int fno;
}dir;

int i,n;

void InsertFile()
{
	printf("\nEnter the name of the file to be inserted : ");
	scanf("%s",dir.fileName[dir.fno++]);
	printf("\n");
}

void DisplayFile()
{
	if(dir.fno == 0)
	{
		printf("No files in the directory!!\n");
		return;
	}
	printf("\nDisplaying all files in Directory \"%s\" are :-\n",dir.dirName);
	for(int i=0;i<dir.fno;i++)
		printf("\t%d. %s\n",i+1,dir.fileName[i]);
	printf("\n");
}

int search(char* file)
{
	int flag=-1;
	for(int i=0;i<dir.fno;i++)
	{
		if(strcmp(dir.fileName[i],file) == 0)
			flag = i;
	}
	
	return flag;
}

void DeleteFile()
{
	char file[MAXSIZE];
	int srch;
	printf("\nEnter the name of the file to be deleted : ");
	scanf("%s",file);

	srch = search(file);
	if(srch == -1)
	{
		printf("File not found!\n");
		return;
	}
	printf("Deleted file : %s\n",dir.fileName[srch]);
	strcpy(dir.fileName[srch],dir.fileName[dir.fno-1]);
	dir.fno--;
	printf("\n");
}

void main()
{
	int choice=0,ans=0;
	char file[MAXSIZE];
	printf("Enter the directory name : ");
	scanf("%s",dir.dirName);
	dir.fno=0;
	
	do
	{
		printf("\n----------------- MENU -----------------\n");
		printf("1. Insert file to directory\n2. Display all files in directory\n3. Delete file in directory\n4. Search for file in directory\n5. Exit\nEnter your choice (1-5) : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: InsertFile();
				break;
			
			case 2: DisplayFile();
				break;

			case 3: DeleteFile();
				break;

			case 4: printf("\nEnter the name of the file to be searched for : ");
				scanf("%s",file);
				int srch = search(file);
				if(srch == -1)
				{
					printf("File not found!\n");
					break;
				}
				printf("File found at postion %d\n",srch+1);
				break;

			case 5: exit(0);
			default:printf("Invalid Choice!\n");

		}
		printf("Do you want to continue (1/0) : ");
		scanf("%d",&ans);
	}while(ans == 1);
}
