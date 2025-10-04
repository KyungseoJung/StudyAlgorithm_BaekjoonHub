#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>	// #sqrt 사용

using namespace std;
// 1977번 문제.

int main()
{
	int N;
	cin >> N;

	vector <vector <char>> body;
	vector <char> bodyRow(N);
	// 쿠키 신체조건 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> bodyRow[j];
		}
		body.push_back(bodyRow);
	}

	// 심장 위치부터 출력
	bool findHeart = false;
	int heartRow = 0;
	int heartCol = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (body[i][j] == '*')	// 머리 위치 찾았음
			{
				findHeart = true;
				// 심장이 위치한 행의 번호와 열의 번호 출력
				heartRow = i+1;
				heartCol = j;
				// 코드에서는 0행 0열부터 시작이지만, 실제 표현은 1행 1열부터 시작하므로
				cout << (heartRow + 1) << " " << (heartCol + 1) << "\n";
			}
		}
		if (findHeart == true)
		{
			break;
		}
	}

	// 왼쪽 팔 길이 출력
	int leftArmLen = 0;
	for (int j = 0; j < heartCol; j++)
	{
		if (body[heartRow][j] == '*')
		{
			leftArmLen++;
		}
	}

	// 오른쪽 팔 길이 출력
	int rightArmLen = 0;
	for (int j = (heartCol + 1); j < N; j++)
	{
		if (body[heartRow][j] == '*')
		{
			rightArmLen++;
		}
	}

	// 허리 길이 출력
	int waistLen = 0;
	for (int i = (heartRow + 1); i < N; i++)
	{
		if (body[i][heartCol] == '*')
		{
			waistLen++;
		}
	}
	
	// 왼쪽 다리 길이 출력
	int leftLegLen = 0;
	for (int i = (heartRow + 2); i < N; i++)
	{
		if (body[i][heartCol - 1] == '*')
		{
			leftLegLen++;
		}
	}

	// 오른쪽 다리 길이 출력
	int rightLegLen = 0;
	for (int i = (heartRow + 2); i < N; i++)
	{
		if (body[i][heartCol + 1] == '*')
		{
			rightLegLen++;
		}
	}

	cout << leftArmLen << " " << rightArmLen << " " << waistLen << " " << leftLegLen << " " << rightLegLen;

	return 0;
}
