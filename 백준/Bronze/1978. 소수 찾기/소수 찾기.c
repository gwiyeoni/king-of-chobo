#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
{
    int n, prime;
    int result = 0;
    scanf("%d", &n);
    int *num = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        prime = 1;
        scanf("%d", &num[i]);
        if (num[i] == 1)
        {
            prime = 0;
        }
        for (int j = 2; j < num[i]; j++)
        {
            if (num[i] % j == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime == 1)
            result++;
    }
    printf("%d", result);

    free(num);
}