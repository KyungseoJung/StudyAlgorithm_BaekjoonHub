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
// 1730번 문제: 판화 

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	//cout << (int)'.' << " | " << (int)'|' << " | " << (int)'-' << " | " << (int)'+';
	int N;
	cin >> N;
	vector <vector <char>> arr(N, vector <char>(N));
	arr.assign(N, vector<char>(N, '.'));

	string input;
	cin >> input;
	int row = 0;	// 첫 시작은 [0,0]에서 시작하기
	int col = 0;	

	//#1 예제를 잘 살펴보니까, arr의 범위를 넘어가는 것도 따로 처리를 해줘야 하는 것 같음...

	for (int i = 0; i < input.length(); i++)
	{
		switch (input[i])
		{
		case 'U':

			//#1 row-1이 0이상일 때에만 row--해주고, 다음 것도 미리 선 그려주기
			//#1 그냥 범위가 벗어나면 명령 자체를 무시해줘야 할 듯!!!!!!!!
			if (row - 1 >= 0)
			{
				if (arr[row][col] == '.')
				{
					arr[row][col] = '|';
				}
				else if (arr[row][col] == '-')
				{
					arr[row][col] = '+';
				}

				row--;

				// 그 다음 것도 미리 선이 그어짐
				if (arr[row][col] == '.')
				{
					arr[row][col] = '|';
				}
				else if (arr[row][col] == '-')
				{
					arr[row][col] = '+';
				}
			}
			break;

		case 'D':
			//#1 row+1이 N-1이하일 때에만 row++해주고, 다음 것도 미리 선 그려주기
			//#1 그냥 범위가 벗어나면 명령 자체를 무시해줘야 할 듯!!!!!!!!
			if (row + 1 < N)
			{
				if (arr[row][col] == '.')
				{
					arr[row][col] = '|';
				}
				else if (arr[row][col] == '-')
				{
					arr[row][col] = '+';
				}

				row++;

				// 그 다음 것도 미리 선이 그어짐
				if (arr[row][col] == '.')
				{
					arr[row][col] = '|';
				}
				else if (arr[row][col] == '-')
				{
					arr[row][col] = '+';
				}
			}

			break;

		case 'R':
			//#1 col+1이 N-1이하일 때에만 col++해주고, 다음 것도 미리 선 그려주기
			//#1 그냥 범위가 벗어나면 명령 자체를 무시해줘야 할 듯!!!!!!!!
			if (col + 1 < N)
			{
				if (arr[row][col] == '.')
				{
					arr[row][col] = '-';
				}
				else if (arr[row][col] == '|')
				{
					arr[row][col] = '+';
				}
				
				col++;

				// 그 다음 것도 미리 선이 그어짐
				if (arr[row][col] == '.')
				{
					arr[row][col] = '-';
				}
				else if (arr[row][col] == '|')
				{
					arr[row][col] = '+';
				}
			}

			break;

		case 'L':
			//#1 col-1이 N-s1이하일 때에만 col++해주고, 다음 것도 미리 선 그려주기
			//#1 그냥 범위가 벗어나면 명령 자체를 무시해줘야 할 듯!!!!!!!!
			if (col - 1 >= 0)
			{
				if (arr[row][col] == '.')
				{
					arr[row][col] = '-';
				}
				else if (arr[row][col] == '|')
				{
					arr[row][col] = '+';
				}
				
				col--;

				// 그 다음 것도 미리 선이 그어짐
				if (arr[row][col] == '.')
				{
					arr[row][col] = '-';
				}
				else if (arr[row][col] == '|')
				{
					arr[row][col] = '+';
				}

			}

			break;

		}
	}
	

	// 최종 arr 모습 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}