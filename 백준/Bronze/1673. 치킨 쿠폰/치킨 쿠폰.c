#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int Chick(int n, int k);

int main(void)
{

    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        printf("%d\n", Chick(n, k));
    }
}

int Chick(int n, int k)
{
    int sum = n;
    while (n >= k)
    {
        sum += n / k;
        n = n / k + n % k;
    }
    return sum;
}
