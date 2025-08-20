#include <iostream>
#include <vector>
#include <string>	// **getline을 사용하기 위함

//** 포인트: 
// (1) getline 사용해서 띄어쓰기까지 한 단어로 구분. 각 줄마다 단어 구분.
// cin.ignore도 중요! (개행문자도 하나의 단어로 인식해버리는 문제 해결)
// (2) str.insert(n, 'a')	// str이라는 string의 n번째 단어 앞에 'a' 추가

using namespace std;

vector <char> keyword;
bool checkAlreadyExist(char _input)	
{
	if (_input == ' ')    // 공백일 때에도 고려해줘야 함! 아니면 split 함수를 이용하거나
	{
		return true;    // true로 return해서, 이 공백 글자가 keyword가 될 수 없도록 해야 함
	}

	for (int i = 0; i < keyword.size(); i++)
	{
		if (keyword[i] == tolower(_input))	// _input은 소문자로만 설정됨
		{
			return true;
		}
	}

	// 위 for문에서 여기까지 온 것이면, 한 번도 return true 되지 않았다는 뜻.

	return false;

}

int main()
{
	int N;	// 옵션의 개수
	cin >> N;
	cin.ignore();   // 개행 문자 제거 
	// (숫자를 입력한 뒤, 엔터를 칠 때에도, 그 공백을 단어로 인식해버림) 그 문제를 해결하기 위함

	vector <string> word(N);

	for (int i = 0; i < N; i++)
	{
		getline(cin, word[i]);
	}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << i << "번째 단어: " << word[i] << "\n";
	//}

	//cout << "체크-------- \n";
	
	bool check;
	// 옵션마다 단축키 표시해주기
	for (int i = 0; i < N; i++)	// 각 N개의 단어들에 대해서
	{
		check = false;
		if (checkAlreadyExist(word[i][0]) == false)	// (1) 만약 첫 번째 단어의 단어[0]이 존재하지 않는 키워드라면, 그것을 키워드로 설정
		{
			keyword.push_back(tolower(word[i][0]));
			word[i].insert(1, "]");	// string에서 0번째 자리 앞에, 특정 요소 추가
			word[i].insert(0, "[");
			check = true;
			continue;	// 다음 for문으로 넘어가기 (아래 코드 실행X)
		}
		else // (2) 만약 첫 번째 글자가 이미 존재하는 키워드라면, 그 다음 단어들의 단어[0]를 검사하기
		{
			for (int j = 1; j < word[i].size(); j++)
			{
				if (word[i][j] == ' ')	// 공백 바로 다음 글자에 대해 검사
				{
					if( (j+1 < word[i].size()) && (checkAlreadyExist(word[i][j + 1]) == false))
					{
						keyword.push_back(tolower(word[i][j + 1]));
						word[i].insert(j + 2, "]");
						word[i].insert(j + 1, "[");
						check = true;
						break;	// 가장 안쪽 for문 벗어나기
					}
				}
			}
			if (check == true)
			{
				continue;	// 다음 for문으로 넘어가기 (아래 코드 실행X)
			}
		}

		// (3) 각 단어의 첫 번째 글자에 대해서 키워드로 지정하지 못했다면, 그냥 모든 글자 검사하기
		for (int j = 0; j < word[i].size(); j++)
		{
			if (checkAlreadyExist(word[i][j]) == false)
			{
				keyword.push_back(tolower(word[i][j]));
				word[i].insert(j + 1, "]");
				word[i].insert(j, "[");
				break;
			}
		}

	}

	// 최종 출력 ========================
	for (int i = 0; i < word.size(); i++)
	{
		cout << word[i] << "\n";
		//if (i != word.size() - 1)
		//{
		//	cout << "\n";
		//}
	}

	return 0;


}