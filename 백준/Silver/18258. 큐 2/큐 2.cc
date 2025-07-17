#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int main()
{
	// 빠른 입출력 가능하도록 하는 코드
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// queue(큐) 구현: push, pop, size, empty, front, back
	int N; // 명령의 수 (1 <= N <= 2,000,000)

	queue <int> qu;

	string command;
	int commandNum;

	cin >> N;
	while (N--)
	{
		cin >> command;
		if(command == "push")
		{
			cin >> commandNum;
			qu.push(commandNum);
		}
		else if (command == "pop")
		{
			if (qu.empty()) // 비어 있다면 -1 출력 
				cout << "-1\n";
			else // 비어 있지 않다면
			{
				cout << qu.front() << "\n";
				qu.pop();
			}
		}
		else if (command == "size")
		{
			cout << qu.size() << "\n";
		}
		else if (command == "empty")
		{
			if (qu.empty())	// (vectorQ.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (command == "front")
		{
			if (qu.empty())
				cout << "-1\n";
			else
				cout << qu.front() << "\n";
		}
		else if (command == "back")
		{
			if (qu.empty())
				cout << "-1\n";
			else
				cout << qu.back() << "\n";
		}

	}

	return 0;

}