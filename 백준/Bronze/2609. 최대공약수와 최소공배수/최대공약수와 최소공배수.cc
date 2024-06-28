#include<iostream>
#include <string.h>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

int main() {

    int num1, num2;

    cin >> num1 >> num2;

    int gcd_ = gcd(num1, num2);
    int lcm_ = lcm(num1, num2);

    cout << gcd_ << endl;
    cout << lcm_ << endl;

    return 0;
}
