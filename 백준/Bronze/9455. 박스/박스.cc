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
// 9455번 문제: 박스

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	int row, col;
	vector <vector <int>> boxes;
	vector <int> height;
	// ===========================
	while (T--)
	{
		cin >> row >> col;

		//boxes.resize(row, vector <int>(col));
		/*height.clear();
		height.resize(col);*/
		// ******위처럼 boxes를 resize를 하면, 행 개수만 조절한대. resize 함수 자체가 원래 그런가봐
		boxes.assign(row, vector<int>(col, 0));		// 모든 행을 새로운 col 크기로 완전히 재생성
		height.assign(col, 0);

		// 각 col마다 일단 몇 층의 탑이 쌓이는지 확인하고
		// 1층보다 높은 박스들에 대해 (현재 몇층인지-1 - 밑에 몇 개의 박스가 있는지) 체크하기
		for (int i=0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> boxes[i][j];
				if(boxes[i][j] == 1)
				{
					height[j]++;
				}
			}
		}

		//cout << "각 col마다 몇 개 탑인지 출력\n";
		//for (int j = 0; j < col; j++)
		//{
		//	cout << height[j] << " ";
		//}

		// (가장 바닥 층수(:총 row 수 -1) - 현재 몇층인지 - 아래에 몇 개 박스 있는지)
		int bottomBoxNum;	// 각 col마다 현재 밑에 남은 박스 개수 세기
		int count = 0;
		for (int j = 0; j < col; j++)
		{
			bottomBoxNum = height[j]-1;	// 일단 먼저 각 col(세로줄)마다 몇 개 박스탑이 있는지 확인
			for (int i = 0; i < row; i++)
			{
				// 해당 row에 박스가 있다면, 
				if (boxes[i][j] == 1)	
				{
					count += ((row - 1) - i - bottomBoxNum);
					bottomBoxNum -= 1;	// 지금 한 박스에 대해 카운팅 한 것이므로, 그 아래 row들의 계산을 위해서 bottomBoxNum -1 해주기
				}
			}
		}

		cout << count << "\n";

	}

	return 0;
}