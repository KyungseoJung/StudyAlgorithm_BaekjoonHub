#include <iostream>

using namespace std;
// 2490번 문제: 윷놀이
int main()
{
	int N = 3;	// 3줄 입력 고정
	int num = 4;
	int count = 0;

	int input;
	for (int i = 0; i < N; i++)
	{
		count = 0;
		for (int j = 0; j < num; j++)
		{
			cin >> input;
			if (input == 0)
			{
				count++;
			}
		}
		switch (count)
		{
		case 0:
			cout << "E\n";
			break;
		case 1:
			cout << "A\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "C\n";
			break;
		case 4:
			cout << "D\n";
			break;
		}
	}
	return 0;
}