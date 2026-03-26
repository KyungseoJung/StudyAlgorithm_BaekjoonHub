#include <iostream>
#include <vector>

using namespace std;
// 2238번 문제: 경매
int main()
{
	int U, N;
	string S;
	int P;

	cin >> U >> N;
	vector <string> names(N);		// name 저장용
	vector <int> prices(N);		// price 저장용
	vector <int> countPrice(U + 1, 0);	// 각 가격별로 몇번 제시되었는지 카운팅
	
	for (int i = 0; i < N; i++)
	{
		cin >> S >> P;
		names[i] = S;
		prices[i] = P;

		countPrice[P]++;	// 해당 가격 P가 몇 번 제시되었는지 확인
	}


	// 제시된 가격들 확인하기 - 가장 적은 사람이 제시한 가격을 찾기
	int minMention = 99999;
	int minPrice = 0; // 가장 적게 언급된 가격 중, 최소 가격
	// i는 1부터 검사하기 (금액은 1부터 가능하므로)
	for (int i = 1; i<=U; i++)
	{
		if ((countPrice[i] > 0) && (countPrice[i] < minMention))
		{
			minMention = countPrice[i];
			minPrice = i;
		}
	}
	
	//cout << minPrice;
	string firstSayPerson;
	// 가장 먼저 해당 금액을 언급한 사람을 찾기
	for (int i = 0; i < N; i++)
	{
		if (prices[i] == minPrice)
		{
			firstSayPerson = names[i];
			break;
		}
	}

	cout << firstSayPerson << " " << minPrice;

	return 0;
}