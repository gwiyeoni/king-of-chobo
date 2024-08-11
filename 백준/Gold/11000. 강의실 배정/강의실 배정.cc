#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct compare {
    bool operator()(pair<int, char> x, pair<int, char>y) const {
        if (x.first == y.first)
            return x.second < y.second;
        else
            return x.first > y.first;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<pair<int, char>, vector<pair<int, char>>, compare> arr;
    
    for (int i = 0; i < n; i++)
    {
        int S;
        cin >> S;
        arr.push(make_pair(S, 'S'));
        int T;
        cin >> T;
        arr.push(make_pair(T, 'T'));
    }

    int result = 0;
    int sum = 0;
    while (!arr.empty())
    {
        char temp = arr.top().second;
        if (temp == 'S')
        {
            sum++;
            if (sum > result)
                result = sum;
        }
        else
            sum--;
        arr.pop();
    }

    cout << result << "\n";
}