#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    int A[100]={0,};

    int dp1[100]={0,};
    int dp2[100]={0,};

    dp1[0]=1;
    dp1[1]=0;

    dp2[0]=0;
    dp2[1]=1;

    for(int i=2;i<100;i++)
    {
        dp1[i]=dp1[i-1]+dp1[i-2];
        dp2[i]=dp2[i-1]+dp2[i-2];
    }

    for(int i=0;i<T;i++)
    {
        cin>>A[i];
        cout<<dp1[A[i]]<<" "<<dp2[A[i]]<<"\n";
    }

    return 0;
}