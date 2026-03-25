#include <iostream>

using namespace std;
// 2921번 문제: 도미노
int main()
{
	int N;
	cin >> N;

	// 밑이 0일 때 1가지 경우. 밑이 1일 때 2가지 경우. 밑이 2일 때 3가지 경우.
	int sum = 0;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum = sum + i + j;
		}
	}

	cout << sum;

	return 0;

}