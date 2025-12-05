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
// 11008번 문제: 복붙의 달인
// ** 간단하게 문자열.find() 이용한 방식

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;	// 테스트케이스의 개수
	cin >> T;
	string s, p;
	int ele;	// s 단어의 ele몇번째 요소에 접근하기 위함
	bool therIsWord;
	int count;
	while (T--)
	{
		cin >> s >> p;

		count = 0;		// 각 s 단어 안에 p가 몇 번 있는지 계산하기
		size_t pos = 0;	// 0의 자리부터 p찾기
		while (true)
		{
			pos = s.find(p, pos);	// pos위치부터 p 찾기;
			if (pos == string::npos)
			{
				break;	// 만약 p단어가 아예 없다면 break;
			}
			else // 단어가 있다면, 카운팅+1 하고, pos의 위치를 p의 길이만큼 이동시키기
			{
				count++;
				pos += p.length();
			}
		}
		// 최소 시간: (p가 몇번 들어가있는지) + (s의 전체 길이 - p의 길이 * p가 몇번 들어가있는지)
		cout << count + (s.length() - p.length() * count) << "\n";
	}

	
	return 0;
}