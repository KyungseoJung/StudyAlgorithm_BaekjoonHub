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
// 2669번 문제: 직사각형 네개의 합집합의 면적 구하기

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
		for (int i = 0; i < s.length(); i++)
		{
			therIsWord = false;
			if (s[i] == p[0])	// 첫 번째 글자가 같다면, 나머지 글자들도 동일한지 확인하기
			{
				//cout << i << "번째 글자가 p의 0번째와 동일 \n";
				therIsWord = true;
				ele = i+1;
				for (int j = 1; j < p.length(); j++)
				{
					if (ele >= s.length())
					{
						therIsWord = false;	//**** false 처리 안해주고 break하면 그냥 카운팅 되어버림
						// 만약, s 단어의 최대 길이를 넘어서면 그냥 거기서 멈추기
						break;
					}
					if (s[ele] != p[j])
					{
						therIsWord = false;	// 한번이라도 다르면, 바로 false처리하고 break; 해서 for문 벗어나기
						break;
					}
					ele++;

					// for문을 지나는동안, 한번도 다른 게 없었다면 s단어 안에 p가 있는 것임!!
				}
			}
			// if문을 나올 때, therIsWord가 true라면 단어가 1개 있는 것.
			// 그 이후에 단어가 또 있을 수 있기 때문에, 계속 체크
			if (therIsWord == true)
			{
				count++;
				// **** 그러면 i를 p.length()만큼 건너뛰어야 함. 왜?: s가 aaaa, p가 aa같은 단어라면, 중복해서 카운팅할 수도 있으니까
				i += p.length()-1;	// (총 p.length()을 더해줘야 함) (But, 큰 for문에서 어차피 +1 해줄거니까. 여기서는 미리 -1해주기)
			}
		}
		// 최소 시간: (p가 몇번 들어가있는지) + (s의 전체 길이 - p의 길이 * p가 몇번 들어가있는지)
		cout << count + (s.length() - p.length() * count) << "\n";
	}

	
	return 0;
}