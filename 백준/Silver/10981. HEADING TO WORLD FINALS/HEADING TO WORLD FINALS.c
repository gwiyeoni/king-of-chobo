#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct Uni {
	char uni_name[31];
	char team_name[31];
	int solved;
	int penalty;
}uni;


int compare(const void* a, const void* b)
{
	uni* uni1 = (uni*)a;
	uni* uni2 = (uni*)b;

	if (uni1->solved > uni2->solved) return -1;
	else if (uni1->solved < uni2->solved) return 1;
	else
	{
		if (uni1->penalty < uni2->penalty) return -1;
		else if (uni1->penalty > uni2->penalty) return 1;
		else return 0;
	}
}

uni arr[100001];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %d %d", &arr[i].uni_name, &arr[i].team_name, &arr[i].solved, &arr[i].penalty);
	}

	qsort(arr, n, sizeof(uni), compare);

	char** select = (char**)malloc(sizeof(char*)*k);
	for (int i = 0; i < k; i++)
	{
		select[i] = (char*)malloc(sizeof(char) * 31);
		strcpy(select[i], "");
	}

	int count = 0;

	for (int i = 0; i < n && count < k; i++)
	{
		int nono = 0;
		for (int j = 0; j < count; j++)
		{
			if (strcmp(select[j], arr[i].uni_name) == 0)
			{
				nono = 1;
				break;
			}
		}
		if (nono == 0)
		{
			strcpy(select[count], arr[i].uni_name);
			printf("%s\n", arr[i].team_name);
			count++;
		}
	}

	for (int i = 0; i < k; i++)
	{
		free(select[i]);
	}
	free(select);
}