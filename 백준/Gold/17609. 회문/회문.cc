#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

bool is_pseudo(string n, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        if (n[i] != n[j])
        {
            return false;
        }
    }
    return true;
}

void is_palindrome(string n)
{
    int start = 0, end = n.size() - 1;
    while (start < end)
    {
        if (n[start] != n[end])
        {
            if (is_pseudo(n, start + 1, end))
            {
                cout << "1" << "\n";
                return;
            }
            if (is_pseudo(n, start, end - 1))
            {
                cout << "1" << "\n";
                return;
            }
            cout << "2" << "\n";
            return;
        }

        start++;
        end--;
    }
    
    cout << "0" << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;

    string input;
    while (T--)
    {
        cin >> input;
        is_palindrome(input);
    }
}