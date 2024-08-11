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
    
    for (int i = 0; i < n*n; i++)
    {
        int temp;
        cin >> temp;
        arr.push(temp);
        if (arr.size() > n)
            arr.pop();
    }

    cout << arr.top() << "\n";
}