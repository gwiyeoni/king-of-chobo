#include<stdio.h>
#include<string.h>

void RemoveBSN(char str[])
{
    int len = strlen(str);
    str[len - 1] = '\0';
}

int main(void)
{
    int a, result =0;
    scanf("%d", &a);
    getchar();

    for (int i = 0; i < a; i++)
    {
        char str[50];
        fgets(str, sizeof(str), stdin);
        RemoveBSN(str);
        if (strcmp(str, "Never gonna give you up") != 0 
            && strcmp(str, "Never gonna let you down") != 0
            && strcmp(str, "Never gonna run around and desert you") != 0
            && strcmp(str, "Never gonna make you cry") != 0
            && strcmp(str, "Never gonna say goodbye") != 0
            && strcmp(str, "Never gonna tell a lie and hurt you") != 0
            && strcmp(str, "Never gonna stop") != 0)
        {
            result = 1;
            break;
        }
    }   

    switch (result) {
    case 0:
        printf("No");
        break;
    case 1:
        printf("Yes");
        break;
    }
    return 0;
}