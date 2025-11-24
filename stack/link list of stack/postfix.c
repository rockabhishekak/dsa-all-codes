#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
    //i want to one or more digit numbers in postfix expression
    //but this code only works for single digit numbers
    //so please modify the code to work for one or more digit numbers in postfix expression
    //for example: 12 3 + 4 * should be valid postfix expression
    //and the result should be 60
    //also please make sure to handle spaces between numbers and operators
    //you can use strtok function to split the input string
    //and then process each token accordingly
    //here is the modified code
    //modified code starts here





    // char exp[100];
    // int stack[100],top=-1;
    // printf("Enter the postfix expression:");
    // fgets(exp, sizeof(exp), stdin);
    // char *token = strtok(exp, " \n");
    // while (token != NULL) {
    //     if (isdigit(token[0])) {
    //         stack[++top] = atoi(token);
    //     } else {
    //         int val1 = stack[top--];
    //         int val2 = stack[top--];
    //         switch (token[0]) {
    //             case '+': stack[++top] = val2 + val1; break;
    //             case '-': stack[++top] = val2 - val1; break;
    //             case '*': stack[++top] = val2 * val1; break;
    //             case '/': stack[++top] = val2 / val1; break;
    //         }
    //     }
    //     token = strtok(NULL, " \n");
    // }
    // printf("The result of the postfix expression is: %d\n", stack[top]);
    // return 0;
    // }







    
    // //modified code ends here

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