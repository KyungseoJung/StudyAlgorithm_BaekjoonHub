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
// 14405번 문제: 피카츄

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;

	vector <string> pikachu = { "pi", "ka", "chu" };

	bool same;
	for (int i = 0; i < S.length(); i++)
	{
		same = false;
		for (int j = 0; j < pikachu.size(); j++)
		{
			if (S[i] == pikachu[j][0])	// 첫 번째 글자와 동일하다면
			{
				same = true;
				for (int k = 1; k < pikachu[j].length(); k++) // 그 이후의 글자도 모두 동일한지 확인
				{
					if (S[i + k] != pikachu[j][k])
					{
						same = false;
					}
				}
				if (same == true)
				{
					i += (pikachu[j].length() - 1);	// 다음 for문에서 i+=1 하니까 여기서는 -1해주기
				}
				else // 하나라도 동일하지 않은 글자가 있다면 바로 NO 출력하고 종료. (***이게 가능한 건, "pi", "ka", "chu" 모두 첫 글자가 다른 덕분임)
				{
					cout << "NO";
					return 0;
				}
			}
		}

		if (same == false)	// 동일한 앞글자가 하나도 없다면
		{
			cout << "NO";
			return 0;
		}
	}

	// 위에서 NO로 한번도 출력이 안됐따 = 문장 전체가 "pi", "ka", "chu"로 이루어져있다.
	cout << "YES";

	return 0;
}