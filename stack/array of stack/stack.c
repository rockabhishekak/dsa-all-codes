#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 15
int N,top=-1;


// finding the top element
int peek_ele(int stk[])
{
    return stk[top];
}


//insert the data
void push(int stk[],int val)
{
    if(top==N-1)
    {
        printf("Stack is full");
        

    }
    else
    {
        top++;
        stk[top]=val;
    }
}

//delete the data
void pop(int stk[])
{
    int data;
    if(top==-1)
    printf("stack is empty");
    else{
            data=stk[top];
            top--;
    }
    printf("pop data is %d\n",data);

}

// is empty or not
bool Isempty(int stk[])
{
    if(top==-1)
    {
        return true;
    }
    else{
        return false;
    }
}

//isFull functions

bool IsFull(int stk[])
{
    if(top==N-1)
    return true;
    else
    return false;
}


//main fuctions
int main()
{
    int stk[100];
    int val;
    scanf("%d",&N);
    scanf("%d",&val);
    while(val!=-1)
    {
        push(stk,val);
        scanf("%d",&val);
    }
    // while(top!=-1)
    // {
    //     pop(stk);
    // }
    // printf("The topmost ele is %d",peek_ele(stk));
    // pop(stk);
    // printf("The topmost ele is %d",peek_ele(stk));


    // isempty or not //


    // int res=Isempty(stk);
    // if(res==1)
    // {
    //     printf("\nYes it is empty");
    // }
    // else{
    //     printf("\nNo it is not empty");
    // }

    
    //finding the is full or not //


    bool result=IsFull(stk);
    if(result==1)
    {
        printf("\nYes it is Full");
    }
    else{
        printf("\nNo it is not FULL");
    }
    

    
    return 0;
}
