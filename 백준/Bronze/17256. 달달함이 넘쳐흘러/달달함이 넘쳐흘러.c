#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int cake[9] = {0};
    scanf("%d %d %d", &cake[0], &cake[1], &cake[2]);
    scanf("%d %d %d", &cake[6], &cake[7], &cake[8]);
    cake[3] = cake[6] - cake[2];
    cake[4] = cake[7] / cake[1];
    cake[5] = cake[8] - cake[0];
    printf("%d %d %d", cake[3], cake[4], cake[5]);
    
}