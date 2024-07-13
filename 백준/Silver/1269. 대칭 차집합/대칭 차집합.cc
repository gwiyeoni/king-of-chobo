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

    int a, b;
    cin >> a >> b;

    int A, B;

    set<int> AB;

    int repeat = 0;
    for (int i = 0; i < a; i++)
    {
        cin >> A;
        auto result = AB.insert(A);
        if (!result.second)
            repeat++;
    }

    for (int i = 0; i < b; i++)
    {
        cin >> B;
        auto result = AB.insert(B);
        if (!result.second)
            repeat++;
    }

    cout << AB.size() - repeat;
}
