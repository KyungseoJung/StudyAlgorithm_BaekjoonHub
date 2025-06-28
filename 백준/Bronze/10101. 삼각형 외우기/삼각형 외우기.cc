#include <iostream>

int main()
{
	int a, b, c;

	std::cin >> a >> b >> c;

	if ((a == 60) && (b == 60) && (c == 60))
		std::cout << "Equilateral";
	else if ((a + b + c) == 180)
	{
		if ((a == b) || (a == c) || (b == c))
		{
			std::cout << "Isosceles";
		}
		if ((a != b) && (b != c) && (a != c))
			std::cout << "Scalene";
	}
	else if ((a + b + c) != 180)
		std::cout << "Error";

	return 0;
}