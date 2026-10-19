#include<stdio.h>
#include<math.h>
int a[50];
int i,j,n,temp;
int main()
{
	int x;
	printf("Enter the number of elements in the array:\n");
	scanf("%d",&n);
	printf("Enter the elements in the array: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	do
	{
		printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Merge Sort\n5.Quick Sort\n6.Exit\n");
		printf("Enter the Option:\n");
		scanf("%d",&x);	
		switch(x)
		{
			case 1:	printf("Using Bubble Sort:\n");
					BubbleSort(a,n);
					break;
			case 2: printf("Using Selection Sort:\n");
					SelectionSort(a,n);
					break;
			case 3: printf("Using Insertion Sort:\n");
					InsertionSort(a,n);
					break;
			case 4: printf("Using Merge Sort:\n");
					MergeSort(0,n-1);
					printf("Sorted Array Elements are:\n");
					for(i=0;i<n;i++)
						printf("%d\n",a[i]);
					break;
			case 5: printf("Using Quick Sort:\n");
					QuickSort(a,0,n-1);
					for(i = 0;i<n;i++)
						printf("%d\n",a[i]);
					break;
			case 6: break;
			default:printf("Invalid Entry!!\n");	
		}
	}
	while(x!=6);	
}
int BubbleSort(int a[50],int n)
{
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			    temp = a[j];
			    a[j] = a[j+1];
			    a[j+1] = temp;	
			}
		}
	}
	DisplaySort(a);
}
int SelectionSort(int a[50],int n)
{
	for(i=0;i<=n-2;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	DisplaySort(a);
}
int InsertionSort(int a[50],int n)
{
	for(i = 1;i<n;i++)
	{
		temp = a[i];
		j = i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = temp;
	}
	DisplaySort(a);
}
int Merge(int low,int mid,int high)
{
	int i = low,x = low,y = mid+1,k;
	int b[20];
	while((x<=mid)&&(y<=high))
	{
		if(a[x]<=a[y])
		{
			b[i] = a[x];
			x++;
 		}
 		else
 		{
 			b[i] = a[y];
			 y++;	
		}
		i++;
	}
	if(x<=mid)
	{
		for(k=x;k<=mid;k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	else
	{
		for(k=y;k<=high;k++)
		{
			b[i] = a[k];
			i++;
		}	
	}
	for(k=low;k<=high;k++)
		a[k] = b[k];
}
int MergeSort(int low,int high)
{
	if(low<high)
	{
		int mid = ceil((low+high)/2);
		MergeSort(low,mid);
		MergeSort(mid+1,high);
		Merge(low,mid,high);
	}
}
int QuickSort(int a[50],int low,int high)
{
	int j;
	if(low<high)
	{
		int j = partition(a,low,high);
		QuickSort(a,low,j-1);
		QuickSort(a,j+1,high);
	}
}
int partition(int a[50],int low,int high)
{
	int i = low,j=high,pivot = low;
	while(i<j)
	{
		while(a[j]<=a[pivot])
		{
			i++;
		}
		while(a[j]>a[pivot])
		{
			j--;
		}
		if(i<j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp1 = a[j];
	a[j] = a[pivot];
	a[pivot] = temp1;
	return j;
}
int DisplaySort(int a[50])
{
	printf("Sorted Array Elements are:\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}

