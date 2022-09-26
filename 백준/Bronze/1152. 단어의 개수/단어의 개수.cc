#include<iostream>

using namespace std;
 
int main()
{
    string cstr;
    
    getline(cin, cstr); //C++ 스타일의 문자열 입력 방식
    int cnt = 0;

    for(int i = 0; i < cstr.length();i++)
    {
        if(cstr[i] == ' ')
        cnt++;

    }
    if(cstr[0] != ' ')
        cnt++;
    if(cstr[cstr.length()-1] == ' ')
        cnt--;

    cout<<cnt;
}