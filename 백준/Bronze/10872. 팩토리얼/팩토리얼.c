#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n, sum=1;
    scanf("%d", &n);
    for (int i = n; i > 0; i--)
    {
        sum *= i;
    }

    printf("%d", sum);
}