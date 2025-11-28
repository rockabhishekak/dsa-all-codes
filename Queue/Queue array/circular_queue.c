#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void enQ(int Q[], int* F, int* R, int val)
{
    if((*F==0 && *R==MAX-1) || *R==*F-1)
    {
        printf("Q is full\n");
        return;
    }
    else if(*R==MAX-1 && *F!=0)
    {
        *R= 0;
    }
    else if(*F == -1 && *R == -1)
    {
        *F = *R = 0;
    }
    else
    {
        (*R)++;
    }
    Q[*R] = val;
}
void deQ(int Q[], int* F, int* R)
{
    if(*F == -1 && *R == -1)
    {
        printf("Q is empty\n");
        return;
    }
    else if(*F == *R)
    {
        *F = *R = -1;
    }
    else if(*F == MAX-1 && *R<*F)
    {
        *F = 0;
    }
    else
    {
        (*F)++;
    }
}
int main()
{
    int Q[MAX];
    int F = -1, R = -1;
    int data;
    scanf("%d", &data);
    while(data != -1)
    {
        enQ(Q, &F, &R, data);
        scanf("%d", &data);
    }
    deQ(Q, &F, &R);
    deQ(Q, &F, &R);
    deQ(Q, &F, &R);

    printf("Q elements are:\n");
    if(F == -1 && R == -1)
    {
        printf("Q is empty\n");
    }
    else
    {
        int i = F;
        while(1)
        {
            printf("%d\n", Q[i]);
            if(i == R)
                break;
            i = (i + 1) % MAX;
        }
    }
    return 0;
}