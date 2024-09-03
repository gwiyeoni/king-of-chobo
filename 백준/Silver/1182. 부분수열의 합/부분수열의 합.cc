#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

class Graph
{
public:
    int N, S;
    vector<int> math;
    int visited[200001];
    int result = 0;

public:
    Graph(int N, int S)
        : N(N), S(S), math(N) {}

    void add_math()
    {
        for (int i = 0; i < N; i++)
            cin >> math[i];
    }
};

void backtracking(int index, int n, Graph& graph)
{
    for (int i = index; i < graph.N; i++)
    {
        n += graph.math[i];
        if (graph.S == n)
        {
            graph.result++;
        }
        backtracking(i + 1, n, graph);
        n -= graph.math[i];
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    Graph graph(N, S);
    graph.add_math();

    backtracking(0, 0, graph);

    cout << graph.result << "\n";
}