#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Index(int x, int y, int z, int M, int N)
{
    return x + (M * y) + (M * N * z);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;

    vector<int> t(M * N * H);
    queue<tuple<int, int, int, int>> tomato;
    int temp;

    int sum = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> temp;
                t[Index(k, j, i, M, N)] = temp;
                if (temp == 1)
                    tomato.push(make_tuple(k, j, i, 0));
                if (temp == 0)
                    sum++;
            }
        }
    }

    int dx[] = { -1, 1, 0, 0 , 0, 0 };//상하좌우위아래
    int dy[] = { 0, 0, -1, 1 , 0, 0 };
    int dz[] = { 0, 0, 0, 0, -1, 1 };


    int x, y, z, level;
    int result = 0;

    while (!tomato.empty())
    {
        int n = tomato.size();
        tie(x, y, z, level) = tomato.front();
        tomato.pop();

        for (int i = 0; i < 6; i++)
        {
            int x_ = x + dx[i];
            int y_ = y + dy[i];
            int z_ = z + dz[i];

            if (x_ >= 0 && x_ < M
                && y_ >= 0 && y_ < N
                && z_ >= 0 && z_ < H
                && t[Index(x_, y_, z_, M, N)] == 0)
            {
                t[Index(x_, y_, z_, M, N)] = 1;
                sum--;
                tomato.push(make_tuple(x_, y_, z_, level + 1));
                result = max(result, level + 1);
            }
        }
    }


    if (sum > 0)
    {
        cout << "-1" << "\n";
    }
    else
    {
        cout << result << "\n";
    }

}
