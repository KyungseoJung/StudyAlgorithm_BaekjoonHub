#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 1268번 문제: 임시 반장 정하기

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int studentNum;
	cin >> studentNum;

	int gradeNum = 5;
	vector <vector <int> > classes(studentNum, vector <int>(gradeNum));
	// studentNum 만큼 행이 있고, gradeNum만큼 열이 있음.

	for (int i = 0; i < studentNum; i++)
	{
		for (int j = 0; j < gradeNum; j++)
		{
			cin >> classes[i][j];
		}
	}

	// 한번이라도 같은 반이었던 사람을 카운팅하기
	vector <int> counting(studentNum);
	for (int i = 0; i < studentNum; i++)
	{
		for (int j = i+1; j < studentNum; j++)
		{
			// 5학년때까지 한번이라도 같은 반이 된 적이 있다면 카운팅 +1
			for (int k = 0; k < gradeNum; k++)
			{
				if (classes[i][k] == classes[j][k])
				{
					// i번째 학생과 j번째 학생을 모두 카운팅+1 해줘서,
					// 항상 자신보다 높은 ele에 해당하는 학생들과만 비교하자
					counting[i]++;
					counting[j]++;
					break;	// 한번이라도 같은 적이 있다면, 카운팅 한번만 하면 됨.
				}
			}
		}
	}

	// 카운팅이 가장 큰 번호 확인하기
	int maxEle = 0;
	int maxCounting = -1;
	for (int i = 0; i < studentNum; i++)
	{
		if (counting[i] > maxCounting)
		{
			maxCounting = counting[i];
			maxEle = i;
		}
	}

	cout << maxEle + 1;		// ele 저장을 0부터 했으므로 출력은 +1해서 하자


	return 0;
}