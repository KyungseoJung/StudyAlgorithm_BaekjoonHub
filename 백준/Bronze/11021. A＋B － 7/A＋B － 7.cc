#include <iostream>


int main()
{
	int T;
	std::cin >> T;

	int num1, num2;
	for (int i = 0; i < T; i++)
	{
		std::cin >> num1 >> num2;

		std::cout << "Case #" << (i+1) << ": " << (num1 + num2) << "\n";
	}


	return 0;
}