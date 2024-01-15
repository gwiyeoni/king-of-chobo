#include<stdio.h>
#include<string.h>

int main(void)
{
    int arr[5] = { 0 };
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < 40)
            arr[i] = 40;
    }
    int result = (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]) / 5;
    printf("%d", result);

}