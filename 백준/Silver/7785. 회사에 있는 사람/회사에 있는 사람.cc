#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
#include<cmath>
#include<unordered_map>
#include<utility>

using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, bool> m;

    int n;
    string name, state;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> state;
        if (state == "enter")
            m[name] = true;
        else
            m[name] = false;
    }

    vector<string> v;
    for (const auto& it : m)
    {
        if (it.second)
            v.push_back(it.first);
    }

    sort(v.begin(), v.end(), greater<string>());

    for (const auto& it : v)
    {
        cout << it << '\n';
    }
}
