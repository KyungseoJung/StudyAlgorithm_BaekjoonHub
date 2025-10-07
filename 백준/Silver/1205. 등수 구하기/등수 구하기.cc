#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 1205번 문제.

int main()
{
	long long int N, tScore, P;
	cin >> N >> tScore >> P;

	bool checkSameScore = false;
	long long int rankNum = 0;
	vector <long long int> scores(N);
	for (int i = 0; i < N; i++)
	{
		cin >> scores[i];

		if (scores[i] == tScore)	// 태수의 새로운 점수와 같은 점수가 있다면
		{
			checkSameScore = true;
			rankNum = i;
			// 만약 같은 수가 여러개여도, 가장 마지막 순위가 저장되도록
		}
	}

	// 1) 점수가 아예 없는 경우부터 고려
	if (N == 0)
	{
		cout << 1;
		return 0;
	}

	
	// 2) 동일한 점수가 존재한다면
	if (checkSameScore == true)
	{
		if ((rankNum + 1) >= P)
		{
			// 위에서 설정한 rankNum은 0부터 시작이므로. +1 처리해주기
			// 점수가 동일한데, P랑 같으면 랭킹 리스트 올라갈 수 없음.
			cout << -1;
			return 0;
		}
		else
		{
			// 만약 같은 수가 여러개여도, 가장 첫 순위가 출력되도록 다시 search
			for (int i = 0; i < N; i++)
			{
				if (scores[i] == tScore)
				{
					cout << i + 1;
					return 0;
				}
			}
		}
	}
	else // 3) 동일한 점수가 없다면, 태수의 점수보다 작은 점수 중 가장 큰 점수를 찾기
	{

		// 만약 태수의 점수가 가장 작다면 
		if (tScore < scores[N - 1]) 
		{ 
			rankNum = N + 1; 
		} 
		else 
		{ 
			// 태수의 점수보다 작은 점수가 하나라도 존재한다면 
			for (int i = 0; i < N; i++) 
			{ 
				if (tScore > scores[i]) 
				{ 
					rankNum = i + 1; 

					break;
				} 
			} 
		}


		if (rankNum > P)
		{
			cout << -1;
			return 0;
		}
		else
		{
			cout << rankNum;
			return 0;
		}
	}


}
