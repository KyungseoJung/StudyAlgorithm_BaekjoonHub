#include <iostream>
#include <deque>
#include <algorithm>	// std::find 기능 사용하기 위함
using namespace std;
deque <int> S;

bool checkIsThereNum(int num)
{
	auto findEle = find(S.begin(), S.end(), num);
	// find 함수의 타입은=> InputIt: 반복자 타입(벡터, 덱, 배열, 리스트 등의 iterator)

	// find를 이용해서 begin()부터 end()까지 탐색함. 
	// 만약 찾았다면, findEle가 S.end()가 아니게 되고,
	// 찾지 못했다면, findEle가 S.end()가 되는 것임.
	if (findEle != S.end())
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> M;

	string order;
	int num;
	while (M--)
	{
		//cout << "현재 M: " << M << "\n";
		cin >> order;

		if (order == "add")
		{
			cin >> num;
			if (checkIsThereNum(num) == true)
			{
				continue;
			}
			else
			{
				S.push_back(num);
			}
		}
		else if (order == "remove")
		{
			cin >> num;
			if (checkIsThereNum(num) == false)
			{
				continue;

			}
			else
			{
				auto findEle = find(S.begin(), S.end(), num);
				S.erase(findEle);
				continue;

			}

		}
		else if (order == "check")
		{
			cin >> num;
			if (checkIsThereNum(num) == true)
			{
				cout << "1\n";
				continue;

			}
			else
			{
				cout << "0\n";
				continue;

			}
		}
		else if (order == "toggle")
		{
			cin >> num;
			if (checkIsThereNum(num) == true)
			{
				auto findEle = find(S.begin(), S.end(), num);
				S.erase(findEle);
				continue;

			}
			else
			{
				S.push_back(num);
				continue;

			}
		}
		else if (order == "all")
		{
			S.clear();
			for (int i = 1; i <= 20; i++)
			{
				S.push_back(i);
			}
		}
		else if (order == "empty")
		{
			S.clear();
			continue;
		}
	}

	return 0;
}