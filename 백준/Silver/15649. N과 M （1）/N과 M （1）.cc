#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> sequence;
vector<bool> visited;

void dfs(int sum, int N, int M)
{
    if (sum == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            sequence.push_back(i);
            dfs(sum+1, N, M);
            visited[i] = false;
            sequence.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    visited.resize(N + 1, false);

    int sum = 0;
    dfs(0, N, M);
}