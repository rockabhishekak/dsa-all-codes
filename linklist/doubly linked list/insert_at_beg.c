#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *pre;
};
struct node *creatnode(int val)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=NULL;
    new_node->pre=NULL;
    return new_node;
}
node* delete_beg(node *start,node **last)
{
    if(start==NULL)
        printf("DDL is already empty");
    else if{

    }

}
node* delete_end()
struct node *insert_beg(struct node *start,struct node last, int val)
{
    struct node * new_node=creatnode(val);
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {
        new_node->next=start;
        start=new_node;
    }
    return start;

}
void print_forward(struct node *start,struct node *last)
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node *start=NULL;
    struct node *last=NULL;
    int val;
    printf("Enter the value(for exit press -1)\n");
    scanf("%d",&val);
    while(val!=-1)
    {
        start=insert_beg(start, &last,val);
        scanf("%d",&val);
    }
    printf("Here is your doubly linked list\n");
    print_forward(start);
    printf("\n");
    start=delete_beg(&start,&last);
    
}