#include <iostream>

using namespace std;
// ** 동적 프로그래밍이란?: https://sectumsempra.tistory.com/86
/*
* 동적 프로그래밍이란: 처음 주어진 문제를 더 작은 문제들로 나눈 뒤 각 조각의 답을 계산하고, 이 답들로부터 원래 문제에 대한 답을 계산하는 방식.
* 피보나치 예시: Top-down 방식과 Bottom-up 방식
*/

int wArr[101][101][101] = { 0 };
// 만약, -50이라면, +50해서 0찾기
// 0이라면, +50해서 50 찾기
// 50이라면, +50해서 100찾기

// ** 내가 이용한 방식: 위 설명글에도 나와있는 Top-down 방식. 이미 계산해둔 값을 반복해서 또 계산하지 않도록 저장해두기!
int w(int a, int b, int c)
{
	if (wArr[a + 50][b + 50][c + 50] != 0)	// 이미 값을 구한 경우라면, 이전에 저장했던 값을 사용
	{
		return wArr[a + 50][b + 50][c + 50];
	}

	// 이미 구한 적이 없다면, 아래 코드를 통해 구하기. return 하기 전에 저장해놓기.
	if ((a <= 0) || (b <= 0) || (c <= 0))
	{
		return 1;
	}
	else if ((a > 20) || (b > 20) || (c > 20))
	{
		wArr[a + 50][b + 50][c + 50] = w(20, 20, 20);
		return wArr[a + 50][b + 50][c + 50];

		//return w(20, 20, 20);
	}
	else if ((a < b) && (b < c))
	{
		wArr[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return wArr[a + 50][b + 50][c + 50];

		//return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		wArr[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		return wArr[a + 50][b + 50][c + 50];

		//return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}
int main()
{
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if ((a != -1) || (b != -1) || (c != -1))	// 셋 중 하나라도 -1이 아니라면
		{
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
		}
		else
		{
			return 0;
		}
	}
}