#include <iostream>
#include <vector>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int input;
	int min = 9999999;
	int max = -9999999;
	for (int i = 0; i < N; i++)
	{
		cin >> input;

		if (input < min)
			min = input;

		if (input > max)
			max = input;
	}

	cout << min << " " << max;
	return 0;
}