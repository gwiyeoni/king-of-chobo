#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>



typedef struct Point {
    int x;
    int y;
}Point;

int compare(const void* a, const void* b)
{
    Point* num1 = (Point*)a;
    Point* num2 = (Point*)b;

    if ((*num1).y < (*num2).y)
        return -1;
    else if ((*num1).y > (*num2).y)
        return 1;
    else if ((*num1).y = (*num2).y)
    {
        if ((*num1).x < (*num2).x)
            return -1;
        if ((*num1).x > (*num2).x)
            return 1;
        else return 0;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    Point* num = (Point*)malloc(sizeof(Point)*n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &num[i].x, &num[i].y);
    }

    qsort(num, n, sizeof(Point), compare);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", num[i].x, num[i].y);
    }
    free(num);
}