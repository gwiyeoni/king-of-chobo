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

    int N;
    cin >> N;

    vector<ll> solution(N);
    for (int i = 0; i < N; i++)
    {
        cin >> solution[i];
    }

    sort(solution.begin(), solution.end());

    ll left = 0, mid, right = N - 1, sum = 0, min_sum = LONG_MAX;
    tuple result = { 0,0,0 };
    while (left < N - 2)
    {
        mid = left + 1, right = N - 1;
        while (mid < right)
        {
            sum = solution[left] + solution[mid] + solution[right];
            if (min_sum > abs(sum))
            {
                min_sum = abs(sum);
                result = { solution[left], solution[mid], solution[right] };
            }

            if (sum < 0)
                mid++;
            else
                right--;

        }
        left++;
    }

    auto [a, b, c] = result;

    cout << a << " " << b << " " << c << "\n";
}