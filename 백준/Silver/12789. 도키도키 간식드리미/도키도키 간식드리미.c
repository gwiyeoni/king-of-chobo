#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 1001



int isFull(int top)
{
	return top == MAX - 1;
}

int Empty(int top)
{
	return top == - 1;
}

void Push(int stack[], int* top, int data)
{
	if (isFull(*top))
	{
		return;
	}
	else
	{
		stack[++(*top)] = data;
	}
}

int Pop(int stack[], int* top)
{
	if (Empty(*top))
	{
		return -1;
	}
	int temp = stack[*top];
	(*top)--;
	return temp;
}

int Search(int stack[], int top, int rank)
{
	while (top != -1)
	{
		if (stack[top] == rank)
			return 1;
		top--;
	}
	return 0;
}


int main()
{
    int stack[MAX];
	int stack_temp[MAX];


	int k;
	scanf("%d", &k);

	int top = k-1;
	int top_temp = -1;


	for (int i = k-1; i >= 0 ; i--)
	{
		scanf("%d", &stack[i]);
    }

	int rank = 1;
	while (1)
	{
		if ((top != -1) && (Search(stack, top, rank)==1))
		{
			while (1)
			{
				int data = Pop(stack, &top);
				if (rank == data)
				{
					rank++;
					break;
				}
				else Push(stack_temp, &top_temp, data);
			}
		}
		else if (top_temp != -1)
		{
			if (rank == stack_temp[top_temp])
			{
				int data_temp = Pop(stack_temp, &top_temp);
				rank++;
			}
			else
			{
				printf("Sad");
				break;
			}
		}
		
		if (rank == k)
		{
			printf("Nice");
			break;
		}
	}
}