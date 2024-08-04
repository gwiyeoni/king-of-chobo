#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[10001];

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int m;
    scanf("%d", &m);

    qsort(arr, n, sizeof(int), compare);

    int result = 0;
    if (sum <= m)
        printf("%d\n", arr[n - 1]);
    else
    {
        int left = 1;
        int right = arr[n - 1];
        while (left <= right)
        {
            int count = 0;
            int mid = left + (right - left) / 2;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > mid)
                {
                    count += mid;
                }
                else count += arr[i];
            }

            if (count <= m)
            {
                left = mid + 1;
                result = mid;
            }
            else right = mid - 1;
        }
        printf("%d\n", result);
    }
}