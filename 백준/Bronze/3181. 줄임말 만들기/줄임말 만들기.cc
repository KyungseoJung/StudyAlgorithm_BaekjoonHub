#include <iostream>
#include <vector>
#include <string>	// getline 사용 목적
#include <sstream>	// stringstream 사용 목적
using namespace std;

// 3181 문제: 줄임말 만들기

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector <string> unnecessaryWords = { "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili" };

	string input;
	getline(cin, input);

	stringstream ss(input);
	string word;
	int ele = 0;
	bool dontPrint;
	while (ss >> word)
	{
		dontPrint = false;
		if (ele == 0)
		{
			cout << (char)toupper(word[0]);
			ele++;
		}
		else
		{
			// 첫 번째 단어 이후의 단어부터는 아래 검문 거치기
			for (int i = 0; i < unnecessaryWords.size(); i++)
			{
				if (word == unnecessaryWords[i])
				{
					dontPrint = true;
					break;
				}
			}

			if (dontPrint == false)
			{
				cout << (char)toupper(word[0]);
			}
		}
	}

	return 0;
}