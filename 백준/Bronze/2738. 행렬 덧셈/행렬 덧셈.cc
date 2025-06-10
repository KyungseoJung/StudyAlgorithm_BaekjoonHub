#include <iostream>

int main()
{
	int arr1[100][100];
	int arr2[100][100];
	int outputArr[100][100];

	int N, M;	// N행 M열의 행렬
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> arr1[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> arr2[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			outputArr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << outputArr[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}