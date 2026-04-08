#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N;
	cin >> N;

	vector <string> names(N);
	for (int i = 0; i < N; i++)
	{
		cin >> names[i];
	}

	// 범인 검사
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < names[i].size(); j++)
		{
			if (names[i][j] == 'S')
			{
				cout << names[i];
				return 0;
			}
		}
	}

}