#include <bits/stdc++.h>
using namespace std;

char white_board[8][8] = {
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'}
};

char black_board[8][8] = {
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'}
};

string board[51];

int solve(int start_x, int start_y)
{
    int cnt_w;
    int cnt_b;
    cnt_w = cnt_b = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i + start_x][j + start_y] != white_board[i][j])
            {
                cnt_w++;
            }
            if (board[i + start_x][j + start_y] != black_board[i][j])
            {
                cnt_b++;
            }
        }
    }
    return min(cnt_w, cnt_b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string temp_str;
    for (int i = 0; i < n; i++)
    {
        cin >> temp_str;
        board[i] = temp_str;
    }
    int ans = 2147483647;

    for (int i = 0; n - 8 - i >= 0; i++)
    {
        for (int j = 0; m - 8 - j >= 0; j++)
        {
            ans = min(ans, solve(i, j));
        }
    }
    cout << ans;
}