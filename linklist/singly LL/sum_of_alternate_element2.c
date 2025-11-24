#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void SUM(struct node * start)
{
    int sum=0;

    struct node *ptr1=start;
    struct node *ptr2=start->next;
    int s1=0;
    int s2=0;
    while(ptr1 != NULL )
    {
        s1=s1+ptr1->data;
        s2=s2+ptr2->data;
        ptr1=ptr1->next->next;
        ptr2=ptr2->next->next;
    }
    if(s1==s2)
    {
        printf("yes");
    }

    else 
    {
        printf("no");
    }

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
    int val,result,r;
    printf("Enter the value(for exit press -1)\n");
    scanf("%d",&val);
    while(val!=-1)
    {
        start=insert_end(start,val);
        scanf("%d",&val);
    }
    printf("Here is your singly linked list\n");
    print_LL(start);
    printf("\n");
    SUM(start);
    

}
