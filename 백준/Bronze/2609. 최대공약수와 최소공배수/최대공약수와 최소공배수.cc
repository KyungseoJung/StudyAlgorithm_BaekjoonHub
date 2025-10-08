#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 2609번 문제.

int GCD(int num1, int num2)
{
	int min = (num1 > num2) ? num2 : num1;
	for (int i = min; i > 0; i--)
	{
		if ((num1 % i == 0) && (num2 % i == 0))
		{
			return i;
		}
	}
}
int main()
{
	// 최대공약수와 최소공배수의 곱은 두 수의 곱과 같다는 성질을 이용하기
	int num1, num2;
	cin >> num1 >> num2;

	int gcd = GCD(num1, num2);
	int lcm = (num1 * num2) / gcd;

	cout << gcd << "\n" << lcm;
	return 0;
}