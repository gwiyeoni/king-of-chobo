#include<stdio.h>
#include<string.h>

int main(void)
{
    int n, result;
    int ary[5] = { 0 };
    scanf("%d", &n);

    result = n%8;
    switch (result)
    {
    case 1:
        printf("1");
        break;
    case 2:
        printf("2");
        break;
    case 3:
        printf("3");
        break;
    case 4:
        printf("4");
        break;
    case 5:
        printf("5");
        break;
    case 6:
        printf("4");
        break;
    case 7:
        printf("3");
        break;
    case 0:
        printf("2");
        break;
    }

    
}