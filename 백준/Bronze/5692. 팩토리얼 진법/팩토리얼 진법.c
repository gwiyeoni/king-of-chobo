#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int Factorial(int);

int main()
{
    while (1)
    {
        int sum = 0;
        char n[5] = "";
        scanf("%s", n);

        if (n[0] == '0')
        {
            break;
        }

        for (int i = 0; i < strlen(n); i++)
        {
            int temp = Factorial(strlen(n) - i);
            while (temp != 0)
            {
                sum += n[i] - '0';
                temp--;
            }
        }
        printf("%d\n", sum);
    }
}

int Factorial(int i)
{
    int result = 1;
    for (i; i > 0; i--)
    {
        result *= i;
    }
    return result;
}

