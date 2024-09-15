#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

typedef struct Fireball
{
    int x;
    int y;
    int m;
    int s;
    int d;
}fireball;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<fireball> fire;

    int r, c, m, d, s;
    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> m >> s >> d;
        fire.push_back({ r - 1, c - 1, m, s, d });
    }

    int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    while (K--)
    {
        map<pii, vector<fireball>> fire_map;
        for (auto& [x, y, m, s, d] : fire)
        {
            x = (x + (dx[d] * s)) % N;
            y = (y + (dy[d] * s)) % N;

            if (x < 0)
                x += N;
            if (y < 0)
                y += N;

            fire_map[{x, y}].push_back({ x, y, m, s, d });
        }

        fire.clear();

        for (auto& [pos, f] : fire_map)
        {
            if (f.size() == 1)
            {
                fire.push_back(f[0]);
                continue;
            }

            int sum_m = 0, sum_s = 0;
            int count_s = f.size();
            int odd = 0, even = 0;
            for (const auto& [x, y, m, s, d] : f)
            {
                sum_m += m;
                sum_s += s;

                if (d % 2 == 0)
                    even++;
                else
                    odd++;
            }

            if (sum_m / 5 == 0) continue;

            if (!even || !odd)
            {
                for (int i = 0; i < 8; i += 2)
                    fire.push_back({ pos.first, pos.second, sum_m / 5, sum_s / count_s, i });
            }
            else
            {
                for (int i = 1; i < 8; i += 2)
                    fire.push_back({ pos.first, pos.second, sum_m / 5, sum_s / count_s, i });
            }

        }
    }

    int result = 0;
    for (const auto& i : fire)
    {
        result += i.m;
    }

    cout << result << "\n";
}