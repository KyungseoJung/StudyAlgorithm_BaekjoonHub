#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
	// 작동 속도 더 빠르게 하기 위한 코드
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

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