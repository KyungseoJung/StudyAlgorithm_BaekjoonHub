#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 11721번 문제: 숫자

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cin.ignore();	// 첫 번째 input값 입력할 때의 엔터 무시

	string inputString;
	getline(cin, inputString);

	for (int i = 0; i < inputString.length(); i++)
	{
		cout << inputString[i];
		if (i % 10 == 9)
		{
			cout << "\n";
		}
	}


	return 0;
}