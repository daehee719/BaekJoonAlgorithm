#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int n;
    cin>>n;
    queue<int> q;
    cout<<'<';

    for (int i = 0; i < n; i++)
    {
        q.push(i+1);
    }
    int k;
    cin>>k;
    
    while(!q.empty())
    {
        for (int i = 0; i < k-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        q.pop();


        if(q.size() >= 1)
            cout<<", ";
    }
    cout<<'>';
}