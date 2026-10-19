#include<stdio.h>
int main()
{
	int A[10],n,flag=0,i,searchdata;
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("enter the searchdata");
	scanf("%d",&searchdata);
	for(i=0;i<n;i++)
	{
		if(A[i]==searchdata)
		{
		
		flag=1;
		break;
		
		}
	}
	if (flag==0)
	printf("search data not found");
	else
	printf("search data  found at index %d",i);
}
