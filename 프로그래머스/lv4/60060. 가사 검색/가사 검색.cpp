#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


bool lengthCompare(const string& a, const string& b) {
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length())
        if (a < b) return true;
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) 
{
    vector<int> answer;
    vector<string> reverseWords = words;
    
    for(int i = 0; i<words.size();i++)
    {
        reverse(reverseWords[i].begin(),reverseWords[i].end());
    }
    
    sort(words.begin(),words.end(),lengthCompare);
    sort(reverseWords.begin(),reverseWords.end(),lengthCompare);
    
    for(string query : queries)
    {
        if(query[0]!='?')
        {
            string start(query);
            string end(query);
            int idx = query.find('?');
            
            for (int i = idx; i < start.length(); ++i)
            {
                if (start[i] == '?')
                    start[i] = 'a';
            }
                
            
            auto startPoint = lower_bound(words.begin(),words.end(),start,lengthCompare);
            for (int i = idx; i < end.length(); ++i)
            {
                if (end[i] == '?')
                    end[i] = 'z';
            }
                
            auto endPoint = upper_bound(words.begin(), words.end(),end,lengthCompare);
            
            answer.push_back(endPoint - startPoint);
        }
        else
        {
            reverse(query.begin(),query.end());
            string start = query;
            string end = query;
            
            for (int i = 0; i < start.length(); ++i)
                if (start[i] == '?')
                    start[i] = 'a';
            auto startPoint = lower_bound(reverseWords.begin(),reverseWords.end(),start,lengthCompare);
            for (int i = 0; i < end.length(); ++i)
                if (end[i] == '?')
                    end[i] = 'z';
            auto endPoint = upper_bound(reverseWords.begin(), reverseWords.end(),end,lengthCompare);
            
            answer.push_back(endPoint - startPoint);
        }
    }
    return answer;
    
}