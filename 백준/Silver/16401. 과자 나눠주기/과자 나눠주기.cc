#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n;
    cin >> m >> n;

    vector<ll> snack(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> snack[i];
    }

    ll left = 1;
    ll result = 0;
    ll right = (*max_element(snack.begin(), snack.end()));
    while (left <= right)
    {
        ll count = 0;
        ll mid = left + (right - left) / 2;
        for (ll i = 0; i < n; i++)
        {
            count += snack[i] / mid;
        }

        if (count >= m)
        {
            left = mid + 1;
            result = mid;
        }
        else
            right = mid - 1;
    }


    cout << result << "\n";
}