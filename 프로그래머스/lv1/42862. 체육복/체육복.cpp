#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    int arr[32] = { 0, };

    for (int n : lost) arr[n]--;
    for (int n : reserve) arr[n]++;

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == -1)
        {
            if (arr[i - 1] == 1 && arr[i + 1] == 1)
            {
                arr[i - 1]--;
                arr[i]++;
            }
            else if (arr[i - 1] == 1)
            {
                arr[i - 1]--;
                arr[i]++;
            }
            else if (arr[i + 1] == 1)
            {
                arr[i + 1]--;
                arr[i]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= 0)
            answer++;
    }
    return answer;
}

