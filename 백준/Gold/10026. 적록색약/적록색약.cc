#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<char>> grid(102, vector<char>(102));
vector<vector<bool>> visited(102, vector<bool>(102, false));
vector<vector<bool>> visited2(102, vector<bool>(102, false));


int color = 0;
int no_color = 0;
void dfs(int i, int j, int N, char now)
{

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int d = 0; d < 4; d++)
    {
        int x = i + dx[d];
        int y = j + dy[d];

        if (x < 0 || x >= N || y < 0 || y >= N || visited[x][y]) continue;
        
        if (now == grid[x][y])
        {
            visited[x][y] = true;
            dfs(x, y, N, grid[x][y]);
        }
    }
}

void dfs2(int i, int j, int N, char now)
{

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int d = 0; d < 4; d++)
    {
        int x = i + dx[d];
        int y = j + dy[d];

        if (x < 0 || x >= N || y < 0 || y >= N || visited2[x][y]) continue;

        if (now == grid[x][y] ||
            (now == 'G' && grid[x][y] == 'R') ||
            (now == 'R' && grid[x][y] == 'G'))
        {
            visited2[x][y] = true;
            dfs2(x, y, N, grid[x][y]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = temp[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                dfs(i, j, N, grid[i][j]);
                color++;
            }

            if (!visited2[i][j])
            {
                visited2[i][j] = true;
                dfs2(i, j, N, grid[i][j]);
                no_color++;
            }
        }
    }

    cout << color <<" " << no_color <<"\n";
}