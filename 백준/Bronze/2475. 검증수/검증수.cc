#include <iostream>
using namespace std;

int main()
{
    int s = 0;
    for(int i = 0; i < 5; i++)
    {
        int a;
        cin>>a;
        s+= a*a;
    }
    cout<<s%10;
}