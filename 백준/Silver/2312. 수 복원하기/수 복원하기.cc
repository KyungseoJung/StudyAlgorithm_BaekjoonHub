#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>	// to_string

using namespace std;
// 2312번 문제.

void printDivisor(long long int num)
{
	vector <int> divisorCount(num + 1, 0);	// num까지의 숫자를 담을 수 있는 벡터 생성
	long long int maxDivisor = 0;

	while (num != 1)	// num이 1이 될 때까지 시행
	{
		for (int i = 2; i <= num; i++)
		{
			if (num % i == 0)	// 만약 나누어진다면 약수로 추가
			{
				num = num / i;	// num을 새롭게 업데이트 (나눈 숫자로)
				divisorCount[i]++;

				// 가장 높은 약수 숫자를 저장해두기 - 나중에 출력하기 위함
				if (i > maxDivisor)
				{
					maxDivisor = i;
				}

				break;	// 약수 하나 찾았다면, break; (다시 처음부터 for문 시작하도록)
			}
		}
	}


	// 약수들 출력
	for (int i = 2; i <= maxDivisor; i++)
	{
		if (divisorCount[i] != 0)
		{
			cout << i << " " << divisorCount[i] << "\n";
		}
	}
}


int main()
{
	int T;
	cin >> T;
	long long int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		printDivisor(N);
	}
	return 0;
}