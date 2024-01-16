#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>



int main() {

	while (1) {

		char a = 'a';

		char arr[251];

		int count = 0;

		scanf("%c", &a);

		if (a == '#') {

			return 0;

		}

		



		scanf("%[^\n]", arr);

        getchar();

		int i = 0;

		for (i; i < strlen(arr) ; i++) {

			if (arr[i] >= 65 && arr[i] <= 90) {

				arr[i] += 32;

			}

			

			if (a == arr[i]) {

				count += 1;

			}

		}



		printf("%c %d\n", a, count);

	}

}