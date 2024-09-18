#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A, T;
    cin >> A >> T;

    deque<char> start, end;

    int s_index = 0, e_index = T.size() - 1;
    int A_len, S_len, E_len;
    bool is_found;

    while (s_index <= e_index)
    {
        while (s_index <= e_index)
        {
            start.push_back(T[s_index]);
            s_index++;

            A_len = A.size();
            S_len = start.size();

            if (S_len >= A_len)
            {
                is_found = true;
                for (int i = A_len - 1; i >= 0; i--)
                {
                    if (A[i] != start[S_len - 1])
                    {
                        is_found = false;
                        break;
                    }
                    S_len--;
                }

                if (is_found)
                {
                    for (int i = 0; i < A_len; i++)
                        start.pop_back();
                    break;
                }
            }
        }

        while (s_index <= e_index)
        {
            end.push_front(T[e_index]);
            e_index--;

            A_len = A.size();
            E_len = end.size();

            if (E_len >= A_len)
            {
                is_found = true;
                E_len = 0;
                for (int i = 0; i < A_len; i++)
                {
                    if (A[i] != end[E_len])
                    {
                        is_found = false;
                        break;
                    }
                    E_len++;
                }

                if (is_found)
                {
                    for (int i = 0; i < A_len; i++)
                        end.pop_front();
                    break;
                }
            }
        }
    }

    string result;
    for (auto& s : start)
        result.push_back(s);
    for (auto& e : end)
        result.push_back(e);

    while (1)
    {
        size_t temp = result.find(A);
        if (temp == string::npos)
            break;

        result.erase(temp, A.size());
    }
    if (!result.empty())
        cout << result << "\n";

    return 0;

}