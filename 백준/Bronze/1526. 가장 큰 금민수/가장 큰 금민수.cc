#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 1526번 문제.

int main()
{
	int N;
	cin >> N;
	string st;
	int len;

	bool only4and7;
	for (int i = N; i >= 4; i--)	// N이하의 수를 차례대로 확인
	{
		//cout << "숫자: " << i << "체크: ";
		st = to_string(i);

		// 해당 숫자의 한 자릿수마다 확인하기
		len = st.length();
		only4and7 = true;	// 모든 자릿수가 4와 7로만 이루어져있는지 확인하기 위함
		for (int j = 0; j < len; j++)
		{
			if ((st[j] != '4') && (st[j] != '7'))
			{
				// 4도 아니고 7도 아니면, 
				// 아예 넘어가기.
				only4and7 = false;
				//cout << "--금민수 아님 --\n";
				break;
			}
		}

		// 해당 숫자의 모든 자릿수를 확인했는데 모두 4 또는 7에 해당하는 숫자였다면, true가 리턴됨
		// 아니라면 그 다음 i 숫자 검토
		if (only4and7 == true)
		{
			cout << i;
			return 0;
		}

	}
}