#include <iostream>
#include <string>

using namespace std;
// 2145번 문제: 숫자 놀이
int main()
{
	string input;
	int sum;
	while (true)
	{
		cin >> input;
		if (stoi(input)== 0)
		{
			break;	// while문 통과 
		}

		while (true)
		{
			if (stoi(input) / 10 == 0)
			{
				cout << input << "\n";	// 최종적으로 얻은 한 자리 숫자
				break;	// 10으로 나눴을 때 목이 0이라면 (즉, 한 자리 숫자라면) while문 통과
			}
			
			// 각 자릿수를 모두 더해서 새로 업데이트하기
			sum = 0;
			for (int i = 0; i < input.length(); i++)
			{
				sum += (input[i] - '0');
			}
			input = to_string(sum);

		}
	}

	return 0;
}