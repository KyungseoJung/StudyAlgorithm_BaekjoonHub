#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>	// stoi 함수

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 3;
	int T;
	cin >> T;
	vector <int> nums(10);
	while (T--)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			cin >> nums[i];
		}

		sort(nums.begin(), nums.end());

		cout << nums[nums.size() - 3] << "\n";
	}

	return 0;

}
