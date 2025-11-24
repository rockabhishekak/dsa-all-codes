#include<iostream>
using namespace std;
int main()
{
	int arr[100];
	int n,i,j;
	cout<<"Enter the number of element."<<endl;
	cin>>n;
	cout<<"Enter the element."<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n-1;i++)
	{
		int min_index=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
			
		}
		int temp=arr[i];
		arr[i]=arr[min_index];
		arr[min_index]=temp;
	}
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
		
	}
}
