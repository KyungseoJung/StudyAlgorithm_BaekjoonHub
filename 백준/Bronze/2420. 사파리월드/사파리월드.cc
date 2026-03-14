#include <iostream>

using namespace std;
int main()
{
	long long int N, M;
	cin >> N >> M;
	long long int diff = N - M;
	long long int answer;
	if (diff > 0)
	{
		answer = diff;
	}
	else
	{
		answer = -diff;
	}

	cout << answer;
	return 0;
}