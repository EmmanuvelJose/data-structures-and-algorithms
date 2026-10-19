//binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*lChild,*rChild;
};
struct node*ptr,*parent;
struct node*root = NULL;
void Inorder(struct node*tree)
{
	if(tree!= NULL)
	{
		Inorder(tree->lChild);
		printf("%d\t",tree->data);
		Inorder(tree->rChild);
	}
}
void Preorder(struct node*tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		Preorder(tree->lChild);
		Preorder(tree->rChild);
	}
}
void Postorder(struct node*tree)
{
	if(tree != NULL)
	{
		Postorder(tree->lChild);
		Postorder(tree->rChild);
		printf("%d\t",tree->data);
	}
}
void Insert(int item)
{
	if(root == NULL)
	{
		struct node*new;
		new = (struct node*)malloc(sizeof(struct node));
		new->data = item;
		new->lChild = NULL;
		new->rChild = NULL;
		root = new;
	}
	else
	{
		int flag = 0;
		ptr = root;
		while(ptr != NULL && flag == 0)
		{
			if(item == ptr->data)
			{
				flag = 1;
				printf("Item already exist!!\n");
				break;
			}
			else if(item<ptr->data)
			{
				parent = ptr;
				ptr = ptr->lChild;
			}
			else
			{
				parent = ptr;
				ptr = ptr->rChild;
			}
		}
		if(ptr == NULL)
		{
			struct node*new;
			new =(struct node*)malloc(sizeof(struct node));
			new->data =item;
			new->lChild = NULL;
			new->rChild = NULL;
			if(parent->data <item)
				parent->rChild = new;
			else
				parent->lChild = new;
		}
	}
}
void  Delete(int item)
{
	int flag = 0;
	struct node *x,*y,*z;
	ptr = root;
	while(ptr != NULL && flag == 0)
	{
		if(item<ptr->data)
		{
			parent = ptr;
			ptr = ptr->lChild;
		}
		else if(item >ptr->data)
		{
			parent = ptr;
			ptr = ptr->rChild;
		}
		else
			flag = 1;
	}
	if(flag == 0)
		printf("Item doesnot exist!!\n");
	else
	{
		if(ptr->rChild == NULL&& ptr->lChild == NULL)
		{
			if(parent ->lChild == ptr)
				parent->lChild = NULL;
			else
				parent->rChild = NULL;
		}
		else if(ptr->lChild !=NULL && ptr->rChild != NULL)
		{
			y = ptr->rChild;
			if(y->lChild != NULL)
			{
				while(y->lChild != NULL)
				{
					parent = y;
					y = y->lChild;
				}
				y = y->rChild;
				ptr->data = y->data;
				parent->lChild = z;
				free(y);
			}
			else
			{
				ptr->data = y->data;
				ptr->rChild = y->rChild;
				free(y);
			}
		}
		else
		{
			if(parent->lChild == ptr)
			{
				if(ptr->lChild != NULL)
					parent->lChild = ptr->lChild;
				else
					parent->lChild = ptr->rChild;
			}
			else
			{
				if(ptr->lChild != NULL)
					parent->rChild = ptr->lChild;
				else
					parent->rChild = ptr->rChild;
			}
		}
	}
}
int main()
{
	int opt,key;
	do
	{
		printf("\n1.Insert a Key\n2.Delete a Key\n3.Inorder Traversal\n4.Preordr Traversal\n5.Postorder Traversal\n6.Exit\n");
		printf("Enter an Option:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:	printf("\nEnter the item to be Inserted:\n");
					scanf("%d",&key);
					Insert(key);
					break;
			case 2: printf("\nEnter the item to be Deleted:\n");
					scanf("%d",&key);
					Delete(key);
					break;
			case 3: printf("\nINORDER TRAVERSAL:\n");
					Inorder(root);
					printf("\n");
					break;
			case 4: printf("\nPREORDER TRAVERSAL:\n");
					Preorder(root);
					printf("\n");
					break;
			case 5: printf("\nPOSTORDER TRAVERSAL:\n");
					Postorder(root);
					printf("\n");
					break;
			case 6: break;
			default:printf("Invalid Option!!\n");
		}
	}
	while(opt!=6);
}
