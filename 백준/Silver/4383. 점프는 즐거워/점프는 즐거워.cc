#include <iostream>
#include <vector>

using namespace std;
// 4383번 문제: 점프는 즐거워
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	int diff;
	vector <int> nums;
	vector <int> checkDiff;
	bool jolly;
	while (cin >> n)
	{
		jolly = true;

		nums.assign(n, 0);
		checkDiff.assign(n, 0);	// 1부터 n-1까지의 요소만 이용하기
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}

		// 차이값들 저장하기
		for (int i = 1; i < n; i++)
		{
			diff = (nums[i] - nums[i - 1] > 0) ? (nums[i] - nums[i - 1]) : -(nums[i] - nums[i - 1]);
			if ((diff >= 1) && (diff <= n - 1))
			{
				checkDiff[diff] += 1;
			}
		}

		// 차이값들 확인하기
		for (int i = 1; i < n; i++)
		{
			if (checkDiff[i] == 0)
			{
				cout << "Not jolly\n";
				jolly = false;
				break;
			}
		}
		if (jolly == true)
		{
			cout << "Jolly\n";
			// 다음으로 넘어가기~
		}
	}

	return 0;
}