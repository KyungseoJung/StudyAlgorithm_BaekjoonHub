#include <iostream>

int main()
{
	int num;

	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		for(int j=0; j<(i+1); j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}