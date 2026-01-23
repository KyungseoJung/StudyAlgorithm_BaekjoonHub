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

	vector <int> seat(100, 0 );	// 1번부터 100번까지 컴퓨터
	int N;
	cin >> N;

	int seatNum;
	int count = 0;
	while (N--)
	{
		cin >> seatNum;
		if (seat[seatNum] == 0)
		{
			seat[seatNum] = 1;
		}
		else
		{
			count++;	// 거절당한 사람의 수 +1
		}
	}

	cout << count;

	return 0;
}