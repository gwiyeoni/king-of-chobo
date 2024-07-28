#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
#include<cmath>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<queue>
#include<list>
#include<deque>
using namespace std;

void Move(deque<pair<int, int>>& snake, int x, int y, set<pair<int, int>>& apple);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n;
    cin >> k;

    set<pair<int, int>> apple;
    int apple_x, apple_y;

    for (int i = 0; i < k; i++)
    {
        cin >> apple_y >> apple_x;
        apple.insert(make_pair(apple_x, apple_y));
    }

    int l;
    cin >> l;

    deque<pair<int, char>> info(l);

    for (int i = 0; i < l; i++)
    {
        cin >> info[i].first >> info[i].second;
    }

    deque<pair<int, int>> snake;
    snake.push_back(make_pair(1, 1));
    snake.push_back(make_pair(0, 1));
    int direction = 0;
    //0=우 1=하 2=좌 3=상

    int time = 0;

    while (1)
    {
        time++;

        //방향설정
        if (!info.empty() && info[0].first + 1== time)
        {
            if (info[0].second == 'D')
                direction = (direction + 1 + 4) % 4;
            else
                direction = (direction - 1 + 4) % 4;
            info.pop_front();
        }

        //이동
        switch (direction)
        {
        case 0:
            Move(snake, 1, 0, apple);
            break;
        case 1:
            Move(snake, 0, 1, apple);
            break;
        case 2:
            Move(snake, -1, 0, apple);
            break;
        case 3:
            Move(snake, 0, -1, apple);
            break;
        }

        //충돌
        int crash = 0;
        auto it = snake.begin();
        for (++it; it != snake.end(); ++it)
        {
            if ((*it).first == snake.front().first && (*it).second == snake.front().second)
                crash = 1;
        }

        if (snake.front().first > n ||
            snake.front().second > n ||
            snake.front().first == 0 ||
            snake.front().second == 0)
            break;
        else if (crash)
            break;
    }

    cout << time << "\n";
}

void Move(deque<pair<int, int>>& snake, int x, int y, set<pair<int, int>>& apple)
{
    pair<int, int> temp = { snake.front().first + x, snake.front().second + y };

    //사과 처리
    set<pair<int, int>>::iterator find_apple = apple.find(make_pair(snake.front().first, snake.front().second));
    int exist_apple = find_apple != apple.end();
    if (!exist_apple)
        snake.pop_back();
    else
        apple.erase(*find_apple);

    snake.push_front(temp);
}
