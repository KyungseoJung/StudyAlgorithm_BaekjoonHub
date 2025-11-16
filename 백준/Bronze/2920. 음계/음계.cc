#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
using namespace std;
// 2920번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 8;
	vector <int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	// 각 숫자들의 간격 확인
	int diff;
	for (int i = 0; i < N - 1; i++)
	{
		if (i == 0)
		{
			diff = nums[i + 1] - nums[i];
		}
		else
		{
			if (nums[i + 1] - nums[i] != diff)
			{
				cout << "mixed";
				return 0;
			}
		}
	}
	// 위 for문을 통과해서 여기까지 왔다며, 각 숫자들간의 값 차이가 모두 동일하다는 것
	// = 오름차순이거나 내림차순이라는 것
	if (diff == 1)
	{
		cout << "ascending";
	}
	else if (diff == -1)
	{
		cout << "descending";
	}

	return 0;
}