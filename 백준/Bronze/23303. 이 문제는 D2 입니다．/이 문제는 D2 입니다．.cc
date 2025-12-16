#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isincreaseper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#23303번 문제: 이 문제는 D2 입니다.

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input;
	getline(cin, input);

	bool checkWord = false;
	for (int i = 0; i < input.length()-1; i++) // 2글자를 검사할 거니까 input.length()-1까지만 검사하기
	{
		if (tolower(input[i]) == 'd')
		{
			if (input[i + 1] == '2')
			{
				checkWord = true;
			}
		}
	}

	if (checkWord)
	{
		cout << "D2";
	}
	else
	{
		cout << "unrated";
	}

	return 0;

}
