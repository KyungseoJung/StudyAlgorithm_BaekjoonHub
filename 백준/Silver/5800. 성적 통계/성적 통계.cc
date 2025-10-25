#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 5800번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int K, N;
	cin >> K;

	int min, max, largestGap;
	vector <int> scores;
	int inputScore;
	for (int i = 0; i < K; i++)
	{
		min = 999;
		max = 0;
		largestGap = 0;
		scores.clear();
		// 각 클래스 i마다 3가지 정보 확인하기
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> inputScore;
			scores.push_back(inputScore);
			if (inputScore > max)
			{
				max = inputScore;
			}
			if (inputScore < min)
			{
				min = inputScore;
			}
		}

		// 가장 큰 gap 찾기. (1) 정렬하기, (2) 각 수의 gap 확인
		sort(scores.begin(), scores.end());
		for (int i = 1; i < scores.size(); i++)
		{
			if (scores[i] - scores[i - 1] > largestGap)
			{
				largestGap = scores[i] - scores[i - 1];
			}
		}

		// 출력
		cout << "Class " << (i + 1) << "\n";
		cout << "Max " << max << ", Min " << min << ", Largest gap " << largestGap << "\n";
	}

	return 0;
}