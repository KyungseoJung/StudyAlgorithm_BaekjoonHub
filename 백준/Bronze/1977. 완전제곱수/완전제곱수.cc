#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>	// #sqrt 사용

using namespace std;
// 1977번 문제.

int main()
{
	int M, N;
	cin >> M >> N;
	int num;
	vector <int> nums;
	for (int i = M; i <= N; i++)
	{
		num = (int) sqrt(i);
		if (pow(num, 2) == i)
		{
			nums.push_back(i);
		}
	}

	if (nums.size() == 0)
	{
		cout << -1;
		return 0;
	}

	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}

	cout << sum << "\n" << nums[0];
	return 0;
}
