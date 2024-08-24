#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int sequence[9];
map<int, int> arr;
vector<int> visited(10001, 0);
int N, M;

void dfs(int n)
{
    if (n == M)
    {
        for (int i = 0; i < n; i++)
            cout << sequence[i] << " ";
        cout << "\n";
        return;
    }

    for (auto i : arr)
    {
        if (visited[i.first] < i.second)
        {
            visited[i.first]++;
            sequence[n] = i.first;
            dfs(n + 1);
            visited[i.first]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        auto it = arr.insert({ temp, 1 });
        if (!it.second)
        {
            arr[temp]++;
        }
    }

    dfs(0);
}