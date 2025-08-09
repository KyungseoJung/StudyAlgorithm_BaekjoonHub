#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N;
	cin >> N;

	vector <vector<int>> info(N);
	// 0번째 값: 몸무게
	// 1번째 값: 키
	// 2번째 값: rank
	
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		info[i].push_back(x);	// 몸무게 등록 (info[i][0])
		info[i].push_back(y);	// 키 등록 (info[i][1])
		info[i].push_back(1);	// rank 초기값을 1로 설정 (info[i][2])
	}

	int rank;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((info[i][0] < info[j][0]) && (info[i][1] < info[j][1]))
			{
				info[i][2] += 1;
			}
		}
	}
		
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
		{
			cout << info[i][2];
			// 공백 없이 바로 종료시키기
			return 0;
		}
		cout << info[i][2] << " ";
	}

}