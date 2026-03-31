#include <iostream>
#include <cmath>

using namespace std;
// 2903번 문제: 중앙 이동 알고리즘
int main()
{
	int N;
	cin >> N;

	// 0번째: 2^2
	// 1번째: 3^2 (3 = 2 + 2^0)
	// 2번째: 5^2 (5 = 3 + 2^1)
	// 3번째: 9^2 (9 = 5 + 2^2)

	// (아마도) 4번째: 17^2 ( 17 = 9 + 2^3)
	// 5번째: 33^2 

	long long int multipleNum = 2;
	for (int i = 0; i < N; i++)
	{
		multipleNum += pow(2, i);
	}
	cout << multipleNum * multipleNum;
	return 0;
}