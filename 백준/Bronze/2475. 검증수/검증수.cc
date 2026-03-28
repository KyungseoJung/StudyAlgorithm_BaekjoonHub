#include <iostream>
#include <vector>

using namespace std;
// 1809번 문제: Moo
int main()
{
	int N = 5;
	int sum = 0;
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		sum  = sum + (input * input);
	}

	int rest;
	rest = sum % 10;

	cout << rest;
	return 0;
}