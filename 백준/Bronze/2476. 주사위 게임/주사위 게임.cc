#include <iostream>
#include <vector>


using namespace std;
int main()
{
	int N;
	cin >> N;
	vector <int> price(N);

	int num = 3;	// 주사위는 총 3개 던짐
	vector <int> dice(num);
	int max;
	for (int i = 0; i < N; i++)
	{
		max = 0;
		// 3개 주사위 적기 -------------------------
		for (int j = 0; j < num; j++)
		{
			cin >> dice[j];
			if (dice[j] > max)
			{
				max = dice[j];
			}
		}

		// 3개 케이스에 따라 상금 확인 -------------------------
		// (1) 같은 눈이 3개가 나오면 10,000원 + (같은 눈)x 1,000원
		if ((dice[0] == dice[1]) && (dice[1] == dice[2]))
		{
			price[i] = 10000 + dice[0] * 1000;
		}
		else if (dice[0] == dice[1])
		{
			price[i] = 1000 + dice[0] * 100;
		}
		else if (dice[0] == dice[2])
		{
			price[i] = 1000 + dice[0] * 100;
		}
		else if (dice[1] == dice[2])
		{
			price[i] = 1000 + dice[1] * 100;
		}
		else
		{
			price[i] = max * 100;
		}
	}

	// 3명의 상금 비교 -------------------------
	int maxPrice = 0;
	for (int i = 0; i < N; i++)
	{
		if (price[i] > maxPrice)
		{
			maxPrice = price[i];
		}
	}

	cout << maxPrice;
	return 0;
}