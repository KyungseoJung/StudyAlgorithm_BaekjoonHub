#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#10448번 문제
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;	// 테스트케이스의 개수
	cin >> T;

	int inputNum;
	int sum;
	bool eureka;
	while (T--)
	{
		cin >> inputNum;
		sum = 0;
		eureka = false;

		// 소수 걱정 할 필요 X: i 또는 (i+1) 둘 중 하나는 짝수이므로, i*(i+1)/2은 무조건 정수가 될 것임.
		for (int i = 1; i * (i + 1) / 2 <= inputNum; i++)
		{
			if (eureka == true)
			{
				break;
			}

			for (int j = 1; j * (j + 1) / 2 <= inputNum; j++)
			{
				if (eureka == true)
				{
					break;
				}

				for (int k = 1; k * (k + 1) / 2 <= inputNum; k++)
				{
					sum = i * (i + 1) / 2 + j * (j + 1) / 2 + k * (k + 1) / 2;
					if (sum == inputNum)
					{
						cout << 1 << "\n";
						eureka = true;
						break;;
					}
				}
			}
		}

		// 만약 위 for문에서도 하나도 inputNum에 해당하는 숫자가 없었다면, 여기까지 왔을 것임.
		if (eureka == false)
		{
			cout << 0 << "\n";
		}

	}

	return 0;
}
