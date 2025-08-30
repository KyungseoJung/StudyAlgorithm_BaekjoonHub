#include <iostream>
#include <vector>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector <int> nums;
	vector <int> remove;	// 지워진 순서대로 K에 넣기
	int min = 9999;

	for (int i = 2; i <= N; i++)
	{
		nums.push_back(i);

		if (i < min)
		{
			min = i;
		}
	}

	int currentK = 0;
	int criterion;
	int recentErase;	// 가장 최근에 삭제한 숫자
	while (true)
	{

		criterion = nums.front();	// 가장 작은 숫자가 기준이 됨
		recentErase = nums.front();

		nums.erase(nums.begin());	// 일단 가장 작은 숫자 삭제
		currentK++;	// 하나 삭제했으므로 k

		if (currentK == K)	// 지울 때마다 수시로 확인하기
		{
			cout << recentErase;
			return 0;
		}
		// 알고리즘 순서대로 숫자 지우기
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % criterion == 0)	// criterion의 배수라면
			{
				// 순서대로 지우기
				recentErase = nums[i];	// 지우기 전에, 무슨 숫자를 지우는지 기억하기
				nums.erase(nums.begin() + i);
				currentK++;

				if (currentK == K)	// 지울 때마다 수시로 확인하기
				{
					cout << recentErase;
					return 0;
				}
			}
		}
	}

}