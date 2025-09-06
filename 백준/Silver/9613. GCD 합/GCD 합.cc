#include <iostream>
#include <vector>

using namespace std;
//** gpt에게 아이디어 얻음 => 유클리드 호제법
// A와 B (A>B)의 최대 공약수는 A%B)와 B의 최대공약수와 동일하다.
/* 이해!!!
* 예) 9와 21의 길이를 가진 두 나무 막대가 있음.
이 두 수의 최대공약수는, 특정한 n의 길이를 가진 작은 나무막대가 한칸한칸 9와 21길이의 나무막대를 커버할 때
완벽하게 떨어지도록 커버하는 나무 막대의 길이를 찾는 것.

즉, 따라서 A와 B의 최대공약수 = (A%B)와 B의 최대 공약수임.
*/

/* 중요한 아이디어는, 이 과정을 서로서로 반복해야 돼! (나머지가 0이 나올 때까지)
그래야 시간적으로도 빠르고, 수식적으로도 정확한 최대공약수가 나오는 것임이로
작은 수에서는 대부분 정답이지만, 큰 수를 다루면 오답이 나올 수 있음.
*/

// long long int 처리 추가
long long int returnGCD(long long int num1, long long int num2)
{
	long long int max = num1 > num2 ? num1 : num2;
	long long int min = num1 > num2 ? num2 : num1;

	long long int temp;
	while (true)
	{
		temp = max % min;	// min으로 나누었을 때 나머지이므로, temp는 min미만의 수임

		if (temp == 0)
		{
			return min;
		}
		// 기존 max는 버리고, 이제 (max % min)과 min만 다룰 것임.
		max = min;
		min = temp;


	}

}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	int n;
	vector<long long int> input;
	vector <long long int> GcdSums(t, 0);	// 각 테스트의 GCD의 합을 저장할 벡터
	for (int i = 0; i < t; i++)
	{
		cin >> n;	// 각 테스트 케이스마다 몇 개의 수를 입력하는지
		input.clear();	// 안의 값을 비우고, n의 크기로 설정하기
		input.resize(n);

		for (int j = 0; j < n; j++)
		{
			cin >> input[j];
		}


		// 각 2개의 숫자의 gcd를 계산하기
		for (int a = 0; a < n; a++)
		{
			for (int b = (a + 1); b < n; b++)
			{
				GcdSums[i] += returnGCD(input[a], input[b]);
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		// 각 테스트의 케이스마다 가능한 모든 쌍의 GCD의 합을 출력
		// GCD가 없다면 1이 GCD(최대공약수)
		cout << GcdSums[i] << "\n";
	}
	return 0;

}