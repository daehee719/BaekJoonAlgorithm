#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
	unordered_map<string, int> um;
	unordered_map<string, int>::iterator iter;
	for (int i = 0; i < participant.size(); i++)
	{
		um[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++)
	{
		um[completion[i]]--;
		if (um[completion[i]] == 0)
			um.erase(completion[i]);
	}

	iter = um.begin();
	answer = iter->first;

    return answer;
}