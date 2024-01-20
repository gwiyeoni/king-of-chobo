#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int binary_search(int* num, int n, int mum);

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}


int main()
{
    int n, m;
    scanf("%d", &n);
    int* num = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    qsort(num, n, sizeof(int), compare);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int mum;
        scanf("%d", &mum);
        printf("%d\n", binary_search(num, n, mum));
    }

    free(num);
    return 0;
}

int binary_search(int* num, int n, int mum)
{
    int low, high, mid;

    low = 0; high = n - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mum == num[mid])
            return 1;
        else if (mum < num[mid])
            high = mid - 1;
        else if (mum > num[mid])
            low = mid + 1;
    }
    return 0;
}
