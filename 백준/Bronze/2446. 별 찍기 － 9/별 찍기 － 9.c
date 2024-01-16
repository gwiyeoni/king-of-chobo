#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j=0; j < 2 * (n - i)-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 1; i < n; i++)
    {
        printf(" ");
    }

    printf("*");

    if (n!=1) printf("\n");


    for (int i = n-1; i > 0; i--)
    {
        for (int j=1; j < i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * (n-i)+1; j++)
        {
            printf("*");
        }

        if (i!= 1) printf("\n");
    }

}