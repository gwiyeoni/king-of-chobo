#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>


int main(void)
{   
    int n;
    scanf("%d", &n);

    int** darg = (int**)malloc(sizeof(int*) * n);
    darg[0] = (int*)malloc(sizeof(int) * n * n);
    for (int i = 1; i < n; i++)
    {
        darg[i] = darg[i - 1] + n;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &darg[i][j]);
        }
    }

    int** sum = (int**)malloc(sizeof(int*) * (n+1));
    sum[0] = (int*)calloc((n+1) * (n+1), sizeof(int));
    for (int i = 1; i < n+1; i++)
    {
        sum[i] = sum[i - 1] + n + 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i + 1][j + 1] = darg[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
        }
    }


    int num;
    scanf("%d", &num);

    int x, y, xx, yy;
    for (int i = 0; i < num; i++)
    {
        int plus = 0, minus = 0;
        scanf("%d %d %d %d", &x, &y, &xx, &yy);

        plus = sum[xx-1][yy-1] - sum[x][yy-1] - sum[xx-1][y] + sum[x][y];
        minus = sum[xx][yy] - sum[x-1][yy] - sum[xx][y-1] + sum[x-1][y-1] - plus;

        printf("%d\n", plus - minus);
    }
    


    free(darg[0]);
    free(darg);
    free(sum[0]);
    free(sum);
}
