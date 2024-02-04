#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int Sum(int*, int, int);

int main(void)
{
    int n, m, x, y;

    scanf("%d %d", &n, &m);

    int* num = (int*)malloc(sizeof(int) * n);
    int* sum = (int*)malloc(sizeof(int) * (m+1));
    
    sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        sum[i+1] = sum[i] + num[i];
    }
    //sum 5, 9, 12, 14, 15
    for (int i = 0; i < m; i++)
    {
        int result = 0;
        scanf("%d %d", &x, &y);
        result = sum[y] - sum[x-1];
        printf("%d\n", result);
    }

    free(num);
    free(sum);
}