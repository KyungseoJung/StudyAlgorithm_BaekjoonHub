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

	int num = 8;
	vector <int> scores(num);			// 기존에 입력한 순서대로의 점수들
	vector <int> sortingScores(num);	// 정렬할 점수들
	int input;
	
	// 일단 점수들 입력
	for (int i = 0; i < num; i++)
	{
		cin >> input;
		scores[i] = input;
		sortingScores[i] = input;
	}

	// 점수들 정렬
	sort(sortingScores.begin(), sortingScores.end());

	// 총점 계산
	int sum = 0;
	vector <int> index;
	for (int i = sortingScores.size() - 5; i < sortingScores.size(); i++)
	{
		sum += sortingScores[i];
		// 포함된 점수들의 index 확인
		for (int j = 0; j < scores.size(); j++)
		{
			if (scores[j] == sortingScores[i])
			{
				index.push_back(j);
				break;
			}
		}
	}

	sort(index.begin(), index.end());


	// 출력
	cout << sum << "\n";
	for (int i = 0; i < index.size(); i++)
	{
		cout << index[i] +1 << " ";
	}


	return 0;
}