//printing the sum of all the elements in LL 
// 1. Create a var for storing the sum i.e int SUM=0
// 2. Visit each node and add to SUM bucket
// SUM=SUM+...........?
// 3. Print the funal Sum

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
int SUM(struct node * start)
{
    int sum=0;
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        sum=sum+ptr->data;
        ptr=ptr->next;
    }
    return sum;
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
    int val,result;
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
    result=SUM(start);
    printf("The sum of all element = ");
    printf("%d",result);
    
}
