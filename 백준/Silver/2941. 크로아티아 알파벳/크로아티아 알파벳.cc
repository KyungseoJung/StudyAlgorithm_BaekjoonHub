#include <iostream>

int main()
{
	std::string input;	// 입력 단어
	std::cin >> input;
	int count = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'c')
		{
			if ((input[i + 1] == '=') || (input[i + 1] == '-'))
			{
				count += 1;
				i++;

				continue;	// 해당 i번째 for문을 통과
			}
		}

		if (input[i] == 'd')
		{
			if ((input[i + 1] == 'z') && (input[i + 2] == '='))
			{
				count += 1;
				i += 2;

				continue;	// 해당 i번째 for문을 통과
			}
			else if (input[i + 1] == '-')
			{
				count += 1;
				i++;
				
				continue;	// 해당 i번째 for문을 통과
			}
		}

		if ((input[i] == 'l') && (input[i + 1] == 'j'))
		{
			count += 1;
			i++;

			continue;	// 해당 i번째 for문을 통과
		}

		if ((input[i] == 'n') && (input[i + 1] == 'j'))
		{
			count += 1;
			i++;

			continue;	// 해당 i번째 for문을 통과
		}

		if ((input[i] == 's') && (input[i + 1] == '='))
		{
			count += 1;
			i++;

			continue;	// 해당 i번째 for문을 통과
		}

		if ((input[i] == 'z') && (input[i + 1] == '='))
		{
			count += 1;
			i++;

			continue;	// 해당 i번째 for문을 통과
		}

		count += 1;
	}

	std::cout << count;
}