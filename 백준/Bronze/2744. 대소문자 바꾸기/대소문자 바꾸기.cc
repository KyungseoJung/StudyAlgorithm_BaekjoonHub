#include <iostream>

using namespace std;
// 2744번 문제: 대소문자 바꾸기

// toupper와 tolower는 기본적으로 int를 출력한대.
// 그래서, char = tolower('A') <- 이런식으로 받으면, 자동으로 변환이 되지만
// 출력할 때에는 숫자가 출력되기 때문에 (char) 변수형 변환이 필요하대
int main()
{
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		if (isupper(input[i]) != 0)
		{
			cout << (char)tolower(input[i]);
		}
		else
		{
			cout << (char)toupper(input[i]);
		}
	}

	return 0;
}