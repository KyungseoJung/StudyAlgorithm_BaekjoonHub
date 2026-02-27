#include <iostream>

using namespace std;
// 2443번 문제: 별 찍기 - 6
int main()
{
	int N;
	cin >> N;

	for (int i = 1; i<= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < (2 * N - (2 * i - 1)); j++)
		{
			cout << '*';
		}
		//for (int j = 1; j < i; j++)
		//{
		//	cout << ' ';
		//}
		cout << "\n";
	}
}