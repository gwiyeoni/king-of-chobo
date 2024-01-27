#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int Stage(int q);

int main(void)
{
    int n;
    scanf("%d", &n);
    int q = (n + 4) / 6;
    printf("%d", Stage(q));
}

int Stage(int q)
{
    int temp = 1;
    int stage = 0;

    while (1)
    {
        if (q >= temp)
        {
            stage++;
            temp += stage;
        }
        else if (q < temp)
        {
            return stage+1;
        }

    }
}
