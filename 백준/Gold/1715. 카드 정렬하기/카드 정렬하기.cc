#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> arr;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push(temp);
    }

    int sum = 0;
    int result = 0;

    while (!arr.empty() && arr.size() != 1)
    {
        sum = arr.top();
        arr.pop();
        sum += arr.top();
        arr.pop();

        arr.push(sum);
        result += sum;
    }

    cout << result << "\n";
}