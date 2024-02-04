#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>



typedef struct Point {
    int x;
    char y[101];
    int z;
}Point;

int compare(const void*, const void*);

int main(void)
{
    int n;
    scanf("%d", &n);
    
    Point* member = (Point*)malloc(sizeof(Point)*n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &member[i].x, &member[i].y);
        member[i].z = i;
    }

    qsort(member, n, sizeof(Point), compare);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", member[i].x, member[i].y);
    }
    free(member);
}

int compare(const void* a, const void* b)
{
    Point* num1 = (Point*)a;
    Point* num2 = (Point*)b;

    if ((*num1).x < (*num2).x)
        return -1;
    else if ((*num1).x > (*num2).x)
        return 1;
    else if ((*num1).x = (*num2).x)
    {
        if ((*num1).z < (*num2).z)
            return -1;
        if ((*num1).z > (*num2).z)
            return 1;
        else return 0;
    }
}