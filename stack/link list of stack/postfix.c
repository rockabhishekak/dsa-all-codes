#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char exp[20];
    int stack[20],top=-1,i;
    printf("Enter the postfix expression:");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(isdigit(exp[i]))
        {
            stack[++top]=exp[i]-'0';
        }
        else
        {
            int val1=stack[top--];
            int val2=stack[top--];
            switch(exp[i])
            {
                case '+': stack[++top]=val2+val1; break;
                case '-': stack[++top]=val2-val1; break;
                case '*': stack[++top]=val2*val1; break;
                case '/': stack[++top]=val2/val1; break;
            }
        }
    }
    printf("The result of the postfix expression is: %d\n",stack[top]);
    return 0;
}