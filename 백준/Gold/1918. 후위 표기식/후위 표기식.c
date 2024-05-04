#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 101

char stack[MAX];
int top = -1;
int exist_rapen = 0;

void Transform(char infix_stack[], char postfix_stack[]);
int Oper_Value(char infix_stack);
void Paren(char infix_stack, char postfix_stack[], int* post_top);

int main()
{

    char infix_stack[MAX];
    char postfix_stack[MAX];

    scanf("%s", infix_stack);
    Transform(infix_stack, postfix_stack);
    printf("%s", postfix_stack);

    //while (1)
    //{
    //    printf("중위식 : ");
    //    scanf("%s", infix_stack);

    //    if (infix_stack[0] == '1')
    //    {
    //        printf("종료합니다.\n");
    //        break;
    //    }

    //    Transform(infix_stack, postfix_stack);


    //    printf("후위식 : %s\n", postfix_stack);
    //}
}

void Transform(char infix_stack[], char postfix_stack[])
{
    int post_top = -1;
    for (int i = 0; i < strlen(infix_stack); i++)
    {
        int value = Oper_Value(infix_stack[i]);
        switch (value)
        {
        case 1: case 2:
            if (top == -1)
                stack[++top] = infix_stack[i];
            else
            {
                if (Oper_Value(stack[top]) < value)
                    stack[++top] = infix_stack[i];
                else
                {
                    while ((Oper_Value(stack[top]) >= value)&&(Oper_Value(stack[top])!=3))
                        postfix_stack[++post_top] = stack[top--];
                    stack[++top] = infix_stack[i];
                }
            }
            break;
        case 3:
            if (top == -1)
                stack[++top] = infix_stack[i];
            else
            {
                Paren(infix_stack[i], postfix_stack, &post_top);
            }
            break;
        default:
            postfix_stack[++post_top]=infix_stack[i];
            break;
        }
    }
    while (top != -1)
    {
        postfix_stack[++post_top] = stack[top--];
    }
    postfix_stack[++post_top] = '\0';
}

int Oper_Value(char infix_stack)
{
    char temp = infix_stack;

    if ((temp == '+') || (temp == '-'))
        return 1;
    else if ((temp == '*') || (temp == '/'))
        return 2;
    else if ((temp == '(') || (temp == ')'))
        return 3;
    else return 0;
}

void Paren(char infix_stack, char postfix_stack[], int* post_top)
{
    if (infix_stack == '(')
    {
        stack[++top] = infix_stack;
    }
    else if (infix_stack == ')')
    {
        while (stack[top] != '(')
        {
            postfix_stack[++(*post_top)] = stack[top--];
        }
        if (top != -1) top--;
    }
}
