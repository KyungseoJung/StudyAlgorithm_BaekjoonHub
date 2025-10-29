#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 11170번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;	// 테스트 개수
	cin >> T;

	int numOfInput = 2;	// 입력할 숫자 개수
	int lowerBound, upperBound;

	string st;
	int count;
	while (T--)
	{
		cin >> lowerBound >> upperBound;

		// 0들어간 개수 세기
		count = 0;
		for (int i = lowerBound; i <= upperBound; i++)
		{
			st = to_string(i);
			// 각 숫자의 자릿수를 확인하면서 0인지 확인
			for (int j = 0; j<st.length(); j++)
			{
				if (st[j] == '0')
				{
					count++;
				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}