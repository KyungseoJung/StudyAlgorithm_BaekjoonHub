#include <iostream>
#include <vector>

using namespace std;
// 1233번 문제: 주사위
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int S1, S2, S3;
	cin >> S1 >> S2 >> S3;
	vector <int> numRecord(S1 + S2 + S3+1, 0);	// 0부터 (S1 + S2 + S3)까지의 등장 횟수를 저장할 vector. 
	// 모든 원소는 0으로 시작.

	int sum;

	// 나오는 합의 숫자를 하나하나 기록
	for (int i = 1; i <= S1; i++)
	{
		sum = 0;
		for (int j = 1; j <= S2; j++)
		{
			for (int k = 1; k <= S3; k++)
			{
				sum = i + j+ k;
				//cout << "합은 " << sum << "\n";
				numRecord[sum]++;
			}
		}
	}

	// 가장 많이 기록된 개수를 확인 & 그때의 숫자를 확인 
	int max = 0;
	int ele = 0;
	for (int i = 0; i < numRecord.size(); i++)
	{
		if (numRecord[i] > max)
		{
			max = numRecord[i];
			ele = i;
		}
	}

	cout << ele;
	return 0;
}