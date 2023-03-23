#include <iostream>

using namespace std;

int arr[10001];
int newArr[10001];


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	newArr[0] = arr[0];
	newArr[1] = arr[0] + arr[1];
	newArr[2] = max(newArr[1], max(newArr[0] + arr[2], arr[1] + arr[2]));

	for (int i = 3; i < n; i++)
	{
		newArr[i] = max(newArr[i-1], 
			max(newArr[i - 2] + arr[i],
				newArr[i - 3] + arr[i - 1] + arr[i]));
	}
	cout << newArr[n - 1];
}