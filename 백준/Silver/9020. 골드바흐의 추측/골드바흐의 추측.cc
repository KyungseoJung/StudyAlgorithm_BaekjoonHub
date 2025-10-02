#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>	// #sqrt 사용

using namespace std;
// 9020번 문제. 골드바흐의 추측.

bool checkPrimeNum(int num)	// 소수가 맞으면 true 리턴
{
	if (num == 1)
	{
		return false;
	}
	else if (num == 2)
	{
		return true;
	}
	else
	{
		// 모든 소수가 아닌 수들은, 약수를 그 수의 제곱근보다 작은 값 & 큰 값을 대칭적으로 가지고 있음
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
	}
	// 위의 모든 과정을 통과했다면, 소수가 맞음
	return true;
}
void GDBH(int num)
{
	int num1, num2;

	// 과정
	// 짝수라면
	if (num % 2 == 0)
	{
		for (int i = 0; i < (num / 2); i++)
		{
			if ( (checkPrimeNum(num/2 - i) == true) && (checkPrimeNum(num/2 + i) == true))
			{
				num1 = num/2 - i;
				num2 = num/2 + i;

				break;	// for문 종료
			}
		}
	}


	cout << num1 << " " << num2 << "\n";
}
int main()
{
	int T;	// 테스트의 개수
	cin >> T;

	int num;
	while (T--)
	{
		cin >> num;

		GDBH(num);
	}
}
