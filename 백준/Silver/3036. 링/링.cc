#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int GCD(int a, int b)
{
	// 최대공약수 구하기
	int min = (a > b) ? b : a;
	for (int i = min; i >= 0; i--)
	{
		if ((a % i == 0) && (b % i == 0))
		{
			return i;
		}
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector <int> circles(N);

	for (int i = 0; i < N; i++)
	{
		cin >> circles[i];
	}


	// 1번재 수와 n번째 수와 최대공약수를 구하고, 그 수로 나누기
	int divisor;
	for (int i = 1; i < N; i++)
	{
		divisor = GCD(circles[0], circles[i]);

		cout << (circles[0] / divisor) << "/" << (circles[i] / divisor) << "\n";
	}

	return 0;
}