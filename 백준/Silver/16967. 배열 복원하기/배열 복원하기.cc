#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, X, Y;
    cin >> H >> W >> X >> Y;

    vector<vector<int>> maps(H + X, vector<int>(W + Y));

    for (int i = 0; i < H + X; i++)
        for (int j = 0; j < W + Y; j++)
            cin >> maps[i][j];

    vector<vector<int>> result(H, vector<int>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            if ((X <= i && i <= H) && (Y <= j && j <= W))
            {
                int temp = maps[i][j] - result[i-X][j-Y];
                result[i][j] = temp;
            }
            else
                result[i][j] = maps[i][j];
        }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }

}