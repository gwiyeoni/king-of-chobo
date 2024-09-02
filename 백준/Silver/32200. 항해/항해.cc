#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int sum = 0;
    int waste = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int temp_sum = A[i] / X;
        int temp_waste = A[i] % X;

        sum += temp_sum;

        if (temp_waste > temp_sum * (Y - X))
        {
            waste += temp_waste - (temp_sum * (Y - X));
        }
    }

    cout << sum << "\n";
    cout << waste << "\n";
}
