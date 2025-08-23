#include <iostream>

using namespace std;
// ** 동적 프로그래밍이란?: https://sectumsempra.tistory.com/86
/*
* 동적 프로그래밍이란: 처음 주어진 문제를 더 작은 문제들로 나눈 뒤 각 조각의 답을 계산하고, 이 답들로부터 원래 문제에 대한 답을 계산하는 방식.
* 피보나치 예시: Top-down 방식과 Bottom-up 방식
*/

int count1= 0;
int count2 = 0;

int fib(int n)
{
	if ((n == 1) || (n == 2))
	{
		count1++;
		return 1;	//# 여기가 코드1이래
	}
	else
	{
		return (fib(n - 1) + fib(n - 2));
	}
}

int f[40];
int fibonacci(int n)
{
	f[1] = 1;
	f[2] = 1;


	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];	//# 여기가 코드2래
		count2++;
	}

	return f[n];
}

int main()
{
	int n;
	cin >> n;
	fib(n);
	fibonacci(n);

	cout << count1 << " " << count2;
	return 0;
}