#include <iostream>

int main()
{
	int X, N;	// 구매한 총 금액과, 총 물건 종류 수

	std::cin >> X >> N;

	int a, b;
	int sum = 0;

	for (int i = 0; i < N; i++)
	{

		std::cin >> a >> b;
		sum += a * b;
	}

	if (sum == X)
		std::cout << "Yes";
	else
		std::cout << "No";
}