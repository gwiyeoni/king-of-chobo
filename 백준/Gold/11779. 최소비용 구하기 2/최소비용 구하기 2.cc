#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;


class Graph
{
public:
    int V;
    vector<vector<pii>> bus;

public:
    Graph(int V)
    {
        this->V = V + 1;
        bus.resize(this->V);
    }

    void addEdge(int a, int b, int c)
    {
        bus[a].emplace_back(b, c);
    }
};

void Dijkstra(Graph& graph, int start, int end)
{
    vector<int> dist(graph.V, INT_MAX);
    vector<int> path(graph.V, -1);
    priority_queue <pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.emplace(dist[start], start);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] < d) continue;

        for (const auto& [w, d_] : graph.bus[u])
        {
            if (dist[u] + d_ < dist[w])
            {
                dist[w] = dist[u] + d_;
                pq.emplace(dist[w], w);
                path[w] = u;
            }
        }
    }

    deque<int> answer;
    for (int v = end; v != -1; v = path[v])
    {
        answer.push_front(v);
    }

    cout << dist[end] << "\n";
    cout << answer.size() << "\n";

    for (auto& i : answer)
    {
        cout << i << " ";
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n;
    cin >> m;

    Graph graph(n);

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph.addEdge(a, b, c);
    }

    int start, end;
    cin >> start >> end;

    Dijkstra(graph, start, end);
}

