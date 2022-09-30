#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
	int n;
    cin>>n;
    int result = 0;
    for(int i = n; i>=0; i-- )
    {
        result += i;
    }
    cout<<result;
}