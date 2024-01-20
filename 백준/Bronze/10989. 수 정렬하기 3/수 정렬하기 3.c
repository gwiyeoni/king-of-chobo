#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    int n, num;
    scanf("%d", &n);

    int count[10001] = { 0 };

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        count[num]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        while (count[i]--)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
