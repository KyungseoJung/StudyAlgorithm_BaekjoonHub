#include <iostream>
#include <vector>
#include <cmath>	// sqrt 사용하기 위함

using namespace std;
/* 핵심 아이디어
제곱근까지만 검사하면 됨!
주의 : 절반까지가 아니라, 제곱근까지임!! 16의 약수가 1, 4, 16이듯이

// 일반적으로 큰 수일수록 num의 제곱근은 num보다는 2에 더 가까울 것이니까, for문의 시작 순서를 바꿔주자. 그러면 시간 단축될 거야.
*/

bool checkPrimeNumber(int num)
{
	if (num == 1)
	{
		return false;
	}
	else if (num == 2)	// 아래 for문에서 num이 2일 땐, return false가 되어버리므로. 2는 따로 설정해주기.
	{
		return true;
	}
	//for (int i = (num - 1); i*i >= num; i--)	// sqrt(i) >= num 대신에 제곱 사용
	for(int i = 2; i<= sqrt(num); i++)	// 일반적으로 큰 수일수록 num의 제곱근은 num보다는 2에 더 가까울 것이니까, for문의 시작 순서를 바꿔주자. 그러면 시간 단축될 거야. 
	{
		// 제곱근까지만 검사해도 됨. 약수들은 어차피 홀수이든, 짝수이든 대칭을 이루니까. 
		if ((num % i == 0))	// 나누었을 때, 나머지가 0인 수가 하나라도 있다면 그 수는 1과 자기자신을 제외한 약수가 있다는 것.
		{
			return false;
		}
	}

	return true;	// 위 for문에서 한번도 return true가 되지 않았다면, 1과 자기자신을 제외한 약수가 없다는 것. = 소수라는 것.

}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		if (checkPrimeNumber(i) == true)
		{
			cout << i << "\n";
		}
	}

	return 0;

}