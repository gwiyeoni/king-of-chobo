#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Graph
{
public:
    int n, m, t;
    int s, g, h;
    int a, b, d;
    vector<vector<pii>> maps;
    vector<int> T;

public:
    Graph()
    {
        cin >> n >> m >> t; //정점, 도로, 목적지후보
        cin >> s >> g >> h; //범인출발지, 단서g-h
        maps.resize(n + 1);
    }

    void add_edge()
    {
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> d;
            maps[a].emplace_back(b, d);
            maps[b].emplace_back(a, d);
        }

        T.resize(t);
        for (int i = 0; i < t; i++)
        {
            cin >> T[i];
        }
    }
};

vector<int> Dijkstra(Graph& graph, int start)
{
    vector<int> dist(graph.n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        auto [cost, curr] = pq.top();
        pq.pop();

        if (dist[curr] < cost) continue;
        for (const auto& edge : graph.maps[curr])
        {
            auto [next, weight] = edge;
            if (dist[next] > cost + weight)
            {
                dist[next] = cost + weight;
                pq.push({ dist[next], next });
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        Graph graph;
        graph.add_edge();

        vector<int> dist_s = Dijkstra(graph, graph.s);
        vector<int> dist_g = Dijkstra(graph, graph.g);
        vector<int> dist_h = Dijkstra(graph, graph.h);

        vector<int> result;

        for (const auto& i : graph.T)
        {
            if ((dist_s[i] == dist_s[graph.h] + dist_g[i] + dist_g[graph.h])
                || dist_s[i] == dist_s[graph.g] + dist_h[i] + dist_g[graph.h])
            {
                result.push_back(i);
            }
        }

        sort(result.begin(), result.end());
        for (const auto& i : result)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
