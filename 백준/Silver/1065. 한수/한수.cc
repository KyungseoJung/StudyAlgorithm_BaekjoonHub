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
// 1065번 문제: 한수

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;
	// 1부터 99까지 한수 : 99개. (한자리, 두자리수는 그 자체로 등차수열)
	// 100이상부터는 : 두 수의 차이가 0, 1, 2, 순으로 카운팅할 수 있음. -> 이렇게 계산하면 연산량이 더 줄어들긴 하는데, 어차피 지금 문제는 1000이하이니까 for문 돌리자.!!
		// 두 수 차이가 0 : 111
		// 두 수 차이가 1 : 123

	int count = 0;
	int diff = 0;	// 두 수 차이
	int num1, num2, num3;	// 세 자리 수 중 첫째자리, 둘째자리, 셋째자리 수
	if (num < 100)
	{
		cout << num;
	}
	else
	{
		count = 99;	// 1이상 99이하의 숫자들은 모두 한수이므로
		// 1000은 어차피 한수가 될 수 없으므로 세자리 수만 생각하자
		for (int i = 100; i <= num; i++)
		{
			num1 = to_string(i)[0] - '0';	// 1번째 자리 숫자를 int로 빼오기
			num2 = to_string(i)[1] - '0';	// 1번째 자리 숫자를 int로 빼오기
			num3 = to_string(i)[2] - '0';	// 1번째 자리 숫자를 int로 빼오기
		
			if ((num2 - num1) == (num3 - num2))
			{
				count++;
			}
		}

		cout << count;
	}

	return 0;
}