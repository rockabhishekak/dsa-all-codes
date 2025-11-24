#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
struct node *prev;
}Node;
//struct node *start=NULL;
//struct node *last= NULL;

struct node * createNode(int val)
{
    struct node *nn= (struct node *)malloc(sizeof(struct node));
    nn->data=val;
    nn->prev=NULL;
    nn->next=NULL;
return nn;
}
struct node *insert_beg(struct node *start, struct node **last, int val)
{
 struct node *nn= createNode(val);
 if(start==NULL)
 {
     start=nn;
     *last=nn;
 }
 else
{
 nn->next=start;
 start->prev=nn;
 start=nn;
 }
return start;
}

void print_forward(struct node *start)
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void print_backward(struct node *last)
{
    struct node *ptr=last;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
}
Node* delete_end(Node * start, Node **last)
{

    if(start==NULL)
        printf("DLL is already empty");
    else if(start==*last)
    {
        start=NULL;
        *last=NULL;
        printf("Last ele has been deleted successfully\n");
    }
    else
    {
        //start=start->next;
        //start->prev=NULL;
        *last=(*last)->prev;
        (*last)->next=NULL;
    }
  return start;
}
void search_delete (Node * start, Node **last, int key)
{
    Node *ptr=start;
    int found=0;
    while(ptr!=NULL)
    {
        if(ptr->data==key)
        {
            found=1;
            if(ptr->prev==NULL) //first node
                 start=delete_end(start, last);
              //  start=delete_beg(start, *last);
            else if(ptr->next==NULL) // last node
                start=delete_end(start, last);
            else
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
           // break;
        }
        else
            ptr=ptr->next;
    }
    if(found)
        printf("Found");
    else
       printf("Not found");
}
int main()
{
struct node *start=NULL;
struct node *last= NULL;
int val;
scanf("%d",&val);
while(val!=-1)
{
    start= insert_beg(start, &last,val);
    scanf("%d",&val);
}
print_forward(start);
printf("\n");
//printf("\nlast data= %d ", last->data);//1

//printf("Start data= %d", start->data);//6
//print_backward(last);

//start=delete_beg(start, &last);

//start=delete_end(start, &last);

//print_forward(start);
printf("\n");
int key;
scanf("%d",&key);
search_delete(start, &last, key);


}

