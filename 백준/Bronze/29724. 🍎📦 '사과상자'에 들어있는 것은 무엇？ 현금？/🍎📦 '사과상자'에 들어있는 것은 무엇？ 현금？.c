#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>


int main(void)
{
    int n;
    scanf("%d", &n);

    char t;
    int w, h, l;
    int weight = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c %d %d %d", &t, &w, &h, &l);

        if (t == 'A')
        {
            sum += (w / 12) * (h / 12) * (l / 12);
            weight += (w / 12) * (h / 12) * (l / 12) * 500 + 1000;
        }
        else weight += 120 * 50;
        
    }

    printf("%d\n", weight);
    printf("%d", sum * 4000);
}
