#include<stdio.h>

int main(void)
{
    int a, b, c, d;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);

    int min, max;
    min = c - d;
    max = c + d;

    if (max < a || min > b)
    {
        printf("IMPOSSIBLE");
        return 0;
    }
    
    if (min < a) min = a;
    if (max > b) max = b;
    printf("%d", max - min + 1);
    return 0;
        
}