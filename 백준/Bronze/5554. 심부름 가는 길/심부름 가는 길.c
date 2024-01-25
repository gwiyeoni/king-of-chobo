#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



int main(void)
{
    int second[4] = { 0 };
    int min = 0;
    int sec = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &second[i]);

        if (second[i] > 60) {
            min += second[i] / 60;
            sec += second[i] % 60;
        }
        else
        {
            sec += second[i];
        }
        if (sec >= 60)
        {
            min++;
            sec -= 60;
        }

    }
    printf("%d\n", min);
    printf("%d", sec);
}