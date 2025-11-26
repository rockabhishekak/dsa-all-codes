#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int F=-1,R=-1;
void enque(int Q[],int val)
{
    if(R==MAX-1)
    {
        printf("Queue overflow");
        return;
    }
    else
    {
        if(F==-1)
        {
            F=0;
        }
        R=R+1;
        Q[R]=val;

    }
}
void deque(int Q[])
{
    if(F==-1)
    {
        printf("Queue underflow");
        return;
    }
    else{
        printf("Deleted element is %d ",Q[F]);
        F=F+1;
    }

}
void display(int Q[])
{
    int i;
    if(F==-1)
    {
        printf("Queue is empty");
        return;
    }
    else{
        printf("Elements in queue are:\n");
        for(i=F;i<=R;i++)
        {
            printf("%d ",Q[i]);
        }

    }
}
int main()
{
    int Q[10];
    int val;
    printf("Enter elements to be inserted in queue");
    scanf("%d",&val);
    while(val!=-1)
    {
        enque(Q,val);
        scanf("%d",&val);
    }
    display(Q);
    printf("\n");
    deque(Q);
    printf("\n");
    display(Q); 
    return 0;
}
