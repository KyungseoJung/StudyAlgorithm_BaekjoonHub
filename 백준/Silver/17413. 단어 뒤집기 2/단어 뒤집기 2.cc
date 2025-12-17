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
// 17413번 문제: 단어 뒤집기 2

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 공백으로 구분된 단어는 공백은 제외하고 단어 저장
	// <>으로 구분된 단어는 <> 포함해서 단어 저장
	// 출력할 땐, <>이 있는지 없는지 구분하여 reverse 할지 말지, 띄어쓰기 할지말지 구분

	string saveWord;
	string inputString;
	getline(cin, inputString);	// 띄어쓰기가 있으면 cin >> 으로 그냥 받지 말고, getline으로 띄어쓰기까지 포함해서 받기

	vector<string> saveWordSet;
	bool tagWord = false;	// 지금 저장하고 있는 단어가 tag 단어인지 아닌지 확인 (tag 단어이면 공백도 다 저장해야 하므로)
	for (int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == '<')
		{
			saveWord += inputString[i];
			tagWord = true;
			continue;	// 아래 코드들 싫애하지 말고 바로 다음 for문으로
		}
		else if (inputString[i] == '>')
		{
			saveWord += inputString[i];
			saveWordSet.push_back(saveWord);	// 최종 저장
			tagWord = false;

			saveWord = "";	// 초기화해주기
			continue;	// 아래 코드들 실행하지 말고 바로 다음 for문으로
		}

		// ----------------------
		if (tagWord == true) // 태그 단어이면 그 안의 입력은 그냥 다 저장해(공백도 그대로 저장)~
		{
			saveWord += inputString[i];
		}
		else // 태그 단어가 아닐 때 = 공백이 있거나 마지막 글자이면 저장해주기
		{
			// 공백으로 구분된 단어 저장하기
			if (inputString[i] == ' ')	// 공백이 나왔을 때 (마지막 글자일 때) 
			{
				// 하나의 단어 저장 완료하기
				saveWordSet.push_back(saveWord);
				saveWord = "";	// 초기화
			}
			else
			{
				saveWord += inputString[i];
			}

			// 단어를 마지막까지 saveWord에 다 저장했는데, 맨 뒤에 공백이 없고, 마지막 단어의 경우에는 직접 저장해주자
			// 그리고 다음에 tag 단어가 나오는 경우에도 저장해주자
			if ((i == (inputString.length() - 1)) || (inputString[i + 1] == '<'))
			{
				saveWordSet.push_back(saveWord);
				//cout << "tag가 아닌 단어들 저장: " << saveWordSet.back() << "\n";;
				saveWord = "";	// 초기화
			}
		}
	}

	// 저장된 단어들을 거꾸로 출력
	for (int i = 0; i < saveWordSet.size(); i++)
	{
		if (saveWordSet[i][0] == '<')	// 첫 번째 글자가 '<'이라면, 즉 Tag 단어라면
		{
			// 그대로 출력하기
			for (int j = 0; j < saveWordSet[i].length(); j++)
			{
				cout << saveWordSet[i][j];
			}
		}
		else
		{
			for (int j = saveWordSet[i].length() - 1; j >= 0; j--)
			{
				cout << saveWordSet[i][j];
			}

			// 이게 마지막 단어이거나, 다음에 tag 단어가 나온다면 공백 넣으면 안돼
			if ((i == saveWordSet.size() - 1) || 
				((i+1 < saveWordSet.size()) && (saveWordSet[i+1][0] == '<')))
			{
				continue;
			}
			else
			{
				cout << " ";	// Tag가 아닌 단어는 단어 사이에 공백 넣어주기
			}
		}

	}

	return 0;
}