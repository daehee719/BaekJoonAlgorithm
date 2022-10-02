#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
int map[110][110];
int N;
int safeArea = 1;
int minArea = 99999;
int maxArea = -99999;
 
queue<pair<int, int>> q;
int visited[110][110];
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
void init()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
}
 
int safe(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void BFS(int x, int y, int rain)
{
    visited[x][y] = 1;
    q.push({x, y});
    
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int xpos = x+dx[i];
            int ypos = y+dy[i];
            
            if(safe(xpos, ypos) == 1 && visited[xpos][ypos] == 0 && map[xpos][ypos] > rain)
            {
                visited[xpos][ypos] = 1;
                q.push({xpos, ypos});
            }
        }
    }
}
 
int main(void)
{
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            
            if(maxArea < map[i][j])
            {
                maxArea = map[i][j];
            }
            
            if(minArea > map[i][j])
            {
                minArea = map[i][j];
            }
        }
    }
    
    for(int k = minArea; k <= maxArea; k++)
    {
        int cnt = 0;
        init();
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(visited[i][j] == 0 && map[i][j] > k)
                {
                    BFS(i, j, k);
                    cnt++;
                }
            }
        }
        
        if(safeArea < cnt)
        {
            safeArea = cnt;
        }
    }
    
    cout << safeArea;
    
    return 0;
}
