#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
#include<cmath>
#include<map>
#include<utility>
#include<set>

using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string line;
        string VPS;

        int result = 1;

        getline(cin, line);
        for (char i : line)
        {
            if (i == '(')
            {
                VPS.push_back(i);
            }
            else if (i == ')')
            {
                if (VPS.empty() || VPS.back() != '(')
                {
                    result = 0;
                    break;
                }
                else VPS.pop_back();
            }
        }

        if (!VPS.empty())
            result = 0;

        if (result)
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
