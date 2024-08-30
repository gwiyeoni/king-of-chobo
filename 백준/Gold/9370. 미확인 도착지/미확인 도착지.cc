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
    int n, m, t;
    int s, g, h;
    int a, b, d;
    int x;
    vector<vector<pii>> maps;
    vector<int> T;
    set<int> result;

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

        for (int i = 0; i < t; i++)
        {
            cin >> x;
            T.push_back(x);
        }
    }

};


vector<int> Dijkstra(Graph& graph, int start)
{
    vector<int> dist(graph.n + 1, INF);
    priority_queue <pii, vector<pii>, greater<pii>> pq;

    dist[start] = { 0 };
    pq.push({ 0, start });

    while (!pq.empty())
    {
        auto [cost, start] = pq.top();
        pq.pop();

        if (dist[start] < cost) continue;
        for (const auto& edge : graph.maps[start])
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

        for (const auto& i : graph.T)
        {
            if ((dist_s[i] == dist_s[graph.h] + dist_g[i] + dist_g[graph.h])
                || dist_s[i] == dist_s[graph.g] + dist_h[i] + dist_g[graph.h])
            {
                graph.result.insert(i);
            }
        }

        for (const auto& i : graph.result)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

}