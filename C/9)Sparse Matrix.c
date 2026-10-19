#include<stdio.h>
int S[10][10],T[10][10];
void Sparse(int A[10][10],int m,int n)
{
     int i,j,k=1;
     S[0][0]=m; S[0][1]=n; k=1;
     for(i=0;i<m;i++)
     {   for (j=0;j<n;j++)
        {
            if (A[i][j]!=0)
            {  S[k][0]=i;
               S[k][1]=j;
               S[k][2]=A[i][j];
               k++;
            }
        }
     }S[0][2]=k;
     printf("\nthe sparse matrix is:\n");
     for (i=0;i<k;i++)
     {   for (j=0;j<3;j++)
        {  printf("%d\t",S[i][j]);}
        printf("\n");
     }
}

void Transpose()
{
     int m,n,i,j,k=1;
     T[0][0]=S[0][1];  T[0][1]=S[0][0];  T[0][2]=S[0][2];
     m=S[0][1]; n=S[0][2];    
     for(i=0;i<m;i++)
     {  for(j=0;j<n;j++)
       {  if (S[j][1]==i)
         {
             T[k][0]=S[j][1];
             T[k][1]=S[j][0];
             T[k][2]=S[j][2];
             k++;
         }
       }
     }
     printf("\nthe transpose is:\n");
     for(i=0;i<T[0][2];i++)
     {  for(j=0;j<3;j++)
       {
          printf("%d\t",T[i][j]);}
          printf("\n");
          }
       
} 

void Addsparse(int x[10][10],int y[10][10])
{
     int i,j,r1,r2,c1,c2,m,n,r[10][10],k;
     r1=x[0][0];  c1= x[0][1];
     r2=y[0][0] ;  c2=y[0][1];
     if (r1!=r2 || c1!=c2)
     {  printf("incompatible matrix");}
     else
     {
         r[0][0]=x[0][0];
         r[0][1]=x[0][1];
         m=n=k=1;
         for (i=0;i<r1;i++)
           {  for(j=0;j<c1;j++)
             {  if (x[m][0]==i && x[m][1]==j && y[n][0]==i && y[n][1]==j)
                {
                   r[k][0]=x[m][0];
                    r[k][1]=x[m][1];
                     r[k][2]= x[m][2]+y[n][2];
                     m++;n++;k++;
                }
                else if(x[m][0]==i && x[m][1]==j)
                {
                     r[k][0]=x[m][0];
                    r[k][1]=x[m][1];
                     r[k][2]= x[m][2];
                     m++;k++;
                     }
                     
                else if(y[n][0]==i && y[n][1]==j)  
                {  
                  r[k][0]=y[n][0];
                    r[k][1]=y[n][1];
                     r[k][2]= y[n][2];
                     n++;k++;        
                }       
             }
           }
           r[0][2]=k;
           printf("the resultant matrix is:");
           for (i=0;i<r[0][2];i++)
             { for (j=0;j<3;j++)
              {
                   printf("%d\t",r[i][j]);
              }printf("\n");
             } 
  }        
}             
               
     
void main()
{
     int A[10][10],m,n,i,j,x[10][10],y[10][10],p,q,B[10][10];
     printf("Enter no. of rows and columns:");
     scanf("%d%d",&m,&n);
     printf("enter the elements");
     for (i=0;i<m;i++)
     {  for (j=0;j<n;j++)
        {  scanf("%d",&A[i][j]);}
     }
     printf("\nthe entered matrix is:\n");
     for (i=0;i<m;i++)
     {  for (j=0;j<n;j++)
        {  printf("%d\t",A[i][j]);}
        printf("\n");
     }
     Sparse(A,m,n);
     Transpose();
     //getch();
     
     for (i=0;i<S[0][2];i++)
     {  for (j=0;j<3;j++)
       {
            x[i][j]=S[i][j];
       }
       printf("\n");
     }
     printf("Enter rows and columns of sec matrix");
     scanf("%d%d",&m,&n);
     printf("enter the elements");
     for (i=0;i<m;i++)
     {  for (j=0;j<n;j++)
        {  scanf("%d",&B[i][j]);}
     }
     printf("\nthe entered matrix is:\n");
     for (i=0;i<m;i++)
     {  for (j=0;j<n;j++)
        {  printf("%d\t",B[i][j]);}
        printf("\n");
     }
     Sparse(B,m,n);
     Transpose();
     //getch();
     for (i=0;i<S[0][2];i++)
     {  for (j=0;j<3;j++)
       {
            y[i][j]=S[i][j];
       }
       printf("\n");
     }
     
     Addsparse(x,y);
     getch();
     
     
}
