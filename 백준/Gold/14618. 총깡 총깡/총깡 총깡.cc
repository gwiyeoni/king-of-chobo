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
    int N, M;
    int J, K, A, B;
    int X, Y, Z;
    vector<int> house[2];
    vector<vector<pii>> maps;

public:
    Graph(int N, int M) : N(N), M(M), maps(N + 1) {}

    void House()
    {
        cin >> J;
        cin >> K;
        for (int i = 0; i < K; i++)
        {
            cin >> A;
            house[0].push_back(A);
        }
        for (int i = 0; i < K; i++)
        {
            cin >> B;
            house[1].push_back(B);
        }
    }

    void add_edge()
    {
        for (int i = 0; i < M; i++)
        {
            cin >> X >> Y >> Z;
            maps[X].emplace_back(Y, Z);
            maps[Y].emplace_back(X, Z);
        }
    }
};

vector<int> Dijkstra(Graph& graph)
{
    vector<int> dist(graph.N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[graph.J] = 0;
    pq.push({ 0, graph.J });
    
    while (!pq.empty())
    {
        auto [cost, start] = pq.top();
        pq.pop();

        if (dist[start] < cost) continue;
        for (const auto& edge : graph.maps[start])
        {
            auto [end, cost_] = edge;
            if (dist[end] > cost + cost_)
            {
                dist[end] = cost + cost_;
                pq.push({ cost + cost_, end });
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
    graph.House();
    graph.add_edge();
    vector<int> dist = Dijkstra(graph);

    int result_A = INF;
    int result_B = INF;
    for (const auto& i : graph.house[0])
    {
        result_A = min(result_A, dist[i]);
    }

    for (const auto& i : graph.house[1])
    {
        result_B = min(result_B, dist[i]);
    }

    if (result_A == INF && result_B == INF)
    {
        cout << "-1" << "\n";
        return 0;
    }
    else if (result_A <= result_B)
    {
        cout << "A" << "\n";
        cout << result_A << "\n";
        return 0;
    }
    else
    {
        cout << "B" << "\n";
        cout << result_B << "\n";
        return 0;
    }
}