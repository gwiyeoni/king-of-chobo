#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


class Graph
{
public:
    int V;
    vector<vector<ll>> bus;

public:
    Graph(int V)
    {
        this->V = V + 1;

        bus.resize(this->V, vector<ll>(this->V, LLONG_MAX));
        //인접행렬 큰 값으로 초기화

        for (int i = 1; i < this->V; i++)
            bus[i][i] = 0; // 대각선 0 초기화
    }

    void addEdge(int a, int b, ll c)
    {
        bus[a][b] = min(bus[a][b], c);
        // 인접행렬 갱신
    }
};

void Floyd_Warshall(Graph& graph)
{
    for (int mid = 1; mid < graph.V; mid++)
        for (int i = 1; i < graph.V; i++)
            for (int j = 1; j < graph.V; j++)
            {
                if (graph.bus[i][mid] == LLONG_MAX || graph.bus[mid][j] == LLONG_MAX) continue;
                graph.bus[i][j] = min(graph.bus[i][j], graph.bus[i][mid] + graph.bus[mid][j]);
            }

    for (int i = 1; i < graph.V; i++)
    {
        for (int j = 1; j < graph.V; j++)
        {
            if (graph.bus[i][j] == LLONG_MAX)
                cout << 0 << " ";
            else
                cout << graph.bus[i][j] << " ";
        }
        cout << "\n";
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

    int a, b; ll c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph.addEdge(a, b, c);
    }

    Floyd_Warshall(graph);

}

