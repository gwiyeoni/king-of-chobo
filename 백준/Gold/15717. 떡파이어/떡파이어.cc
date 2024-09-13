#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;


ll repeat(ll N)
{
    if (N == 0) return 1;
    if (N == 1) return 2;

    ll temp = repeat(N / 2);
    if (N % 2 == 0)
        return (temp * temp) % (1000000000 + 7);
    else
        return ((temp * temp) % (1000000000 + 7) * 2) % (1000000000 + 7);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;

    ll result = 0;

    if (N > 0)
        N--;
    result = repeat(N);

    cout << result << "\n";
}