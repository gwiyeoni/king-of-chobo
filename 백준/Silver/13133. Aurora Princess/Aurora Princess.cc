#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
#include<cmath>

using namespace std;

typedef struct Information
{
    int me;
    int mom;
    int dad;
}information;

int main() 
{
    int n;
    cin >> n;

    vector<information> info;

    for (int i = 1; i < n+1; i++)
    {
        int mom, dad;
        cin >> mom >> dad;

        if (mom == 0 || dad == 0)
            continue;
        else
        {
            info.push_back({ i, mom, dad });
        }
    }

    int m;
    cin >> m;

    while (m--)
    {
        int num;
        cin >> num;
        for (auto it = info.begin(); it != info.end();)
        {
            if (it->me == num || it->mom == num || it->dad == num)
                it = info.erase(it);
            else
                it++;
        }
    }

    cout << info.size() << endl;
}
