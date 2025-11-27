#include<stdio.h>
#include<stdlib.h> 
#define MAX 10
int F=-1,R=-1;
void enque_front(int Q[],int val)
{
    if(F==0)
    {
        printf("Queue overflow at front");
        return;
    }
    else
    {
        if(F==-1)
        {
            F=0;
            R=0;
        }
        else
        {
            F=F-1;
        }
        Q[F]=val;

    }
}
void deque_front(int Q[])
{
    if(F==-1)
    {
        printf("Queue underflow at front");
        return;
    }
    else
    {
        printf("Deleted element is %d\n",Q[F]);
        if(F==R)
        {
            F=-1;
            R=-1;
        }
        else
        {
            F=F+1;
        }
    }
}
void deque_rear(int Q[])
{
    if(R==-1)
    {
        printf("Queue underflow at rear");
        return;
    }
    else
    {
        printf("Deleted element is %d\n",Q[R]);
        if(F==R)
        {
            F=-1;
            R=-1;
        }
        else
        {
            R=R-1;
        }
    }
}
void enque_rear(int Q[],int val)
{
    if(R==MAX-1)
    {
        printf("Queue overflow at rear");
        return;
    }
    else
    {
        if(F==-1)
        {
            F=0;
            R=0;
        }
        else
        {
            R=R+1;
        }
        Q[R]=val;

    }
}

int main()
{
    int Q[10];
    int val;
    printf("Enter elements to be inserted at front (-1 to stop): ");
    scanf("%d",&val);
    while(val!=-1)
    {
        enque_front(Q,val);
        printf("Enter elements to be inserted at front (-1 to stop): ");
        scanf("%d",&val);
    }

    printf("Enter elements to be inserted at rear (-1 to stop): ");
    scanf("%d",&val);
    while(val!=-1)
    {
        enque_rear(Q,val);
        printf("Enter elements to be inserted at rear (-1 to stop): ");
        scanf("%d",&val);
    }
    printf("Elements in the double ended queue are:\n");
    for(int i=F;i<=R;i++)
    {
        printf("%d ",Q[i]);
    }
    printf("\n");
    deque_front(Q);
    deque_rear(Q);
    printf("Elements in the double ended queue after deletion are:\n");
    for(int i=F;i<=R;i++)
    {
        printf("%d ",Q[i]);
    }
    


    return 0;
}