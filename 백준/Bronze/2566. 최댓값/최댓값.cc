#include <iostream>

int main()
{
	int input;
	int maxVal = -1;	// 가장 큰 숫자의 값
	int maxValNum = 0;	// 가장 큰 숫자의 값이 몇 번째 숫자인지

	for (int i = 0; i < 81; i++)
	{
		std::cin >> input;
		if (input > maxVal)    //0의 경우도 포함해줘야 함 (모든 값이 0일 때에도, 결국엔 어떤 좌표를 출력을 해줘야 하니까)
		{
			maxVal = input;
			maxValNum = i;
		}
	}

	std::cout << maxVal << std::endl;
	std::cout << (maxValNum / 9) + 1 << " " << (maxValNum % 9) + 1;

	return 0;

}