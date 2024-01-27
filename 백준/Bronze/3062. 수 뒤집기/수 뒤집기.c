#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>



int main(void)
{
    //앞뒤가 똑같은 전화번호 1577!
    int n;
    scanf("%d", &n);
    getchar();
    char num[7] = { 0 };
    char num_t[7] = { 0 };
    char result[7] = { 0 };
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int same = 1;

        scanf("%[^\n]s", num);
        getchar();

        for (int j = 0; j < strlen(num); j++)
        {
            num_t[j] = num[strlen(num) - j - 1];
        }
        for (int j = 0; j < strlen(num); j++)
        {
            sum += (num_t[j] - '0' + num[j] - '0') * pow(10,(strlen(num) - j-1));
        }

        sprintf(result, "%d", sum);
        for (int j = 0; j <= strlen(result) / 2; j++)
        {
            if (result[j] != result[strlen(result) - j - 1])
            {
                printf("NO\n");
                same = 0;
                break;
            }
        }  

        if (same == 1)
            printf("YES\n");

        memset(num_t, 0, sizeof(char) * 7);
        memset(result, 0, sizeof(char) * 7);
    }
}