#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N, M;	// 총 바구니 N개. 공을 넣는 횟수 M번
	cin >> N >> M;
	//vector <int> basket(N);	// N개의 요소를 0으로 초기화
	vector <int> basket(N, 0);	// N개의 요소를 0으로 초기화

	int start, end, ballNum;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> ballNum;
		for (int j = start - 1; j <= end - 1; j++)
		{
			basket[j] = ballNum;
		}
	}

	// 출력
	for (int i = 0; i < N; i++)
	{
		cout << basket[i];
		if (i != (N - 1))
		{
			cout << " ";
		}
	}

	return 0;
}