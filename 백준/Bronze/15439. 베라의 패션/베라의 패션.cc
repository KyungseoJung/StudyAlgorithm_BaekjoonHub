#include <iostream>

using namespace std;
int main()
{

	int N;	// 상의 N벌과 하의 N벌
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				count++;
			}
		}
	}

	cout << count;
	return 0;
}