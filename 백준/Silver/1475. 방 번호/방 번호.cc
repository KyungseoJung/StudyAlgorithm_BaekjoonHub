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
// 11441번 문제: 합 구하기

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string num;
	cin >> num;

	int checkNum;

	vector <int> numSet(10);	// 0부터 9까지의 숫자가 들어있는 숫자 세트
	// 한 번 쓰일 때마다 +1씩하기

	for (int i = 0; i < num.length(); i++)
	{
		checkNum = (num[i] - '0');	// char 형태의 값을 정수로 확인해서 넣기
		numSet[checkNum]++;
	}

	// 가장 많이 사용된 숫자의 횟수를 세면 됨.
	// 단 6과 9는 (둘의 횟수를 합친 것 +1)의 나누기 2를 해서 최댓값을 계산
	int max = 0;
	for (int i = 0; i < numSet.size(); i++)
	{
		if ((i != 6) && (i != 9) && (numSet[i] > max))
		{
			max = numSet[i];
		}

		int sum = (numSet[6] + numSet[9] + 1) / 2;

		max = (max > sum) ? max : sum;
	}

	cout << max;

	return 0;
}