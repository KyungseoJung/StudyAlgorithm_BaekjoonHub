#include <iostream>

int main()
{
	int num;
	std::cin >> num;

	std::string input[10];
	std::string string;

	for (int i = 0; i < num; i++)
	{
		std::cin >> input[i];
	}

	for (int i = 0; i < num; i++)
	{
		std::cout << input[i][0];
		std::cout << input[i][input[i].length()-1] << "\n";
	}

	return 0;
}


	//std::cout << S[num - 1];
	//std::cout << S.at(num-1);
	//https://m.blog.naver.com/dorergiverny/223046924132
