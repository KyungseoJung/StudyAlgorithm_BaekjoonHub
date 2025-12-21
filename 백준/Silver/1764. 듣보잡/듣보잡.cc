#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 1764번 문제: 듣보잡
// ** set은 요소들이 정렬이 되어서 들어가고, find하는 속도도 vector보다 훨씬 빠르다
int main()
{
	// 연산 속도 빠르게 해주는 코드 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	//vector <string> donthear(N);
	set <string> donthear;
	string input;

	//vector <string> donthearandsee;
	set <string> donthearandsee;
	for (int i = 0; i < N; i++)	// 듣도 못한 사람 저장
	{
		cin >> input;
		donthear.insert(input);
	}
	for (int i = 0; i < M; i++) // 보도 못한 사람 입력받아서, 듣도 못한 사람의 이름들과 비교 -> 동일한 이름이 있으면, 그 사람은 듣보잡
	{
		cin >> input;
		//for (int j = 0; j < N; j++)
		//{
		//	if (dontsee == donthear[j])
		//	{
		//		donthearandsee.push_back(dontsee);
		//	}
		//}
		//auto it = find(donthear.begin(), donthear.end(), input);	// <-- 이 방식은 vector에서 find하는 거랑 같은 방식임. set의 장점을 전혀 이용하지 못하는 것
		auto it = donthear.find(input);
		if (it != donthear.end())	// 듣도 못한 사람 중에, 보도 못한 사람도 있는 것임
		{
			donthearandsee.insert(input);
		}
		//else // 겹치는 사람이 없는 것
		//{

		//}
	}

	// set 은 이미 정렬되어서 들어간대
	//sort(donthearandsee.begin(), donthearandsee.end());

	cout << donthearandsee.size() << "\n";
	for (const string& s : donthearandsee)
	{
		cout << s << "\n";
	}




	return 0;
}