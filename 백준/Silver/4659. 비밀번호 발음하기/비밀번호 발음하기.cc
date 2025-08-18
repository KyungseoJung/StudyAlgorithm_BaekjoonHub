#include <iostream>
#include <vector>

using namespace std;

vector <char> include = { 'a', 'e', 'i', 'o', 'u'};

void printEvaluation(string word)
{
	/*
	* 높은 품질을 가진 비밀번호의 조건
	1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
	2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
	3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
	*/
	// false이면 조건을 만족하지 못 한 것. true이면 조건을 만족한 것.
	bool condition1 = false; // 처음엔 false. 모음 하나라도 포함되면 true로 바꾸자
	bool condition2 = true;	// 처음엔 true. 3개 연속으로 오면 false로 바꾸자
	bool condition3 = true; // 처음엔 true. 같은 글자가 연속으로 오면 false로 바꾸자
	// 1번째 조건 확인
	for(int i=0; i<word.length(); i++)
	{
		for (int j = 0; j < include.size(); j++)
		{
			if (word[i] == include[j])
			{
				condition1 = true;
				break;
			}
		}
		if (condition1 == true)
		{
			break;
		}
	}
	// 2번째 조건 확인
	bool checkAlphabet = false;
	int vowel = 0; // 모음이 연속으로 몇 번 나왔는지
	int consonant = 0; //자음이 연속으로 몇 번 나왔는지
	for (int i = 0; i < word.length(); i++)
	{
		checkAlphabet = false;
		for (int j = 0; j < include.size(); j++)
		{
			if (word[i] == include[j])
			{
				// 비밀번호의 i번째 알파벳이 모음이라면
				checkAlphabet = true;

				if(consonant > 0)
				{
					consonant = 0;
					vowel = 1;
				}
				else 
				{
					vowel++;
				}
				break;
			}

		}
		if (checkAlphabet == false)	// 위 for문에서 checkAlphabet이 true가 안 됐다 = i번째 알파벳은 모음이 아니다.
		{
			if (vowel > 0)
			{
				vowel = 0;
				consonant = 1;
			}
			else
			{
				consonant++;

			}
		}

		if ((consonant >= 3) || (vowel >=3))
		{
			condition2 = false;
			break;
		}
	}
	// 3번째 조건 확인
	for (int i = 1; i < word.size(); i++) // 1번째 글자부터 시작. [i-1]번째 단어를 확인할 것이기 때문
	{
		if (word[i] == word[i - 1])
		{
			if ((word[i] != 'e') && (word[i] != 'o'))	// 그 겹친 글자가 e도 아니고, o도 아니라면
			{
				condition3 = false;
				break;
			}
		}
	}
	
	if ((condition1 == false) || (condition2 == false) || (condition3 == false))
	{
		cout << "<" << word << "> is not acceptable.\n";

	}
	else
	{
		cout << "<" << word << "> is acceptable.\n";

	}
}

int main()
{
	//vector <string> passwd;
	string input;
	while (true)
	{
		cin >> input;
		if (input == "end")
		{
			return 0;
		}
		//passwd.push_back(input);

		printEvaluation(input);
	}
}