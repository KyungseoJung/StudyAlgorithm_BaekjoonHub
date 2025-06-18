#include <iostream>

int main()
{
	int num1, num2, num3;


	while (true)
	{
		std::cin >> num1 >> num2 >> num3;

		if ((num1 == 0) && (num2 == 0) && (num3 == 0))
			break;

		// 삼각형 조건 자체가 안 되는 경우
		// 가장 긴 변의 길이를 따로 설정할 필요 없이 아래 3가지 경우 중 하나라도 해당되면, 삼각형이 안 됨
		if (((num1 + num2) <= num3) || ((num1 + num3) <= num2) || ((num2 + num3) <= num1))
			std::cout << "Invalid" << std::endl;

		else if ((num1 == num2) && (num1 == num3) && (num2 == num3))
			std::cout << "Equilateral" << std::endl;
		else if ((num1 == num2) || (num1 == num3) || (num2 == num3))
			std::cout << "Isosceles" << std::endl;
		else if ((num1 != num2) && (num1 != num3) && (num2 != num3))
			std::cout << "Scalene" << std::endl;
	}

	return 0;
}