#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

vector<int> arr = {2,3,5,7};

int main()
{
	int n;
    int count = 0;
    cin>>n;
    while(n!=0)
    {
        int a;
        cin>>a;
        int cnt = 0;
        for (int i = a; i >=1 ; i--)
        {
            if(a%i == 0)
                cnt++;
        }

        if(cnt == 2)
            count++;
        n--;
        
    }
    cout<<count;
}