#include <iostream>

int main()
{
	/*
	순서 파악해보기
	[0][0] --(열 증가)--> [0][1] --(열 감소 & 행 증가)--> [1][0]			// 3번까지는 (행+1) 또는 (열+1) 작동 X (즉, 아래의 while문의 a가 0, 1일 때)
	--(행+1, 행 감소 & 열 증가)--> [2][0] -> [1][1] -> [0][2] --(열+1, 열 감소 & 행 증가)--> [0][3] -> [1][2] -> [2][1] -> [3][0] 
	--(행+1, 행 감소 & 열 증가)--> [4][0] -> [3][1] -> [2][2] -> [1][3] -> [0][4]
	*/

	int row = 0;
	int col = 0;	// 몇 행, 몇 열인지만 알면 분수도 편하게 구할 수 있음

	int a = 0;
	//int b = 0;

	int num =1;	// 구하고자 하는 X번째 숫자를 확인하기 위함
	int X;
	std::cin >> X;

	while (true)	// 한 번씩 차례대로 열 증가, 행 증가를 하기 위함
	{
		if (num == X)
		{
			//std::cout << "row: " << row << " | col: " << col << "\n";
			std::cout << (row + 1) << "/" << (col + 1);
			break;
		}

		if (a == 0)
		{
			col++;
			num++;
		}
		else if (a == 1)
		{
			col--;
			row++;
			num++;
		}
		else if (a % 2 == 0)	// 열 증가
		{
			//b = row + 1;
			row += 1;	// (행+1)
			num++;

			while(row>0)
			{
				if (num == X)
				{
					//std::cout << "row: " << row << " | col: " << col << "\n";
					std::cout << (row + 1) << "/" << (col + 1);
					return 0;
				}
				
				row -= 1;
				col += 1;

				num++;
			}
		}
		else if (a % 2 == 1) // 행 증가
		{
			//b = col +1;
			col += 1;	// (열+1)
			num++;


			while(col >0)
			{
				if (num == X)
				{
					//std::cout << "row: " << row << " | col: " << col << "\n";
					std::cout << (row + 1) << "/" << (col + 1);
					return 0;
				}

				col -= 1;
				row += 1;

				num++;
			}
		}
		a++;
	}



}