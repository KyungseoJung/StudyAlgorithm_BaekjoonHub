#include <iostream>

int main()
{
	std::string input;

	std::cin >> input;

	int num = (input.length() / 2);	// 몫
	for (int i = 0; i < num; i++)
	{
		if (input[i] != input[input.length() - i-1])
		{
			std::cout << "0";
			return 0;
		}
	}
	std::cout << "1";
	return 0;

}