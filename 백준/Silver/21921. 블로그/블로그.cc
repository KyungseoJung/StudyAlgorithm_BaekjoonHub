#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
using namespace std;
// 21921번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, X;
	cin >> N >> X;
	vector <int> inputNum(N);
	vector <int> numDuringPeriod(N - X + 1);

	int sum = 0;
	int ele = 0;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> inputNum[i];

		sum += inputNum[i];
		if (i < X - 1)
		{
			continue;	// 아래 코드 거치지 않도록 continue
		}

		if (i >= X)
		{
			sum -= inputNum[i - X];
		}

		// X-1 이상부터는 numDuringPeriod에 기록해주기
		numDuringPeriod[ele] = sum;
		if (sum > max)	// 최댓값 기록
		{
			max = sum;
		}
		ele++;
	}

	// 최댓값과 동일한 숫자가 몇 개인지 카운팅
	int count = 0;
	for (int i = 0; i < numDuringPeriod.size(); i++)
	{
		if (numDuringPeriod[i] == max)
		{
			count++;
		}
	}

	if (max == 0)
	{
		cout << "SAD";
	}
	else
	{
		cout << max << "\n" << count;
	}

	return 0;
}