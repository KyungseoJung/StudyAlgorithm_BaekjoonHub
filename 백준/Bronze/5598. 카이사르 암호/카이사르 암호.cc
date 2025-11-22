#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 5598번 문제: 카이사르 암호

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	string inputString;
	cin >> inputString;

	// 'A': 65, 'Z': 90
	for (int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] - 3 < 65)
		{
			cout << char(inputString[i] - 3 + 25 + 1);
		}
		else
		{
			cout << char(inputString[i] - 3);
		}
	}
	

	return 0;
}