#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
#include<cmath>
#include<map>
#include<utility>

using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string, greater<string>> m;

    int n;
    string name, state;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> state;
        if (state == "enter")
            m.insert({ name, state });
        else
            m.erase(name);
    }

    for (auto it : m)
    {
        cout << it.first << "\n";
    }
}
