#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int Check(int *, int n);

int main(void)
{
    //달에 마구니가 꼈다! 누가 기침소리를 내었는가!
    int n;
    scanf("%d", &n);

    int peak[30000] = { 0 };
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &peak[i]);
    }

    printf("%d", Check(peak, n));
}

int Check(int *peak, int n)
{
    int temp = peak[0];
    int temp_death = 0;
    int death = 0;
    for (int i = 1; i < n; i++) {
        if (temp < peak[i])
        {
            temp = peak[i];
            if (death < temp_death)
            {
                death = temp_death;
            }
            temp_death = 0;
        }
        else if (temp > peak[i])
        {
            temp_death++;
        }

    }
    if (death < temp_death)
        return temp_death;
    else return death;
}
