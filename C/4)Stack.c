#include<stdio.h>
int a[100],n,top,i,item;
void push(int item)
{
     if (top==n-1)
     {
        printf("stack is full\n");
     }
     else
     {
         top++;
         a[top]=item;
     }
}
void pop()
{
     if (top==-1)
     {
        printf("stack is empty\n");
     }
     else
     {
         printf("item popped is %d\n",a[top]);
         top--;
     }
}
void status()
{
     if (top<0)
     {
            printf("stack is empty\n");
     }
     else
     {
         if (top==n-1)
         {
            printf("stack is full\n");
         }
         else
         {
            printf("the topmost element is %d\n",a[top]);
         }
     }
}
void display()
{
     if (top==-1)
         {
            printf("stack is empty\n");
         }
     else
     {
     	 printf("\n The elements in stack are:");
         for (i=0;i<=top;i++)
         {
             printf("%d\n",a[i]);
         }
     }
}
void main()
{
     int item,op;
     top=-1;
     printf("enter the size:\n");
     scanf("%d",&n);
     do
     {
                    printf("\nEnter the choice :\n1.PUSH \n2.POP \n3.DISPLAY \n4.STATUS \n5.EXIT\n");
                    scanf("%d",&op);
                    switch(op)
                    {
                            case 1:printf("enter value to be inserted:\n");
                                   scanf("%d",&item);
                                   push(item);
                                   break;
                            case 2:pop();
                                   break;
                            case 3:display();
                                   break;
                            case 4:status();
                                   break;
                            case 5:break;
                            default:printf("invalid option");
                    }
     }while(op!=5);
}
