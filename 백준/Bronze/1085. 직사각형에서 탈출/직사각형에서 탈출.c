#include<stdio.h>
#include<string.h>

int main(void)
{
    int x, y, w, h;
    int arr[4] = { 0 };
    scanf("%d %d %d %d", &x, &y, &w, &h);
    arr[0] = x; arr[1] = y; arr[2] = w - x; arr[3] = h - y;
    int temp;
    temp = arr[0];
    for (int i = 1; i < 4; i++)
    {
        if (arr[i] < temp)
        {
            temp = arr[i];
        }
    }
    printf("%d", temp);
}