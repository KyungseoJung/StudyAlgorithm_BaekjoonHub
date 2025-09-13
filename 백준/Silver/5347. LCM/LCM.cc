#include <iostream>
#include <vector>

using namespace std;
// **** 핵심 아이디어: 곱셈과 나눗셈을 계산할 때, 숫자가 매우 커질 것 같다면, 나누기 먼저 해주기
long long int GCD(long long int a, long long int b)
{


	long long int num1 = (a > b) ? a : b;
	long long int num2 = (a > b) ? b : a;


	// GCD(num1, num2) = GCD(num1%num2, num2)
	// 서로 나눈 값의 나머지로 업데이트 해주기. 
	// 만약 그 나머지가 0이 되는 순간이 온다면, 그 순간의 작은 값이 최대공약수임.
	while (true)
	{
		if (num1 % num2 == 0)
		{
			return num2;
		}
		else
		{
			num1 = num1 % num2;
		}

		if (num2 % num1 == 0)
		{
			return num1;
		}
		else
		{
			num2 = num2 % num1;
		}

	}
}

long long int LCM(int a, int b)
{
	// 두 수의 곱 = 두 수의 최대공약수(GCD) * 두 수의 최소공배수(LCM)

	//long long int lcm = (a * b) / GCD(a, b);	// **** 이렇게 처음부터 곱셈을 계산하고 나누면, 오버플로우가 발생해서 계산이 비정상적일 수도 있음.
	long long int temp = a / GCD(a, b);

	return temp * b;
}


int main()
{
	int n;
	cin >> n;
	long long int a, b;
	while (n--)
	{
		cin >> a >> b;
		cout << LCM(a, b) << "\n";
	}

	return 0;
}