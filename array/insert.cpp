#include<iostream>
using namespace std;
int main()
{
	int arr[100];
	cout<<"Enter the number of element.";
	int n,i;
	cin>>n;
	cout<<"Enter the Element.";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the key";
	int key;
	cin>>key;
	cout<<"Enter the pos";
	int pos;
	cin>>pos;
	for(i=n-1;i>=pos;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[pos]=key;
	for(i=0;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}

