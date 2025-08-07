// 이전 문제와 동일한 방식: 누적합 계산 방식 그대로 다시 이용
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;

	vector <int> nums(N);
	vector <int> sums(N);	// 누적합 | 예: sums[2] = 0번째~2번째 데이터까지 누적합한 값
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		if (i == 0)
		{
			sums[i] = nums[i];
		}
		else // i >= 1
		{
			sums[i] = sums[i - 1] + nums[i];
		}
	}


	long long int max = -999999999999;
	int calNum;
	// 최대값 확인
	for (int i = 0; i < N - K + 1; i++)
	{
		if (i == 0)
		{
			calNum = sums[i + K - 1];
		}
		else
		{
			calNum = sums[i + K - 1] - sums[i - 1];
		}

		if (calNum > max)
		{
			max = calNum;
		}
	}

	cout << max;
	return 0;
}