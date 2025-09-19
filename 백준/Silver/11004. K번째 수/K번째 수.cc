#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector <int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());	// 오름차순 정렬

	cout << nums[K - 1];
}