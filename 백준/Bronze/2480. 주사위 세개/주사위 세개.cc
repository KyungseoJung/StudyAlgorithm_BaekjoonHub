#include <iostream>

int main()
{
	int num1, num2, num3;

	std::cin >> num1 >> num2 >> num3;

	int same, biggest, price;

	// 3개 숫자가 모두 다를 때
	if ((num1 != num2) && (num1 != num3) && (num2 != num3))
	{
		if (num1 > num2)
			biggest = num1;
		else
			biggest = num2;
		
		if (biggest < num3)
			biggest = num3;

		price = biggest * 100;
	}

	// 같은 눈 3개 나올 때
	if ((num1 == num2) && (num1 == num3))
	{
		price = 10000 + num1 * 1000;
	}

	// 같은 눈 2개 나올 때
	if ((num1 == num2) && (num1 != num3))
	{
		price = 1000 + num1 * 100;
	}
	else if ((num1 == num3) && (num1 != num2))
	{
		price = 1000 + num1 * 100;

	}
	else if ((num2 == num3) && (num1 != num2))
	{
		price = 1000 + num2 * 100;

	}
	
	std::cout << price << std::endl;
	return 0;
}