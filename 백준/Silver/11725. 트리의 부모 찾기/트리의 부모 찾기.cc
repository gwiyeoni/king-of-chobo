#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



void dfs(int v, vector<int>& mama, vector<vector<int>>& graph, vector<bool>& visited)
{
    for (int& w : graph[v])
    {
        if (!visited[w])
        {
            visited[w] = true;
            dfs(w, mama, graph, visited);
            mama[w] = v;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);

    int u, v;
    for (int i = 0; i < N-1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N + 1);
    vector<int> mama(N + 1);

    for (int i = 1; i < N + 1; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i, mama, graph, visited);
        }
    }

    for (int i = 2; i < N + 1; i++)
    {
        cout << mama[i] << "\n";
    }
}
