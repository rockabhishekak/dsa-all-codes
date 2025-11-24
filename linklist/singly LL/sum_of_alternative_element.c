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
    while(ptr != NULL)
    {
        sum = sum + ptr->data;
        if(ptr->next != NULL)
            ptr = ptr->next->next;  // Move two steps if possible
        else
            break;  // stop if no next node
    }
    return sum;

}
int S(struct node * start)
{
    int sum=0;
    struct node *ptr=start->next;
    while(ptr != NULL)
    {
        sum = sum + ptr->data;
        if(ptr->next != NULL)
            ptr = ptr->next->next; 
        else
            break; 
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
    result=SUM(start);
    printf("The sum of alternetive element = ");
    printf("%d",result);
    r=S(start);
    printf("\n");
    printf("%d",r);
    if(r==result)
    {
        printf("\nThe alternetive sum is equale\n");
    }
    else{
        printf("\nThe ealternetive sum is not equale");
    }


}
