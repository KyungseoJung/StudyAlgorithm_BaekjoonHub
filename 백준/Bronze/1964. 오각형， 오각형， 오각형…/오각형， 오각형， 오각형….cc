#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 2964번 문제.

int main()
{
	// 5 -> 12 -> 22
	// 더하는 숫자가 처음에는 7이고, 그 이후부터는 3씩 증가하나
	int N;
	cin >> N;

	long long int answer = 5;
	long long int sumNum = 7;
	for (int i = 1; i < N; i++)
	{
		answer += sumNum;
		sumNum += 3;
	}

	cout << answer % 45678;

	return 0;
}