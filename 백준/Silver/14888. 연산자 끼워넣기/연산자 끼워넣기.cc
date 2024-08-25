#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Cal(int a, int b, int oper)
{
    switch (oper)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    }
}

void dfs(int n, int N, vector<int>& A, int oper[], vector<int>& sequence, int sum[], int visited[])
{
    if (n == N - 1)
    {
        int temp = 0;
        int result = A[temp];
        for (auto i : sequence)
        {
            result = Cal(result, A[temp + 1], i);
            temp++;
        }
        sum[0] = max(sum[0], result);
        sum[1] = min(sum[1], result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (visited[i] < oper[i])
        {
            visited[i]++;
            sequence.push_back(i);
            dfs(n + 1, N, A, oper, sequence, sum, visited);
            sequence.pop_back();
            visited[i]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A;
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        A.push_back(temp);
    }

    int oper[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }

    int sum[2] = { INT_MIN, INT_MAX };
    vector<int> sequence;
    int visited[4] = { 0 };
    dfs(0, N, A, oper, sequence, sum, visited);

    for (auto i : sum)
        cout << i << "\n";

}