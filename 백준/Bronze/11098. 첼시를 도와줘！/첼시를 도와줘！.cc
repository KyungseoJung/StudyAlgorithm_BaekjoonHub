#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 11170번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;	// 테스트 개수
	cin >> T;

	int num;
	string price, name;
	int maxPrice;
	int rememberEle;
	string member[100][2];
	for (int i = 0; i < T; i++)
	{
		cin >> num;
		maxPrice = 0;
		for (int j = 0; j < num; j++)
		{
			//cout << "num for문 -- \n";
			cin >> price >> name;
			member[j][0] = price;
			member[j][1] = name;

			if (stoi(price) > maxPrice)
			{
				maxPrice = stoi(price);
				rememberEle = j;
			}
		}

		cout << member[rememberEle][1] << "\n";
	}
	return 0;
}