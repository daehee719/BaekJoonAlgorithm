#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> v;

int main()
{
    int a;
    cin>>a;
    for(int i = 0; i < a; i++)
    {
        double b ;
        cin>>b;
        v.push_back(b);
    }
    
    sort(v.begin(),v.end());
    
    double result = 0;
    
    for(int i = 0; i < a; i++)
    {
        result += v.at(i) / v.at(a-1) * 100;
    }
    cout<<result/a;
}