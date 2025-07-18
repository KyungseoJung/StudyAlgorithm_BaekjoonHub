#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int main()
{
	// push_front(), push_back(), pop_front(), pop_back()
	// at(idx), [dix], .front(), .back(), .clear(), .size(), .empty(), 
	// 등등 다양한 멤버 함수

	int N;
	cin >> N;

	deque <int> dq(N);

	for (int i = 0; i < N; i++)	// 번호 먼저 입력
	{
		dq[i] = i + 1;
	}

	int i = 1;
	while(dq.size()>1)
	{
		if (i % 2 != 0)	// i가 홀수일 때
		{
			dq.pop_front();	// 맨 앞에 있는 값을 pop
		}
		else if (i % 2 == 0)	// i가 짝수일 때
		{
			dq.push_back(dq.front());	// 맨 앞에 있는 값을 뒤로 push하고,
			dq.pop_front();				// 맨 앞에 있는 값을 pop하기
		}
		i++;
	}
	cout << dq.front();
	
	return 0;
}