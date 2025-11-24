#include<iostream>
using namespace std;
int main()
{
	int arr[100];
	int n,i,key,j;
	cout<<"Enter the number of element."<<endl;
	cin>>n;
	cout<<"Enter the element."<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//logic of insertion sort
	for(i=1;i<n;i++)
	{
			key=arr[i];
			j=i-1;
			while(j>=0 && arr[j]>key)
			{
				arr[j+1]=arr[j];
				j--;
			}
			arr[j+1]=key;
	}
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	 
}
