#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff,expo;
	struct node *next;
};

struct node *Phead,*Qhead,*Rhead;

struct node *Readpoly()
{
	struct node *new,*temp,*head=NULL;
	int n,i;
	printf("Enter the number of terms in the Polynomial:\n");
	scanf("%d",&n);
	printf("Enter the coefficients and exponents of polynomial:\n");
	for(i=1;i<=n;i++)
	{
		printf("Enter the coefficient %d and exponent %d:\n",i,i);
		new=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&new->coeff);
		scanf("%d",&new->expo);
		new->next = NULL;
		if(head == NULL)
		{
			head = new;
			temp = head;
		}
		else
		{
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = new;
			temp = new;
		}
	}
	return(head);
}

void Displaypoly(struct node *head)
{
	struct node *temp;
	if(head == NULL)
	{
		printf("Polynomial is Empty!!!\n");
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
		{
			printf("%d(x^%d)+",temp->coeff,temp->expo);
			temp = temp->next;
		}
		printf("%d(x^%d)\t",temp->coeff,temp->expo);
	}
}
struct node*Multiplypoly()
{
	struct node*new;
	struct node*P,*Q,*prev,*R,*head;
	P = Phead;
	Q = Qhead;
	Rhead = NULL;
	while(P!=NULL)
	{
		while(Q!=NULL)
		{
		    new = (struct node*)malloc(sizeof(struct node));
			new->coeff = P->coeff * Q->coeff;
			new->expo = P->expo + Q->expo;
			new->next = NULL;
			if(Rhead == NULL)
			{
				Rhead = R = new;
			}
			else
			{
				R->next = new;
				R = new;	
			}	
			Q = Q->next;
		}
		P = P->next;
		Q = Qhead;
	}
	P = Rhead;
	while(P!=NULL)
	{
		prev = P;
		Q = P->next;
		while(Q!= NULL)
		{
			if(P->expo == Q->expo)
			{
				P->coeff = P->coeff + Q->coeff;
				prev->next = Q->next;
				free(Q);
				Q = prev->next;
			}
			else
			{
				prev = Q;
				Q = Q->next;
			}
		}
		P = P->next;
	}
	return(Rhead);
}
int main()
{
	printf("Enter the details of 1st Polynomial:\n");
	Phead = Readpoly();
	printf("Enter the details of 2nd Polynomial:\n");
	Qhead = Readpoly();
	printf("\nFirst Polynomial:\n");
	Displaypoly(Phead);
	printf("\nSecond Polynomial:\n");
	Displaypoly(Qhead);
	Rhead = Multiplypoly();
	printf("\nResultant polynomial:\n");
	Displaypoly(Rhead);
}

