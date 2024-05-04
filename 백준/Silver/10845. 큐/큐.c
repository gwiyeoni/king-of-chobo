#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 10001



int isFull(int rear)
{
	return rear == MAX - 1;
}

void Push(int queue[], int* rear, int data)
{
	if (isFull(*rear))
	{
		return;
	}
	else
	{
		queue[++(*rear)] = data;
	}
}

int Pop(int queue[], int* front)
{
	int temp = queue[++(*front)];
	return temp;
}


int main()
{
	int queue[MAX];
	int front = -1, rear = -1;
	int data;

	int k;
	scanf("%d", &k);


	for (int i = 0; i < k; i++)
	{
		char command[6];
		scanf("%s", command);

		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &data);
			Push(queue, &rear, data);
		}
		else if (strcmp(command, "pop") == 0)
		{
			if (rear - front == 0)
			{
				printf("-1\n");
			}
			else
				printf("%d\n", Pop(queue, &front));
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", rear - front);
		}
		else if (strcmp(command, "empty") == 0)
		{
			if (rear - front == 0)
			{
				printf("1\n");
			}
			else printf("0\n");
		}
		else if (strcmp(command, "front") == 0)
		{
			if (rear - front == 0)
				printf("-1\n");
			else printf("%d\n", queue[front+1]);
		}
		else if (strcmp(command, "back") == 0)
		{
			if (rear - front == 0)
				printf("-1\n");
			else printf("%d\n", queue[rear]);
		}
	}
}