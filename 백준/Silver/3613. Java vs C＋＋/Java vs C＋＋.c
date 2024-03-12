#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char var[101];
    scanf("%s", var);
    
    int len = strlen(var);
    int isJava = 0, isC = 0;
    
    // 변수명이 C++ 형식인지 Java 형식인지 판별
    for(int i = 0; i < len; i++) {
        if(var[i] == '_') {
            if(i == 0 || i == len-1 || isJava || var[i-1] == '_') { // C++ 형식에 어긋나는 경우
                printf("Error!\n");
                return 0;
            }
            isC = 1;
        } else if(isupper(var[i])) {
            if(i == 0 || isC) { // Java 형식에 어긋나는 경우
                printf("Error!\n");
                return 0;
            }
            isJava = 1;
        }
    }
    
    // 변환 과정
    if(isC) {
        for(int i = 0; i < len; i++) {
            if(var[i] == '_') {
                var[i+1] = toupper(var[i+1]); // 다음 문자 대문자로 변경
            } else {
                printf("%c", var[i]);
            }
        }
    } else if(isJava) {
        for(int i = 0; i < len; i++) {
            if(isupper(var[i])) {
                printf("_%c", tolower(var[i])); // 대문자 앞에 _ 추가 후 소문자로 변경
            } else {
                printf("%c", var[i]);
            }
        }
    } else { // 이미 C++ 형식이거나, 변환할 필요가 없는 경우
        printf("%s", var);
    }
    
    printf("\n");
    return 0;
}
