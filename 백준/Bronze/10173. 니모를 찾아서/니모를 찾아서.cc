#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 10173번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string inputString;

	//// 숫자 입력하고 엔터칠 때, 첫 엔터는 무시하도록
	//cin.ignore();
	bool found;
	while(true)
	{
		getline(cin, inputString);
		found = false;

		if (inputString == "EOI")
		{
			return 0;
		}
		for (int j = 0; j < inputString.length(); j++)
		{
			if ((tolower(inputString[j]) == 'n') && (tolower(inputString[j + 1]) == 'e')
				&& (tolower(inputString[j + 2]) == 'm') && (tolower(inputString[j + 3]) == 'o'))
			{
				cout << "Found\n";
				found = true;
				break;
			}
		}
		// for문을 통과했을 때의 found 상태 확인하고, 여전히 못 찾았다면 "Missing" 출력
		if (found == false)
		{
			cout << "Missing\n";
		}
	}
}