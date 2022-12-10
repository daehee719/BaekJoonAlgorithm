#include <map>
#include <iostream>
#include <string>

using namespace std;

map<string,int> pocketMap;
map<int,string> pocketNumMap;
int main()
{
	ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        string name;
        cin>>name;
        pocketMap.insert(make_pair(name,i+1));
        pocketNumMap.insert(make_pair(i+1,name));
    }
    //cout<<pocketMap["Butterfree"];
    
    for(int i = 0; i < m; i++)
    {
        string s;
        cin>>s;
        if(isdigit(s[0]))
        {
	        int c = stoi(s);
            cout<<pocketNumMap[c]<<'\n';
        }
        else
        {
            cout<<pocketMap[s]<<'\n';
        }
    }
}
