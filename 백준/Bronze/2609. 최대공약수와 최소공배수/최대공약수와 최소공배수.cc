#include <iostream>
#include <vector>
#include <string>

using namespace std;


int n,m;


int min()
{
    int a= n;
    int b= m;

    if(a<b)
    {
        swap(a,b);
    }

    int x;
    while( b != 0)
    {
        x = a%b;
        a=b;
        b =x;
    }
    return a;
}


int main()
{
    cin>>n>>m;
    int gcd = min();

    cout<<gcd<<' '<<m*n/gcd;

}