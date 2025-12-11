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
	
	int N;
	cin >> N;
	vector <int> sums(N + 1);	// i번째 숫자까지 더한 값 저장하는 벡터

	// N개의 숫자 입력, i번째 숫자까지 더한 값 저장
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (i == 0)
		{
			sums[i] = input;
		}
		else
		{
			sums[i] = sums[i - 1] + input;
		}
	}

	int M;
	cin >> M;
	int startNum, endNum;
	while (M--)
	{
		cin >> startNum >> endNum;
		if (startNum == 1)
		{
			cout << sums[endNum - 1] << "\n";
		}
		else
		{
			cout << sums[endNum - 1] - sums[startNum - 2] << "\n";
		}
	}

	return 0;
}