#include <iostream>

using namespace std;

// 2446번 문제: 별 찍기 - 9
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j<(2*N-1); j++)
		{
			if ((j >= i) && (j < 2 * N - i - 1))
			{
				cout << '*';
			}
			else if(j< i)	// ** 그냥 else를 사용하면, 대칭으로 공백 만드는 것. else if(j<i) 사용하면, 오른쪽 공백은 없도록 하는 것
			{
				cout << ' ';
			}
		}
		cout << "\n";
	}
	
	for (int i = (N-2); i >= 0; i--)
	{
		for (int j = 0; j < (2 * N - 1); j++)
		{
			if ((j >= i) && (j < 2 * N - i - 1))
			{
				cout << '*';
			}
			else if (j < i)	// ** 그냥 else를 사용하면, 대칭으로 공백 만드는 것. else if(j<i) 사용하면, 오른쪽 공백은 없도록 하는 것
			{
				cout << ' ';
			}
		}
		cout << "\n";
	}

	return 0;
}