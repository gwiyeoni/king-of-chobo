#define _CRT_NO_SECURE_WARNINGS

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b;

    while (1)
    {
        cin >> a >> b;
        if (cin.eof())
        {
            break;
        }
        cout << a + b << "\n";
    }
    return 0;
}