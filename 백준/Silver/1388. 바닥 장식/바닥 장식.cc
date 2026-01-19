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

	int N, M;
	cin >> N >> M;

	vector <vector <char>> floor(N, vector <char>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> floor[i][j];
		}
	}

	// 가로 나무 판자 개수 파악
	bool horizontal = true;
	int countHorizontal = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (floor[i][j] == '-')
			{
				// 만약 맨 처음부터 가로 판자가 잘 나왔다면
				if ((i == 0) && (j == 0))
				{
					countHorizontal++;
				}
				else if (horizontal == false)	// 만약 이전에 가로 판자가 아니었다면, 지금 가로판자가 나온거라면
				{
					countHorizontal++;
				}
				horizontal = true;
			}
			else if(floor[i][j] == '|')
			{
				horizontal = false;
			}
		}
		horizontal = false;	// 줄 바꾸기 할 땐, horizontal = false로 설정하기
	}

	bool vertical = true;
	int countVertical = 0;
	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (floor[i][j] == '|')
			{
				if ((i == 0) && (j == 0))	// 만약 맨 처음부터 가로 판자가 잘 나왔다면
				{
					countVertical++;
				}
				else if (vertical == false)	// 만약 이전에 가로판자가 나왔었는데, 지금 세로판자가 나온거라면
				{
					countVertical++;
				}
				vertical = true;
			}
			else if (floor[i][j] == '-')
			{
				vertical = false;
			}
		}
		vertical = false;	// 줄 바꾸기 할 땐, vertical = false로 설정하기
	}

	cout << countHorizontal + countVertical;

	return 0;
}