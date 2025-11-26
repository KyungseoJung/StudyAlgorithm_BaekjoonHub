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
// 10845번 문제: 큐(queue)

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	queue <int> q;

	int N;
	cin >> N;

	string commandString;
	int input;
	while (N--)
	{
		cin >> commandString;
		if (commandString == "push")
		{
			cin >> input;
			q.push(input);
		}
		else if (commandString == "pop")
		{
			if (q.empty() != 0)	// empty인 것이 거짓이 아니라면 (= 비어있다면)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (commandString == "size")
		{
			cout << q.size() << "\n";
		}
		else if (commandString == "empty")
		{
			if (q.empty() != 0)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (commandString == "front")
		{
			if (q.empty() != 0)	// 비어있다면
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
			}
		}
		else if (commandString == "back")
		{
			if (q.empty() != 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
	}
	

	return 0;
}