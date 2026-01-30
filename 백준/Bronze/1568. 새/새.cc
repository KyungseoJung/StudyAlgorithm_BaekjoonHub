#include <iostream>

using namespace std;
// 1568번 문제: 새

int main()
{
	int N;
	cin >> N;

	long long int num = 1;	// 노래하는 숫자 기록
	long long int rest = N;	// 남은 새의 수

	long long int singTime = 0;
	while (true)
	{
		if (num <= rest)
		{
			rest -= num;
			//cout << rest << "명 남았는데, " << num << "만큼 날아감\n";
		}
		else // num이 rest보다 커지면 1부터 다시 시작
		{
			num = 1;
			rest -= num;
		}
		num++;
		singTime++;

		if (rest <= 0)
		{
			cout << singTime;
			break;
		}
	}
	return 0;
}