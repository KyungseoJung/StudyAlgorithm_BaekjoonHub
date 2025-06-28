#include <iostream>

int main()
{
	int N, M;	// 보드의 각 길이 (N개 행, M개 열)

	std::cin >> N >> M;

	std::string square[50];	// 첫 사각형 데이터
	for (int i = 0; i < N; i++)
	{
		std::cin >> square[i];
	}

	int num = 0;	// 다시 칠해야 하는 정사각형의 개수
	int min = 99999;	// 최소 개수 기록

	for (int i = 0; i < N - 7; i++)	// 각 체스판에서 자를 수 있는 사각형의 모든 경우의 수를 for문으로 확인
	{
		for (int j = 0; j < M - 7; j++)
		{
			num = 0;	// num 초기화
			// 고려1: 맨 왼쪽 위 칸이 흰색인 체스판을 만들고자 할 때, 다시 칠해야 하는 정사각형의 개수
			for (int k = 0; k < 8; k++)	// 잘라낸 사각형에서 계산
			{
				for (int l = 0; l < 8; l++)
				{
					// 고려1: 맨 왼쪽 위 칸이 흰색인 체스판을 만들고자 할 때, 다시 칠해야 하는 정사각형의 개수
					if (k % 2 == 0)	// 0번째 줄, 2번째 줄, 4번째 줄, 6번째 행
					{
						if (l % 2 == 0)	// 0, 2, 4, 6 번째 열
						{
							if (square[k + i][l + j] == 'B')
							{
								num++;
							}
						}
						else
						{
							if (square[k + i][l + j] == 'W')
							{
								num++;
							}
						}
					}
					else
					{
						if (l % 2 == 0)	// 1, 3, 5, 7 번째 열
						{
							if (square[k + i][l + j] == 'W')
							{
								num++;
							}
						}
						else
						{
							if (square[k + i][l + j] == 'B')
							{
								num++;
							}
						}
					}
				}

			}

			if (num < min)
				min = num;


			// ---------------------------

			num = 0;	// num 초기화
			// 고려2: 맨 왼쪽 위 칸이 검은색인 체스판을 만들고자 할 때, 다시 칠해야 하는 정사각형의 개수
			for (int k = 0; k < 8; k++)	// 잘라낸 사각형에서 계산	
			{
				for (int l = 0; l < 8; l++)
				{
					// 고려2: 맨 왼쪽 위 칸이 검은색인 체스판을 만들고자 할 때, 다시 칠해야 하는 정사각형의 개수
					if (k % 2 == 0)	// 0번째 줄, 2번째 줄, 4번째 줄, 6번째 행
					{
						if (l % 2 == 0)	// 0, 2, 4, 6 번째 열
						{
							if (square[k + i][l + j] == 'W')
							{
								num++;
							}
						}
						else
						{
							if (square[k + i][l + j] == 'B')
							{
								num++;
							}
						}
					}
					else // 1번째, 3번째, 5번째, 7번째 행
					{
						if (l % 2 == 0)	// 1, 3, 5, 7 번째 열
						{
							if (square[k + i][l + j] == 'B')
							{
								num++;
							}
						}
						else
						{
							if (square[k + i][l + j] == 'W')
							{
								num++;
							}
						}
					}
				}

			}

			if (num < min)
				min = num;
		}
	}

	std::cout << min;

	return 0;
}