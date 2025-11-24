#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Function to create a new node
struct node *createNode(int val) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

// Insert a new node at the beginning of the list
void *insert_beg(struct node **start, struct node **last, int val) {
    struct node *nn = createNode(val);

    if (*start == NULL) {
        // List is empty — new node is both start and last
        *start = nn;
        *last = nn;
    } else {
        // Link new node before current start
        nn->next = *start;
        (*start)->prev = nn;
        *start = nn;
    }
    // return *start; we don't need to return anything as we are using call by address.
}

// Print list in forward direction
void print_LL(struct node *start) {
    struct node *ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Print list in backward direction
void print_backward(struct node *last) {
    struct node *ptr = last;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}

int main() {
    struct node *start = NULL;
    struct node *last = NULL;
    int val;

    // Input values until -1 is entered
    scanf("%d", &val);
    while (val != -1) {
        insert_beg(&start, &last, val);//call by address
        scanf("%d", &val);
    }

    // Display forward and backward traversal
    printf("Traversing in forward direction:\n");
    print_LL(start);

    printf("\nTraversing in backward direction:\n");
    print_backward(last);

    // Display some info
    if (start && last) {
        printf("\nStarting element: %d", start->data);
        printf("\nLast element: %d", last->data);
        printf("\nStart address: %p", (void *)start);
        printf("\nLast address: %p\n", (void *)last);
    }

    return 0;
}
