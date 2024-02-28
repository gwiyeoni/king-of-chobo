#include <stdio.h>
#include <string.h>

#define MAX 200001

int psum[26][MAX];

int main() {
    char S[MAX];
    scanf("%s", S);

    int len = strlen(S);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            psum[j][i + 1] = psum[j][i];
        }
        psum[S[i] - 'a'][i + 1]++;
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        char arr;
        int l, r;
        scanf(" %c %d %d", &arr, &l, &r);

        printf("%d\n", psum[arr - 'a'][r + 1] - psum[arr - 'a'][l]);
    }

    return 0;
}
