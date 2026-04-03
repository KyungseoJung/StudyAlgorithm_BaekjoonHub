#include <iostream>
#include <vector>

using namespace std;
// 2740번 문제: 행렬 곱셈
int main()
{
	int N, M;
	cin >> N >> M;
	vector <vector <int>> arrA(N, vector <int>(M));

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			cin >> arrA[row][col];
		}
	}

	//int M;	// 이미 정의함
	int K;
	cin >> M >> K;
	vector <vector <int>> arrB(M, vector <int>(K));
	for (int row = 0; row < M; row++)
	{
		for (int col = 0; col < K; col++)
		{
			cin >> arrB[row][col];
		}
	}

	// 행렬A와 행렬B의 곱 계산하기
	int sum;
	vector <vector <int>> arrC(N, vector <int>(K));	// 행렬A와 행렬B의 곱으로 얻어지는 행렬C
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < K; col++)
		{
			sum = 0;
			// 만약 0행 0열의 값을 구한다면, [행렬A의 0행의 값]들과 [행렬B의 0열의 값]들을 곱한 값의 합
			// 단순히 이중 for문으로 모두 곱하면 안되고, 짝끼리만 곱해야 함
			// arrA의 열번호와 arrB의 행번호가 동일할 때만 곱해야 함
			for (int c = 0; c < M; c++)
			{
				for (int r = 0; r < M; r++)
				{
					if (c == r)
					{
						sum += (arrA[row][c] * arrB[r][col]);
						//cout << row << "행 " << col << "열 계산: " << (arrA[row][c] * arrB[r][col]) << "더하기 => " << sum << "\n";

					}
				}
			}


			arrC[row][col] = sum;
		}
	}

	// 행렬C 출력하기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << arrC[i][j];
			
			if (j < K - 1)
			{
				cout << " ";
			}
			else if ((j == K-1) && (i < N-1))	// 마지막 행은 개행할 필요가 없으니까
			{
				cout << "\n";
			}
		}
	}

	return 0;
}