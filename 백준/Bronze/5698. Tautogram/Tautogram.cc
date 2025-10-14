#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// getline 함수
//#include <cctype>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input;


	while (true)
	{
		getline(cin, input);	// 문장 자체를 cin으로 받는 코드

		if (input == "*")	// '*'입력 받으면 코드 자체를 중단
		{
			return 0;
		}

		// 문장에 있는 단어들을 공백 기준으로 쪼개서 담기 ---------------------------
		// 문자열을 스트림화 
		stringstream  ss(input);
		
		vector <string> words;	// 공백 분리 결과를 저장할 vector 배열

		string word;

		// ss >> word : ss안에 들어간 각 단어들을 하나씩 빼내서 word에 넣어주고, true를 리턴함. 
		// 빼낼 단어가 없다면 false를 리턴함
		while (ss >> word)
		{
			words.push_back(word);
		}

		// 이제 각 단어들의 첫 시작 알파벳이 동일한지 확인하기 (모두 소문자로 만들어서 비교)(A와 a를 동일하다 판단하기 위함) ---------------------------
		char rememberAlphabet;
		rememberAlphabet = tolower(words[0][0]);	// 가장 첫 번째 단어의 첫 글자를 기억해두기
		
		bool alreadyPrint = false;
		for (int i = 1; i < words.size(); i++)
		{
			if (tolower(words[i][0]) != rememberAlphabet)
			{
				cout << "N\n";
				alreadyPrint = true;
				break;
			}
		}

		if (alreadyPrint == false)	// 아직도 프린트한 게 없다 = 각 단어의 첫 글자가 모두 동일하다
		{
			cout << "Y\n";
		}
	}

}
