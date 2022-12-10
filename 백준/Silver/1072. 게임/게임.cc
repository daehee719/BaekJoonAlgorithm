#include <iostream>

using namespace std;

long long X, Y, Z;

int main()
{
	cin >> X >> Y;
	Z = Y * 100 / X;
	if (Z >= 99) {
		cout << -1;
		return 0;
	}

	long long L = 0, R = 1e10;
	while (L <= R) {
		long long mid = (L + R) / 2;
		long long cal = 100 * (Y + mid) / (X + mid);
		if (cal > Z) {
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}

	cout << L;

}