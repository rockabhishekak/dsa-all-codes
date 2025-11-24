#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node * createNode(int val)
{
    node * nn= (node*)malloc(sizeof(node));
    nn->data=val;
    nn->next=NULL;
    return nn;
}
node * insert_beg(node *start, int val)
{
    node *nn=createNode(val);
    nn->next=start->next;
    start->next=nn;

    return start;
}
node * insert_end(node *start, int val)
{
    node *nn=createNode(val);
    node *ptr=start->next;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->next=start;

    return start;
}

void print_ll(node *start)
{  node* ptr=start->next;
//printf("entered the print func\n");
while(ptr!=start)
{
    printf("%d ",ptr->data);
    ptr=ptr->next;
}
}
node* delete_beg(node *start)
{
    if(start->next==start)
        printf("LL is empty\n");
    else
   // start=start->next;
    start->next=start->next->next;
    return start;
}

node* delete_end(node *start)
{
    if(start->next==start)
        printf("LL is empty\n");
    else
    {
        node *ptr=start;
        while(ptr->next->next!=start)
            ptr=ptr->next;
        ptr->next=start;

    }
    return start;
}
int main()
{   node * start= createNode(0);
    start->next=start;
    int val;
    scanf("%d",&val);//-1
    while(val!=-1)
    {
    start=insert_beg(start, val);
    scanf("%d",&val);
    }
    print_ll(start);
    //start=delete_beg(start);
    //printf("\n");
    //print_ll(start);

    return 0;
}

