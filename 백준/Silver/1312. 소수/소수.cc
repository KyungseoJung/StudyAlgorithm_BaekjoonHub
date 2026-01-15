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
// 1312번 문제: 소수 (https://www.acmicpc.net/problem/1312)
//*** 세로 나눗셈에서 영감 받아서 수식으로 풀어야 하는 문제

int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B;
	int N;
	cin >> A >> B >> N;

	/*
	long double result = A / B;

	// 소수점 n번째 자리 숫자 = 10^n을 곱한 후, 일의 자리의 숫자 (=10으로 나눴을 때의 나머지)
	long double multiple = result * pow(10, N);

	// double(실수)를 10으로 나눈 후의 나머지 계산은 적절하지 X.
	//*** int로 변환해서 자연스럽게 소수점 아래의 값들을 날려주기
	cout << int(multiple) % 10;
	*/

	// 위와 같은 방식으로 하면, 숫자가 너무 커지는 문제가 생김. 10^N을 곱할 때 숫자가 너무너무 커짐 - (N은 1이상 1,000,000 이하이므로)
	
	//*** 초등학교 때 하던 세로 나눗셈을 이용하기
	// Ex) 25 7 1 -> 25%7의 소수점 아래 1번째 자리 숫자는 [(25 - (25/7) * 7) * 10 ] / 7  = 5.
	//						소수점 아래 2번재 자리 숫자는 [(40 - 5 * 7) * 10] / 7 = 7

	int dividend = A;	// 피제수 (나눔을 당하는 수)				 // 처음에는 A로 설정
	int mult = A / B;	// 곱셈 계산에 쓰이는 수 (소수점 버린 정수)	 // 처음에는 A/B로 설정
	int point;	// 소수점 자리 숫자 (1번째, 2번째, ...)
	// 소수점 아래 1번째 숫자
	point = ((dividend - mult * B) * 10) / B;

	dividend = ((dividend - mult * B) * 10);
	mult = point;
	for (long long int i = 2; i <= N; i++)	// 소수점 아래 2번째 숫자, 3번째 숫자 ...
	{
		point = ((dividend - mult * B) * 10) / B;

		dividend = ((dividend - mult * B) * 10);
		mult = point;
	}

	cout << point;



	return 0;
}