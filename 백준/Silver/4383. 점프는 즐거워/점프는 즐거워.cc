#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
#include<cmath>

using namespace std;

void Find_Absolute_value(int n, vector<int>&);

int main() 
{
    while (1)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        vector<int> absolute_value(n);
        Find_Absolute_value(n, absolute_value);

        if (n == 1)
        {
            cout << "Jolly" << endl;
            continue;
        }

        bool is_Jolly = true;
        for (int i = 1; i < n; i++)
        {
            if (absolute_value[i] != 1)
            {
                cout << "Not jolly" << endl;
                is_Jolly = false;
                break;
            }
        }

        if(is_Jolly)
            cout << "Jolly" << endl;

    }
    return 0;
}

void Find_Absolute_value(int n, vector<int>& value)
{
    int temp1, temp2;
    cin >> temp1;
    for (int i = 1; i < n; i++)
    {
        cin >> temp2;
        if(abs(temp2-temp1) <= n)
            value[abs(temp2 - temp1)]++;
        temp1 = temp2;
    }
}
