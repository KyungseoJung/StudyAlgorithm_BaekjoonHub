#include <iostream>
#include <string>

using namespace std;
//# 4378번 문제: 트ㅏㅊ;
int main()
{
	// \을 입력받기 위해서는 \\라고 작성해야 하는 듯
	string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

	string input;

	bool find;
	while (getline(cin, input))
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == ' ')
			{
				cout << ' ';
			}
			else if (input[i] != ' ')
			{
				//find = false;

				// 키보드 중 어떤 문자인지 확인 (왼쪽끝의 문자는 나오지 않는다고 했으므로 안심하기~)
				for (int j = 0; j < keyboard.length(); j++)
				{
					if (input[i] == keyboard[j])
					{
						cout << keyboard[j - 1];
						//find = true;
						break;	// for문 통과
					}
				}
				/*if (find == true)
				{
					continue;
				}*/
			}
		}

		cout << "\n";
	}
	
}