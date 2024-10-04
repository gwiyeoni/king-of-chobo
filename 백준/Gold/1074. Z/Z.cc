#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;


void dfs(int index, int N, int r, int c, int result)
{
    if (index == N)
    {
        cout << result << "\n";
        return;
    }

    int level = 0;
    if (r % 2 == 0 && c % 2 == 0)
        level = 0;
    else if (r % 2 == 0 && c % 2 == 1)
        level = 1;
    else if (r % 2 == 1 && c % 2 == 0)
        level = 2;
    else if (r % 2 == 1 && c % 2 == 1)
        level = 3;

    result += pow(2, index) * pow(2, index) * level;
    dfs(index + 1, N, r / 2, c / 2, result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, r, c;
    int result = 0;

    cin >> N >> r >> c;

    int index = 0;

    dfs(0, N, r, c, 0);
}