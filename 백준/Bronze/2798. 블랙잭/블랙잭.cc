#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> card(N);

    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }

    int result = 0;
    for (int i = 0; i < N - 2; i++)
        for (int j = i + 1; j < N - 1; j++)
            for (int k = j + 1; k < N; k++)
            {
                int sum = card[i] + card[j] + card[k];

                if (sum <= M)
                    result = max(sum, result);
            }

    cout << result << "\n";
}
