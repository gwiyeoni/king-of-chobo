#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>



int main(void)
{   

    int n, m;
    scanf("%d %d", &n, &m);

    int** arr = (int**)malloc(sizeof(int*) * (n+1));
    for (int i = 0; i < n+1; i++)
        arr[i] = (int*)malloc(sizeof(int)* (n+1));

    int** sum = (int**)malloc(sizeof(int*) * (n+1));
    for (int i = 0; i < n+1; i++)
        sum[i] = (int*)malloc(sizeof(int) * (n+1));


    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            scanf("%d", &arr[row][col]);
            sum[row][col] = sum[row-1][col]+sum[row][col-1]-sum[row-1][col-1]+arr[row][col];
        }
    }

    int  x1, y1, x2, y2;
    
    int zzin_sum;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        zzin_sum = sum[x2][y2] - sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
        printf("%d\n", zzin_sum);
    } 

    for (int i = 0; i <= n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    for (int i = 0; i <= n; i++)
    {
        free(sum[i]);
    }
    free(sum);
}