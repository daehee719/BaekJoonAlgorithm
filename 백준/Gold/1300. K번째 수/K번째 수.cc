#include<iostream>
#include<algorithm>
using namespace std;

long long N, K;
long long startNum, endNum, mid;
long long cnt;

long long count(long long x)
{
	long long sum = 0;
	for (int i = 1; i <= N; i++) 
        sum += min(x / i, N);
    
	return sum;
}

int main()
{
	cin >> N >> K;

	startNum = 1;
	endNum = N * N;

	while (startNum <= endNum)
	{
		mid = (startNum + endNum) / 2;

		cnt = count(mid);

		if (cnt >= K) endNum = mid - 1;
		else startNum = mid + 1;
	}
    
	cout << startNum;
}