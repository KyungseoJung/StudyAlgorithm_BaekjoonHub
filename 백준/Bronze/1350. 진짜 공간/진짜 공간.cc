#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N;
	cin >> N;

	// 입력-----------
	long long int clusterSize;
	vector <long long int> files(N);

	for (int i = 0; i < N; i++)
	{
		cin >> files[i];
	}
	cin >> clusterSize;

	// 계산 -----------
	long long int clusterSum = 0;
	long long int quotient;	// 나머지에서의 몫
	for (int i = 0; i < N; i++)
	{
		if (files[i] == 0)
		{
			continue;	// 파일 크기 0이면 덧셈 안하고 넘어가기
		}
		else
		{
			quotient = files[i] / clusterSize;

			if (files[i] % clusterSize == 0)
			{
				clusterSum += (clusterSize * (quotient));
			}
			else
			{
				clusterSum += (clusterSize * (quotient + 1));

			}
		}
	}
	cout << clusterSum;

	return 0;
}