#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	// 각 숫자가 <몇 행, 몇 열>인지만 알면 됨
	int row1, col1, row2, col2;

	// 행 계산하기
	if (num1 % 4 == 0)
	{
		row1 = 3;
	}
	else
	{
		row1 = (num1 % 4) - 1;
	}

	if (num2 % 4 == 0)
	{
		row2 = 3;
	}
	else
	{
		row2 = (num2 % 4) - 1;
	}

	// 열 계산하기
	if (num1 % 4 == 0)
	{
		col1 = num1 / 4 - 1;
	}
	else
	{
		col1 = num1 / 4;
	}
	if (num2 % 4 == 0)
	{
		col2 = num2 / 4 - 1;
	}
	else
	{
		col2 = num2 / 4;
	}
	//cout << col1 << " " << col2 << "\n";


	int rowDiff = (row1 - row2 > 0)? (row1-row2) : (row2-row1) ;
	int colDiff = (col1 - col2 > 0)? (col1-col2) : (col2-col1) ;

	int distance = rowDiff + colDiff;

	cout << distance; 

	return 0;
}