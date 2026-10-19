#include<stdio.h>
int main()
{
    
    int n,i,a[100],low,high,mid,key,flag;
    printf("enter size:");
    scanf("%d",&n);
    printf("enter the array elements:");
    for(i=0;i<n;i++)
      {
       scanf("%d",&a[i]);
      }
    printf("enter the key to be searched:");
    scanf("%d",&key);
    low=0;
    high=n-1;
 
    while (low<=high)
    {
    	 mid=(low+high)/2;
          if(a[mid]==key)
          {
                flag=1;
                break;
          }
          else if(key<a[mid])
          {
              high=mid-1;
          }
          else
          {
              low=mid+1;
          }
          
    }
    if (flag==0)
    printf("element not found");
    else
    printf("element found at %d",mid);
    return 0;
}
