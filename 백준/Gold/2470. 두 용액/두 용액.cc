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

    vector<int> solution(N);
    for (int i = 0; i < N; i++)
    {
        cin >> solution[i];
    }

    sort(solution.begin(), solution.end());

    int left = 0, right = N - 1, sum = 0, min_sum = INT_MAX;
    pii result = { 0,0 };
    while (left != right)
    {
        sum = solution[left] + solution[right];
        if (min_sum > abs(sum))
        {
            min_sum = abs(sum);
            result = { solution[left], solution[right] };
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    cout << result.first << " " << result.second << "\n";
}