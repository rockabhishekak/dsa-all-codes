#include <iostream>
using namespace std;

#define MAX 100

int heap[MAX];
int size = 0;

// Heapify down (for heap sort & deletion)
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Heapify up (for insertion)
void heapifyUp(int child)
{
    int parent = child / 2;

    while (child > 1 && heap[parent] < heap[child])
    {
        swap(heap[parent], heap[child]);
        child = parent;
        parent = child / 2;
    }
}

// Insert into heap
void insert(int value)
{
    if (size == MAX)
    {
        cout << "Heap is full\n";
        return;
    }

    heap[++size] = value;
    heapifyUp(size);
}

// Heap Sort using max heap
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2; i >= 1; i--)
        maxHeapify(arr, n, i);

    // Extract elements
    for (int i = n; i > 1; i--)
    {
        swap(arr[1], arr[i]);
        maxHeapify(arr, i - 1, 1);
    }
}

// Display heap
void display(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insert(value);
    }

    cout << "Heap elements: ";
    display(heap, size);

    heapSort(heap, size);

    cout << "Sorted elements: ";
    display(heap, size);

    return 0;
}
