#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> pos(n);
	for (int i = 0; i < n; i++)
	{
		cin >> pos[i];
	}

	long long int sum = 0;
	long long int dist;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// n^2개의 모든 쌍에 대해서 거리를 더하라고 했으므로, j=(i+1)에서 시작하는 게 아닌 듯
			dist = (pos[i] - pos[j] > 0) ? (pos[i] - pos[j]) : (pos[j] - pos[i]);
			sum += dist;
		}
	}

	cout << sum;
	return 0;
}