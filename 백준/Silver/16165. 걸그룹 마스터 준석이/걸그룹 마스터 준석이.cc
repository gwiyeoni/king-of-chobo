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

    int N, M;
    cin >> N >> M;
    
    string name;
    string member;
    int count;

    map<string, set<string>> m;
    while (N--)
    {
        cin >> name;
        cin >> count;

        set<string> s;
        while (count--)
        {
            cin >> member;
            s.insert(member);
        }

        m.insert({ name, s });
    }

    while (M--)
    {
        int value;

        cin >> name;
        cin >> value;

        if (value)
        {
            for (const auto& team_name : m)
            {
                if (team_name.second.find(name) != team_name.second.end())
                {
                    cout << team_name.first << "\n";
                    break;
                }
            }
        }
        else
        {
            for (const auto& member_name : m[name])
            {
                cout << member_name << "\n";
            }
        }
    }

    return 0;
}
