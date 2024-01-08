#include<stdio.h>
int CheckScore(char n);

int main(void)
{
    int sum = 0;
    char arr[8][9];
    for (int i = 0; i < 8; i++)
    {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            sum += CheckScore(arr[i][j]);
        }
    }
    printf("%d", sum);

    return 0;
}

int CheckScore(char n)
{
    int result;
    if (n == 'k' || n == 'K') result = 0;
    else if (n == 'p' || n == 'P') result = 1;
    else if (n == 'n' || n == 'N') result = 3;
    else if (n == 'b' || n == 'B') result = 3;
    else if (n == 'r' || n == 'R') result = 5;
    else if (n == 'q' || n == 'Q') result = 9;
    else result = 0;
    
    if (n >= 'a' && n <= 'z') result = -result;

    return result;
}
