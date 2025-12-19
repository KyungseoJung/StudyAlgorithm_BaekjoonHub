#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 17413번 문제: 단어 뒤집기 2

int main()
{
	int time;
	cin >> time;

	// A,B,C는 각각 5분, 1분, 10초를 의미한다.
	int A = 300;
	int B = 60;
	int C = 10;

	int ANum, BNum, CNum;
	int rest = time;	// 계산용으로 사용하기 위한 나머지
	if (time >= A)
	{
		ANum = rest / A;
		rest -= A * ANum;
	}
	else
	{
		ANum = 0;
	}


	if (rest >= B)
	{
		BNum = rest / B;
		rest -= B * BNum;
	}
	else
	{
		BNum = 0;
	}


	if (rest >= C)
	{
		CNum = rest / C;
		rest -= C * CNum;
	}
	else
	{
		CNum = 0;
	}


	if (rest == 0)
	{
		cout << ANum << " " << BNum << " " << CNum;
	}
	else
	{
		cout << -1;
	}

	return 0;
}