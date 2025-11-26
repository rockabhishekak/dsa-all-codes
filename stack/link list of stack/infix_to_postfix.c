#include<stdio.h>
#include<ctype.h>
int main()
{
    char infix[100], postfix[100], stack[100];
    int top = -1, j = 0;
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    for(int i=0;infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if(isalnum(ch))
        {
            postfix[j++] = ch;

        }
        else if(ch == '(')
        {
            stack[++top] = ch;
        }
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--; // pop '('
        }
        else
        {
            // operator: pop until lower precedence
            int prec;
            if(ch == '^')
                prec = 3;
            else if(ch == '*' || ch == '/' || ch == '%')
                prec = 2;
            else if(ch == '+' || ch == '-')
                prec = 1;
            else
                prec = 0; // unknown operator
        
            while(top != -1)
            {   
                int stackPrec;
                if(stack[top] == '^')
                    stackPrec = 3;
                else if(stack[top] == '*' || stack[top] == '/' || stack[top] == '%')
                    stackPrec = 2;
                else if(stack[top] == '+' || stack[top] == '-')
                    stackPrec = 1;
                else
                    stackPrec = 0;
                if(stackPrec >= prec)
                    postfix[j++] = stack[top--]; 
                else
                    break;
                
        }
        stack[++top] = ch; // push current operator

    }
}
    // pop remaining stacck items
    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0'; // null terminate
    printf("Postfix expression: %s\n", postfix);
    return 0;

    
}