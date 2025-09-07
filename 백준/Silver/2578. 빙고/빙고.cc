#include <iostream>
//#include <vector>

using namespace std;
int numArr[5][5];	// 확인용 숫자 배열
int boardArr[5][5] = { 0 };	// 실제 빙고판 배열 (불리지 않았으면 0, 불렸으면 1의 값을 가짐)

int checkRowBingoNums()
{
	int sum = 0;	// 빙고의 개수 세기
	bool check;
	for (int row = 0; row < 5; row++)
	{
		check = true;
		// 각 row마다 탐색
		for (int col = 0; col < 5; col++)
		{
			if (boardArr[row][col] == 0)
			{
				check = false;
				break;
			}
		}
		// 위 for문을 거쳤을 때, 하나라도 0이라면 check = false. 모두 1이라면 check = true;
		if (check == true)
		{
			sum++;
		}
	}

	return sum;	// 모든 row를 확인한 후, 빙고 개수 반환
}

int checkColBingoNums()
{
	int sum = 0;
	bool check;
	for (int col = 0; col < 5; col++)
	{
		check = true;
		for (int row = 0; row < 5; row++)
		{
			if (boardArr[row][col] == 0)
			{
				check = false;
				break;
			}
		}
		if (check == true)
		{
			sum++;
		}
	}
	return sum;
}

int checkCrossBingoNums()
{
	int sum = 0;
	bool check = true;
	// 1번째 대각선 (왼쪽 위에서 오른쪽 아래로)
	for (int i = 0; i < 5; i++)
	{
		if (boardArr[i][i] == 0)
		{
			check = false;
		}
	}
	if (check == true)
	{
		// 위 for문에서 하나라도 0인 값이 없었다는 뜻 = 대각선 빙고
		sum++;
	}

	// 2번째 대각선 (오른쪽 위에서 왼쪽 아래로)
	check = true;
	for (int i = 0; i < 5; i++)
	{
		if(boardArr[i][5-1-i] == 0)
		{
			check = false;
		}
	}
	if (check == true)
	{
		sum++;
	}


	return sum;
}


int main()
{
	/* 빙고가 나오는 경우
	1) 가로로 5개 연속 이어짐
	2) 세로로 5개 연속 이어짐
	3) 대각선으로 5개 연속 이어짐
	*/
	// 빙고판에 숫자 입력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> numArr[i][j];
		}
	}

	// 부르는 숫자 순서 저장
	int callNum[25];
	for (int i = 0; i < 25; i++)
	{
		cin >> callNum[i];
	}
	// 숫자 부르는 거 듣고, 불린 숫자는 1로 바꾸기
	int bingoNum;
	for (int i = 0; i < sizeof(callNum); i++)
	{
		bingoNum = 0;
		// 보드에서 해당하는 숫자의 위치 값을 1로 바꾸기
		for (int a = 0; a < 5; a++)
		{
			for (int b = 0; b < 5; b++)
			{
				if (numArr[a][b] == callNum[i])
				{
					boardArr[a][b] = 1;
					break;
				}
			}
		}
		//cout << i << "번째의 sum: " << checkRowBingoNums() << " | " << checkColBingoNums() << " | " << checkCrossBingoNums() << "\n";
		bingoNum = checkRowBingoNums() + checkColBingoNums() + checkCrossBingoNums();
		if (bingoNum >= 3)
		{
			cout << i+1;	// 0번째부터로 코드를 구성했기 때문에, 실제로는 +1 해서 출력하기
			return 0;
		}
	}
}