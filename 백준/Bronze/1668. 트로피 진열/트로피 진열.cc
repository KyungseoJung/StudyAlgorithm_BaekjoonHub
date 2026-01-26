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
// 1225번 문제: 이상한 곱셈 

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector <int> heights(N);
	for (int i = 0; i < N; i++)
	{
		cin >> heights[i];
	}

	// 왼쪽에서 봤을 때 보이는 개수 확인 ----------------------
	int maxHeight = 0;
	int leftCount = 0;
	for (int i = 0; i < N; i++)
	{
		if (heights[i] > maxHeight)
		{
			maxHeight = heights[i];
			leftCount++;
		}
	}

	// 오른쪽에서 봤을 때 보이는 개수 확인 ----------------------
	maxHeight = 0;
	int rightCount = 0;
	for (int i = N-1; i >=0; i--)
	{
		if (heights[i] > maxHeight)
		{
			maxHeight = heights[i];
			rightCount++;
		}
	}

	cout << leftCount << "\n" << rightCount;

	return 0;
}