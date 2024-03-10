#include <stdio.h>

int main() {
    int N, i, j, count = 0, maxTruth = -1;
    scanf("%d", &N); // 항승이가 한 말의 개수 N 입력
    int statements[N]; // 정수 배열 선언
    
    for(i = 0; i < N; i++) {
        scanf("%d", &statements[i]); // 각 말에 대한 정수 입력
    }
    
    for(i = 0; i <= N; i++) { // 가능한 참인 말의 개수를 0부터 N까지 검사
        count = 0;
        for(j = 0; j < N; j++) {
            if(statements[j] == i) {
                count++; // 현재 가정한 참인 말의 개수가 실제로 몇 개인지 세기
            }
        }
        if(count == i) { // 가정한 참인 말의 개수와 실제로 센 개수가 같다면
            maxTruth = i; // 최대 참인 말의 개수 업데이트
        }
    }

    printf("%d\n", maxTruth); // 결과 출력
    return 0;
}
