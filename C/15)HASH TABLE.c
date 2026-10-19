#include<stdio.h>
#include<stdlib.h>

struct set
{
	int key,data;
};
struct set A[10];
int size=10;

void Insert(int key,int data)
{
	int index=key%size;
	if(A[index].data==-1)
	{
		A[index].key=key;
		A[index].data=data;
	}
	else
	{
		printf("Collision Occured!!!\n");
	}
}

void Delete(int key)
{
	int index=key%size;
	if(A[index].data==-1)
	{
		printf("This key does not exist!!!\n");
	}
	else
	{
		A[index].key=-1;
		A[index].data=-1;
	}
}

void Display()
{
	int i;
	for(i=0;i<size;i++)
	{
		if(A[i].data==-1)
			printf("\nA[%d]: /",i);
		else	
			printf("\nA[%d]: (%d %d) ",i,A[i].key,A[i].data);
	}
}

int main()
{
	int choice,key,data,n,i;
	for(i=0;i<size;i++)
	{
		A[i].key=-1;
		A[i].data=-1;
	}
	do
	{
		printf("\n1.Insert item\n2.Remove item\n3.Display\n4.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Key:\n");
				scanf("%d",&key);
				printf("Enter data:\n");
				scanf("%d",&data);
				Insert(key,data);
				break;
			case 2:
				printf("Enter the key to delete:\n");
				scanf("%d",&key);
				Delete(key);
				break;
			case 3:
				Display();
				break;
			case 4:
				break;
			default:
				printf("Invalid Choice!!!\n");	
		}
	}while(choice!=4);
}
