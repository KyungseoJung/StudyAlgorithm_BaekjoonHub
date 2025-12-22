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
// 2576번 문제: 홀수

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 7;
	
	int input;
	int sum = 0;
	vector <int> oddNum;
	while (N--)
	{
		cin >> input;
		if (input % 2 == 1)
		{
			oddNum.push_back(input);
			sum += input;
		}
	}
	if (oddNum.size() > 0)
	{
		sort(oddNum.begin(), oddNum.end());
		cout << sum << "\n" << oddNum[0];
	}
	else
	{
		cout << -1;
	}


	return 0;
}