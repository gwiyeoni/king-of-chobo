#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

long long int A[200000];

long long int compare(const void* a, const void* b);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);


    long long int sum = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
        sum += A[i];
    }

    qsort(A, n, sizeof(long long int), compare);


    int t;
    long long int q;
    long long int past = 0, j = 0;
    long long int remain = n;
    long long int increase = 0;
    long long int used_A = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %lld", &t, &q);

        increase += (t - past); // 증가한 시간

        if (q > sum + (increase * remain)) //sum에 증가한시간 * 남은 운영진 더한거
        {
            printf("-1");
            return 0;
        }

        while (q > used_A) // 조건 맞출 때 까지
        {
            used_A += A[j++] + increase; //누적역량 += 새 역량 + 증가한 시간
        }

        sum += remain * (t - past); //최종역량 += 남은 운영진 수 * 일 수 증가
        remain = n - j; // 남은 운영진 수 = 원래의 운영진 수 - 일한 운영진 수
        past = t; // 지난 시간 = 이번 시간
    }
    printf("%lld", sum);
}

long long int compare(const void* a, const void* b)
{
    long long int n1 = *(long long int*)a;
    long long int n2 = *(long long int*)b;


    if (n1 < n2)
        return 1;
    else if (n1 > n2)
        return -1;
    else return 0;
}