#include <iostream>

int main()
{
	std::string input;
	std::cin >> input;

	char output = '?';
	int alphabetNum[26] = { 0 };	// 각 알파벳마다 몇 개 있는지 세기 위한 array (총 크기가 0~25까지 26개)
	// 첫 번째 요소를 0으로. 그 외에는 자동으로 0으로 설정됨

	for (char c : input)
	{
		c = std::toupper(c);	// 모두 대문자로 만들어주기
		alphabetNum[c - 'A'] += 1;
	}

	int maxNum = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alphabetNum[i] > maxNum)
		{
			maxNum = alphabetNum[i];
			output = 'A' + i;
		}
		else if (alphabetNum[i] == maxNum)
		{
			output = '?';
		}
	}

	std::cout << output;
    
    return 0;
}