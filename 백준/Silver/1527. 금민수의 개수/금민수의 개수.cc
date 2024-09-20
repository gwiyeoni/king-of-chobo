#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;


int A, B;
ll result = 0;

void dfs(ll n)
{
    if (n > B)
    {
        return;
    }
    if (n >= A && n <= B)
    {
        result++;
    }

    dfs(n * 10 + 4);
    dfs(n * 10 + 7);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    dfs(4);
    dfs(7);

    cout << result;

}