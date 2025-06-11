#include <iostream>

int main()
{
	std::string wordArr[5][15];	// 5행 15열의 배열
	
	std::string word[5];

	// 확인 목적 코드
	//word[1] = "abc";
	//std::cout << "word[1] is " << word[1] << "\n";
	//std::cout << "word[2] is " << word[2] << "\n";
	//if (word[2] == "")
	//	std::cout << "word[2] is null";

	for (int i = 0; i < 5; i++)
	{
		std::cin >> word[i];	// 5개의 글자 입력
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < word[i].length(); j++)
		{
			wordArr[i][j] = word[i][j];	// wordArr 배열에 각 단어들을 한 개씩 넣는 작업
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << wordArr[j][i];
		}
	}
	return 0;
}