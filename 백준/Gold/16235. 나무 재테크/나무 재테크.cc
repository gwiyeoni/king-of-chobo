#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> sequence;
vector<bool> visited;

bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;

    return a3 < b3;
}

void Spring(vector<vector<int>>& Energy, deque<tuple<int, int, int>>& Tree, vector<tuple<int, int, int>>& Dead)
{
    int temp = Tree.size();

    for (int i = 0; i < temp; i++)
    {
        auto [x, y, z] = Tree.front();
        Tree.pop_front();
        if (Energy[x][y] >= z)
        {
            Energy[x][y] -= z;
            Tree.push_back({ x, y, z + 1 });
        }
        else
        {
            Dead.push_back({ x, y, z });
        }
    }
}

void Summer(vector<vector<int>>& Energy, vector<tuple<int, int, int>>& Dead)
{
    int temp = Dead.size();
    for (int i = 0; i < temp; i++)
    {
        auto [x, y, z] = Dead.back();
        Energy[x][y] += z / 2;
        Dead.pop_back();
    }
}

void Autumn(int N, deque<tuple<int, int, int>>& Tree)
{
    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    int temp = Tree.size();

    deque<pii> Tree_temp;
    for (int i = 0; i < temp; i++)
    {
        auto [x, y, z] = Tree.front();
        Tree.pop_front();
        if (z % 5 == 0)
        {
            Tree_temp.push_back({ x, y });
        }
        Tree.push_back({ x,y,z });
    }

    int temp2 = Tree_temp.size();

    for (int i = 0; i < temp2; i++)
    {
        auto [x, y] = Tree_temp.back();
        Tree_temp.pop_back();
        for (int d = 0; d < 8; d++)
        {
            int x_ = x + dx[d];
            int y_ = y + dy[d];

            if (x_ < 0 || y_ < 0 || x_ >= N || y_ >= N) continue;
            Tree.push_front({ x_, y_, 1 });
        }
    }
}

void Winter(int N, vector<vector<int>>& Energy, vector<vector<int>>& A)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Energy[i][j] += A[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    deque<tuple<int, int, int>> Tree;
    vector<tuple<int, int, int>> Dead;

    int x, y, z;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        Tree.push_back({ x - 1, y - 1, z });
    }

    sort(Tree.begin(), Tree.end(), compare);


    vector<vector<int>> Energy(N, vector<int>(N, 5));

    for (int i = 0; i < K; i++)
    {
        Spring(Energy, Tree, Dead);
        Summer(Energy, Dead);
        Autumn(N, Tree);
        Winter(N, Energy, A);
    }

    cout << Tree.size() << "\n";
}