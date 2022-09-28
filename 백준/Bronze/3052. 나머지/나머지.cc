#include<iostream>
#include <algorithm>
using namespace std;


int arr[42];
bool isbig(int a,int b)
{
    return a>b;
}

int main()
{
    // fill_n(arr,arr + 42,0);
    for(int i = 0; i<10;i++)
    {
        int a;
        cin>>a;
        arr[a%42]++;
    }

    sort(arr,arr+42,isbig);
    for(int i = 0; i<42;i++)
    {
        if(arr[i] == 0)
        {
            cout<<i;
            break;
        }
        
    }
    

}