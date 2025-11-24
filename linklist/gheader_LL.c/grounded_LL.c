#include<stdlib.h>
#include<stdio.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;                         //jaha pe struct node likhete hai waha pe ye karne se sirf node likhana padega 

node* createNode(int val)
{
    node * nn=(node*)malloc(sizeof(node));
    nn->data=val;
    nn->next=NULL;
    return nn;

}
node* insert_beg(node *start,int val)
{
    node *nn=createNode(val);
    nn->next=start->next;
    start->next=nn;
    return start;
}
void print_LL(node *start)
{
    node* ptr=start->next;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;

    }
}
node* delete_beg(node * start)
{
    if(start->next==NULL)
    {
        printf("LL is empty\n");
    }
    else{
        start->next=start->next->next;
    }
    return start;
    
    
}
int main()
{

    int val;
    node * start=createNode(0);
    scanf("%d",&val);

    while(val!=-1)
    {
        start=insert_beg(start,val);
        scanf("%d",&val);
    }
    print_LL(start);
    printf("\n");
    delete_beg(start);
    print_LL(start);


    return 0;
}
