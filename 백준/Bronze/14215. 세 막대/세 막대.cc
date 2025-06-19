#include <iostream>

int main()
{
	// 삼각형 특징: 가장 작은 두 변의 길이의 합이 가장 긴 변의 길이보다 길어야 함
	int num1, num2, num3;

	std::cin >> num1 >> num2 >> num3;

	int max = 0;	// 가장 큰 수
	int sum = 0;	// 가장 작은 두 수의 합
	if ((num1 >= num2) && (num1>=num3))
	{
		max = num1;
		sum = num2 + num3;
	}
	else if ((num2>= num3) && (num2 >= num1))
	{
		max = num2;
		sum = num1 + num3;
	}
	else if ((num3 >= num1) && (num3 >= num2))
	{
		max = num3;
		sum = num1 + num2;
	}
	



	if ((num1 == num2) && (num1 == num3) && (num2 == num3))	// (조건 추가) 정삼각형의 경우
		std::cout << num1 * 3;
	else if (max >= sum)		// 경우1: 가장 작은 두 수의 합보다 가장 큰 수가 더 크거나 같다면, 삼각형의 최대 둘레는 가장 작은 두 수의 합 + (가장 작은 두 수의 합 -1)	// 가장 긴 길이의 변은 (가장 작은 두 수의 합)보다 무조건 작아야 하니까
		std::cout << (sum + sum - 1);
	else if (max < sum)			// 경우2: 가장 작은 두 수의 합보다 가장 큰 수가 더 작다면, 그냥 3개 숫자의 합이 삼각형의 최대 둘레
		std::cout << (sum + max);

	return 0;
}