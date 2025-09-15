#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
	int N;
	cin >> N;
	vector <int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	for(int i = nums.size() - 1; i >=0 ; i--)
	{
		cout << nums[i] << "\n";
	}
	return 0;
}