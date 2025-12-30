#include <iostream>
using namespace std;

#define MAX 100

int heap[MAX];
int size = 0;

// Heapify UP (Insertion ke time)
void heapifyUp(int i) {
    while(i > 1 && heap[i] < heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

// Heapify DOWN (Deletion ke time)
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= size && heap[left] < heap[smallest])
        smallest = left;

    if(right <= size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert element in Min Heap
void insertMinHeap(int value) {
    if(size == MAX - 1) {
        cout << "Heap Overflow\n";
        return;
    }

    size++;
    heap[size] = value;
    heapifyUp(size);
}

// Delete minimum element (root)
void deleteMin() {
    if(size == 0) {
        cout << "Heap Underflow\n";
        return;
    }

    cout << "Deleted element: " << heap[1] << endl;

    heap[1] = heap[size];
    size--;
    heapifyDown(1);
}

// Display heap elements
void display() {
    if(size == 0) {
        cout << "Heap empty\n";
        return;
    }

    for(int i = 1; i <= size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- MIN HEAP MENU ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete Min";
        cout << "\n3. Display";
        cout << "\n0. Exit\n";

        cin >> choice;

        switch(choice) {
            case 1:
                cin >> value;
                insertMinHeap(value);
                break;

            case 2:
                deleteMin();
                break;

            case 3:
                display();
                break;
        }
    } while(choice != 0);

    return 0;
}
