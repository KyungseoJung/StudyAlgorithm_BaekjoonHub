#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isincreaseper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#1543번 문제: 문서 검색

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string st;
	getline(cin, st);	// 띄어쓰기를 줄 바꿈으로 인식할 수 있으므로, getline으로 받기

	//cin.ignore();	// 그 사이에 띄어쓰기 1번은 무시해주기 (아닌가봐 그냥 getline만 하면, 한줄씩 받아들이나봐)

	string word;
	getline(cin, word);
	int ele;
	int same;
	int count = 0;
	for (int i = 0; i < st.length(); i++)
	{
		if (st[i] == word[0])	// 첫 글자가 똑같다면, 그 다음 글자부터 확인하기
		{
			ele = 1;
			same = true;
			for (int j = 1; j < word.length(); j++)
			{
				// 일단 길이가 초과되면 안됨
				if (i + ele >= st.length())
				{
					same = false;
				}
				else if (st[i + ele] == word[j])
				{
					ele++;
				}
				else
				{
					same = false;
				}
			}

			// 끝났을 때, 모든 글자가 동일하다면 (다른 글자가 하나도 없었다면)
			if (same == true)
			{
				count += 1;
				i += word.length()-1;	// 이미 for문에서 한번 i++을 해줄 것이기 때문에 -1 한만큼만 더해주기
			}
		}
	}

	cout << count;


	return 0;

}
