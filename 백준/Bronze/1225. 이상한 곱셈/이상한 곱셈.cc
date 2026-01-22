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
// 1225번 문제: 이상한 곱셈 

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string A, B;
	cin >> A;
	if (A == "0")	// 0만 주어지는 경우를 고려하기 위해, A만 따로 cin으로 받아서 판단하기
	{
		cout << 0;
		return 0;
	}

	cin >> B;

	long long int subtract;
	long long int sum = 0;
	for (int i = 0; i < A.length(); i++)
	{
		for (int j = 0; j < B.length(); j++)
		{
			subtract = (A[i] - '0') * (B[j] - '0');	// char를 int형으로 바꾸는 방법
			sum += subtract;
		}
	}

	cout << sum;
	return 0;
}