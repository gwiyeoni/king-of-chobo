#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
#include<cmath>
#include<unordered_map>
#include<utility>
#include<set>

using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int gomgom = 0;
    int result = 0;

    unordered_map<string, int> m;
    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;

        if (input == "ENTER")
            gomgom++;
        else
        {
            auto it = m.insert({ input, gomgom });
            if (!it.second)
            {
                if (m[input] != gomgom)
                {
                    result++;
                    m[input] = gomgom;
                }

            }
            else
                result++;
        }
    }

    cout << result << "\n";
}
