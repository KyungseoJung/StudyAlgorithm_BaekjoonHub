 // 문제집) 영단어 암기는 괴로워
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 영어 단어 순서
	/*
	1. 자주 나오는 단어일수록 앞에 배치
	2. 해당 단어의 길이가 길수록 앞에 배치
	3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치

	+) M보다 짧은 길이의 단어는 취급X.
	*/

	int N, M;
	cin >> N >> M;	// 영어 지문에 나오는 단어의 개수 N. 단어의 길이 기준이 되는 M

	map <string, int> m;
	string inputStr;
	for (int i = 0; i < N; i++)
	{
		cin >> inputStr;
		if (inputStr.length() >= M)
		{
			m[inputStr]++;
		}
		// 초기 입력: 처음 입력되는 inputStr이면 자동으로 추가해주고,
		// 중복 입력: 이미 존재했던 inputStr이면 그에 대한 int 값을 1씩 증가시켜주도록
	}

	// * 이해 목적: m이 어떻게 정렬되어 들어갔는지 검토 (for (auto& member: m) 사용해야 함!!) ------------- 
	//cout << "m.size() = " << m.size() << "\n";
	//for (auto& member : m)
	//{
	//	cout << member.first << " " << member.second << "\n";
	//}
	/* 아래는 잘못된 코드: map은 []인덱스 접근을 허용하지 않음. []로 접근하면, 그냥 [괄호] 안에 있는 Key에 접근한다는 뜻 => map[1] : 1이라는 Key에 접근한다 */
	/* 따라서, 아래처럼 auto& 형식을 이용해서 접근해야 함*/
	//for (int i = 0; i < m.size(); i++)
	//{
	//	cout << m[i].first << " " << m[i].second << "\n";
	//}

	// sort를 진행하기 위해 map의 데이터들을 vector로 옮겨주기
	vector<pair<string, int>> v(m.begin(), m.end());

	// sort 진행하기
	sort(v.begin(), v.end(), [](pair<string, int> const& l, pair<string, int> const& r)
	{
		if (l.second != r.second)
		{
			return l.second > r.second;	// 내림차순
		}
		else if (l.first.length() != r.first.length())
		{
			return l.first.length() > r.first.length();	// 내림차순
		}
		else if(l.first != r.first)
		{
			return l.first < r.first;	// 오름차순
		}
	});

	// 최종 출력 ------------------
	for (auto& member : v)
	{
		cout << member.first << "\n";
	}
	// 메모리 크기를 다루거나 인덱스를 다루기 때문에 size_t 사용. (unsigned type이고, 다루는 숫자의 범위가 더 넓다는 장점이 있음)
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	cout << v[i].first << "\n";
	//}

	return 0;
}