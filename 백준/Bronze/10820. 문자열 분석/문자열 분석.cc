#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 10820번 문제: 문자열 분석

//** isdigit() 함수 익히기 (islower도 같은 방식) ====> 그냥 '0이 아님'으로 판단하기
// isdigit(숫자) 라면, 0이 아닌 수가 나옴
// isdigt(숫자아님) 라면, 0이 나옴

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string inputString;
	int countLower, countUpper, countNum, countBlank;
	while (getline(cin, inputString))
	{
		

		countLower = 0;
		countUpper = 0;
		countNum = 0;
		countBlank = 0;
		for (int i = 0; i < inputString.length(); i++)
		{
			if (islower(inputString[i]) != 0)
			{
				countLower++;
			}
			else if (isupper(inputString[i]) != 0)
			{
				countUpper++;
			}
			else if (isdigit(inputString[i]) != 0)
			{
				countNum++;
			}
			else if (inputString[i] == ' ')
			{
				countBlank++;
			}
		}

		cout << countLower << " " << countUpper << " " << countNum << " " << countBlank << "\n";
	}
	

	return 0;
}