#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isupper, islower 함수 (소문자인지, 대문자인지 확인)

//#11655번 문제
// *** 핵심, islower와 isupper의 출력값: 맞다면 0이 아닌 수가 출력되고, 아니면 0이 출력됨.
// 즉, islower(문자) == true라고 하면, 안 됨!! true는 1을 의미하므로, 만약 정말 소문자여도 == true가 틀릴 수 있음.
// 진짜 구분하고 싶다면, ==0인지, 또는 !=0인지를 체크해야 함.
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 각 알파벳을 숫자로 나타내면 몇인지 확인.
	// 대문자 (65~90), 소문자 (97~122)
	//int A = 'A';	//65
	//int Z = 'Z';	// 90
	//int a = 'a';	// 97
	//int z = 'z';	// 122
	//cout << "A: " << A << ", Z: " << Z << ", a: " << a << ", z: " << z;

	
	string inputString;
	getline(cin, inputString);

	int len = inputString.length();
	for (int i = 0; i < len; i++)
	{
		if (inputString[i] == ' ')
		{
			cout << ' ';
		}
		else if (isdigit(inputString[i]))	// 숫자는 바로 그대로 출력하기
		{
			cout << inputString[i];
		}
		else
		{
			// 대문자인데, 13을 더했을 때 'Z'를 넘어가버리면 
			if ((isupper(inputString[i]) != 0) && (inputString[i] + 13 > 90))
			{
				cout << char(inputString[i] + 13 - 26);
			}
			else if ((islower(inputString[i]) != 0) && (inputString[i] + 13 > 122))
			{
				cout << char(inputString[i] + 13 - 26);
			}
			else
			{
				cout << char(inputString[i] + 13);
			}
		}
	}
	

	return 0;

}
