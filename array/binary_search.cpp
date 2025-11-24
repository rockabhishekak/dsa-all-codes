#include<iostream>
//Binary search
using namespace std;
int main()
{
	int i,n,lb,ub,mid,key,found=0;
	cout<<"Enter the number of Element."<<endl;
	cin>>n;
	cout<<"Enter the element."<<endl;
	int arr[100];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter you key"<<endl;
	cin>>key;
	lb=0;
	ub=n-1;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(key==arr[mid])
		{
			found=1;
			cout<<"Found at "<<mid<<" index"<<endl;
			break;
		}
		else if(key>arr[mid])
		{
			lb=mid+1;
		}
		else
		{
			ub=mid-1;
		}
	}
	if(found==0)
	cout<<"Not found";
	
}
