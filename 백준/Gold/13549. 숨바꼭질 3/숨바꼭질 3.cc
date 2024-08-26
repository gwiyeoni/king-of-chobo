#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int bfs(int N, int K) 
{
    if (N >= K) return N - K;

    vector<int> visited(200001, false);
    queue<pair<int, int>> q;
    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) 
    {
        int location = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (location == K) {
            return dist;
        }

        if (location * 2 <= 200000 && !visited[location * 2]) 
        {
            visited[location * 2] = true;
            q.push({ location * 2, dist });
        }
        if (location - 1 >= 0 && !visited[location - 1]) 
        {
            visited[location - 1] = true;
            q.push({ location - 1, dist + 1 });
        }
        if (location + 1 <= 200000 && !visited[location + 1]) 
        {
            visited[location + 1] = true;
            q.push({ location + 1, dist + 1 });
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << bfs(N, K) << "\n";
    return 0;
}
