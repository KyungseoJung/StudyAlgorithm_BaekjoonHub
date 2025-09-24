#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int test;
	cin >> test;

	int maxIndex;
	string sentence;
	for (int i = 0; i < test; i++)
	{
		cin >> sentence;
		int maxIndex;
		maxIndex = sqrt(sentence.length());

		//cout << sentence.length() << " " << length << "\n";

		// 마지막 열부터 0행, 1행, 2행, .. 순서로 읽어야 함
		// 만약, 3x3 행렬이라면, 처음: 3, 6, 9번째 단어/ 다음: 2, 5, 8번재 단어/ 다음: 1, 4, 7번째 단어를 출력해야 함
		// 총 몇 단계인지 결정하는 게 j
		int ele = 1;
		for (int j = 0; j < maxIndex; j++)
		{
			for (int k = 1; k <= maxIndex; k++)
			{
				//cout << k * maxIndex - ele << " | ";
				cout << sentence[k * maxIndex - ele];
			}
			ele += 1;
		}
		cout << "\n";
	}

	return 0;
}