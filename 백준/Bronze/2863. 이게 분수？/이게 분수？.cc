#include <iostream>
#include <vector>

using namespace std;
// 2863번 문제: 이게 분수?
int main()
{
	float A, B, C, D;
	cin >> A >> B >> C >> D;

	vector <float> score(4);	// 0번~3번회전까지의 점수 기록
	score[0] = A / C + B / D;
	score[1] = C / D + A / B;
	score[2] = D / B + C / A;
	score[3] = B / A + D / C;

	int max = 0;
	int ele = 0;
	for (int i = 0; i < score.size(); i++)
	{
		if (score[i] > max)
		{
			max = score[i];
			ele = i;
		}
	}

	cout << ele;

	return 0;
}