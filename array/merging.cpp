// You are using GCC
#include<iostream>
using namespace std;
int main()
{
    int i;
    int arr1[5]={1,2,3,4,5};
    int arr2[3]={6,7,8};
    int arr[8];
    
    for(i=0;i<5;i++)
    {
        arr[i]=arr1[i];
    }
    for(i=0;i<3;i++)
    {
        arr[i+5]=arr2[i];
    }
    for(i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}