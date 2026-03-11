#include <iostream>
#include <vector>

using namespace std;
int main()
{
	//cout << (int)'1' << " " << (int)'9';
	// '1' = 49, '9' = 57
	//cout << (int)'.' << "\n";
	//cout << '3' - '0';

	int N;
	cin >> N;
	vector <vector<char>> bombMap(N, vector<char>(N));	// N행 N열의 지뢰 map
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> bombMap[i][j];
		}
	}

	// 지뢰 찾기 map 만들기
	vector <vector <char>> bombFindMap(N, vector<char>(N));	
	int countBomb = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (((int)bombMap[i][j] >= 49) && ((int)bombMap[i][j] <= 57))
			{
				//cout << i << "행 " << j << "열은 지뢰\n";
				bombFindMap[i][j] = '*';
			}
			else
			{
				// 주변에 있는 지뢰 카운팅
				//cout << "주변에 있는 지뢰 카운팅\n";
				countBomb = 0;
				for (int row = i - 1; row <= (i + 1); row++)
				{
					for (int col = j - 1; col <= (j + 1); col++)
					{
						if ((row < 0) || (row >= N) || (col < 0) || (col >= N))	// 범위를 초과하면 PASS
						{
							continue;
						}
						else if ((row == i) && (col == j))	// i행 j열이면 PASS
						{
							continue;
						}
						else if (bombMap[row][col] != '.')
						{
							countBomb += (bombMap[row][col] - '0');	// 글자를 숫자로 변환
						}
					}
				}

				// 주변에 있는 지뢰의 개수에 따라 지뢰 찾기 Map에 올바른 글자를 적기
				if (countBomb >= 10)	
				{
					bombFindMap[i][j] = 'M';
					//cout << i << "행 " << j << "열은 M\n";

				}
				else
				{
					bombFindMap[i][j] = countBomb + '0';
					// int to char: 3 + '0' => '3'
					// char to int: '3' - '0' => 3

					//cout << i << "행 " << j << "열은 주변에 지뢰가 " << countBomb << "개\n";

				}
			}
		}
	}



	// 지뢰 찾기 Map 출력하기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << bombFindMap[i][j];
		}
		cout << "\n";
	}
}