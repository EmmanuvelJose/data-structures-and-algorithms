//double ended queue using array
#include<stdio.h>
int front,rear,n,item,A[100];
int dqpush(int item)
{
	int i;
	if((front == 0 && rear == n-1)||(front == rear +1))
	printf("DEQUE is Full\n");
	else if((front == -1)&&(rear ==-1))
	{
		front = 0;
		rear = 0;
		A[front] = item;
	}
	else if(front==0)
	{
		front = n-1;
		A[front] = item;
	}
	else
	{
		front --;
		A[front]= item;
	}
}
int dqpop()
{
	if(front == -1&& rear == -1)
		printf("Deque is EMPTY");
	else if (front == rear)
	{
		printf("Popped element is:%d\n",A[front]);
		front = -1;
		rear = -1;
	}
	else if(front == n-1)
	{
		printf("Popped element is:%d\n",A[front]);
		front =0;
	}
	else
	{
		printf("Popped element is:%d\n",A[front]);
		front ++;
	}
}
int dqinject(int item)
{	
	int i;
	if((front ==0&&rear == n-1)||(front == rear+1))
		printf("DEQUE is Full\n");
	else if((front ==-1)&&(rear==-1))
	{
		front = 0; 
		rear = 0;
		A[rear] = item;
	}
	else if(rear == n-1)
	{
		rear = 0;
		A[rear]= item;	
	}
	else
	{
		rear ++;
		A[rear] = item;
	}
}
int dqreject()
{
	if(front == -1&&rear==-1)
		printf("Deque is EMPTY");
	else if(front == rear)
	{
		printf("Rejected item is:%d\n",A[rear]);
		front = -1;
		rear = -1;
	}
	else if(rear == 0)
	{
		printf("Rejected item is:%d\n",A[rear]);
		rear = n-1;
	}
	else
	{
		printf("Rejected item is: %d\n",A[rear]);
		rear --;
	}
}
int dqdisplay()
{	
	int i = front;
	if((front == -1)&&(rear == -1))
		printf("DEQUE is Empty\n");
	else
	{	
		printf("Deque is:\n");
		while(i!=rear)
		{
			printf("%d\n",A[i]);
			i = (i+1)%n;
		}
		printf("%d\n",A[i]);
	}
}
void main()
{
	int opt;
	front =-1;
	rear = -1;
	printf("Enter the size of deque:\n");
	scanf("%d",&n);
	do
	{
		printf("1.Push\n2.Pop\n3.Inject\n4.Reject\n5.Display\n6.Exit\n");
		printf("Enter the option:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: printf("Enter an element to push:\n");
					scanf("%d",&item);
					dqpush(item);
					break;
			case 2: dqpop();
					break;
			case 3: printf("Enter the element to inject:\n");
					scanf("%d",&item);
					dqinject(item);
					break;
			case 4:	dqreject();
					break;
			case 5:	dqdisplay();
					break;
			case 6: break;
			default: printf("Invalid Entry\n");
			
		}
	}
	while(opt!=6);
}
