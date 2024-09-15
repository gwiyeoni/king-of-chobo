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

    bool operator>(const Fireball& other) const
    {
        if (this->x != other.x)
            return this->x > other.x;
        if (this->y != other.y)
            return this->y > other.y;
        return false;
    }

}fireball;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<fireball> maps;
    priority_queue<fireball, vector<fireball>, greater<fireball>> maps_temp;

    int r, c, m, d, s;
    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> m >> s >> d;
        maps.push_back({ r - 1, c - 1, m, s, d });
    }

    int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    while (K--)
    {
        for (auto& [x, y, m, s, d] : maps)
        {
            x = (x + (dx[d] * s)) % N;
            y = (y + (dy[d] * s)) % N;

            if (x < 0)
                x += N;
            if (y < 0)
                y += N;

            maps_temp.push({ x, y, m, s, d });
        }

        maps.clear();

        while (!maps_temp.empty())
        {
            auto [x, y, m, s, d] = maps_temp.top();
            maps_temp.pop();

            int sum_m = m, sum_s = s;
            int odd = 0, even = 0;
            if (d % 2 == 0)
                even++;
            else
                odd++;

            int count_s = 1;
            bool is_add = false;
            while (!maps_temp.empty())
            {
                auto [x_, y_, m_, s_, d_] = maps_temp.top();
                if (x != x_ || y != y_) break;
                maps_temp.pop();
                is_add = true;

                sum_m += m_;
                sum_s += s_;
                count_s++;

                if (d_ % 2 == 0)
                    even++;
                else
                    odd++;
            }

            if (is_add)
            {
                if (sum_m / 5 == 0) continue;

                if (!even || !odd)
                {
                    for (int i = 0; i < 8; i += 2)
                        maps.push_back({ x, y, sum_m / 5, sum_s / count_s, i });
                }
                else
                {
                    for (int i = 1; i < 8; i += 2)
                        maps.push_back({ x, y, sum_m / 5, sum_s / count_s, i });
                }
            }
            else
                maps.push_back({ x, y, m, s, d });
        }
    }


    int sum = 0;
    for (const auto& [x, y, m, s, d] : maps)
    {
        sum += m;
    }

    cout << sum << "\n";
}

