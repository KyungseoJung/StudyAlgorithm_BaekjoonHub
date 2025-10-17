#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 1531번 문제.

int main()
{

	// 그림의 크기는 100x100 (10,000)
	int arr[101][101] = { 0 };	// 100행 100열 (초기값은 0)
	// 각 좌표는 100이하의 수래. 즉, 1부터 100이라는 거니까, 배열의 크기를 101로 설정해주자
	// **주의!!: 마지막 count 계산하는 for문에서도 1부터 100까지 검사하기!!
    int N, M;
	cin >> N >> M;

	int startX, startY, endX, endY;

	for (int i = 0; i < N; i++)
	{
		cin >> startX >> startY >> endX >> endY;
		// 시작점부터 끝점까지 종이 1장씩 추가해주기
		// (startX, startY)좌표부터 (endX, endY)좌표까지 종이 1장씩 추가해주기
		for (int i = startX; i <= endX; i++)	// 문제에서 꼭짓점도 포함한다고 했음
		{
			for (int j = startY; j <= endY; j++)
			{
				arr[i][j] += 1;
			}
		}
	}

	// M장 이상 올려져있는 좌표를 확인 (1부터 100까지 검사)
	int count = 0;
	for (int i = 1; i < 101; i++)
	{
		for (int j = 1; j < 101; j++)
		{
			if (arr[i][j] > M)	// M개보다 커야함 (M개 이상 아님)
			{
				count++;
			}
		}
	}

	cout << count;
	return 0;
}