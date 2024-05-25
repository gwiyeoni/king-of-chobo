#define _CRT_NO_SECURE_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Min_clock(vector<int>& n)
{
    int min = 10000;
    for (int i = 0; i < 4; i++)
    {
        int temp = n[i % 4] * 1000 + n[(i + 1) % 4] * 100 + n[(i + 2) % 4] * 10 + n[(i + 3) % 4];
        if (temp < min)
            min = temp;
    }
    return min;
}

int Check_min(int min)
{
    vector<int> clocknumber;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            for (int k = 1; k <= 9; k++)
                for (int l = 1; l <= 9; l++)
                {
                    vector<int> temp = { i,j,k,l };
                    clocknumber.push_back(Min_clock(temp));
                }

    sort(clocknumber.begin(), clocknumber.end());
    clocknumber.erase(unique(clocknumber.begin(), clocknumber.end()), clocknumber.end());

    int sum = distance(clocknumber.begin(), lower_bound(clocknumber.begin(), clocknumber.end(), min)) + 1;

    return sum;
}

int main()
{
    vector<int> n;
    int x;

    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        n.push_back(x);
    }

    int min = Min_clock(n);
    cout << Check_min(min);
}