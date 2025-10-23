#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#2460번 문제
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num = 10;	// 총 10개의 역
	int off, on;	// 내린 사람, 탄 사람 숫자 입력
	int presentNum = 0;	// 현재 기차에 탄 사람 숫자 카운팅
	int max = 0;

	for (int i = 0; i < num; i++)
	{
		cin >> off >> on;
		presentNum = presentNum -off + on;
		if (presentNum > max)
		{
			max = presentNum;
		}
	}

	cout << max;

	return 0;
}
