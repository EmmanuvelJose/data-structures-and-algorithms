#include<stdio.h>
int size,front=-1,rear=-1;
struct pq
{
       int item;
       int priority;
}a[100];

void display()
{
     int i;
     if (front==-1)
     {
        printf("pq is empty\n");
     }
     else
     {
         for (i=front;i<=rear;i++)
         {
             printf("%d\n",a[i].item);
         }
     }
}
void enqueue_pq(int Item,int Priority)
{
     int i,loc;
     if (front==0 && rear==size-1)
     {
            printf("Priority queue is full\n");
     }
     else if(front==-1)
     {
          front=rear=0;
          a[front].item=Item;
          a[front].priority=Priority;
     }
     
          else if (rear==size-1)
         {
            for (i=front;i<=rear;i++)
                {
                    a[i-1]=a[i];
                    front--;
                    rear--;
                }
            for (i=rear;i>=front;i--)
                {
                    if (a[i].priority<Priority)
                        {
                          break;
                        }
                }
            loc=i+1;
            for(i=rear;i>=loc;i--)
              {
                 a[i+1]=a[i];
              }
                a[loc].item=Item;
                a[loc].priority=Priority;
                rear++;
         }             
         else
         {
            for (i=rear;i>=front;i--)
                {
                  if (a[i].priority<Priority)
                    {
                      break;
                    }
                }
                loc=i+1;
            for(i=rear;i>=loc;i--)
                {
                    a[i+1]=a[i];
                }
                    a[loc].item=Item;
                    a[loc].priority=Priority;
                    rear++;
         }      
}
void dequeue_pq()
{
     if (front==-1)
     {
            printf("Priority queue is empty\n");
     }
     else if (front==rear)
     {
          printf("deleted item is %d\n",a[front].item);
          front=rear=-1;
     }
     else
     {
          printf("deleted item is %d\n",a[front].item);
          front++;
     }
}
int main()
{
     int op,Item,Priority;
     front=rear=-1;
     printf("enter size of queue\n");
     scanf("%d",&size);
     do
     {
        printf("\nEnter the choice :\n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT \n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("enter element:\n");
            scanf("%d",&Item);
            printf("enter priority:\n");
            scanf("%d",&Priority);
            enqueue_pq(Item,Priority);
            break;
            case 2:dequeue_pq();
            break;
            case 3:display();
            break;
            case 4:break;
            default:printf("invalid option");
                       }
     }while(op!=4);
}
         
                          
