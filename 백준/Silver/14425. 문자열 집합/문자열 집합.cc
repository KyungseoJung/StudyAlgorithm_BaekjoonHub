#include <iostream>
//#include <vector>
//#include <set>
#include <unordered_set>
using namespace std;

// 문제: 집합과 맵 | (4) 문자열 집합
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	string input;
	unordered_set <string> originSet;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		originSet.insert(input);
	}

	int sum = 0;
	while (M--)
	{
		cin >> input;
		//for (int i = 0; i < N; i++)
		//{
		if (originSet.count(input))
		{
			sum++;
			//break;	// for문 통과
		}
		//}
	}

	cout << sum;
	return 0;

}