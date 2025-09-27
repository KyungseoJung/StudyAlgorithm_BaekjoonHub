#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수 목적
#include <string>	// stoi 함수 목적
#include <algorithm>	// sort, reverse 함수 목적

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	int num;
	int input;
	int min;
	int sum;

	while (T--)
	{
		num = 7;
		min = 9999;
		sum = 0;
		while (num--)
		{
			cin >> input;
			if (input % 2 == 0)
			{
				sum += input;
				if (input < min)
				{
					min = input;
				}
			}

		}
		cout << sum << " " << min;
		
		cout << "\n";
	}

	return 0;
}