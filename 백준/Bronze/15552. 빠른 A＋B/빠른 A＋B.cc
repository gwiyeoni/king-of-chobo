#define _CRT_NO_SECURE_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    int a, b;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        cout << a + b << "\n";
    }
}