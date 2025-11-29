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
// 2774번 문제: 아름다운 수

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	string num;
	vector <int> count;	// 0부터 9까지 체크
	int beauty;
	while (T--)
	{
		count.assign(10, 0);	// 크기를 10으로 하고 모든 요소를 0으로 초기화
		beauty = 0;
		cin >> num;
		for (int i = 0; i < num.length(); i++)
		{
			//cout << int(num[i] - '0') << "\n";
			count[int(num[i] - '0')] += 1;
		}

		// 얼마나 아름다운지 판단
		for (int i = 0; i < 10; i++)
		{
			if (count[i] > 0)
			{
				beauty++;
			}
		}

		cout << beauty << "\n";

	}
	
	return 0;
}