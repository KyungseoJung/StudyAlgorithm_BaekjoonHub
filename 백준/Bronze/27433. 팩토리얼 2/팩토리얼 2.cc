#include <iostream>

using namespace std;



// 재귀 문제 | 팩토리얼2

long long int factorial(long long int num, long long int& ans)

{

	if (num == 0)

	{

		return ans;

	}

	else

	{

		ans = ans * num;

		factorial(num -1, ans);

	}



	return ans;

}



int main()

{

	int N;

	cin >> N;

	long long int ans = 1;

	cout << factorial(N, ans);

}