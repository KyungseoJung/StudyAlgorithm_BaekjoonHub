#include <iostream>

int main()
{
	int num = 5; // 5개의 자연수 고정
	int input[5];

	int sum = 0;

	for (int i = 0; i < num; i++)
	{
		std::cin >> input[i];
		sum += input[i];
	}

	// 평균 찾기
	int average = sum / 5;

	// 중앙값 찾기
	int output[5];
	int min;
	//int checkMin = -999;
	int rememberMemNum;
	int member = 0;	// while문에서 체크할 member 차례

	while (member < num)	// 1번째로 작은 숫자, 2번째로 작은 숫자, 3번째, 4번째, 5번째로 작은 숫자를 output 배열에 입력하는 코드
	{
		min = 9999;

		for (int i = 0; i < num; i++)
		{
			if (input[i] <= min)
			{
				//std::cout << "member: " << member << "| min 숫자: " << min << "\n";

				min = input[i];
				rememberMemNum = i;
			}
		}

		input[rememberMemNum] = 999;
		output[member] = min;
		//checkMin = min;
		member++;
	}

	std::cout << average << "\n" << output[2];

	return 0;

}
