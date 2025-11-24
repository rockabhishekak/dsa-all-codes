#include<iostream>
using namespace std;
int main()
{
	int arr[100];
	int n,i,peak,found=0;
	cout<<"Enter the number of element."<<endl;
	cin>>n;
	cout<<"Enter the element."<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<n-1;i++)
	{
		if(arr[i-1]<arr[i] && arr[i]>arr[i+1])
		{
			peak=arr[i];
			found=1;
		}
	}
	if(found=0)
	{
		cout<<"No Found";
	}
	else
	{
		cout<<peak;
	}
}
