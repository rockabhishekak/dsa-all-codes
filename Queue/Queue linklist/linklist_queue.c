#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}N;
void enqueue(N** front, N** rear, int val)
{
    N* newNode = (N*)malloc(sizeof(N));
    newNode->data = val;
    newNode->next = NULL;
    if (*rear == NULL)
    {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}
void dequeue(N** front, N** rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    N* temp = *front;
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;
    free(temp);
}

int main()
{
    N* front = NULL;
    N* rear = NULL;
    int data;
    scanf("%d", &data);
    while(data != -1)
    {
        enqueue(&front, &rear, data);
        scanf("%d", &data);
    }
    printf("Dequeuing elements:\n");
    while(front != NULL)
    {
        printf("%d\n", front->data);
        dequeue(&front, &rear);
    }
    return 0;
    
    

}