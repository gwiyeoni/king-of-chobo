#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



int main(void)
{
    int second[4] = { 0 };
    int sum=0, min, sec;

    for (int i = 0; i < 4; i++) {
        scanf("%d", &second[i]);
        sum += second[i];
    }
    min = sum / 60;
    sec = sum % 60;

    printf("%d\n%d", min, sec);
}