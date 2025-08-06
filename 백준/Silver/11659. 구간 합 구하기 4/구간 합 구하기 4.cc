// **아이디어: 계산 시간 줄이기
// while(M--)  문 안에서 매번 for문을 계산하면, 시간 복잡도가 O(NM)으로 매우 커질 수 있음.
// 따라서, gpt 추천: 미리 누적합을 계산해놓기. -> 시간 복잡도 O(N) & 이후 while(M--)에서 계산해서 쓰기 => 최종 시간 복잡도 O(N+M)


#include <iostream>
#include <vector>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;	// 수의 개수 N. 합을 구해야 하는 횟수 M
	cin >> N >> M;

	vector <int> nums(N);
	vector <long long int> sums(N);	// 미리 누적합을 계산해놓기 (예: sums[1] = 0~1번째 수까지 더한 값)
	//int input;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		if (i == 0)
			sums[i] = nums[i];
		if (i >= 1)
		{
			sums[i] = sums[i - 1] + nums[i];
		}
	}

	int start, end;
	int sum;
	while (M--)
	{
		sum = 0;
		cin >> start >> end;
		
		if (start - 2 < 0)
		{
			//cout << "start-2 = " << start - 2 << "\n";
			sum = sums[end - 1];

		}
		else
		{
			sum = sums[end - 1] - sums[start - 2];

		}
		cout << sum << "\n";
	}

	return 0;
}