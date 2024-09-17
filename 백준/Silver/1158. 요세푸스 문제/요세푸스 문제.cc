#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
#include<cmath>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<queue>

using namespace std;

#define MAX 1001


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.empty() != 1)
    {
        for (int i = 1; i < k; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        result.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < n-1; i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[n - 1] << ">" << "\n";
}
