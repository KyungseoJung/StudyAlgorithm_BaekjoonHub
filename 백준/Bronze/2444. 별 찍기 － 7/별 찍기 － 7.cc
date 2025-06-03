#include <iostream>

int main()
{
	int num;
	std::cin >> num;

	for (int i = 0; i < (2 * num - 1); i++)
	{

		if (i < num)
		{
			for (int j = 0; j < (num - i - 1); j++)
			{
				std::cout << " ";
			}
			for (int j = 0; j < (i + 1) * 2 - 1; j++)
			{
				std::cout << "*";
			}
			//for (int j = 0; j < (num - i - 1); j++)
			//{
			//	std::cout << " ";
			//}
		}
		else
		{
			for (int j = 0; j < (i - num+1); j++)
			{
				std::cout << " ";
			}
			for (int j = 4*num -3 -2*i; j > 0; j--)	// (2*num-1)을 표현하고 싶어. 예를 들어, i가 5라면, j=9여야 돼// 
			{
				std::cout << "*";
			}
			//for (int j = 0; j < (i - num)+1; j++)
			//{
			//	std::cout << " ";
			//}
		}
		std::cout << "\n";
	}

	return 0;
}