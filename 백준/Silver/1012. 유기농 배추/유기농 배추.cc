#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<int>> arr(M, vector<int>(N));

        int X, Y;
        for (int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            arr[X][Y] = 1;
        }
        
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        queue<pii> que;

        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        int result = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == false && arr[i][j] == 1)
                {
                    que.push(make_pair(i,j));
                    visited[i][j] = true;
                    result++;

                    while (!que.empty())
                    {
                        pii temp = que.front();
                        que.pop();

                        for (int d = 0; d < 4; d++)
                        {
                            int nx = temp.first + dx[d];
                            int ny = temp.second + dy[d];

                            if (nx >= 0 && nx < M 
                                && ny >= 0 && ny < N 
                                && arr[nx][ny] == 1
                                && !visited[nx][ny])
                            {
                                que.push(make_pair(nx, ny));
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }

        cout << result << "\n";
        
    }
}