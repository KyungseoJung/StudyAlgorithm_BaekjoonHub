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
// 1268번 문제: 임시 반장 정하기

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 비어있는 행, 열이 있을 때 더 많이 비어있는 쪽의 숫자만큼만 경비원을 채우면 됨.
	// 어떤 직사각형 모양이든 행에서는 3개 행이, 열에서는 2개 열이 비어있다면 -> 3개 행을 채우면서 2개 열을 충분히 겹치게 채울 수 있기 때문에

	int row, col;
	cin >> row >> col;

	vector <vector <char>> castle(row, vector <char>(col));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> castle[i][j];
		}
	}

	// 비어있는 행의 개수 카운팅
	int rowEmpty = 0;
	bool empty;
	for (int i = 0; i < row; i++)
	{

		empty = true;
		for (int j = 0; j < col; j++)
		{
			if (castle[i][j] == 'X')
			{
				//cout << i << "행 " << j << "열은 채워져 있음 ==== \n";
				empty = false;	// 해당 행은 비워져 있지 않다.
				break;
			}
		}
		if(empty == true)	// 위 j에 대한 for문에서 'X'가 하나도 없다는 것이므로 해당 행은 비어있음
		{ 
			//cout << "체크1 \n";

			rowEmpty++;
		}
	}

	// 비어있는 열의 개수 카운팅
	int colEmpty = 0;
	for (int j = 0; j < col; j++)
	{
		empty = true;
		for (int i = 0; i < row; i++)
		{
			if (castle[i][j] == 'X')
			{
				empty = false;
				break;
			}
		}
		if (empty == true)
		{
			colEmpty++;
		}
	}

	int needPerson = (rowEmpty > colEmpty) ? rowEmpty : colEmpty;
	cout << needPerson;

	return 0;
}