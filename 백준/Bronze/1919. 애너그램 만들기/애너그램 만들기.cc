#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 1919번 문제: 애너그램 만들기

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input1, input2;
	cin >> input1 >> input2;
	int len1 = input1.length();
	int len2 = input2.length();

	int commonCount = 0;	// 동일한 알파벳 개수를 카운팅
	for (int i = 0; i < input1.length(); i++)
	{
		for (int j = 0; j < input2.length(); j++)
		{
			if (input1[i] == input2[j])
			{
				input2.erase(j, 1);	// (j번째에 있는 문자부터 1개까지의 문자를 삭제하기
				commonCount++;

				break;
			}
		}
	}

	cout << (len1 - commonCount) + (len2 - commonCount);
	return 0;
}