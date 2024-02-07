#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>


typedef struct Point
{
    int num;
    char name[21];
} Point;

int binary_search(Point* , int, char*);

int compare(const void*, const void*);


int main(void)
{   

    int n, m;
    scanf("%d %d", &n, &m);

    Point* p1 = (Point*)malloc(sizeof(Point) * n);
    Point* p2 = (Point*)malloc(sizeof(Point) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &p1[i].name);
        p1[i].num = i + 1;

        p2[i] = p1[i];
    }

    qsort(p2, n, sizeof(Point), compare);

    
    for (int i = 0; i < m; i++)
    {
        char result[21] = { 0 };
        scanf("%s", result);

        if (isdigit(result[0]))
        {
            int temp;
            sscanf(result, "%d", &temp);
            temp--;
            printf("%s\n", p1[temp].name);
        }
        else printf("%d\n", binary_search(p2, n, result));
    }

    
    free(p1);
    free(p2);
}

int binary_search(Point* p2, int n, char* result)
{
    int high, mid, low;
    high = n-1, low = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (strcmp(result, p2[mid].name) == 0)
            return p2[mid].num;
        else if (strcmp(result, p2[mid].name) < 0)
            high = mid - 1;
        else low = mid + 1;
    }
}

int compare(const void* a, const void* b)
{
    Point* n1 = (Point*)a;
    Point* n2 = (Point*)b;

    return strcmp(n1->name, n2->name);
}