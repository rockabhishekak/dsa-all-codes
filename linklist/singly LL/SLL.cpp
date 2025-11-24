#include <iostream>
using namespace std;

// ---------------------------
// Simple Node Structure
// ---------------------------
struct Node {
    int data;
    Node* next;
};

// ---------------------------
// Create a new node
// ---------------------------
Node* createNode(int data) {
    // ek naya node banate hain
    Node* nn = new Node();
    nn->data = data;
    nn->next = NULL;
    return nn;
}

// ---------------------------
// Insert at end of list
// ---------------------------
void insertEnd(Node** head, int data) {
    Node* nn = createNode(data);

    // agar list empty ho
    if (*head == NULL) {
        *head = nn;
        return;
    }

    // last node tak jao
    Node* ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // last me add kar do
    ptr->next = nn;
}

// ---------------------------
// Print list
// ---------------------------
void display(Node* head) {
    cout << "List: ";
    Node* ptr = head;

    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// ---------------------------
// Reverse K nodes (important)
// ---------------------------
Node* reverseKNodes(Node* head, int k) {
    if (head == NULL) return NULL;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    int count = 0;

    // STEP 1: Reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;     // pehle next save kar lo
        curr->next = prev;     // link ulta karo
        prev = curr;           // prev ko aage badhao
        curr = next;           // curr ko aage badhao
        count++;
    }

    // STEP 2: Baaki list ko recursive reverse karo
    if (next != NULL) {
        head->next = reverseKNodes(next, k);
    }

    return prev;  // prev new head hai
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    Node* head = NULL;

    // list me values insert karte hain
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);

    display(head);

    int k = 3;

    cout << "Reversing " << k << " nodes at a time...\n";

    head = reverseKNodes(head, k);

    display(head);

    return 0;
}
