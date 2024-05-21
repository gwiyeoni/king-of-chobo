#define _CRT_NO_SECURE_WARNINGS

#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    int* A = new int[n];
    int* B = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    sort(A, A + n);
    sort(B, B + n, compare);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i] * B[i];
    }

    cout << sum;

    delete[] A;
    delete[] B;
}