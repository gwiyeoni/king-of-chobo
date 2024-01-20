#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main()
{
    char n[7];
    int nothing = 1;
    scanf("%s", n);
    int temp = atoi(n)-(strlen(n)*9);
    char result[7];
    for (int i = temp; i <= atoi(n); i++)
    {
        int sum = i;
        sprintf(result, "%d", i);
        for (int j = 0; j < strlen(result); j++)
        {
            sum += result[j] - '0';
        }
        if (atoi(n) == sum)
        {
            printf("%d", i);
            nothing = 0;
            break;
        }
    }
    if (nothing == 1)
    {
        printf("0");
    }
}

