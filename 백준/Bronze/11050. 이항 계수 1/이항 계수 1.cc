#include <iostream>

using namespace std;
int factorial(int num)
{
	int answer = 1;
	for (int i = 1; i <= num; i++)
	{
		answer = answer * i;
	}

	return answer;
}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;

	cin >> N >> K;

	// N개 중, K개를 뽑는 조합
	// 공식이 따로 있긴 함. N_Combination_K = (N!)/[K! (N-K)!]

	cout << factorial(N) / (factorial(K)* factorial(N-K));

	return 0;
}