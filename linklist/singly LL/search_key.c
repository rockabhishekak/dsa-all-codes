#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *creatnode(int val)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    new_node->next=NULL;
    return new_node;
}
void search_key(struct node *start)
{
    int key;
    printf("Enter the key\n");
    scanf("%d",&key);
    struct node *ptr=start;
    int found=0;
    while(ptr!=NULL)
    {
        if(ptr->data==key)
        {
            // printf("Key is found");
            found=1;
            break;
        }
        else{
            ptr=ptr->next;
        }
    }
    if(found==0)
    {
        printf("Key is not found.");
    }
    else{
        printf("Key is found");
    }
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
    printf("\n");
    search_key(start);
    printf("\n");
}
