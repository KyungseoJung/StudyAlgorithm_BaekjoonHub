#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 3040번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num = 9;
	int sum = 0;
	vector <int> capNum(num);
	for (int i = 0; i < num; i++)
	{
		cin >> capNum[i];
		sum += capNum[i];
	}
	int diff = sum - 100;

	// 이 diff를 만족시키는 난쟁이 2명을 찾으면 되는 것!
	for (int i = 0; i < num; i++)
	{
		for (int j = (i + 1); j < num; j++)
		{
			if (capNum[i] + capNum[j] == diff)
			{
				// 난쟁이 2명을 vector 리스트에서 제거하기 (뒷번호부터 제거해야 앞번호의 난쟁이 번호가 올바르게 삭제됨)
				capNum.erase(capNum.begin() + j);
				capNum.erase(capNum.begin() + i);
				
				//바로 출력해서 코드종료시키기
				for (int k = 0; k < capNum.size(); k++)
				{
					cout << capNum[k] << "\n";
				}
				return 0;
			}
		}
	}
}