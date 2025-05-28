#include <iostream>

int main()
{
	int num;
	std::cin >> num;

	for (int i = 0; i < num; i++)	// 각 줄마다 실행
	{
		for (int j = 0; j < (num-i-1); j++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < (i+1); j++)
		{
			std::cout << "*";
		}

		std::cout << "\n";
	}

}