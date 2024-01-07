#include<stdio.h>
#include<stdlib.h>
typedef struct Point
{
    int num;
    int rank;
} Point;

int main(void)
{
    int test;
    scanf("%d", &test);
    Point* arr = (Point*)malloc(sizeof(Point) * test);
    for (int i = 0; i < test; i++)
    {
        arr[i].num = i+1;
        scanf("%d", &arr[i].rank);
    }
    for (int i = 0; i < test; i++)
    {
        if (arr[i].rank > 4500)
            printf("Case #%d: Round 1\n", i+1);
        else if (arr[i].rank > 1000)
            printf("Case #%d: Round 2\n", i+1);
        else if (arr[i].rank > 25)
            printf("Case #%d: Round 3\n", i+1);
        else
            printf("Case #%d: World Finals\n", i+1);
    }
    free(arr);
}