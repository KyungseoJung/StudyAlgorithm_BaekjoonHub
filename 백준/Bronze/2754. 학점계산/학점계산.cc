#include <iostream>
#include <iomanip>	// setprecision 함수 사용
using namespace std;
int main()
{
	string input;
	cin >> input;

	char firstChar = input[0];
	
	float criterion = 0.0;
	switch (firstChar)
	{
	case 'A':
		criterion = 4.0;
		break;
	case 'B':
		criterion = 3.0;
		break;
	case 'C':
		criterion = 2.0;
		break;
	case 'D':
		criterion = 1.0;
		break;
	case 'F':
		criterion = 0.0;
		break;

	}

	if (input.length() > 1)
	{
		char secondChar = input[1];
		switch (secondChar)
		{
		case '+':
			criterion += 0.3;
			break;
		case '-':
			criterion -= 0.3;
			break;
		}
	}

	cout << fixed << setprecision(1) << criterion;	// 소수점 1자리까지 출력되도록
}