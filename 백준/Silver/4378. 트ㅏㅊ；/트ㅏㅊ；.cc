#include <iostream>
#include <string>

using namespace std;
//# 4378번 문제: 트ㅏㅊ;
int main()
{
	string line1 = "`1234567890-=";
	string line2 = "QWERTYUIOP[]\\";	// \을 입력받기 위해서는 \\라고 작성해야 하는 듯
	string line3 = "ASDFGHJKL;'";
	string line4 = "ZXCVBNM,./";

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
				find = false;

				// 1번째 라인의 문자인지 확인
				for (int j = 0; j < line1.length(); j++)
				{
					if (input[i] == line1[j])
					{
						cout << line1[j - 1];
						find = true;
						break;
					}
				}
				if (find == true)
				{
					continue;
				}

				// 2번째 라인의 문자인지 확인
				for (int j = 0; j < line2.length(); j++)
				{
					if (input[i] == line2[j])
					{
						cout << line2[j - 1];
						find = true;
						break;
					}
				}
				if (find == true)
				{
					continue;
				}

				// 3번째 라인의 문자인지 확인
				for (int j = 0; j < line3.length(); j++)
				{
					if (input[i] == line3[j])
					{
						cout << line3[j - 1];
						find = true;
						break;
					}
				}
				if (find == true)
				{
					continue;
				}

				// 4번째 라인의 문자인지 확인
				for (int j = 0; j < line4.length(); j++)
				{
					if (input[i] == line4[j])
					{
						cout << line4[j - 1];
						find = true;
						break;
					}
				}
				if (find == true)
				{
					continue;
				}
			}
		}

		cout << "\n";
	}
	
}