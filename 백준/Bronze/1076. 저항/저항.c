#include<stdio.h>
#include<string.h>
typedef struct Point
{
    char name[10];
    char num[2];
    long long int mul;
} Point;


int main(void)
{
    Point color[10] = {
        {"black", "0", 1},
        { "brown", "1", 10 },
        { "red", "2", 100},
        { "orange", "3", 1000 },
        { "yellow", "4", 10000},
        { "green", "5", 100000},
        { "blue", "6",1000000},
        { "violet", "7",10000000},
        { "grey", "8",100000000},
        { "white", "9", 1000000000}
    };
    char resis[3][10];
    char sum[3] = { '\0' };
    long long int result = 0;
    for (int i = 0; i < 2; i++)
    {
        scanf("%s", resis[i]);
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(resis[i], color[j].name) == 0)
            {
                strcat(sum, color[j].num);
            }
        }
    }
    scanf("%s", resis[2]);
    for (int j = 0; j < 10; j++)
    {
        if (strcmp(resis[2], color[j].name) == 0)
        {
            result += color[j].mul;
        }
    }
    result *= atoi(sum);
    printf("%lld", result);
}