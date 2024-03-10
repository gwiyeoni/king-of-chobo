#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>


int main(void)
{   
    int start, finish;

    scanf("%d %d", &start, &finish);

    int n = 1, button = 1, f_s = finish-start;

    int cookie1 = 0, cookie2 = 0;

    int sum1 = 0, sum2 = 0, zzin_sum = 0;

    while (finish > 0)
    {
        start -= n;
        finish -= n;

        if (start <= 0 && button)
        {
            
            sum1 = start+n;
            if (f_s - n >= 0)
            {
                zzin_sum += (n + 1 - sum1) * n;
            }
            else
            {
                zzin_sum += f_s * n;
            }

            cookie1 = n+1;
            button = 0;
        }
        
        if (finish <= 0)
        {
            sum2 = finish+n;
            if (f_s - sum2 >= 0)
            {
                zzin_sum += sum2 * n;
            }
            else zzin_sum += n;
            cookie2 = n-1;
        }

        n++;
    }

    if (cookie1 > cookie2)
        cookie1 = 0, cookie2 = 0;

    for (int i = cookie1; i <= cookie2; i++)
    {
        zzin_sum += i * i;
    }

    printf("%d", zzin_sum);
}
