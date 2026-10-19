
//Singly Linked List Operations using Switch
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head;

void Display()
{
	struct node*t;
	if(head == NULL)
		printf("Linked List is EMPTY\n");
	else
	{
		t = head;
		printf("Linked list is:\n");
		while(t!=NULL)
			{
				printf("%d\t",t->data);
				t=t->next;
			}
	}	
}
void Insert_Front(int x)
{
	struct node*newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = head;
	head = newnode;
	Display();
}
void Insert_End(int x)
{
	struct node*newnode,*t;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = NULL;
	if(head == NULL)
		head = newnode;
	else
	{
		t = head;
		while(t->next!=NULL)
			t = t->next;
		t->next = newnode;
	}
	Display();
}
void Insert_After(int key, int x)
{
	struct node*newnode,*t;
	newnode = malloc(sizeof(struct node));
	t = head;
	while(t->data!=key && t->next!=NULL)
		t = t->next;
	if(t->data!=key)
		printf("Search Failed.Insertion not possible.\n");
	else
	{	
		newnode->data = x;
		newnode->next= t->next;
		t->next = newnode;
	}
	Display();
}
void Delete_Front()
{
	struct node*t1;
	if(head == NULL)
		printf("List is empty\n");
	else
	{
		t1 = head;
		head = head->next;
		printf("Deleted data is %d\n",t1->data);
		free(t1);
	}
	Display();
}
void Delete_End()
{
	struct node*p,*c,*t1;
	if(head == NULL)
		printf("List is empty\n");
	else if(head->next == NULL)
	{
		t1 = head;
		head = NULL;
		printf("Deleted data is %d\n",t1->data);
		free(t1);
	}
	else
	{	
		p = head;
		c = head->next;
		while(c->next != NULL)
		{
			p = c;
			c = c->next;
		}
		p->next = NULL;
		printf("Deleted data is %d\n",c->data);
		free(c);
	}
	Display();
}
void Delete_Any(int key)
{
	struct node*p,*c,*t1;
	if(head == NULL)
		printf("List is Empty\n");
	else if(head->data == key)
	{
		t1 = head;
		head = head->next;
		free(t1);
	}
	else
	{
		p = head;
		c = head;
		while(c->data != key && c->next != NULL)
		{
			p = c;
			c = c->next;
		}
		if(c->data != key)
			printf("Search data not found!!\n");
		else
		{
			p->next = c->next;
			free(c); 
		}
	}
	Display();
}
int main()
{
	int opt,x,key;
	do
	{
		printf("\n1.Insert at Front\n2.Insert at End\n3.Insert After a Specified Node\n4.Delete at Front\n5.Delete at End\n6.Delete Any Node\n7.Display\n8.Exit");
		printf("\nEnter the Option:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: printf("Enter the new data:\n");
					scanf("%d",&x);
					Insert_Front(x);
					break;	
			case 2: printf("Enter the new data:\n");
					scanf("%d",&x);
					Insert_End(x);
					break;
			case 3: printf("Enter the search data:\n");
					scanf("%d",&key);
					printf("Enter the new data:\n");
					scanf("%d",&x);
					Insert_After(key,x);
					break;
			case 4: Delete_Front();
					break;
			case 5: Delete_End();
					break;
			case 6: printf("Enter the data to be deleted:\n");
					scanf("%d",&key);
					Delete_Any(key);
					break;
			case 7: Display();
					break;
			case 8: break;
			default:printf("INVALID INPUT\n");
		}
	}
	while(opt!=8);	
}
