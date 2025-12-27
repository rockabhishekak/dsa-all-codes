//heapsort

#include <stdio.h>

/* Swap two elements */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Max Heapify (1-based indexing) */
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

/* Heap Sort using Max Heap */
void heapSort(int arr[], int n) {

    /* Build Max Heap */
   for (int i = n / 2; i >= 1; i--) {
        maxHeapify(arr, n, i);
    }

    /* Extract elements */
   for (int i = n; i > 1; i--) {
        swap(&arr[1], &arr[i]);
        maxHeapify(arr, i-1, 1);
    }
}

int main() {
    int n;
    int arr[101];   // index 0 unused
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}