// circular queue using array
#include<stdio.h>
int A[100],item,size,rear,front;
int main()
{
	int opt;
	front = -1; rear = -1;
	printf("Enter the size of the queue:\n ");
	scanf("%d",&size);
	do{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter the choice:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: printf("Enter the element to be enqueued:\n");
			        scanf("%d",&item);
			        cqenqueue(item);
					break;
			case 2: cqdequeue();
			        break;
			case 3: displaycq();
			        break;
			case 4: break;
			default: printf("Invalid entry");
		}
	}while(opt!=4);
	
}

int cqenqueue(int item)
{
	if((rear+1)%size == front)
		printf("Circular queue is full\n");
	else if(front== -1 && rear == -1)
	{
		front = 0;
		rear = 0;
		A[rear] = item;
	}
	else
	{
	rear = (rear +1)% size;
	A[rear] = item;	
	}
}

int cqdequeue()
{
	if(front == -1 && rear == -1)
		printf("Circular Queue is Empty\n");
	else if(front == rear)
	{
		printf("Dequeued element is %d\n",A[front]);
		front= -1;
		rear = -1;
	}
	else
	{
		printf("Dequeued element is %d\n",A[front]);
		front = (front +1)%size;
	}
}

int displaycq()
{	int i= front;
	if(front == -1 && rear == -1)
		printf("Circular queue is Empty\n");
	else 
	{
		printf("Circular Queue is:\n");
		while(i!=rear)
		{
			printf("%d\n",A[i]);
			i = (i+1)%size;
		}
		printf("%d",A[rear]);
	}
}
