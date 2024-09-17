#include <iostream>
#include <vector>
using namespace std;

// 셔플 기술을 한 번 적용하는 함수
vector<int> applyShuffle(const vector<int>& current, const vector<int>& shuffle) {
    int N = current.size();
    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
        result[i] = current[shuffle[i] - 1]; // shuffle[i]는 1부터 N까지의 값이므로 -1 해줌
    }
    return result;
}

// 셔플 기술을 여러 번 적용하는 함수
vector<int> applyShuffleMultiple(const vector<int>& current, const vector<int>& shuffle, long long times) {
    int N = current.size();
    vector<int> result = current;
    
    // 셔플을 최대 times 번 반복하지만, times % N 번만 하면 됨
    times = times % N;
    for (long long i = 0; i < times; ++i) {
        result = applyShuffle(result, shuffle);
    }
    
    return result;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    // 각 셔플 기술 저장
    vector<vector<int>> shuffles(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> shuffles[i][j];
        }
    }

    // 처음 카드 배열
    vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        cards[i] = i + 1;
    }

    // K번의 셔플 실행
    for (int i = 0; i < K; ++i) {
        int X;
        long long Y;
        cin >> X >> Y;
        --X; // 셔플 번호를 0-index로 맞춤

        // X번 셔플 기술을 Y번 적용
        cards = applyShuffleMultiple(cards, shuffles[X], Y);
    }

    // 최종 결과 출력
    for (int i = 0; i < N; ++i) {
        cout << cards[i] << " ";
    }
    cout << endl;

    return 0;
}
