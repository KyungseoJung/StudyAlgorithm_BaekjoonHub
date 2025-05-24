#include <iostream>

int main()
{
	int A, B;	// 세자리 자연수
	int b1, b2, b3;
	int num1, num2, num3, answer;

	std::cin >> A >> B;

	b1 = B / 100;
	b2 = (B - b1 * 100)/10;
	b3 = (B - b1 * 100) % 10;

	//std::cout << b1 << " " << b2 << " " << b3 << std::endl;

	num1 = A * b3;
	num2 = A * b2;
	num3 = A * b1;
	answer = A * B;

	std::cout << num1 << "\n" << num2 << "\n" << num3 << "\n" << answer;

	return 0;
}