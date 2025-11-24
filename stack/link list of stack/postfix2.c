#include<stdio.h>
#include<ctype.h>
int main()
{
    char expr[100];
    int stack[100], top = -1;
    printf("Enter a postfix expression: ");
    scanf("%s", expr);
    for(int i = 0; expr[i] != '\0'; i++)
    {
        char ch = expr[i];
        if(isdigit(ch))
        {
            stack[++top] = ch - '0';
        }
        else
        {
            int val2 = stack[top--]; //pop()
            int val1 = stack[top--]; //pop()
            int result;
            switch(ch)
            {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: 
                    printf("Invalid operator: %c\n", ch);
                    return 1;
            }
            stack[++top] = result; //push(result)
            
        }
    }
    printf("The result of the postfix expression is: %d\n",stack[top]);
    return 0;
}
    