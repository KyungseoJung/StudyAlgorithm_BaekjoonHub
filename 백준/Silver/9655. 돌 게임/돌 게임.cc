#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	if (N % 2 == 0)
	{
		// 짝수라면 창영 승
		cout << "CY";
		return 0;
	}
	else
	{
		// 홀수라면 상근 승
		cout << "SK";
		return 0;
	}
}