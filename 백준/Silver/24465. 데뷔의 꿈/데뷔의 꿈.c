#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct member {
    int month;
    int day;
}mem;

int compare(const void* a, const void* b) {
    mem* n1 = (mem*)a;
    mem* n2 = (mem*)b;
    if (n1->month != n2->month) {
        return n1->month - n2->month;
    }
    return n1->day - n2->day;
}

int Select(int month, int day);

int main()
{
    mem origin[7];
    int select[13] = { 0 };
    for (int i = 0; i < 7; i++)
    {
        scanf("%d %d", &origin[i].month, &origin[i].day);
        select[Select(origin[i].month, origin[i].day)]++;
    }
    int n;
    scanf("%d", &n);
    int temp_mon;
    int temp_day;
    mem* new_ = malloc(sizeof(mem)*n);
    int temp=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &temp_mon, &temp_day);
        if (select[Select(temp_mon, temp_day)]==0)
        {
            new_[temp].month = temp_mon;
            new_[temp].day = temp_day;
            temp++;
        }
    }

    if (temp==0)
    {
        printf("ALL FAILED");
        return 0;
    }

    qsort(new_, temp, sizeof(mem), compare);

    for (int i = 0;i<temp; i++)
    {
        printf("%d %d\n", new_[i].month, new_[i].day);
    }
    free(new_);
}

int Select(int month, int day)
{
    if (month == 1) 
        return day < 20 ? 12 : 1;
    else if (month == 2)
        return (day < 19) ? 1 : 2;
    else if (month == 3)
        return (day < 21) ? 2 : 3;
    else if (month == 4)
        return (day < 20) ? 3 : 4;
    else if (month == 5)
        return (day < 21) ? 4 : 5;
    else if (month == 6)
        return (day < 22) ? 5 : 6;
    else if (month == 7)
        return (day < 23) ? 6 : 7;
    else if (month == 8)
        return (day < 23) ? 7 : 8;
    else if (month == 9)
        return (day < 23) ? 8 : 9;
    else if (month == 10)
        return (day < 23) ? 9 : 10;
    else if (month == 11)
        return (day < 23) ? 10 : 11;
    else if (month == 12)
        return (day < 22) ? 11 : 12;
    return 0;
}