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
// 16435번 문제: 스네이크버드

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, L;	// 과일의 개수, 스네이크버드의 초기 길이
	cin >> N >> L;

	vector <int> heights(N);
	for (int i = 0; i < N; i++)
	{
		cin >> heights[i];
	}

	sort(heights.begin(), heights.end());	// 오름차순 정렬해주기

	// 낮은 높이의 과일부터 하나씩 먹기
	for (int i = 0; i < N; i++)
	{
		if (heights[i] <= L)
		{
			L += 1;
		}
		else // 스네이크버드의 길이보다 큰 과일이 나왔다면, L 바로 출력하기 (그 이상의 과일들은 먹을 수 없으므로, 스네이크버드는 더이상 커질 수 없음)
		{
			cout << L;
			return 0;
		}
	}

	cout << L;	// 모든 과일을 먹을 수 있다면, for문을 모두 통과했을 것이므로
	return 0;
}