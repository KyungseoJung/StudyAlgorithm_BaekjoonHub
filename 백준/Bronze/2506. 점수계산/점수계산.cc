#include <iostream>

using namespace std;
// 2506번 문제: 점수계산
int main()
{
	int N;
	cin >> N;
	
	int score = 1;	// 배점 (연속으로 맞추면 배점+1)
	int input;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> input;
		if (input == 1)
		{
			sum += (score);
			score += 1;	// 다음 배점 올리기
		}
		else if (input == 0)
		{
			score = 1;
		}
	}

	cout << sum;
	return 0;
}