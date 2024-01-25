#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



int main(void)
{
    //앞뒤가 똑같은 전화번호 1577!
    int n;
    scanf("%d", &n);
    getchar();
    char arr[19] = { 0 };
    for (int i = 0; i < n; i++)
    {
        int same = 1;

        scanf("%[^\n]s", arr);
        getchar();
        for (int j = 0; j <= strlen(arr)/2; j++)
        {
           
            if (tolower(arr[j]) != tolower(arr[strlen(arr) - j-1]))
            {
                printf("No\n");
                same = 0;
                break;
            }
        }
        if (same == 1)
            printf("Yes\n");
    }
}