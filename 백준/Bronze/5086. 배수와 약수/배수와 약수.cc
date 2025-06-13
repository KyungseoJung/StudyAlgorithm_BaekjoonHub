#include <iostream>

int main()
{
	int num1, num2;

	while (true)
	{
		std::cin >> num1 >> num2;
		if ((num1 == 0) && (num2 == 0))
		{
			break;
		}
		else
		{
			if (num1 % num2 == 0)
				std::cout << "multiple\n";
			else if (num2 % num1 == 0)
				std::cout << "factor\n";
			else 
				std::cout << "neither\n";
		}
	}
}