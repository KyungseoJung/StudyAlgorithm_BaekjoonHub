#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector <int> nums(n+1);
	nums[0] = 0;
	nums[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		nums[i] = nums[i - 1] + nums[i - 2];
	}

	cout << nums[n];
	return 0;
}