#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	deque <int> people(N);
	vector <int> answer(N);

	for (int i = 0; i < N; i++)
	{
		people[i] = i + 1;	// 0번째 사람에게는 1번 부여.
	}

	int num;
	int popNum = K - 1;
	int ele = 0;
	while (people.size() >0)
	{
		while(popNum >= people.size())
		{
			popNum = popNum - people.size();
		}
		//cout << people.size() << "개 데이터 중에, " << popNum << "번 요소 빼기\n";

		answer[ele] = (people[popNum]);

		people.erase(people.begin() + popNum);
		popNum += K -1;	// 앞의 원소가 없어지면서 1칸씩 앞으로 땡겨졌기 때문에, 뽑는 번호의 수도 앞으로 1칸씩 당겨주기
		ele++;
	}

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		cout << answer[i];
		if (i < N - 1)
		{
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}