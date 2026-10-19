#include <stdio.h>
#include <stdlib.h>

int source,V,E,visited[20],G[20][20],Q[20],front=-1,rear=-1;

void DFS(int i)
{
    int j;
    visited[i]=1;
    printf(" %d\t",i);
    for(j=1;j<=V;j++)
    {
        if(G[i][j]==1 && visited[j]==0)
            DFS(j);
    }
}

void enqueue(int item)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		Q[rear]=item;
	}
	else
	{
		rear++;
		Q[rear]=item;
	}
}
int dequeue()
{
	int item;
	if(front==-1 && rear==-1)
		return -1;
	else if(front==rear)
	{
		item=Q[front];
		front=rear=-1;
		return item;
	}
	else
	{
		return Q[front++];
	}
}

void BFS(int s) 
{
	int i;
	visited[s]=1;
	printf(" %d\t",s);
	enqueue(s);
	
	while(front!=-1)
	{
		s=dequeue();
		for(i=1;i<=V;i++)
	  	{	
		  	if(G[s][i]==1 && visited[i]==0)
	  		{
	  			printf(" %d\t",i);
				visited[i]=1;
	  			enqueue(i);
			}
	   }
	}
}

void main()
{
    int i,j,v1,v2,opt;
    
    printf("Enter the no of vertices of the graph:\n");
    scanf("%d",&V);
    for(i=1;i<=V;i++)
        for(j=1;j<=V;j++)
            G[i][j]=0;
            
    printf("Enter the no of edges of the graph:\n");
    scanf("%d",&E);
    
    for(i=1;i<=E;i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf("%d%d",&v1,&v2);
        G[v1][v2]=1;
        G[v2][v1]=1;
    }
    printf("\nThe adjacency matrix:\n");
    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
            printf("%d\t",G[i][j]);
        printf("\n");
    }
    
    do
    {
    	printf("\n1. DFS\n2. BFS\n3.Exit\n");
    	printf("Enter the option:\n");
    	scanf("%d",&opt);
    	switch(opt)
    	{
    		case 1:	for(i=1;i<=V;i++)
    					visited[i]=0;
					
					printf("Enter the source:\n");
    				scanf("%d",&source);
    				
    				printf("\nDFS\n");
					DFS(source);
    				break;
    				
    		case 2:	for(i=1;i<=V;i++)
    					visited[i]=0;
					
					printf("Enter the source:\n");
    				scanf("%d",&source);
    				
    				printf("\nBFS\n");
					BFS(source);
					break;
					
			case 3:	break;		
		}
	}while(opt!=3);
}
