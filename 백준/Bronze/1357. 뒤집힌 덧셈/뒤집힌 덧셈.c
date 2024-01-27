#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int Rev(int x);

int main(void)
{
    //앞뒤가 똑같은 전화번호 1577!
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", Rev(Rev(x) + Rev(y)));
}

int Rev(int x)
{
    int result = 0;
    while (1)
    {
        result = result*10+(x % 10);
        x /= 10;
        if (x == 0)
        {
            return result;
            break;
        }
    }
}
