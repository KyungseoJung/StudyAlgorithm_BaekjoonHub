#include <iostream>
#include <string>	// to_string 함수 사용
#include <cmath>	// pow 함수 사용 
using namespace std;
// 1357번 문제: 뒤집힌 덧셈

int Rev(int num)
{
	string input = to_string(num);
	int len = input.length();

	int output = 0;
	for (int i = 0; i < len; i++)
	{
		// 100의 자리의 숫자는 x(10^0) 하고 바로 더하고
		// 10의 자리의 숫자는 x(10^1) 하고 더하고
		// 1의 자리의 숫자는 x(10^2)하고 더하고 ...
		output += (input[i] - '0') * pow(10, i);
	}

	return output;
}

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int X, Y;
	cin >> X >> Y;

	int Rev_X = Rev(X);
	int Rev_Y = Rev(Y);

	cout << Rev(Rev_X + Rev_Y);
	return 0;
}