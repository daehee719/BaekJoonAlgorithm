#include <iostream>

using namespace std;

int change(int a)
{
    
    int result = 0;
    
    for(int i = a; i >= 1; i/=10)
    {
        result+=i%10;
        if(i > 10)
        {
            result*=10;
        }
    }
    return result;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    int a = change(n);
    int b = change(m);
    
    if(a>b)
        cout<<a;
    else
        cout<<b;
    
}