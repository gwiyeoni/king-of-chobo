#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
	long long int n;
	scanf("%lld", &n);
	long long int sum;


	sum = n*(n - 1)*(n - 2) / 6;
	printf("%lld\n", sum);
	printf("3");


}