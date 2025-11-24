#include<stdio.h>
//linear search
int main()
{
	int i,n,key;
	int arr[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&key);
//	int count = 0;
	for(i=0;i<n;i++)
	{
		if(key==arr[i])
		{
//			count=1;
			break ;
		}
		
	}
	if(i<n)
	{
		printf(" found at %d index",i);
	}
	else
	{
		printf("not found.");
	}
}
