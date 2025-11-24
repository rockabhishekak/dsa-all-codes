#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node * createNode(int val)
{
    node *nn=(node*) malloc(sizeof(node));
    nn->data=val;
    nn->next=NULL;
    return nn;
}
node * insert_end(node *start, int val)
{
    node *nn= createNode(val);
    if(start->next==NULL)
        start->next=nn;
    else{
    node *ptr=start->next;
    while(ptr->next!=NULL)
        ptr=ptr->next;

    ptr->next=nn;
    }


    return start;
}
node* insert_beg(node *start, int val)
{
    node* nn=createNode(val);
    if(start->next==NULL)
        start->next=nn;
    else
        {
        nn->next=start->next;
        start->next=nn;
        }
        return start;
}
node * delete_beg(node * start)
{
    if(start->next==NULL)
        printf("LL is already empty\n");
    else
        start->next=start->next->next;

return start;

}
node * delete_end(node * start)
{
    if(start->next==NULL)
        printf("LL is already empty\n");
    else
        {
            node *ptr=start->next;
            while(ptr->next->next!=NULL)
            {
              ptr=ptr->next;
            }
            ptr->next=NULL;
        }

        return start;

}
void print_ll(node *start)
{
    node *ptr=start->next;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

}
int main()
{   node * start= createNode(0);
    int val;
    scanf("%d",&val);//10 20 30 -1
    while(val!=-1)
    {
    start=insert_end(start, val);
    scanf("%d",&val);
    }
    print_ll(start);

    start=delete_end(start);
//start=delete_end(start);
   printf("\n");
   print_ll(start);

    return 0;
}

