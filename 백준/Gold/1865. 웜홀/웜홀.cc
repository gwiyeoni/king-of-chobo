#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

#define INF (int)1e9

class Graph
{
public:
    int N, M, W;
    int S, E, T;
    vector<tuple<int, int, int>> graph;


public:
    Graph(int N, int M, int W)
    {
        this->N = N + 1;
        this->M = M;
        this->W = W;
        graph.resize(this->N);
    }

    void add_road()
    {
        for (int i = 0; i < M; i++)
        {
            cin >> S >> E >> T;
            graph.emplace_back(S, E, T);
            graph.emplace_back(E, S, T);
        }
    }

    void add_wormhole()
    {
        for (int i = 0; i < W; i++)
        {
            cin >> S >> E >> T;
            graph.emplace_back(S, E, -T);
        }
    }
};

bool bellman_ford(Graph& graph)
{
    vector<ll> visited(graph.N, INF);

    visited[1] = 0;

    for (int v = 1; v < graph.N; v++)
        for (const auto& edge : graph.graph)
        {
            auto [start, end, cost] = edge;
            if (visited[end] > visited[start] + cost)
            {
                if (v == graph.N - 1)
                {
                    return true;
                }
                visited[end] = visited[start] + cost;
            }
        }

    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    int N, M, W;
    while (TC--)
    {
        cin >> N >> M >> W;
        Graph graph(N, M, W);
        graph.add_road();
        graph.add_wormhole();

        if (bellman_ford(graph))
        {
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";
    }
}

