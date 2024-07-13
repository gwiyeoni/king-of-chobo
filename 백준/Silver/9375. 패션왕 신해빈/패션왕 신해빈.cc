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

    int test_case, n;
    map<string, int> m;

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cin >> n;

        string name, type;
        for (int j = 0; j < n; j++)
        {
            cin >> name >> type;
            auto it = m.insert({ type, 1 });
            if (!it.second)
                m[type]++;
        }

        int result = 1;
        for (auto it : m)
        {
            result *= it.second + 1;
        }

        cout << result - 1<< "\n";

        m.clear();
    }
}
