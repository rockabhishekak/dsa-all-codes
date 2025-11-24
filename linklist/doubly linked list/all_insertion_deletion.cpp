#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;

    Node(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

// --------------------------------------------------
// PRINT DOUBLY LINKED LIST
// --------------------------------------------------
void printDLL(Node* head) {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


// --------------------------------------------------
// INSERTION FUNCTIONS
// --------------------------------------------------

// INSERT AT BEGINNING
Node* insertBeg(Node* head, int val) {
    Node* newNode = new Node(val);

    newNode->next = head;
    if (head != nullptr)
        head->prev = newNode;

    return newNode;
}

// INSERT AT END
Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr)
        return newNode;

    Node* ptr = head;
    while (ptr->next != nullptr)
        ptr = ptr->next;

    ptr->next = newNode;
    newNode->prev = ptr;

    return head;
}

// INSERT AT POSITION
Node* insertAtPos(Node* head, int val, int pos) {
    if (pos == 1)
        return insertBeg(head, val);

    Node* newNode = new Node(val);
    Node* ptr = head;

    for (int i = 1; i < pos - 1 && ptr != nullptr; i++)
        ptr = ptr->next;

    if (ptr == nullptr) {
        cout << "Position out of range\n";
        return head;
    }

    newNode->next = ptr->next;
    newNode->prev = ptr;

    if (ptr->next != nullptr)
        ptr->next->prev = newNode;

    ptr->next = newNode;

    return head;
}


// --------------------------------------------------
// DELETION FUNCTIONS
// --------------------------------------------------

// DELETE AT BEGINNING
Node* deleteBeg(Node* head) {
    if (head == nullptr)
        return nullptr;

    Node* ptr = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete ptr;
    return head;
}

// DELETE AT END
Node* deleteEnd(Node* head) {
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* ptr = head;

    while (ptr->next != nullptr)
        ptr = ptr->next;

    ptr->prev->next = nullptr;
    delete ptr;

    return head;
}

// DELETE AT POSITION
Node* deleteAtPos(Node* head, int pos) {
    if (head == nullptr)
        return nullptr;

    if (pos == 1)
        return deleteBeg(head);

    Node* ptr = head;

    for (int i = 1; i < pos && ptr != nullptr; i++)
        ptr = ptr->next;

    if (ptr == nullptr) {
        cout << "Position out of range\n";
        return head;
    }

    if (ptr->prev != nullptr)
        ptr->prev->next = ptr->next;

    if (ptr->next != nullptr)
        ptr->next->prev = ptr->prev;

    delete ptr;
    return head;
}


// DELETE IN RANGE L TO R
Node* deleteRange(Node* head, int L, int R) {
    if (head == nullptr || L > R)
        return head;

    // first delete until reaching L
    while (L == 1) {
        head = deleteBeg(head);
        L++;
        if (L > R)
            return head;
    }

    Node* ptr = head;

    for (int i = 1; i < L - 1 && ptr != nullptr; i++)
        ptr = ptr->next;

    if (ptr == nullptr || ptr->next == nullptr)
        return head;

    Node* del = ptr->next;

    for (int i = L; i <= R && del != nullptr; i++) {
        Node* nxt = del->next;
        delete del;
        del = nxt;
    }

    ptr->next = del;
    if (del != nullptr)
        del->prev = ptr;

    return head;
}

int main() {
    Node* head = nullptr;
    int choice, val, pos, L, R;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Delete in Range (L to R)\n";
        cout << "8. Print List\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            head = insertBeg(head, val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            head = insertEnd(head, val);
            break;

        case 3:
            cout << "Enter value and position: ";
            cin >> val >> pos;
            head = insertAtPos(head, val, pos);
            break;

        case 4:
            head = deleteBeg(head);
            break;

        case 5:
            head = deleteEnd(head);
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            head = deleteAtPos(head, pos);
            break;

        case 7:
            cout << "Enter L and R: ";
            cin >> L >> R;
            head = deleteRange(head, L, R);
            break;

        case 8:
            cout << "List: ";
            printDLL(head);
            break;

        case 9:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
