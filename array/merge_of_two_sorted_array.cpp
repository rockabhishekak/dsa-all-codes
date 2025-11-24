#include<iostream>
using namespace std;
int main()
{
    int i=0,j=0,k=0;
    int arr1[6]={1,5,9,12,15,20};
    int arr2[4]={3,7,8,10};
    int arr[10];
    while (i<6 && j<4)
    {
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            k++;
            i++;

        }
        else
        {
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<6)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<4)
    {
        arr[k]=arr1[j];
        j++;
        k++;
    }
    for(int p=0;p<10;p++)
    {
        cout<<arr[p]<<" ";
    }
    
}