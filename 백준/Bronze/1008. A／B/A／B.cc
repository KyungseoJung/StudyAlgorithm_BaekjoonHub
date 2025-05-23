#include <iostream>

int main()
{
	double a, b;
	std::cin >> a >> b;
	double answer = a / b;
	//std::cout << answer << std::endl;
	std::cout.precision(10);
	std::cout << answer;
	
	return 0;
}