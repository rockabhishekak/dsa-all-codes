#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *delete_beg(struct node *start)
{
    if(start==NULL)
    {
        printf("LL is already empthy.");
    }
    else
    start=start->next;
    return start;
}
struct node *creatnode(int val)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=NULL;
    return new_node;
}
void print_LL(struct node *start)
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
struct node *insert_end(struct node *start,int val)
{

    struct node * new_node=creatnode(val);
    
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {
        
        struct node *ptr=start;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
    return start;

}
int main()
{
    struct node *start=NULL;
    int val;
    printf("Enter the value(for exit press -1)\n");
    scanf("%d",&val);
    while(val!=-1)
    {
        start=insert_end(start,val);
        scanf("%d",&val);
    }
    printf("Here is your singly linked list\n");
    print_LL(start);
    start=delete_beg(start);
    printf("\n");
    print_LL(start);
    
}
