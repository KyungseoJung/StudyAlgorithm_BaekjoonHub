#include <iostream>
#include <vector>

using namespace std;
// 29807번 문제
int main()
{
	int T;
	cin >> T;

	vector <int> scores(5, 0);	// 기본 값은 0

	for (int i = 0; i < T; i++)
	{
		cin >> scores[i];
	}

	int sum = 0;
	// 국어 점수가 영어 점수보다 높다면
	if (scores[0] > scores[2])
	{
		sum += (scores[0] - scores[2]) * 508;
	}
	else
	{
		sum += (scores[2] - scores[0]) * 108;
	}

	// 수학 점수가 탐구 점수보다 높다면
	if (scores[1] > scores[3])
	{
		sum += (scores[1] - scores[3]) * 212;
	}
	else
	{
		sum += (scores[3] - scores[1]) * 305;
	}

	if (scores[4] > 0)
	{
		sum += scores[4] * 707;
	}

	int studentNumber = sum * 4763;


	cout << studentNumber;

	return 0;
}