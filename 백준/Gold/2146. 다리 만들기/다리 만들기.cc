#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<vector<int>> map_(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map_[i][j];

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    // 섬 구분
    int island_num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map_[i][j] == 1 && !visited[i][j]) {
                island_num++;
                queue<pii> q;
                q.push({i, j});
                visited[i][j] = true;
                map_[i][j] = island_num;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
                        if (map_[nx][ny] == 1) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            map_[nx][ny] = island_num;
                        }
                    }
                }
            }
        }
    }

    // 최단 다리 찾기
    int shortest_bridge = INT_MAX;
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map_[i][j] != 0) {
                visited = vector<vector<bool>>(N, vector<bool>(N, false));
                q.push({i, j, 0});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y, dist] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;

                        if (map_[nx][ny] == 0) {
                            q.push({nx, ny, dist + 1});
                            visited[nx][ny] = true;
                        } else if (map_[nx][ny] != map_[i][j]) {
                            shortest_bridge = min(shortest_bridge, dist);
                        }
                    }
                }
            }
        }
    }

    cout << shortest_bridge << "\n";
    return 0;
}