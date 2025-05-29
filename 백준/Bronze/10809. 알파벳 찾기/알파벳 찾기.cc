#include <iostream>

int main()
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";	// 비교하기 위한 용도의 string (각 원소들에 접근할 예정)
	int alphabetNum[26];	// 답안 제출용 arr
	for (int i = 0; i < 26; i++)
	{
		alphabetNum[i] = -1;	// 일단 모든 요소들을 -1로 저장
	}
	std::string inputString;
	std::cin >> inputString;
	
	int inputSize = inputString.length();

	//std::cout << inputSize;

	for (int i = inputSize-1; i >=0; i--)	// 입력한 문장의 알파벳 하나씩 확인
	{
		for (int j = 0; j < alphabet.length(); j++)
		{
			if (inputString[i] == alphabet[j])
			{
				alphabetNum[j] = i;

				break;
			}
		}
	}

	for (int i = 0; i < alphabet.length(); i++)
	{
		std::cout << alphabetNum[i] << " ";
	}

	return 0;
}


	//std::cout << S[num - 1];
	//std::cout << S.at(num-1);
	//https://m.blog.naver.com/dorergiverny/223046924132
