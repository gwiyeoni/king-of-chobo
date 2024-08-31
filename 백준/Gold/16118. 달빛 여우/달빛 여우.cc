#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

#define INF (int)2e9

class Graph
{
public:
    int N, M;
    int a, b, d;
    vector<vector<pii>> path;

public:
    Graph(int N, int M) : N(N), M(M), path(N + 1) {}

    void add_edge()
    {
        for (int i = 0; i < M; i++)
        {
            cin >> a >> b >> d;
            path[a].push_back({ b, d * 2 });
            path[b].push_back({ a, d * 2 });
            //숫자보정
        }
    }
};


vector<int> Dijkstra_fox(Graph& graph)
{
    vector<int> dist(graph.N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        auto [cost, start] = pq.top();
        pq.pop();

        if (dist[start] < cost) continue;
        for (const auto& edge : graph.path[start])
        {
            auto [end, weight] = edge;

            if (dist[end] > cost + weight)
            {
                dist[end] = cost + weight;
                pq.push({ dist[end], end });
            }
        }
    }
    return dist;
}

vector<vector<int>> Dijkstra_wolf(Graph& graph)
{
    int next_level;
    vector<vector<int>> dist(graph.N + 1, vector<int>(2, INF));
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

    dist[1][0] = 0;
    pq.push({ 0, 1, 0 });

    while (!pq.empty())
    {
        auto [cost, start, level] = pq.top();
        pq.pop();

        if (dist[start][level] < cost) continue;

        for (const auto& edge : graph.path[start])
        {
            auto [end, weight] = edge;
            
            next_level = level == 0 ? 1 : 0;
            if (next_level == 1)
                weight /= 2;
            else
                weight *= 2;

            if (dist[end][next_level] > cost + weight)
            {
                dist[end][next_level] = cost + weight;
                pq.push({ dist[end][next_level], end, next_level});
            }
        }
    }
    return dist;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    Graph graph(N, M);
    graph.add_edge();

    vector<int> fox_dist = Dijkstra_fox(graph);
    vector<vector<int>> wolf_dist = Dijkstra_wolf(graph);

    int result = 0;
    for (int i = 1; i < N + 1; i++)
    {
        if (fox_dist[i] < min(wolf_dist[i][0], wolf_dist[i][1]))
            result++;
    }
    cout << result << "\n";
    return 0;
}