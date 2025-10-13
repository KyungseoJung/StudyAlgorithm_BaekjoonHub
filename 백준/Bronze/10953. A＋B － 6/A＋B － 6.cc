#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 10953번 문제.

int main()
{
	int T;
	cin >> T;
	string st;
	int A, B;
	int sum;
	for (int i = 0; i < T; i++)
	{
		cin >> st;
		A = st[0] - '0';
		B = st[2] - '0';

		sum = A + B;
		cout << sum << "\n";
	}
	return 0;
}