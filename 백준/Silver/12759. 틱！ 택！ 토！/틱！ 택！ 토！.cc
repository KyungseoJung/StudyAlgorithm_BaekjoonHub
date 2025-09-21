#include <iostream>
#include <vector>

using namespace std;
#define ARR_NUM 3

int arr[ARR_NUM][ARR_NUM] = { 0 };	// 모든 원소를 0으로 초기화
bool checkBingo(int playerNum)
{
	int bingoNum = 0;

	// 가로줄 검사
	for (int i = 0; i < ARR_NUM; i++)
	{
		if ((arr[i][0] == playerNum) && (arr[i][1] == playerNum) && (arr[i][2] == playerNum))
		{
			return true;
			//bingoNum++;
		}
	}
	// 세로줄 검사
	for (int i = 0; i < ARR_NUM; i++)
	{
		if ((arr[0][i] == playerNum) && (arr[1][i] == playerNum) && (arr[2][i] == playerNum))
		{
			return true;
			//bingoNum++;
		}
	}

	// 대각선 검사 (1) (좌측상단에서 우측하단)
	bool crossBingo = true;
	for (int i = 0; i < ARR_NUM; i++)
	{
		if (arr[i][i] != playerNum)
		{
			crossBingo = false;
			break;
		}
		// 하나라도 다르다면 false가 되고, 모두 다 playerNum이면 true가 출력됨
	}
	if (crossBingo == true)
	{
		return true;
		//bingoNum++;
	}

	// 대각선 검사 (2) (우측상단에서 좌측하단)
	crossBingo = true;
	for (int i = 0; i < ARR_NUM; i++)
	{
		if (arr[2 - i][i] != playerNum)
		{
			crossBingo = false;
			break;
		}
	}
	if (crossBingo == true)
	{
		return true;
		//bingoNum++;
	}

	//return bingoNum;
	return false;
}

int main()
{
	int firstPlayer;
	int secondPlayer;

	cin >> firstPlayer;
	secondPlayer = (firstPlayer == 1) ? 2 : 1;

	int currPlayer = firstPlayer;
	int row, col;
	int num = 1;
	
	while (cin >> row >> col)
	{
		arr[row - 1][col - 1] = currPlayer;

		if (checkBingo(currPlayer)  == true)	// 방금 O 또는 X를 그린 사람에 대해서만 검사
		{
			cout << currPlayer;
			return 0;
		}

		currPlayer = (currPlayer == 1) ? 2 : 1;	// 이제 다음 for문에는 currPlayer가 바뀌도록
		if (num < 9)
		{
			num++;
		}
		else if (num >= 9)	// 9칸이 모두 채워졌는데 빙고가 안 나옴. 즉, 무승부
		{
			cout << "0";
			return 0;
		}
	}
}