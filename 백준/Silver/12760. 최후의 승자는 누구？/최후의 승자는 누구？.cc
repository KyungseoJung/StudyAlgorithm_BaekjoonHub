#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int N, M;	// N명의 플레이어, 각 플레이어가 가진 카드의 숫자 M장
	cin >> N >> M;

	// 숫자 넣기 ============================
	vector <int> num(M);	// 크기가 CARDNUM인 벡터
	vector <vector <int>> sortNums;
	for (int i = 0; i < N; i++)
	{
		// 카드 숫자들 입력하고, 정렬 (가장 작은 수가 맨 앞에 오도록) 
		for (int j = 0; j < M; j++)
		{
			cin >> num[j];
		}
		sort(num.begin(), num.end());

		sortNums.push_back(num);	// i행에 각각의 num들이 입력됨	
	}

	// 숫자 비교 ============================
	vector <int> win(N,0);	// N명의 플레이어의 우승 횟수를 기록 (처음에는 모두 0회)
	int max;
	for (int i = M-1; i >=0; i--)	// 가장 큰 카드를 차례대로 제출하도록 하기
	{
		// 가장 큰 값부터 파악해두기
		max = 0;
		for (int j = 0; j < N; j++)
		{
			if (sortNums[j][i] > max)
			{
				max = sortNums[j][i];
			}
		}

		// 가장 큰 값을 가진 플레이어들을 기록해두기 (1승 추가)
		for (int j = 0; j < N; j++)
		{
			if (sortNums[j][i] == max)
			{
				win[j] += 1;
			}
		}
	}

	// 가장 많이 이긴 횟수 파악하기
	int numMaxWin = 0;	// 가장 많이 이긴 횟수
	for (int i = 0; i < win.size(); i++)
	{
		if (win[i] > numMaxWin)
		{
			numMaxWin = win[i];
		}
	}

	// 해당하는 플레이어를 출력
	vector <int> winner;
	for (int i = 0; i < win.size(); i++)
	{
		if (win[i] == numMaxWin)
		{
			winner.push_back(i + 1);	// 플레이어들의 번호는 1부터이므로 +1 해주기
		}
	}

	sort(winner.begin(), winner.end());
	for (int i = 0; i<winner.size(); i++)
	{
		cout << winner[i] << " ";
	}

	return 0;
}
