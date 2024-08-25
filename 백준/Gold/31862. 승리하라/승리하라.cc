#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int N, M, K;
vector<int> team;
vector<pii> arr;
int result = 0;

pii check(pii temp, int x)
{
    if (team[temp.first] < team[x])
    {
        swap(temp.first, temp.second);
        temp.first = x;
    }
    else if (team[temp.second] < team[x])
        temp.second = x;
    return temp;
}

void dfs(int n, pii temp)
{
    if (n == arr.size())
    {
        if (temp.first == K && (team[temp.first] > team[temp.second] || temp.first == temp.second))
            result++;
        return;
    }

    auto [a, b] = arr[n];

    team[a]++;
    dfs(n + 1, check(temp, a));
    team[a]--;
    team[b]++;
    dfs(n + 1, check(temp, b));
    team[b]--;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    team.resize(N + 1, 0);
    team[0] = -1;

    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        switch (c)
        {
        case 0:
            arr.push_back({ a, b });
            break;
        case 1:
            team[a]++;
            break;
        case 2:
            team[b]++;
            break;
        }
    }

    dfs(0, { K, 0 });

    cout << result << "\n";
}

