#include<stdio.h>
int a[100],n,front,rear;
void ENQUEUE(int item)
{
     if ( front==-1 && rear==-1)
         {
            front=0; rear=0;
            a[rear]=item;
            rear++;
         }
     else if(rear==n)
        {
            printf("Queue is full");
        }
     else
      {
          a[rear]=item;
          rear++;
             }   
}
void DEQUEUE()
{
     int item;
     if (front==-1)
     {
                   printf("Queue is empty\n");
     }
     else if (front==rear)
     {
        item=a[front];
        printf("the deleted item is %d\n",a[front]);
        front=-1;rear=-1;
     }
     else
         {
            item=a[front];
            printf("the deleted item is %d\n",a[front]);
            front++;
         }  
     
}
void DISPLAY()
{
     int i;
     if (front==-1)
     {
                   printf("queue is empty\n");
     }
     else
     {
         for (i=front;i<rear;i++)
         {
            printf("%d ",a[i]);
         }
     }
}
void main()
{
     int item,op;
     front=-1;
     rear=-1;
     

     printf("enter the size:");
     scanf("%d",&n);
     do
     {
        printf("\nEnter the choice :\n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT \n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("enter element to be inserted:");
            scanf("%d",&item);
            ENQUEUE(item);
            break;
            case 2:DEQUEUE();
            break;
            case 3:DISPLAY();
            break;
            case 4:break;
            default:printf("invalid option\n");
        }
                    
     }while(op!=4);
}     
