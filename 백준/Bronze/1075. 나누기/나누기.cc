#include <iostream>
#include <vector>
#include <cmath>	// pow 사용 목적
#include <string>	// stoi 사용 목적 (String -> to -> int)

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string NString;	// N의 값이 몇자리수인지 확인하기 위함
	int N;
	int F;
	
	cin >> NString >> F;
	N = stoi(NString);
	//cout << "출력: " << NString.length();

	int baseNum = 0;	// 뒤의 두 자리수를 바꾸기 전 숫자
	for (int i = 2; i < NString.length(); i++)
	{
		//cout << "끝에서 " << i+1 << "번째 자리: " << NString[NString.length() - i -1] << "\n";
		baseNum += pow(10, i) * (NString[NString.length() - i - 1 ] - '0');
	}
	//cout << "baseNum: " << baseNum;

	int endNum;
	for (int i = 0; i < 100; i++)
	{
		if ((baseNum + i) % F == 0)
		{
			endNum = i;
			break;
		}
	}

	if (endNum < 10)
	{
		cout << "0" << endNum;
		return 0;
	}
	else if (endNum >= 10)
	{
		cout << endNum;
		return 0;
	}

}