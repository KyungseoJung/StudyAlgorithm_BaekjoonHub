#include <iostream>
#include <vector>

using namespace std;
int checkPrimeNumber(int num)	// num이 소수인지 확인 (소수라면 1, 아니라면 0 return)
{
	// 한번이라도 1과 자기 자신이 아닌 수로 나눠서 나머지가 0이라면, 소수가 아님
	if ((num != 2) && (num % 2 == 0))	// 짝수로 나누었을 때 (모든 짝수는 2의 배수이므로, 2로만 나눠봐도 됨
		return 0;
	else // 홀수로 나누었을 때
	{
		for (int i = 3; i*i <= num; i += 2)	// i의 제곱이 num보다 작거나 같을 때까지만 확인하면 됨. 
			// (왜: 어떤 수의 약수는 16같은 완전제곱수의 경우 4라는 중간지점을 기준으로 대칭적인 개수의 약수를 가지고 있음)
			// 즉, 제곱근까지만 확인해보면, 약수가 있는지 없는지 확인이 가능하다는 말임.
			// 2부터 제곱근까지 확인했을 때 약수가 없다면 : 그 수는 소수인 것
			// 2부터 제곱근까지 확인했을 때 약수가 있다면 : 그 수는 소수가 아닌 것
		{
			if (num % i == 0)
				return 0;
		}
	}

	return 1;	// 위 for문에서 한번이라도 if문에 해당되지 않았다면 소수임
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	int sum;

	vector <int> answer(99999);
	int ele = 0;

	while (true)
	{
		cin >> n;
		if (n == 0)
			break;

		sum = 0;

		for (int i = n + 1; i <= (2 * n); i++)
		{
			sum += checkPrimeNumber(i);
		}
		answer[ele] = sum;

		ele++;
	}

	for (int i = 0; i < ele; i++)
	{
		cout << answer[i] << "\n";
	}
	return 0;


}