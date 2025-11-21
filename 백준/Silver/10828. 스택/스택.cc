#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 10828번 문제: 스택(stack)
// stack: 후입선출(LIFO). queue: 선입선출(FIFO).

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	stack <int> st;
	int N;	// 명령어 개수
	cin >> N;

	string command;
	int commandInt;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> commandInt;
			st.push(commandInt);
		}
		else if (command == "pop")
		{
			if (st.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (command == "size")
		{
			cout << st.size() << "\n";
		}
		else if (command == "empty")
		{
			if (st.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (command == "top")
		{
			if (st.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << st.top() << "\n";
			}
		}
	}

	return 0;
}