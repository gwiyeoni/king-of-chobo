#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
	char arr[101];


	scanf("%[^\n]", arr);
	getchar();

	int c = 0;
	int java = 0;

	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == '_')
		{
			if (i == 0 || i == strlen(arr) - 1
				|| java == 1 || arr[i - 1] == '_'
				|| strchr(arr, ' ') != NULL)
			{
				printf("Error!\n");
				return 0;
			}
			c = 1;
		}
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			if (i == 0 || c == 1)
			{
				printf("Error!\n");
				return 0;
			}

			java = 1;
		}
	}

	if (c == 1)
	{
		for (int i = 0; i < strlen(arr); i++)
		{
			if (arr[i] == '_')
			{
				i++;
				arr[i] -= 32;
			}
			printf("%c", arr[i]);
		}
	}
	else if (java == 1)
	{
		for (int i = 0; i < strlen(arr); i++)
		{
			if (arr[i] >= 'A' && arr[i] <= 'Z')
			{
				printf("_%c", arr[i] + 32);
			}
			else
				printf("%c", arr[i]);
		}
	}
	else
		printf("%s", arr);

	printf("\n");
	return 0;
}