#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>


int main(void)
{
    int n;
    scanf("%d", &n);
    int s, button=0;
    int num[51] = { 0 };
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s);
        num[s]++;
    }

    int temp = 0;

    if (num[0] == n)
    {
        printf("-1");
    }
    else
    {
        for (int i = 0; i <= n; i++)
        {
            if (num[i]==i)
            {
                temp = i;
                button = 1;
            }
        }

        if (button==1)
        {
            printf("%d", temp);
        }
        else printf("-1");
            
    }

}
