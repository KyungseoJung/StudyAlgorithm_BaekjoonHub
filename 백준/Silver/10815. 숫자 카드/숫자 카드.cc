#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;

	vector <int> card(N);	// 상근이가 가지고 있는 숫자 카드에 적혀있는 정수들 (-10,000,000 ~ 10,000,000)
	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}
	// ** 추가 코드
	sort(card.begin(), card.end());	// O(N log N)



	std::cin >> M;
	vector <int> find(M);	// 가지고 있는지 구분해야 할 M개의 정수

	vector <bool> answer(M);	// 가지고 있는지 or 아닌지 여부를 작성할 행렬

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		//** 이진 탐색으로 카드에 있는지 확인
		answer[i] = binary_search(card.begin(), card.end(), x);	// O(long N)
	}

	for (int i = 0; i < M; i++)
	{
		cout << (answer[i] ? 1 : 0) << " ";
	}

	return 0;
}