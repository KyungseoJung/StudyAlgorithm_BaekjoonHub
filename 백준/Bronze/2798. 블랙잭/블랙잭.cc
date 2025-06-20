#include <iostream>

int main()
{
	// 게임 블랙잭
	// N: 놓을 카드 개수, M: 3장의 카드 합이 이 M값을 넘지 않으면서 최대한 가깝게 맞춰야 함

	int N, M;
	int num[100];	// 카드의 개수는 100이하이므로

	std::cin >> N >> M;

	for (int i = 0; i < N; i++)	// 숫자 카드 입력
	{
		std::cin >> num[i];
	}

	int sum = 0;
	int maxSum = 0;

	for (int i = 0; i < N; i++)	// 1번째 카드 선택
	{
		for (int j = i + 1; j < N; j++)	// 2번째 카드 선택
		{
			for (int k = j + 1; k < N; k++)	// 3번째 카드 선택
			{
				sum = num[i] + num[j] + num[k];
				if ((sum > maxSum) && (sum <= M))
				{
					maxSum = sum;
				}
			}
		}
	}


	std::cout << maxSum;

	return 0;
}