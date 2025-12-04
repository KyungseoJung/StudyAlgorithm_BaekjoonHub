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
// 2669번 문제: 직사각형 네개의 합집합의 면적 구하기

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> arr(100, vector <int>(100, 0));	// 100행 100열	-> 총 100x100개의 칸에 직사각형이 올려져 있는지 아닌지 검사하는 것.
		// 각 요소들을 모두 0으로 초기화해주기
	int smallestX = 101;	// 탐색하는 범위를 줄이기 위해서 저장하는 변수들
	int smallestY = 101;
	int biggestX = 0;
	int biggestY = 0;	

	int N = 4;	// 총 4개 직사각형 입력한대
	int leftX, leftY, rightX, rightY;
	// **헷갈리니까 메모: 만약 (0,0)부터 (1,1)을 차지하는 직사각형이 올라간다면 -> 그 직사각형은 arr[0][0]만 1로 만듦.

	while (N--)
	{
		cin >> leftX >> leftY >> rightX >> rightY;

		for (int x = leftX; x < rightX; x++)
		{
			for (int y = leftY; y < rightY; y++)
			{
				if (arr[x][y] != 1)	// 직사각형이 올려져 있지 않았다면 1로 만들어주기
				{
					//cout << x << "행, " << y << "열 - 배열 1로 만들기 \n";
					arr[x][y] = 1;
				}
			}
		}
		// 가장 작은/ 큰 지점 업데이트
		if (leftX < smallestX)
		{
			smallestX = leftX;
		}
		if (leftY < smallestY)
		{
			smallestY = leftY;
		}
		if (rightX > biggestX)
		{
			biggestX = rightX;
		}
		if (rightY > biggestY)
		{
			biggestY = rightY;
		}
	}

	// 최종적으로 직사각형이 올라간 면적들 확인
	int sum = 0;
	for (int x = smallestX; x < biggestX; x++)
	{
		for (int y = smallestY; y < biggestY; y++)
		{
			if (arr[x][y] == 1)
			{
				sum++;
			}
		}
	}

	cout << sum;
	
	return 0;
}