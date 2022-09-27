#include <iostream>
#include<queue>
#include<algorithm>

class Virus
{
public:
    Virus(int posx, int posy, int type, int time)
    {
        this->posx = posx;
        this->posy = posy;
        this->type = type;
        this->time = time;
    }

    bool operator < (Virus& other)
    {
        return this->type < other.type;
    }

public:
    int posx;
    int posy;
    int type;
    int time;
};


using namespace std;

int n, k, s, x, y;
int arr[200][200];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<Virus> vi;

int main(void)
{
    //n: 시험관 크기, k: 바이러스 번호
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                vi.push_back(Virus(j, i, arr[i][j], 0));
            }
        }
    }

    sort(vi.begin(), vi.end());

    cin >> s >> x >> y;

    queue<Virus> q;
    for (int i = 0; i < vi.size(); i++)
        q.push(vi[i]);

    while (!q.empty())
    {
        Virus vir = q.front();
        q.pop();
        if (vir.time == s)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nx = vir.posx + dir[i][0];
            int ny = vir.posy + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (arr[ny][nx] == 0)
                {
                    arr[ny][nx] = vir.type;
                    q.push(Virus(nx, ny, vir.type, vir.time + 1));
                }
            }
        }
    }

    cout << arr[x - 1][y - 1];
}