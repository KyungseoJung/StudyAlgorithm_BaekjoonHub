#include <iostream>

int main()
{
	int testNum;
	std::cin >> testNum;

	int repeatNum[1000];
	std::string inputString[1000];

	// 입력 단계
	for (int i = 0; i < testNum; i++)
	{
		std::cin >> repeatNum[i] >> inputString[i];
	}

	// 출력 단계
	for (int i = 0; i < testNum; i++)
	{
		for (int j = 0; j < inputString[i].length(); j++)
		{
			for (int k = 0; k < repeatNum[i]; k++)
			{
				std::cout << inputString[i][j];
			}
		}

		std::cout << "\n";
	}
	return 0;
}


	//std::cout << S[num - 1];
	//std::cout << S.at(num-1);
	//https://m.blog.naver.com/dorergiverny/223046924132
