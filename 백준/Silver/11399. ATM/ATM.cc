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
// 1524번 문제: 세준세비 (https://www.acmicpc.net/problem/1524)

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector <int> P(N);
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}
	// 오름차순으로 정렬해서 서야, 필요한 시간의 합이 최소화 됨. (작은 숫자가 앞으로, 큰 숫자가 뒤로 가도록)
	sort(P.begin(), P.end());

	int time = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		time = time + P[i];
		sum += time;
	}

	cout << sum;

	return 0;
}