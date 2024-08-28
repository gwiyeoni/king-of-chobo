#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;


class Map
{
public:
    int H, W;
    int start, end;
    vector<vector<int>> map_;
    vector<vector<int>> visited;

private:
    char temp;

public:
    Map(int H, int W)
    {
        this->H = H + 1;
        this->W = W + 1;
        map_.resize(this->H, vector<int>(this->W));
        visited.resize(this->H, vector<int>(this->W, INT_MAX));
    }

    void add(int i, int j)
    {
        if (temp == '.')//바다
            map_[i][j] = 0;
        else if (temp == '#')//암초
            map_[i][j] = -1;
        else if (temp == 'K')//배
        {
            map_[i][j] = 1;
            start = i;
            end = j;
        }
        else if (temp == '*')//보물
            map_[i][j] = 2;
    }

    void input()
    {
        for (int i = 1; i < H; i++)
            for (int j = 1; j < W; j++)
            {
                cin >> temp;
                add(i, j);
            }
    }
};

int zero_one_bfs(Map& map_)
{
    deque<tuple<int, int, int>> dq;

    int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
    //오른쪽 위-아래 -> 중앙 위아래 -> 왼쪽 위-아래 순

    map_.visited[map_.start][map_.end] = 0;
    dq.push_front({ map_.start, map_.end, 0 });

    while (!dq.empty())
    {
        auto [x, y, count] = dq.front();
        dq.pop_front();

        if (map_.map_[x][y] == 2)
            return count;
        //보물을 찾으면 종료

        for (int d = 0; d < 8; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 1 || ny < 1 || nx >= map_.H || ny >= map_.W) continue;
            //위치 조건
            if (map_.map_[nx][ny] == -1) continue;
            //암석 조건

            int increase = d < 3 ? 0 : 1;
            //오른쪽으로 가면 0 증가
            int nd = map_.visited[x][y] + increase;

            if (map_.visited[nx][ny] > nd)
            {
                map_.visited[nx][ny] = nd;
                if (increase == 0)
                    dq.push_front({ nx, ny, nd });
                else
                    dq.push_back({ nx, ny, nd });
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    Map maps(H, W);
    maps.input();
    cout << zero_one_bfs(maps) << "\n";
}

