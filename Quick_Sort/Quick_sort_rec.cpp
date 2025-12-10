#include<iostream>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int j=low;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    i++;
    return i;
}
void quick_sort(int arr[], int low, int high){
    int pos;
    if(low < high){
        pos = partition(arr, low, high);
        quick_sort(arr, low, pos - 1);
        quick_sort(arr, pos + 1, high);
    }
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr, 0, n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}