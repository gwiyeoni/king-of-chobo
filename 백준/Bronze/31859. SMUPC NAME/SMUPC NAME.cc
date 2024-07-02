#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>

using namespace std;

void Reverse(string& str);

int main() {
    int n;
    string str;
    int select[26] = { 0 };
    int same = 0;

    cin >> n >> str;
    for (int i = 0; i < str.size(); i++)
    {
        int temp = str[i] - 97;
        if (!select[temp])
        {
            select[temp] = 1;
        }
        else
        {
            str.erase(i, 1);
            i--; // 하나 지워서 인덱스 당겨졌으니까 i도 같이 땡기기
            same++;
        }
    }
    str = to_string(1906 + n) + str + to_string(same+4);
    Reverse(str);
    cout << "smupc_" << str << endl;
}

void Reverse(string& str)
{
    reverse(str.begin(), str.end());
}
