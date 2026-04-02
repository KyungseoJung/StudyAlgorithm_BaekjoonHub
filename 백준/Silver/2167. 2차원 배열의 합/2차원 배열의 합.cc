#include <iostream>
#include <vector>

using namespace std;
// 2167번 문제: 2차원 배열의 합
int main()
{
	// 기준이 되는 2차원 배열 입력
	int N, M;
	cin >> N >> M;

	vector <vector <int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	// 합 구하는 연산 시작
	int K;
	cin >> K;
	int i, j, x, y;
	int sum = 0;
	while (K--)
	{
		sum = 0;
		cin >> i >> j >> x >> y;

		for (int row = i - 1; row <= x - 1; row++)
		{
			for (int col = j - 1; col <= y - 1; col++)
			{
				sum += arr[row][col];
			}
		}

		cout << sum << "\n";
	}

	return 0;
}